/*****************************************************/
/************* BMD-350 Pin Assignments ***************/
/*****************************************************/
#define ATMD                          26                                                                                                 // Toggle pin for BMD-350 AT mode or UART pass through mode
#define BMD350Reset                   38                                                                                                 // BMD-350 reset pin active; LOW
#define BMD350_SERIAL_DEBUG                                                                                                              // Comment out to suppress BMD-350 start-up diagnostic messages over the STM32L4 USB serialmonitor

/*****************************************************/
/************* RGB LED Pin Assignments ***************/
/*****************************************************/
#define myLed1                        A3                                                                                                 // Green LED
#define myLed2                        A5                                                                                                 // Red LED
#define myLed3                        A0                                                                                                 // Blue LED

/*****************************************************/
/*************** Serial Configuration ****************/
/*****************************************************/
#define UART_NUMBER                   4                                                                                                  // Total number of possible serial ports on the STM32L4 (including USB); differs by variant
#define OTA_DATA_BLOCK_SIZE           32                                                                                                 // OTA data message payload size; 32 is optimal for UART without HW flow control

/******** BLE UART port (Uncomment one only) *********/
#define BLE_UART_1
//#define BLE_UART_2
//#define BLE_UART_3

/************** UART Port Definitions ****************/
#ifdef BLE_UART_1
  #define STM32L4_BLE_UART              1
  #define BMD350_UART                   Serial1
#endif
#ifdef BLE_UART_2
  #define STM32L4_BLE_UART              2
  #define BMD350_UART                   Serial2
#endif
#ifdef BLE_UART_3
  #define STM32L4_BLE_UART              3
  #define BMD350_UART                   Serial3
#endif
