#include <Arduino.h>
#include <TaunoMax7219.h>


// https://www.best-microcontroller-projects.com/max7219.html

#define SS_PIN 15

/* init matrix */
TaunoMax7219 my_matrix(SS_PIN);

void random_patern(int16_t delay_value){
   uint8_t row=0;
   //int i=0, ud=1; // Need signed numbers.

   for(;;) {
     /*  i += ud;
      if (i>255) {ud=-1;i=255;}
      if (i<0)   {ud=1 ;i=0;}
      if (row++>8) row=1;
     */
      my_matrix.transfer_DATA(row, random(0,255));
     // my_matrix.brightness(i>>4);
     delay(delay_value);
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
   int rida = 1;
   int tulp = 1;

   //my_matrix.test(500);
   my_matrix.clear();

 
     for (uint8_t i = 0; i < 9; i++)
      {
         my_matrix.transfer_DATA(rida, tulp);
         tulp = tulp << 1;
         delay(500);
      }

      tulp = 1;

      for (uint8_t i = 0; i < 9; i++)
      {
         my_matrix.transfer_DATA(2, tulp);
         tulp = tulp << 1;
         delay(500);
      }


}






