@echo off
echo ota.bat
set /p ComPort=Place device into ISP then enter COM port number:
echo Erasing the device FLASH memory
C:\nxp\DK6ProductionFlashProgrammer\DK6Programmer -V5 -P 1000000 -s COM%ComPort% -e Flash
echo Provisioning of the image directory
C:\nxp\DK6ProductionFlashProgrammer\DK6Programmer -V5 -s COM%ComPort% -P 1000000 -w PSECT:64@0x160=00800000900401010000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
echo Flashing the SSBL First you need to get the path of the SSBL binary file. For that you can check Building the SSBL. 
C:\nxp\DK6ProductionFlashProgrammer\DK6Programmer -V5 -s COM%ComPort% -P 1000000 -p FLASH@0x00=./ssbl.bin -Y -P 1000000
echo Flashing the application blob (version 1.0) 
C:\nxp\DK6ProductionFlashProgrammer\DK6Programmer -V5 -s COM%ComPort% -P 1000000 -p FLASH@0x8000=./k32w061dk6_otap_client_att_freertos.bin -Y -P 1000000
pause