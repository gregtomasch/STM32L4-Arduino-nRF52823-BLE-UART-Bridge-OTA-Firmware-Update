/*
 5/25/17 V0.0
 This example sketch the basic infrastructure to use the BMD-350 for data monitoring and STM32L4 OTA FW updates paired with a Nordic UART Service (NUS) Central Role device:
 https://www.tindie.com/products/TleraCorp/dragonfly-stm32l476-development-board/?pt=ac_prod_search - Dragonfly STM32L4 development board
 https://www.tindie.com/products/TleraCorp/butterfly-stm32l433-development-board/?pt=ac_prod_search - Butterfly STM32L4 development board
 https://github.com/GrumpyOldPizza/arduino-STM32L4 - STM32L4 Arduino core
 https://www.rigado.com/products/modules/bmd-350/ - Rigado BMD-350 NUS BLE peripheral device
 
 1) "WirelessSerial::serialCom()" is called each iteration of the loop to check for incoming OTA FW update requests
 2) The BMD-350 BLE unit is connected to the STM32L4 UART1 port. Data updates to the paired BLE Central device are done using "BMD350_UART.print()" or "BMD350_UART.write()"
 3) When notification of an OTA FW update request arrives, "OTA::OTA_Update()" is called and control is diverted to the OTA FW update handler
 4) The OTA FW update messages contain 32-byte payloads; this is the largest practicable size for BLE NUS UART without HW flow control
 5) Each data block message has to be ACK'd and the ACK message has to be received by the OTA FW update utility before the next data block message is sent
 8) The target STM32L4 board will NAK the transaction if the FW image exceeds available flash space or if a data black is skipped; all NAK conditions result
    in resumption of normal steady-state operaton of the STM32L4 board using the original FW image
 9) BMD-350 pin assignments/parameters, RGB LED pin assignments and UART bridge parameters are defined in "Config.h"
*/
