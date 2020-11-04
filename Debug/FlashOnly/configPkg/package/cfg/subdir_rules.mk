################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
FlashOnly/configPkg/package/cfg/%.obj: ../FlashOnly/configPkg/package/cfg/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccs1010/ccs/tools/compiler/ti-cgt-arm_20.2.2.LTS/bin/armcl" -mv7M3 --code_state=16 --include_path="D:/Projects/Beacon_HTU21D" --include_path="C:/ti/ccs1010/ccs/tools/compiler/ti-cgt-arm_20.2.2.LTS/include" -g --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="FlashOnly/configPkg/package/cfg/$(basename $(<F)).d_raw" --obj_directory="FlashOnly/configPkg/package/cfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

build-1886353473:
	@$(MAKE) --no-print-directory -Onone -f FlashOnly/configPkg/package/cfg/subdir_rules.mk build-1886353473-inproc

build-1886353473-inproc: ../FlashOnly/configPkg/package/cfg/app_ble_pem3.cfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: XDCtools'
	"C:/ti/xdctools_3_51_03_28_core/xs" --xdcpath="C:/ti/simplelink_cc2640r2_sdk_4_20_00_04/source;C:/ti/simplelink_cc2640r2_sdk_4_20_00_04/kernel/tirtos/packages;" xdc.tools.configuro -o configPkg -t ti.targets.arm.elf.M3_big_endian -p ti.platforms.simplelink:CC2640R2F -r debug -b "D:/Projects/Beacon_HTU21D/FlashOnly/configPkg/config.bld" -c "C:/ti/ccs1010/ccs/tools/compiler/ti-cgt-arm_20.2.2.LTS" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

configPkg/linker.cmd: build-1886353473 ../FlashOnly/configPkg/package/cfg/app_ble_pem3.cfg D:/Projects/Beacon_HTU21D/FlashOnly/configPkg/config.bld
configPkg/compiler.opt: build-1886353473 D:/Projects/Beacon_HTU21D/FlashOnly/configPkg/config.bld
configPkg/: build-1886353473 D:/Projects/Beacon_HTU21D/FlashOnly/configPkg/config.bld


