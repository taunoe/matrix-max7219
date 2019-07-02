#ifndef TaunoMax7219_h
#define TaunoMax7219_h

#include "Arduino.h"

// MAX7219 Register Address Map
#define MAX7219_NOOP_REG        0x00
#define MAX7219_DECODE_MODE_REG 0x09 
#define MAX7219_BRIGHTNESS_REG  0x0a 
#define MAX7219_SCAN_LIMIT_REG  0x0b 
#define MAX7219_SHUTDOWN_REG    0x0c
#define MAX7219_TEST_REG        0x0f

class TaunoMax7219
{
    private:
    int _ss_pin;

    public:
    // constructor
    TaunoMax7219(const byte ss_pin);

    // deconstructor
    ~TaunoMax7219();

    // methods
    void begin();
    void test(uint16_t delay_value);
    void brightness(uint8_t value); // 0-15 0x0 - 0xF
    void transfer_CMD(uint8_t address, uint8_t value);
    void transfer_DATA(uint8_t address, uint8_t value);
    void clear(); // all off
};

#endif