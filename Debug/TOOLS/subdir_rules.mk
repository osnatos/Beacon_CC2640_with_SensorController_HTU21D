################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
build-486195569:
	@$(MAKE) --no-print-directory -Onone -f TOOLS/subdir_rules.mk build-486195569-inproc

build-486195569-inproc: ../TOOLS/app_ble.cfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: XDCtools'
	"C:/ti/xdctools_3_51_03_28_core/xs" --xdcpath="C:/ti/simplelink_cc2640r2_sdk_4_20_00_04/source;C:/ti/simplelink_cc2640r2_sdk_4_20_00_04/kernel/tirtos/packages;" xdc.tools.configuro -o configPkg -t ti.targets.arm.elf.M3_big_endian -p ti.platforms.simplelink:CC2640R2F -r debug -b "D:/Projects/Beacon_HTU21D/FlashOnly/configPkg/config.bld" -c "C:/ti/ccs1010/ccs/tools/compiler/ti-cgt-arm_20.2.2.LTS" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

configPkg/linker.cmd: D:/Projects/Beacon_HTU21D/FlashOnly/configPkg/config.bld
configPkg/linker.cmd: build-486195569 ../TOOLS/app_ble.cfg D:/Projects/Beacon_HTU21D/FlashOnly/configPkg/config.bld
configPkg/compiler.opt: build-486195569 D:/Projects/Beacon_HTU21D/FlashOnly/configPkg/config.bld
configPkg/: build-486195569 D:/Projects/Beacon_HTU21D/FlashOnly/configPkg/config.bld


