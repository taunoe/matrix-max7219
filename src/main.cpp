#include <Arduino.h>
#include <TaunoMax7219.h>


// https://www.best-microcontroller-projects.com/max7219.html

#define SS_PIN 15

/* init matrix */
TaunoMax7219 my_matrix(SS_PIN);


void random_patern(int16_t delay_value) {
   uint8_t row=0;
   //int i=0, ud=1; // Need signed numbers.

   for(;;) {
     /*  i += ud;
      if (i>255) {ud=-1;i=255;}
      if (i<0)   {ud=1 ;i=0;}
      if (row++>8) row=1;
     */
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
  my_matrix.brightness(3);

}

void loop() {

   //random_patern(10);
   //my_matrix.test(500);

   my_matrix.clear();
   one_by_one(300);
   

}






