################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccs1010/ccs/tools/compiler/ti-cgt-arm_20.2.2.LTS

GEN_OPTS__FLAG := --cmd_file="configPkg/compiler.opt" 
GEN_CMDS__FLAG := -l"configPkg/linker.cmd" 

ORDERED_OBJS += \
"./Application/SensorController/scif.obj" \
"./Application/SensorController/scif_framework.obj" \
"./Application/SensorController/scif_osal_tirtos.obj" \
"./Application/board_key.obj" \
"./Application/micro_eddystone_beacon.obj" \
"./Application/util.obj" \
"./HAL/Common/hal_assert.obj" \
"./ICall/icall.obj" \
"./ICall/icall_cc2650.obj" \
"./Stack/port.obj" \
"./Stack/uble.obj" \
"./Stack/ugap.obj" \
"./Stack/ull.obj" \
"./Stack/urfi.obj" \
"./Startup/board.obj" \
"./Startup/ccfg_app_ble.obj" \
"./Startup/main.obj" \
"./Startup/urfc.obj" \
"../TOOLS/cc26xx_app.cmd" \
$(GEN_CMDS__FLAG) \
-llibc.a \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include Application/SensorController/subdir_vars.mk
-include Application/subdir_vars.mk
-include HAL/Common/subdir_vars.mk
-include ICall/subdir_vars.mk
-include Stack/subdir_vars.mk
-include Startup/subdir_vars.mk
-include TOOLS/subdir_vars.mk
-include Application/SensorController/subdir_rules.mk
-include Application/subdir_rules.mk
-include HAL/Common/subdir_rules.mk
-include ICall/subdir_rules.mk
-include Stack/subdir_rules.mk
-include Startup/subdir_rules.mk
-include TOOLS/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
Beacon_CC2640_with_SensorController_HTU21D.out \

EXE_OUTPUTS__QUOTED += \
"Beacon_CC2640_with_SensorController_HTU21D.out" \

BIN_OUTPUTS += \
Beacon_CC2640_with_SensorController_HTU21D.hex \

BIN_OUTPUTS__QUOTED += \
"Beacon_CC2640_with_SensorController_HTU21D.hex" \


# All Target
all: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "Beacon_CC2640_with_SensorController_HTU21D.out"

# Tool invocations
Beacon_CC2640_with_SensorController_HTU21D.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: ARM Linker'
	"C:/ti/ccs1010/ccs/tools/compiler/ti-cgt-arm_20.2.2.LTS/bin/armcl" -mv7M3 --code_state=16 -g --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi -z -m"Beacon_CC2640_with_SensorController_HTU21D.map" --heap_size=0 --stack_size=256 -i"C:/ti/ccs1010/ccs/tools/compiler/ti-cgt-arm_20.2.2.LTS/lib" -i"C:/ti/ccs1010/ccs/tools/compiler/ti-cgt-arm_20.2.2.LTS/include" --reread_libs --diag_wrap=off --display_error_number --warn_sections --xml_link_info="Beacon_CC2640_with_SensorController_HTU21D_linkInfo.xml" --rom_model -o "Beacon_CC2640_with_SensorController_HTU21D.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

Beacon_CC2640_with_SensorController_HTU21D.hex: $(EXE_OUTPUTS)
	@echo 'Building files: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo 'Invoking: ARM Hex Utility'
	"C:/ti/ccs1010/ccs/tools/compiler/ti-cgt-arm_20.2.2.LTS/bin/armhex" --memwidth=8 --romwidth=8 --intel -o "Beacon_CC2640_with_SensorController_HTU21D.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(BIN_OUTPUTS__QUOTED)$(GEN_FILES__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "Application\SensorController\scif.obj" "Application\SensorController\scif_framework.obj" "Application\SensorController\scif_osal_tirtos.obj" "Application\board_key.obj" "Application\micro_eddystone_beacon.obj" "Application\util.obj" "HAL\Common\hal_assert.obj" "ICall\icall.obj" "ICall\icall_cc2650.obj" "Stack\port.obj" "Stack\uble.obj" "Stack\ugap.obj" "Stack\ull.obj" "Stack\urfi.obj" "Startup\board.obj" "Startup\ccfg_app_ble.obj" "Startup\main.obj" "Startup\urfc.obj" 
	-$(RM) "Application\SensorController\scif.d" "Application\SensorController\scif_framework.d" "Application\SensorController\scif_osal_tirtos.d" "Application\board_key.d" "Application\micro_eddystone_beacon.d" "Application\util.d" "HAL\Common\hal_assert.d" "ICall\icall.d" "ICall\icall_cc2650.d" "Stack\port.d" "Stack\uble.d" "Stack\ugap.d" "Stack\ull.d" "Stack\urfi.d" "Startup\board.d" "Startup\ccfg_app_ble.d" "Startup\main.d" "Startup\urfc.d" 
	-$(RMDIR) $(GEN_MISC_DIRS__QUOTED)
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

