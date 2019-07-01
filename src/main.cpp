#include <Arduino.h>
#include <TaunoMax7219.h>


// https://www.best-microcontroller-projects.com/max7219.html

//#include <SPI.h>
#define SS_PIN 15

TaunoMax7219 my_matrix(SS_PIN);



void setup() {

  Serial.begin(115200);
  Serial.println("Debug MAX7219");

  my_matrix.begin();

}

void loop() {

   
uint8_t row=0;
int i=0, ud=1; // Need signed numbers.

   for(;;) {      

      i += ud; 

      if (i>255) {ud=-1;i=255;}

      if (i<0)   {ud=1 ;i=0;}

      if (row++>8) row=1;  
     
      my_matrix.transfer_DATA(row, random(0,255));             
      my_matrix.transfer_CMD(MAX7219_BRIGHTNESS,i>>4);

      delay(10); 

      Serial.print(" i ");
      Serial.print(i);
      Serial.print(" ud ");
      Serial.println(ud);
   }


/* 
maxTransferDATA(0x01, 1);
delay(500);
maxTransferDATA(0x02, 1);
delay(500);
maxTransferDATA(0x03, 1);
delay(500);
maxTransferDATA(0x04, 1);
delay(500);
maxTransferDATA(0x05, 1);
delay(500);
maxTransferDATA(0x06, 1);
delay(500);
maxTransferDATA(0x07, 1);
delay(500);
maxTransferDATA(0x08, 1);
delay(500);

maxTransferDATA(0x01, 0);
delay(500);
maxTransferDATA(0x02, 0);
delay(500);
maxTransferDATA(0x03, 0);
delay(500);
maxTransferDATA(0x04, 0);
delay(500);
maxTransferDATA(0x05, 0);
delay(500);
maxTransferDATA(0x06, 0);
delay(500);
maxTransferDATA(0x07, 0);
delay(500);
maxTransferDATA(0x08, 0);
delay(500);

maxTransferDATA(0x01, 0b00000001);
delay(500);
maxTransferDATA(0x02, 0b00000010);
delay(500);
maxTransferDATA(0x03, 0b00000100);
delay(500);
maxTransferDATA(0x04, 0b00001000);
delay(500);
maxTransferDATA(0x05, 0b00010000);
delay(500);
maxTransferDATA(0x06, 0b00100000);
delay(500);
maxTransferDATA(0x07, 0b01000000);
delay(500);
maxTransferDATA(0x08, 0b10000000);
delay(500);

maxTransferDATA(0x01, 0b00000001);
delay(500);
maxTransferDATA(0x01, 0b00000010);
delay(500);
maxTransferDATA(0x01, 0b00000100);
delay(500);
maxTransferDATA(0x01, 0b00001000);
delay(500);
maxTransferDATA(0x01, 0b00010000);
delay(500);
maxTransferDATA(0x01, 0b00100000);
delay(500);
maxTransferDATA(0x01, 0b01000000);
delay(500);
maxTransferDATA(0x01, 0b10000000);
delay(500);

maxTransferDATA(0x01, 0b00000001);
delay(500);
maxTransferDATA(0x01, 0b00000011);
delay(500);
maxTransferDATA(0x01, 0b00000110);
delay(500);
maxTransferDATA(0x01, 0b00001100);
delay(500);
maxTransferDATA(0x01, 0b00011000);
delay(500);
maxTransferDATA(0x01, 0b00110000);
delay(500);
maxTransferDATA(0x01, 0b01100000);
delay(500);
maxTransferDATA(0x01, 0b11000000);
delay(500);

*/

}






