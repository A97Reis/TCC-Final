Conversor::Conversor(float volumeTotal)
{
  this->volumeTotal = volumeTotal;
}

void Conversor::atualizar(float distanciaFiltro1, float distanciaFiltro2)
{
  this->distanciaFiltro1 = distanciaFiltro1;
  this->distanciaFiltro2 = distanciaFiltro2;
  
  this->volumeMedido = distanciaFiltro2 * AREA;
  this->volume  = this->volumeTotal - this->volumeMedido;
  this->peso = this->volume * DENSIDADE;
}
