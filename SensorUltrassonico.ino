SensorUltrassonico::SensorUltrassonico(int trigPin, int echoPin)
{
  SensorUltrassonico(trigPin, echoPin, COEF_VEL_SOM_POR_CM);
}

SensorUltrassonico::SensorUltrassonico(int trigPin, int echoPin, float spCoef)
{
  this->trigPin = trigPin;
  this->echoPin = echoPin;
  this->spCoef = spCoef;
}

void SensorUltrassonico::inicializar()
{
  pinMode(this->trigPin, OUTPUT);
  pinMode(this->echoPin, INPUT);  
}

float SensorUltrassonico::ler()
{
  long duracao = 0;
  digitalWrite(this->trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(this->trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(this->trigPin, LOW);

  duracao = pulseIn(this->echoPin, HIGH);

  return duracao * this->spCoef;
}
