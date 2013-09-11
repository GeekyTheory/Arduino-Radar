/*
     Arduino Radar
        
Author: Geeky Theory

Blog: http://www.geekytheory.com

https://www.youtube.com/user/telecoreference
https://twitter.com/geekytheory
https://www.facebook.com/geekytheory
*/


//Variables LCD
#include 
LiquidCrystal lcd(9, 8, 5, 4, 3, 2);

//Variables ULTRASONIDOS
#include "Ultrasonic.h"
Ultrasonic ultrasonic(6,7);
int dist;

//Variables STEPPER
int DelayTime=50;
int MP[] = {10, 11, 12, 13};
int n=0;
int NP;
int i;

//DIBUJOS DEL LCD+++++++++++++++++++++++++++++++++++++++++++++++++
byte CERO[8] = {
B00000,
B00000,
B00000,
B00000,
B00000,
B00000,
B00000,
B00000
};

byte UNO[8] = {
B00000,
B00000,
B00000,
B00000,
B00000,
B00000,
B00000,
B11111
};

byte DOS[8] = {
B00000,
B00000,
B00000,
B00000,
B00000,
B00000,
B11111,
B11111
};

byte TRES[8] = {
B00000,
B00000,
B00000,
B00000,
B00000,
B11111,
B11111,
B11111
};

byte CUATRO[8] = {
B00000,
B00000,
B00000,
B00000,
B11111,
B11111,
B11111,
B11111
};

byte CINCO[8] = {
B00000,
B00000,
B00000,
B11111,
B11111,
B11111,
B11111,
B11111
};

byte SEIS[8] = {
B00000,
B00000,
B11111,
B11111,
B11111,
B11111,
B11111,
B11111
};

byte SIETE[8] = {
B00000,
B11111,
B11111,
B11111,
B11111,
B11111,
B11111,
B11111
};

byte OCHO[8] = {
B11111,
B11111,
B11111,
B11111,
B11111,
B11111,
B11111,
B11111
};
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++

void setup() {
  lcd.createChar(0,CERO);
  lcd.createChar(1,UNO);
  lcd.createChar(2,DOS);
  lcd.createChar(3,TRES);
  lcd.createChar(4,CUATRO);
  lcd.createChar(5,CINCO);
  lcd.createChar(6,SEIS);
  lcd.createChar(7,SIETE);
  lcd.createChar(8,OCHO);
  lcd.begin(16, 2);

  //pines del stepper  
  pinMode(10, OUTPUT);    
  pinMode(11, OUTPUT);     
  pinMode(12, OUTPUT);    
  pinMode(13, OUTPUT);
}

void loop() {

  //GIRA HACIA UN LADO
  for(i=0;i<16;i++){
    while (n<4){
      NP=MP[n];
      digitalWrite(NP,HIGH);
      delay(DelayTime);
      digitalWrite(NP,LOW);
      delay(DelayTime);
      n+=1;

  //lectura ultrasonido
  dist=ultrasonic.Ranging(CM);

  //imprime byte
  if (dist<10) lcd.print(" ");
  if ((10<dist)&&(dist<25)) lcd.write(1);
  if ((25<dist)&&(dist<50)) lcd.write(2);
  if ((50<dist)&&(dist<100)) lcd.write(3);
  if ((100<dist)&&(dist<150))  lcd.write(4);
  if ((150<dist)&&(dist<250)) lcd.write(5);
  if((250<dist)&&(dist<350)) lcd.write(6);
  if((350<dist)&&(dist<400)) lcd.write(7);
  if (dist>400) lcd.write(8);

  //el cursor se desplaza a la derecha
  lcd.setCursor(i,0);
      }
     n=0;
  }

    //GIRA HACIA EL OTRO LADO
    for(i=0;i<16;i++){
      while (n>-1){
      NP=MP[n];
      digitalWrite(NP,HIGH);
      delay(DelayTime);
      digitalWrite(NP,LOW);
      delay(DelayTime);
      n-=1;

  //lectura ultrasonido
  dist=ultrasonic.Ranging(CM);

  //imprime byte
  if (dist<10) lcd.print(" ");
  if ((10<dist)&&(dist<25)) lcd.write(1);
  if ((25<dist)&&(dist<50)) lcd.write(2);
  if ((50<dist)&&(dist<100)) lcd.write(3);
  if ((100<dist)&&(dist<150))  lcd.write(4);
  if ((150<dist)&&(dist<250)) lcd.write(5);
  if((250<dist)&&(dist<350)) lcd.write(6);
  if((350<dist)&&(dist<400)) lcd.write(7);
  if (dist>400) lcd.write(8);

  //el cursor se desplaza a la derecha
  lcd.setCursor(i,0);
      }
    n=3;
  }
}
