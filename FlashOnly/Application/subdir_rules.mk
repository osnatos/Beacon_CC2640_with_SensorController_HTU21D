################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
Application/%.obj: ../Application/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccs1010/ccs/tools/compiler/ti-cgt-arm_16.9.11.LTS/bin/armcl" -mv7M3 --code_state=16 -me -Ooff --opt_for_speed=0 --include_path="D:/Projects/Beacon_HTU21D/Beacon_CC2640_with_SensorController_HTU21D_Clone" --include_path="D:/Projects/Beacon_HTU21D/Beacon_CC2640_with_SensorController_HTU21D_Clone/Application" --include_path="D:/Projects/Beacon_HTU21D/Beacon_CC2640_with_SensorController_HTU21D_Clone/Startup" --include_path="C:/ti/simplelink_cc2640r2_sdk_4_20_00_04/source/ti/blestack/controller/cc26xx_r2/inc" --include_path="C:/ti/simplelink_cc2640r2_sdk_4_20_00_04/source/ti/blestack/inc" --include_path="C:/ti/simplelink_cc2640r2_sdk_4_20_00_04/source/ti/blestack/rom" --include_path="C:/ti/simplelink_cc2640r2_sdk_4_20_00_04/source/ti/blestack/boards" --include_path="C:/ti/simplelink_cc2640r2_sdk_4_20_00_04/source/ti/blestack/common/cc26xx" --include_path="C:/ti/simplelink_cc2640r2_sdk_4_20_00_04/examples/rtos/CC2640R2_LAUNCHXL/blestack/micro_eddystone_beacon_with_SensorController/src/app" --include_path="C:/ti/simplelink_cc2640r2_sdk_4_20_00_04/source/ti/blestack/icall/inc" --include_path="C:/ti/simplelink_cc2640r2_sdk_4_20_00_04/source/ti/blestack/profiles/roles/cc26xx" --include_path="C:/ti/simplelink_cc2640r2_sdk_4_20_00_04/source/ti/blestack/profiles/roles" --include_path="C:/ti/simplelink_cc2640r2_sdk_4_20_00_04/source/ti/blestack/target" --include_path="C:/ti/simplelink_cc2640r2_sdk_4_20_00_04/source/ti/blestack/hal/src/target/_common" --include_path="C:/ti/simplelink_cc2640r2_sdk_4_20_00_04/source/ti/blestack/hal/src/target/_common/cc26xx" --include_path="C:/ti/simplelink_cc2640r2_sdk_4_20_00_04/source/ti/blestack/hal/src/inc" --include_path="C:/ti/simplelink_cc2640r2_sdk_4_20_00_04/source/ti/blestack/heapmgr" --include_path="C:/ti/simplelink_cc2640r2_sdk_4_20_00_04/source/ti/blestack/icall/src/inc" --include_path="C:/ti/simplelink_cc2640r2_sdk_4_20_00_04/source/ti/blestack/osal/src/inc" --include_path="C:/ti/simplelink_cc2640r2_sdk_4_20_00_04/source/ti/blestack/services/src/saddr" --include_path="C:/ti/simplelink_cc2640r2_sdk_4_20_00_04/source/ti/blestack/services/src/sdata" --include_path="C:/ti/simplelink_cc2640r2_sdk_4_20_00_04/source/ti/devices/cc26x0r2" --include_path="C:/ti/ccs1010/ccs/tools/compiler/ti-cgt-arm_16.9.11.LTS/include" --define=DeviceFamily_CC26X0R2 --define=BOARD_DISPLAY_USE_LCD=0 --define=BOARD_DISPLAY_USE_UART=1 --define=BOARD_DISPLAY_USE_UART_ANSI=1 --define=CC2640R2_LAUNCHXL --define=CC26XX --define=CC26XX_R2 --define=FEATURE_ADVERTISER --define=FEATURE_BROADCASTER --define=xFEATURE_STATIC_ADDR --define=ICALL_EVENTS --define=POWER_SAVING --define=RF_SINGLEMODE --define=USE_DEFAULT_USER_CFG --define=xUSE_ICALL --define=xdc_runtime_Assert_DISABLE_ALL --define=xdc_runtime_Log_DISABLE_ALL -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="Application/$(basename $(<F)).d_raw" --obj_directory="Application" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


