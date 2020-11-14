#include "LiquidCrystal.h"

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int trigPin = 9;
const int echoPin = 10;
long duration;
float distanceCm;
float volumeCm, volumeOcupado;
float alturaTotal = 18.2;
float raioCirc = 7.5;
float areaCirc = 3.14 * (raioCirc * raioCirc);
float volumeTotal = alturaTotal * areaCirc;
float densidade = 1.99;
float massaG;

//primeira media das leituras
const int bufferSize1 = 16;
float ultraBuffer1[bufferSize1];
int bufferIndex1 = 0;
int bufferLength1 = 0; 
float mediaUltra1 = 0;

//faz a média da média da leitura
const int bufferSize2 = 4;
float ultraBuffer2[bufferSize2];
int bufferIndex2 = 0;
int bufferLength2 = 0; 
float mediaUltra2 = 0;
// VolumeTotal = 21.195

// Medir em um copo graduado a quantidade de 100g (por ex) de areia
// verificar quantos mL deu = 50ml
// Converter para m3 = 0.00005 m3
// dividir kg/m3 (calculo da densidade), no caso 0.1kg/X m3 (do copo graduado convertido em m3)0,000005
// Sabendo o volume em m3 (leitura do sensor)
// multiplicar m3 pela desidade (kg/m3) VolumeOcupado
// m3 (sensor) x    Kg
//                ------    = Kg
//                  m3


void setup() {

  lcd.begin(16, 2);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}


void DisplayProcedure()
{
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  lcd.print(mediaUltra2);
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


  UltrassonicProcedure();

  DisplayProcedure();
  
  delay(3000);
}
