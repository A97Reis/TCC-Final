#include "LiquidCrystal.h"

/********************** CLASSES *************************/
class SensorUltrassonico
{
  private:
    int trigPin;
    int echoPin;
    float spCoef; // sound speed coefficient
  public:
    SensorUltrassonico(int trigPin, int echoPin);
    SensorUltrassonico(int trigPin, int echoPin, float spCoef);
    float ler();
    void inicializar();
};

class Filtro
{
  private:
    uint8_t indice;
    uint8_t tamanho;
    uint8_t tamanhoMaximo;
    float *valores;
  public:
    Filtro(const uint8_t tamanhoMaximo);
    void atualizar(float valor);
    float lerMedia();
};

class Conversor{
  public:
    float distancia;
    float volume;
    float volumeMedido;
    float volumeTotal;
    float peso;
    Conversor(float volumeTotal);
    void atualizar(float distancia);
};


/********************** DISPLAY ***********************/

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


/***************** SENSOR ULTRASSONICO *****************/

#define COEF_VEL_SOM_POR_CM     0.034/2
#define TRIG_PIN                9
#define ECHO_PIN                10

SensorUltrassonico sensor(TRIG_PIN, ECHO_PIN);


/********************* FILTROS *************************/

#define TAMANHO_FILTRO_1      16
#define TAMANHO_FILTRO_2      8

Filtro filtro1(TAMANHO_FILTRO_1);
Filtro filtro2(TAMANHO_FILTRO_2);


/******************* CONVERSOR *************************/

#define ALTURA_MAX          12.10
#define RAIO                4
#define AREA                3.14 * pow(RAIO, 2)
#define DENSIDADE           1.99
#define VOLUME_TOTAL        ALTURA_MAX * AREA

Conversor conversor(VOLUME_TOTAL);


void setup() {
  lcd.begin(16, 2);
  sensor.inicializar();
  Serial.begin(9600);
}

void loop() {

  for(int i=0;i<4;i++)
  {
    ProcedimentoSensor();
    delay(10);
  }

  ProcedimentoDisplay();
  delay(50);
}
