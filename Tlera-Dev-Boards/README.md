# Dragonfly/nRF52dev, Butterfly/BMD-350

This folder contains two Arduino sketches. "STM32L4_BMD350_Blink_UART_BLE_OTA_V0.0.ino" is a simple sketch that demonstrates the infrastructure to support BLE OTA firmware updates. The sketch merely blinks the RGB LED's and sends BLE serial messages regarding the active LED color. The BLE serial messages allow verification that the peripheral/remote MCU is properly sending data and that the central/host MCU is receiving it properly. "STM32L4_nRF52dev_BLE_OTA_Update_Monitor_Utility_V0.0.ino" runs on the Dragonfly host MCU and both passes data from the remote MCU to the USB serial port and manages OTA firmware updates.

The ".hex" files are the compiled executables for the nRF52 development board for it to run in central role. "STM32L4_BLE_Data_Bridge_and_OTA" provides a detailed step-by-step guide for setting up, programming and using both the host and remote MCU's for data monitoring and OTA firmware updates
