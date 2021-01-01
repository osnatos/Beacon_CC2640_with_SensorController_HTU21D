/******************************************************************************

 @file  main.c

 @brief main entry of the Micro BLE sample application.

 Group: WCS, BTS
 Target Device: cc2640r2

 ******************************************************************************
 
 Copyright (c) 2013-2020, Texas Instruments Incorporated
 All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions
 are met:

 *  Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.

 *  Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.

 *  Neither the name of Texas Instruments Incorporated nor the names of
    its contributors may be used to endorse or promote products derived
    from this software without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

 ******************************************************************************
 
 
 *****************************************************************************/

/*******************************************************************************
 * INCLUDES
 */

#include <xdc/runtime/Error.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Clock.h>
#include <ti/display/Display.h>
#include <ti/drivers/Power.h>
#include <ti/drivers/power/PowerCC26XX.h>
#include <ti/drivers/PIN.h>

/* Header files required to enable instruction fetch cache */
#include <inc/hw_memmap.h>
#include <driverlib/vims.h>
#include "board.h"

#ifdef USE_ICALL
#include <icall.h>
#endif // USE_ICALL

#include <hal_assert.h>
#include "micro_eddystone_beacon.h"
//#include "stdlib.h"
//--------------------------------------------------------------------
// Sensor controller:
#include <application/SensorController/scif_htu21d.h>
#define BV(n) (1 << (n))
/*******************************************************************************
 * MACROS
 */

/*******************************************************************************
 * CONSTANTS
 */

/*******************************************************************************
 * TYPEDEFS
 */

/*******************************************************************************
 * LOCAL VARIABLES
 */

/*******************************************************************************
 * GLOBAL VARIABLES
 */
// uint16 temperature;
// uint16 humidity;
 float temperature;
 float humidity;


/*******************************************************************************
 * EXTERNS
 */
extern assertCback_t halAssertCback;

extern void AssertHandler(uint8 assertCause, uint8 assertSubcause);

extern Display_Handle dispHandle;

/*******************************************************************************
 * @fn          Main
 *
 * @brief       Application Main
 *
 * input parameters
 *
 * @param       None.
 *
 * output parameters
 *
 * @param       None.
 *
 * @return      None.
 */
int main()
{
  /* Register Application callback to trap asserts raised in the Stack */
  halAssertCback = AssertHandler;

  PIN_init(BoardGpioInitTable);

  /* Enable iCache prefetching */
  VIMSConfigure(VIMS_BASE, TRUE, TRUE);

  /* Enable cache */
  VIMSModeSet(VIMS_BASE, VIMS_MODE_ENABLED);

#ifndef POWER_SAVING
  /* Set constraints for Standby, powerdown and idle mode */
  /* PowerCC26XX_SB_DISALLOW may be redundant */
  Power_setConstraint(PowerCC26XX_SB_DISALLOW);
  Power_setConstraint(PowerCC26XX_IDLE_PD_DISALLOW);
#endif /* POWER_SAVING */

#ifdef USE_ICALL
  /* Initialize ICall module */
  ICall_init();
#endif /* USE_ICALL */

  /* Kick off application - Priority 1 */
  MicroEddystoneBeacon_createTask();
  //------------------------------------------------------------------------------
  void scTaskAlertCallback(void);
    // Initialize the Sensor Controller
    scifOsalInit();
    scifOsalRegisterTaskAlertCallback(scTaskAlertCallback);
    scifInit(&scifHtu21dDriverSetup);

    // Set the Sensor Controller task tick interval to 1 second
    uint32_t rtc_Hz = 1;  // 1Hz RTC
    scifHtu21dStartRtcTicksNow(0x00010000 / rtc_Hz);

    // Configure Sensor Controller tasksSCIF_HTU21DTASK_TASK_ID

    // Start Sensor Controller task
    scifStartTasksNbl(BV(SCIF_HTU21D_HTU21DTASK_TASK_ID));
    //------------------------------------------------------------------------------

  BIOS_start();     /* enable interrupts and start SYS/BIOS */

  return 0;
}

/*******************************************************************************
 * @fn          AssertHandler
 *
 * @brief       This is the Application's callback handler for asserts raised
 *              in the stack.  When EXT_HAL_ASSERT is defined in the Stack
 *              project this function will be called when an assert is raised,
 *              and can be used to observe or trap a violation from expected
 *              behavior.
 *
 *              As an example, for Heap allocation failures the Stack will raise
 *              HAL_ASSERT_CAUSE_OUT_OF_MEMORY as the assertCause and
 *              HAL_ASSERT_SUBCAUSE_NONE as the assertSubcause.  An application
 *              developer could trap any malloc failure on the stack by calling
 *              HAL_ASSERT_SPINLOCK under the matching case.
 *
 *              An application developer is encouraged to extend this function
 *              for use by their own application.  To do this, add hal_assert.c
 *              to your project workspace, the path to hal_assert.h (this can
 *              be found on the stack side). Asserts are raised by including
 *              hal_assert.h and using macro HAL_ASSERT(cause) to raise an
 *              assert with argument assertCause.  the assertSubcause may be
 *              optionally set by macro HAL_ASSERT_SET_SUBCAUSE(subCause) prior
 *              to asserting the cause it describes. More information is
 *              available in hal_assert.h.
 *
 * input parameters
 *
 * @param       assertCause    - Assert cause as defined in hal_assert.h.
 * @param       assertSubcause - Optional assert subcause (see hal_assert.h).
 *
 * output parameters
 *
 * @param       None.
 *
 * @return      None.
 */
void AssertHandler(uint8 assertCause, uint8 assertSubcause)
{
#if !defined(Display_DISABLE_ALL)
  // Open the display if the app has not already done so
  if ( !dispHandle )
  {
  #if defined(BOARD_DISPLAY_USE_LCD)
    dispHandle = Display_open(Display_Type_LCD, NULL);
  #elif defined (BOARD_DISPLAY_USE_UART)
    dispHandle = Display_open(Display_Type_UART, NULL);
  #endif // BOARD_DISPLAY_USE_LCD, BOARD_DISPLAY_USE_UART
  }

  Display_print0(dispHandle, 0, 0, ">>>STACK ASSERT");
#endif // ! Display_DISABLE_ALL

  // check the assert cause
  switch (assertCause)
  {
    case HAL_ASSERT_CAUSE_OUT_OF_MEMORY:
#if !defined(Display_DISABLE_ALL)
      Display_print0(dispHandle, 0, 0, "***ERROR***");
      Display_print0(dispHandle, 2, 0, ">> OUT OF MEMORY!");
#endif // ! Display_DISABLE_ALL
      break;

    case HAL_ASSERT_CAUSE_INTERNAL_ERROR:
      // check the subcause
      if (assertSubcause == HAL_ASSERT_SUBCAUSE_FW_INERNAL_ERROR)
      {
#if !defined(Display_DISABLE_ALL)
        Display_print0(dispHandle, 0, 0, "***ERROR***");
        Display_print0(dispHandle, 2, 0, ">> INTERNAL FW ERROR!");
#endif // ! Display_DISABLE_ALL
      }
      else
      {
#if !defined(Display_DISABLE_ALL)
        Display_print0(dispHandle, 0, 0, "***ERROR***");
        Display_print0(dispHandle, 2, 0, ">> INTERNAL ERROR!");
#endif // ! Display_DISABLE_ALL
      }
      break;

    case HAL_ASSERT_CAUSE_ICALL_ABORT:
#if !defined(Display_DISABLE_ALL)
      Display_print0(dispHandle, 0, 0, "***ERROR***");
      Display_print0(dispHandle, 2, 0, ">> ICALL ABORT!");
#endif // ! Display_DISABLE_ALL
      HAL_ASSERT_SPINLOCK;
      break;

    default:
#if !defined(Display_DISABLE_ALL)
      Display_print0(dispHandle, 0, 0, "***ERROR***");
      Display_print0(dispHandle, 2, 0, ">> DEFAULT SPINLOCK!");
#endif // ! Display_DISABLE_ALL
      HAL_ASSERT_SPINLOCK;
  }

  return;
}


/*******************************************************************************
 * @fn          smallErrorHook
 *
 * @brief       Error handler to be hooked into TI-RTOS.
 *
 * input parameters
 *
 * @param       eb - Pointer to Error Block.
 *
 * output parameters
 *
 * @param       None.
 *
 * @return      None.
 */
void smallErrorHook(Error_Block *eb)
{
  for (;;);
}


/*******************************************************************************
 */
//==============================================================================
void processTaskAlert(void)
{
  //----------------------------------------------------------------------------
  // Clear the ALERT interrupt source
  scifClearAlertIntSource();
  //----------------------------------------------------------------------------
  // Do SC Task processing here
  //---
  bool  htu21_crc_check( uint16_t value, uint8_t crc);
  float ConvertTemperature(float temp);
  float ConvertHumidity(float hum);
  //---
  temperature = scifHtu21dTaskData.htu21dtask.output.tmp;
  humidity = scifHtu21dTaskData.htu21dtask.output.hum;
  //---
  temperature= ConvertTemperature(temperature);
  humidity = ConvertHumidity(humidity);
  //----------------------------------------------------------------------------
  // Acknowledge the ALERT event
  scifAckAlertEvents();

} // processTaskAlert
//==============================================================================
void scTaskAlertCallback(void)
{
    // Call process function
     processTaskAlert();
} // scTaskAlertCallback
//==============================================================================
bool  htu21_crc_check( uint16_t value, uint8_t crc)
{
   uint32_t polynom = 0x988000; // x^8 + x^5 + x^4 + 1
   uint32_t msb     = 0x800000;
   uint32_t mask    = 0xFF8000;
   uint32_t result  = (uint32_t)value<<8; // Pad with zeros as specified in spec

   while( msb != 0x80 ) {
       // Check if msb of current value is 1 and apply XOR mask
       if( result & msb )
           result = ((result ^ polynom) & mask) | ( result & ~mask);

       // Shift by one
       msb >>= 1;
       mask >>= 1;
       polynom >>=1;
   }
   if( result == crc ) return  true;  // CRC OK
   else return false;  // CRC ERR
}
//==============================================================================
float ConvertTemperature(float temp){
    float fTemp;
    fTemp = -46.85+(175.72*temp/65536);
    return fTemp;
}
//==============================================================================
float ConvertHumidity(float hum){
    float fRH;
    fRH = -6+(125*hum/65536);
    return fRH;
}
//==============================================================================



