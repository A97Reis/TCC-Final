void UltrassonicProcedure()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distanceCm = duration * 0.034 / 2;
  media1();
  media2();

  Serial.println("BufferIndex1: "); 
  Serial.println(bufferIndex1);
  Serial.print("mediaUltra1: ");
  Serial.println(mediaUltra1); 
  Serial.print("Buffer1:");
  for(int i = 0; i <= bufferLength1; i++){
    Serial.print(ultraBuffer1[i]);
    Serial.println(" ");
  }
  volumeCm = mediaUltra2 * areaCirc;
  volumeOcupado = volumeTotal - volumeCm; //volume de areia
  massaG = volumeOcupado * densidade; 
}

void media1()
{
  ultraBuffer1[bufferIndex1] = distanceCm;
  
  if(bufferLength1 < bufferSize1)
  {
    bufferLength1++;
  }
  if(bufferIndex1 >= bufferSize1)
  {
    bufferIndex1 = 0;
  }else{
    bufferIndex1++;
  }
  mediaUltra1 = media(&ultraBuffer1[0],bufferLength1);
}

void media2()
{
  ultraBuffer2[bufferIndex2] = media(&ultraBuffer1[0], bufferLength1);
  mediaUltra2 = media(&ultraBuffer2[0], bufferLength2);
  if(bufferLength2 < bufferSize2)
  {
    bufferLength2++;
  }
  bufferIndex2 = bufferIndex2 >= bufferSize2 ? 0 : bufferIndex2 + 1;// bufferIndex2 recebe o valor resultando da cndição (bufferIndex2 >= bufferSize2) se a condição for verdadeiro ele recebe 0, se não ele recebe bufferIndex2+1
}


float media(float *bufferUltra, int bufferLength)
{
  float media = 0;
  
  for(int i=0;i<=bufferLength; i++)
  {
    media += bufferUltra[i];
    
  }

  return media / bufferLength;
}
