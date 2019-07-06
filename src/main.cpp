#include <Arduino.h>
#include <TaunoMax7219.h>


// https://www.best-microcontroller-projects.com/max7219.html

#define SS_PIN 15

/* init matrix */
TaunoMax7219 my_matrix(SS_PIN);

byte matrix[8] = {
   0b10000001, // 1
   0b01000010, // 2
   0b00100100, // 3
   0b00011000, // 4
   0b00011000, // 5
   0b00100100, // 6
   0b01000010, // 7
   0b10000001  // 8
};


void random_patern(int16_t delay_value) {
   uint8_t row = 0;
   int i = 0, ud = 1; // Need signed numbers.

   while(1) {
       i += ud;
      if (i > 255) { ud = -1; i = 255;}
      if (i < 0)   { ud = 1 ; i = 0;}
      if (row++ > 8) { row = 1;}
     
      my_matrix.write_register(row, random(0,255));
     // my_matrix.brightness(i>>4);
     delay(delay_value);
   }
}

void one_by_one(int16_t delay_value) {
   int tulp = 1;

   for (uint8_t j = 1; j < 9; j++) {
      for (uint8_t i = 0; i <= 8; i++) {
         if (i == 8) {
            my_matrix.write_register(j, 0);
         } else {
            my_matrix.write_register(j, tulp);
            tulp = tulp << 1;
            delay(delay_value);
         }
      }
      tulp = 1;
   }
}


void setup() {

  Serial.begin(115200);
  Serial.println("Debug MAX7219");

  my_matrix.begin();
  my_matrix.brightness(5);

}

void loop() {
   // my_matrix.test(500);
   my_matrix.clear();
   // random_patern(10);
   // one_by_one(300);

   
   for (size_t i = 1; i < 9; i++)
   {
      my_matrix.write_register(i, matrix[i-1]);
      delay(200);
   }
   
   matrix[0] ^= 0b01010100; // biti vastupidiseks muutmine
   matrix[1] |= 0b10101010; // biti kõrgeks seadmine
}






