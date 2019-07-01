#include "Arduino.h"
#include <SPI.h>
#include "TaunoMax7219.h"

TaunoMax7219::TaunoMax7219(const byte ss_pin)
{
    pinMode(ss_pin, OUTPUT);
    
    _ss_pin = ss_pin;
}

// deconstructor
TaunoMax7219::~TaunoMax7219()
{
    
}

void TaunoMax7219::begin() {
    SPI.setBitOrder(MSBFIRST);   // Reverse the SPI Data o/p. 
    SPI.begin();                 // Start SPI

    // Run test - All LED segments lit. 
    transfer_CMD(MAX7219_TEST, 0x01);  
    delay(500);  
    transfer_CMD(MAX7219_TEST, 0x00);        // Finish test mode.
    transfer_CMD(MAX7219_DECODE_MODE, 0x00); // Disable BCD mode. 
    transfer_CMD(MAX7219_BRIGHTNESS, 0x00);  // Use lowest intensity. 
    transfer_CMD(MAX7219_SCAN_LIMIT, 0x0f);  // Scan all digits.
    transfer_CMD(MAX7219_SHUTDOWN, 0x01);    // Turn on chip.
}

void TaunoMax7219::transfer_CMD(uint8_t address, uint8_t value) {  
  digitalWrite(_ss_pin, LOW);   
  SPI.transfer(address);      // Send address
  SPI.transfer(value);        // Send the value
  digitalWrite(_ss_pin, HIGH); // Finish transfer
}

void TaunoMax7219::transfer_DATA(uint8_t address, uint8_t value) {  
  digitalWrite(_ss_pin, LOW);   

  SPI.transfer(address);      // Send address
  SPI.transfer(value);        // Send the value

  digitalWrite(_ss_pin, HIGH); // Finish transfer.
}