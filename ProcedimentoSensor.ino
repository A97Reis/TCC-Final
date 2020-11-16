void ProcedimentoSensor()
{
  float distancia;

  // le a distancia do sensor ultrassonico
  distancia = sensor.ler();

  // atualiza o filtro 1
  filtro1.atualizar(distancia);

  // atualiza o filtro 2
  filtro2.atualizar(filtro1.lerMedia());

  // trunca a distancia com uma casa deciaml
  distancia = filtro2.lerMedia();
  distancia = (int)(distancia * 10);
  distancia = ((float)distancia)/10;

  // atualiza o conversor com a distancia truncada
  conversor.atualizar(distancia);
}
