# invoke SourceDir generated makefile for app_ble.pem3
app_ble.pem3: .libraries,app_ble.pem3
.libraries,app_ble.pem3: package/cfg/app_ble_pem3.xdl
	$(MAKE) -f D:\Projects\Beacon_HTU21D\Beacon_CC2640_with_SensorController_HTU21D_Clone\TOOLS/src/makefile.libs

clean::
	$(MAKE) -f D:\Projects\Beacon_HTU21D\Beacon_CC2640_with_SensorController_HTU21D_Clone\TOOLS/src/makefile.libs clean

