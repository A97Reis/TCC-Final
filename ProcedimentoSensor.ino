void ProcedimentoSensor()
{
  float distancia1, distancia2;
  float distancia = 0;

  // le a distancia do sensor ultrassonico
  distancia = sensor.ler();

  // atualiza o filtro 1
  filtro1.atualizar(distancia);

  // atualiza o filtro 2
  filtro2.atualizar(filtro1.lerMedia());

  // trunca a distancia com uma casa decimal
  distancia1 = truncar_distancia(filtro1.lerMedia());
  distancia2 = truncar_distancia(filtro2.lerMedia());

  // atualiza o conversor com a distancia truncada
  conversor.atualizar(distancia1, distancia2);
}

float truncar_distancia(float valor)
{
  float aux = valor;
  aux = (int) (aux * 10);
  return ((float) aux)/10;
}
