# Beacon_CC2640_with_SensorController_HTU21D
Sensor beacon with the HTU21D temperature and humidity sensor. 
Based on the Ti CC2640R2F SoC.
# The project used:
*	[Micro Eddystone Beacon](http://software-dl.ti.com/lprf/simplelink_cc2640r2_sdk/1.30.00.25/exports/examples/rtos/CC2640R2_LAUNCHXL/blestack/micro_eddystone_beacon/README.html)
*	[HTU21D-sensor-controller](https://github.com/osnatos/HTU21D-sensor-controller)
# Software Tools:
* Sensor Controller Studio v2.7.0.155
* Code Composer Studio v10.1.0
* XDCtools v3.51.03.28_core
* simplelink_cc2640r2_sdk_4_20_00_04

# Temperature and humidity advertising:
* [Eddystone TLM frame](https://github.com/google/eddystone/blob/master/eddystone-tlm/tlm-plain.md) is used for temperature advertising. 
This makes it possible to use applications such as [Beacon Scaner](https://play.google.com/store/apps/details?id=com.bridou_n.beaconscanner) or similar for viewing.
* Fot humidity advertising, TLM format expanded, additional two bytes are added(bytes offset 14,15). 
  Humidity, measured by the beacon, is expressed in a unsigned [8.8 fixed-point notation](https://inst.eecs.berkeley.edu/~cs61c/sp06/handout/fixedpt.html). 
  Range of the humidity  0-100%. 
  To view humidity, you need an application that can work with the extended TLM format.
