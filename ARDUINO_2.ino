#include "LiquidCrystal.h"

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int trigPin = 9;
const int echoPin = 10;
long duration;
float distanceCm;
float volumeCm, volumeOcupado;
const float alturaTotal = 12;
const float raioCirc = 4;
const float areaCirc = 3.14 * (raioCirc * raioCirc);
const float volumeTotal = alturaTotal * areaCirc;
const float densidade = 1.99;
float massaG;
int mediaRound = 0; 
//primeira media das leituras
const int bufferSize1 = 16;
float ultraBuffer1[bufferSize1];
int bufferIndex1 = 0;
int bufferLength1 = 0; 
float mediaUltra1 = 0;

//faz a média da média da leitura
const int bufferSize2 = 8;
float ultraBuffer2[bufferSize2];
int bufferIndex2 = 0;
int bufferLength2 = 0; 
float mediaUltra2 = 0;

void setup() {

  lcd.begin(16, 2);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}


void DisplayProcedure()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Distancia: ");
  lcd.print(mediaRound);
  lcd.print("cm");
  delay(10);
  lcd.setCursor(0, 1);
  lcd.print("Volume: ");
  lcd.print(volumeOcupado);
  lcd.print("cm3");
  lcd.display();
  delay(10);
  if (distanceCm <= 0) {
    tone(11, 400, 100);
  }
  else {
    noTone(11);
  }
}

void loop() {

for(int i=0;i<4;i++)
{
 UltrassonicProcedure();
  delay(10);
   
}

  DisplayProcedure();
  
  delay(50);
}
