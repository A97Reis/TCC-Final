Conversor::Conversor(float volumeTotal)
{
  this->volumeTotal = volumeTotal;
}

void Conversor::atualizar(float distancia)
{
  this->volumeMedido = distancia * AREA;
  this->volume  = this->volumeTotal - this->volumeMedido;
  this->peso = this->volume * DENSIDADE;
}
