/**
 * @author Tauno Erik
 */
#include "Arduino.h"
#include <SPI.h>
#include "TaunoMax7219.h"

/**
 * @param ss_pin
 */
TaunoMax7219::TaunoMax7219(const uint8_t ss_pin) {
    pinMode(ss_pin, OUTPUT);
    
    _ss_pin = ss_pin;
}

TaunoMax7219::~TaunoMax7219() {
    write_register(MAX7219_SHUTDOWN_REG, 0); // Turn off chip.
    SPI.end ();
}

/**
 * 
 */
void TaunoMax7219::begin() {
    SPI.setBitOrder(MSBFIRST);   // Reverse the SPI Data o/p. 
    SPI.begin();                 // Start SPI

    // Run test - All LED segments lit. 
    //write_register(MAX7219_TEST_REG, 0x01);        // Display test mode ON
    //delay(500);  
    write_register(MAX7219_TEST_REG, 0x00);        // Display test mode OFF
    write_register(MAX7219_DECODE_MODE_REG, 0x00); // Disable BCD mode. 
    write_register(MAX7219_BRIGHTNESS_REG, 0x00);  // Use lowest intensity. 
    write_register(MAX7219_SCAN_LIMIT_REG, 0x07);  // All rows are active 0x00 -> 0x07
    write_register(MAX7219_SHUTDOWN_REG, 0x01);    // Turn on chip.
}

/**
 * @param delay_value duration of test
 */
void TaunoMax7219::test(const uint16_t delay_value) {
    write_register(MAX7219_TEST_REG, 0x01);     // Display test mode ON
    delay(delay_value);  
    write_register(MAX7219_TEST_REG, 0x00); // Display test mode OFF
}

/**
 * @param value brightness value
 */
void TaunoMax7219::brightness(const uint8_t value) {
    write_register(MAX7219_BRIGHTNESS_REG, value);  // 0-15, 0x00 - 0x0f
}

/**
 * @address register address
 * @value 
 */
void TaunoMax7219::write_register(const uint8_t address, const uint8_t value) {  
  digitalWrite(_ss_pin, LOW);   
  SPI.transfer(address);        // Send address
  SPI.transfer(value);          // Send the value
  digitalWrite(_ss_pin, HIGH);  // Finish transfer
}


/**
 *  Turn all LEDs off
 */
void TaunoMax7219::clear() {
  for (uint8_t i = 0; i < 9; i++) {
    write_register(i, 0);
  }
  
}