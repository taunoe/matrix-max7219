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
    transfer_CMD(MAX7219_SHUTDOWN_REG, 0); // Turn off chip.
    SPI.end ();
}


void TaunoMax7219::begin() {
    SPI.setBitOrder(MSBFIRST);   // Reverse the SPI Data o/p. 
    SPI.begin();                 // Start SPI

    // Run test - All LED segments lit. 
    //transfer_CMD(MAX7219_TEST_REG, 0x01);        // Display test mode ON
    //delay(500);  
    transfer_CMD(MAX7219_TEST_REG, 0x00);        // Display test mode OFF
    transfer_CMD(MAX7219_DECODE_MODE_REG, 0x00); // Disable BCD mode. 
    transfer_CMD(MAX7219_BRIGHTNESS_REG, 0x00);  // Use lowest intensity. 
    transfer_CMD(MAX7219_SCAN_LIMIT_REG, 0x07);  // All rows are active 0x00 -> 0x07
    transfer_CMD(MAX7219_SHUTDOWN_REG, 0x01);    // Turn on chip.
}

void TaunoMax7219::test(uint16_t delay_value){
    transfer_CMD(MAX7219_TEST_REG, 0x01);     // Display test mode ON
    delay(delay_value);  
    transfer_CMD(MAX7219_TEST_REG, 0x00); // Display test mode OFF
}

void TaunoMax7219::brightness(uint8_t value){
    transfer_CMD(MAX7219_BRIGHTNESS_REG, value);  // 0-15, 0x00 - 0x0f
}


void TaunoMax7219::transfer_CMD(uint8_t address, uint8_t value) {  
  digitalWrite(_ss_pin, LOW);   
  SPI.transfer(address);        // Send address
  SPI.transfer(value);          // Send the value
  digitalWrite(_ss_pin, HIGH);  // Finish transfer
}


void TaunoMax7219::transfer_DATA(uint8_t address, uint8_t value) {  
  digitalWrite(_ss_pin, LOW);   
  SPI.transfer(address);        // Send address
  SPI.transfer(value);          // Send the value
  digitalWrite(_ss_pin, HIGH);  // Finish transfer.
}

// all off
void TaunoMax7219::clear(){
  for (uint8_t i = 0; i < 9; i++)
  {
    transfer_DATA(i, 0);
  }
  
}