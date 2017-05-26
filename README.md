# STM32L4-Arduino-nRF52823-BLE-UART-Bridge-OTA-FW-Update
This repository contains information and software for adding a BLE/UART communication bridge to Tlera Corporation (a.k.a. Pesky Products) Arduino-programmable STM32L4 MCU development boards. The STM32L4 is feature and I/O rich, delivering excellent performance at low power consumption. This family of boards is well-supported by Thomas Roell's STM32L4 Arduino core. However, the STM32L4 does not have any embedded wireless connectivity.

The STM32L4 family can be augmented for Bluetooth Low Energy (BLE) connectivity by bundling with Nordic Semiconductor's nRF52-based modules such as the Rigado BMD-350. nRF52-based devices support the Nordic UART Service (NUS) that can be used to make BLE/UART communication bridge devices. Typically, a module such as the BMD-350 is hard-configured in peripheral role and is paired with an NUS central role device such as a smart phone running the Nordic tool kit application or a custom Android/iOS application.

However, it is often convenient to have an NUS-capable Central role BLE device that can communicate directly with another microcontroller or a PC by UART connection. In addition to serving as another way of viewing, storing and manipulating data transmitted from a remote MCU device, it is also possible to use such a BLE/UART communication bridge to update the firmware running on a remote MCU without developing custom applications for tablets or smart phones.

Using the Pesky Products nRF52 development board it is possible to make the NUS-capable BLE Central role device necessary for a full bi-directional BLE/UART bridge. The initial commits to ths repository are to suport the combination of the Rigado BMD-350 as the peripheral and the nRF52 development board as the central. The example software and documentation here show the user how to:

1) Pair any of the STM32L4 development boards as a remote target with the Rigado BMD-350 peripheral role device
2) Pair "Dragonfly" STM32L4 development board with the nRF52 development board central role device
3) Use the nRF52/Dragonfly combination to both monitor data broadcast by the BMD-350 and update the firmware on the remote STM32L4 remotely over-the-air

The Dragonfly development board was paired with the central role device for the initial example because it has a built-in 128Mbit QSPI flash chip and Windows-compatible virtual drive file system. The is convenient for storing the new firmware image and allows for easy data parsing and transfer by the MCU. Any of the other STM32L4 development boards can be used as well but require additional DOSFS-compatible flash memory.

Custom nRF52-based shield boards for the STM42L4 family of MCU development boards are currently under development. Once thoroughly tested, additional versions of BLE/UART software will be posted.
