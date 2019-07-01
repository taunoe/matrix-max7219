#ifndef TaunoMax7219_h
#define TaunoMax7219_h

#include "Arduino.h"

// MAX7219 Register Address Map
#define MAX7219_DECODE_MODE 0x09 
#define MAX7219_BRIGHTNESS  0x0a 
#define MAX7219_SCAN_LIMIT  0x0b 
#define MAX7219_SHUTDOWN    0x0c
#define MAX7219_TEST        0x0f

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
    void transfer_CMD(uint8_t address, uint8_t value);
    void transfer_DATA(uint8_t address, uint8_t value);
};

#endif