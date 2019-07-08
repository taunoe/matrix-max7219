/************************************************************
 * Project:     Matrix MAX7219
 * File:        main.cpp
 * Author:      Tauno Erik
 * Created:     08.07.2019
 * Description:
 *
 **************************************************************/

/*
 * https://tttapa.github.io/ESP8266/Chap10%20-%20Simple%20Web%20Server.html
 * https://circuits4you.com/2016/12/16/esp8266-web-server-html/
 * https://www.best-microcontroller-projects.com/max7219.html
 * https://circuits4you.com/2018/02/04/esp8266-ajax-update-part-of-web-page-without-refreshing/
 * 
 */
#include <Arduino.h>
#include <TaunoMax7219.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WebServer.h>
#include "root.h"           // html index


/********************************
 ** Wifi 
 ********************************/
ESP8266WiFiMulti wifiMulti;
ESP8266WebServer server(80);

void handleRoot();
void handleNotFound();


/********************************
 **  Matrix 
 ********************************/
#define SS_PIN 15

TaunoMax7219 my_matrix(SS_PIN);

byte matrix[9] = {
   B00000000, // 1
   B00000000, // 2
   B00000000, // 3
   B00000000, // 4
   B00000000, // 5
   B00000000, // 6
   B00000000, // 7
   B00000000, // 8
   B00000000
};

void random_patern(int16_t delay_value);
void one_by_one(int16_t delay_value);


void setup() {
  Serial.begin(115200);
  Serial.println('\n');
  Serial.println("MAX7219 Matrix");

  /* Wifi */
  #include "wifilogin.h"
  //wifiMulti.addAP("Ingel", "4B9GNT454M4");
  //wifiMulti.addAP("Tsenter1", "kompetentsikeskus");
  //wifiMulti.addAP("Tsenter2", "kompetentsikeskus");

  Serial.println("Connecting .");

  while (wifiMulti.run() != WL_CONNECTED) {
    delay(250);
    Serial.print('.');
  }

  Serial.println('\n');
  Serial.print("Connected to ");
  Serial.println(WiFi.SSID());
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());

  server.on("/", HTTP_GET, handleRoot);
  server.onNotFound(handleNotFound);
  
  server.begin();
  Serial.println("HTTP server started");


  /* Matrix */
  my_matrix.begin();
  my_matrix.brightness(5);
  my_matrix.clear();
}

void loop() {
   server.handleClient();
   // my_matrix.test(500);
   // my_matrix.clear();
   // random_patern(10);
   // one_by_one(300);
   
   /* 
   for (size_t i = 1; i < 9; i++)
   {
      my_matrix.write_register(i, matrix[i-1]);
      delay(200);
   }
   
   matrix[0] ^= 0b01010100; // biti vastupidiseks muutmine
   matrix[1] |= 0b10101010; // biti kõrgeks seadmine
   */
}


/* Wifi functions */

void handleRoot() {
  String ingoming = server.arg(0);
  Serial.print("String=");
  Serial.println(ingoming);
  Serial.println(ingoming.toInt());             // 63
  int rida = (ingoming.toInt() / 10) % 10; // rida 6 
  int tulp = ingoming.toInt() % 10;        // tulp 3
  Serial.println(rida);
  Serial.println(tulp);
  Serial.print("matrix[rida] enne ");
  for(int i = 0; i < 9; i++)
  {
    Serial.println(matrix[i], BIN);
  } 
  matrix[rida] ^= 1<<(tulp-1);
  Serial.print("matrix[rida] parast ");
  for(int i = 0; i < 9; i++)
  {
    Serial.println(matrix[i], BIN);
  }
  my_matrix.write_register(rida, matrix[rida]);

  Serial.println('\n');

  String webpage = web_index;
  server.send(200, "text/html", webpage);
}

void handleNotFound(){
  server.send(404, "text/plain", "404: Not found");
}

/* Matrix */

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
