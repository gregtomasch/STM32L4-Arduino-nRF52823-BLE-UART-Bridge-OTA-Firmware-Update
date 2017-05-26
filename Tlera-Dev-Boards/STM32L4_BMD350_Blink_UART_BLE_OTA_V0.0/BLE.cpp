#include "Arduino.h"
#include "BLE.h"

BLE::BLE()
{
}

void BLE::initBLE()
{
  // Open the BLE UART port
  WirelessSerial::SerialOpen(STM32L4_BLE_UART, 57600);
  delay(1000);
  #ifdef BMD350_SERIAL_DEBUG
    Serial.println("");
    Serial.print("BLE UART Serial enabled...");
    Serial.println("");
  #endif
  pinMode(ATMD, OUTPUT);
  pinMode(BMD350Reset, OUTPUT);
  delay(100);

  // Put BMD-350 in AT mode 
  digitalWrite(ATMD, LOW);                                                                                              // Set ATMD pin for AT mode
  #ifdef BMD350_SERIAL_DEBUG
    Serial.println("");
    Serial.print("ATMD pin set LOW!");
    Serial.println("");
  #endif
  delay(100);
  digitalWrite(BMD350Reset, LOW);                                                                                       // Reset BMD-350
  #ifdef BMD350_SERIAL_DEBUG
    Serial.println("");
    Serial.print("Reset pin set LOW!");
    Serial.println("");
  #endif
  delay(100);                                                                                                           // Wait a while
  digitalWrite(BMD350Reset, HIGH);                                                                                      // Restart BMD-350
  #ifdef BMD350_SERIAL_DEBUG
    Serial.println("");
    Serial.print("Reset pin set HIGH!");
    Serial.println("");
  #endif
  digitalWrite(myLed3, LOW);
  delay(3000);                                                                                                          // Hold ATMD pin LOW for at least 2.5 seconds

  // Get some basic info about the module using AT commands
  BMD350_UART.write("at\r");
  while(!BMD350_UART.available() ) { delay(100); }
  #ifdef BMD350_SERIAL_DEBUG
    Serial.print("AT working? ");
    while ( BMD350_UART.available() ) { Serial.write(BMD350_UART.read() ); }
    Serial.println(" ");
  #endif
   
  BMD350_UART.write("at$ver?\r");
  while(!BMD350_UART.available() ) { delay(100); }
  #ifdef BMD350_SERIAL_DEBUG
    Serial.print("BMDware version? ");
    while ( BMD350_UART.available() ) { Serial.write(BMD350_UART.read() ); }
    Serial.println(" ");
  #endif
  
  BMD350_UART.write("at$blver?\r");
  while(!BMD350_UART.available() ) { delay(100); }
  #ifdef BMD350_SERIAL_DEBUG
    Serial.print("Bootloader version? ");
    while ( BMD350_UART.available() ) { Serial.write(BMD350_UART.read() ); }
    Serial.println(" ");
  #endif
  
  BMD350_UART.write("at$pver?\r");
  while(!BMD350_UART.available() ) { delay(100); }
  #ifdef BMD350_SERIAL_DEBUG
    Serial.print("Protocol version? ");
    while ( BMD350_UART.available() ) { Serial.write(BMD350_UART.read() ); }
    Serial.println(" ");
  #endif
  
  BMD350_UART.write("at$hwinfo?\r");
  while(!BMD350_UART.available() ) { delay(100); }
  #ifdef BMD350_SERIAL_DEBUG
    Serial.print("Hardware info: ");
    while( BMD350_UART.available() ) { Serial.write(BMD350_UART.read() ); }
    Serial.println(" ");
  #endif

  // Configure UART pass through mode
  //Set Baud rate
  BMD350_UART.write("at$ubr 115200\r");                                                                                 // Decimal values 38400, 57600, etc
  while(!BMD350_UART.available() ) { delay(100); }
  #ifdef BMD350_SERIAL_DEBUG
    Serial.print("Set new Baud rate? ");
    while ( BMD350_UART.available() ) { Serial.write(BMD350_UART.read() ); }
    Serial.println(" ");
  #endif
  delay(100);
  
  /* Query Baud rate*/
  BMD350_UART.write("at$ubr?\r");
  while(!BMD350_UART.available() ) { delay(100); }
  #ifdef BMD350_SERIAL_DEBUG
    Serial.print("New Baud rate? ");
    while ( BMD350_UART.available() ) { Serial.write(BMD350_UART.read() ); }
    Serial.println(" ");
  #endif
  digitalWrite(myLed3, !digitalRead(myLed3));

  /* Configure Flow Control */
  BMD350_UART.write("at$ufc 00\r");                                                                                     // 0x00 to disable, 0x01 to enable
  while(!BMD350_UART.available() ) { delay(100); }
  #ifdef BMD350_SERIAL_DEBUG
    Serial.print("Configured flow control? ");
    while ( BMD350_UART.available() ) { Serial.write(BMD350_UART.read() ); }
    Serial.println(" ");
  #endif
  delay(100);
  
  /* Query Flow control */
  BMD350_UART.write("at$ufc?\r");
  while(!BMD350_UART.available() ) { delay(100); }
  #ifdef BMD350_SERIAL_DEBUG
    Serial.print("Flow control enabled? ");
    while ( BMD350_UART.available() ) { Serial.write(BMD350_UART.read() ); }
    Serial.println(" ");
  #endif

  /* Configure Parity */
  BMD350_UART.write("at$upar 00\r");                                                                                    // 0x00 to disable, 0x01 to enable
  while(!BMD350_UART.available() ) { delay(100); }
  #ifdef BMD350_SERIAL_DEBUG
    Serial.print("Configured parity? ");
    while ( BMD350_UART.available() ) { Serial.write(BMD350_UART.read() ); }
    Serial.println(" ");
  #endif
  digitalWrite(myLed3, !digitalRead(myLed3));
  delay(100);
  
  /* Query Parity */
  BMD350_UART.write("at$upar?\r");
  while(!BMD350_UART.available() ) { delay(100); }
  #ifdef BMD350_SERIAL_DEBUG
    Serial.print("Parity enabled? ");
    while ( BMD350_UART.available() ) { Serial.write(BMD350_UART.read() ); }
    Serial.println(" ");
  #endif

  /* Enable UART pass through mode */
  BMD350_UART.write("at$uen 01\r");                                                                                     // 0x00 to disable, 0x01 to enable
  while(!BMD350_UART.available() ) { delay(100); }
  #ifdef BMD350_SERIAL_DEBUG
    Serial.print("Set UART pass through mode ? ");
    while ( BMD350_UART.available() ) { Serial.write(BMD350_UART.read() ); }
    Serial.println(" ");
  #endif
  delay(100);
   
  /* Query UART pass through mode */
  BMD350_UART.write("at$uen?\r");
  while(!BMD350_UART.available() ) { delay(100); }
  #ifdef BMD350_SERIAL_DEBUG
    Serial.print("UART pass through mode enabled? ");
    while ( BMD350_UART.available() ) { Serial.write(BMD350_UART.read() ); }
    Serial.println(" ");
  #endif

  /* Put BMD-350 in UART pass through mode */
  digitalWrite(ATMD, HIGH);                                                                                             // Set ATMD pin for UART pass through (normal) mode
  #ifdef BMD350_SERIAL_DEBUG
    Serial.println("ATMD pin set HIGH!");
  #endif
  digitalWrite(myLed3, !digitalRead(myLed3));
  delay(100);
  digitalWrite(BMD350Reset, LOW);                                                                                       // Reset BMD-350
  #ifdef BMD350_SERIAL_DEBUG
    Serial.println("Reset pin set LOW!");
  #endif
  digitalWrite(myLed3, !digitalRead(myLed3));
  delay(100);                                                                                                           // Wait a while
  digitalWrite(BMD350Reset, HIGH);                                                                                      // Restart BMD-350
  #ifdef BMD350_SERIAL_DEBUG
    Serial.println("Reset pin set HIGH!");
  #endif
  digitalWrite(myLed3, !digitalRead(myLed3));

  // Close the BLE serial port and re-start at the BLE/UART pass-through baud rate configured above
  WirelessSerial::SerialEnd(STM32L4_BLE_UART);
  digitalWrite(myLed3, LOW);
  delay(100);
  WirelessSerial::SerialOpen(STM32L4_BLE_UART, 115200);
  digitalWrite(myLed3, !digitalRead(myLed3));
  delay(100);
  digitalWrite(myLed3, HIGH);
}
