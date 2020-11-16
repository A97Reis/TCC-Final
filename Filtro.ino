Filtro::Filtro(const uint8_t tamanhoMaximo)
{
  this->indice = 0;
  this->tamanho = 0;
  this->tamanhoMaximo = tamanhoMaximo;
  this->valores = (float*) malloc(sizeof(float)*tamanhoMaximo);
}

void Filtro::atualizar(float valor)
{
  this->valores[this->indice] = valor;
  this->indice = this->indice >= this->tamanhoMaximo ? 0 : this->indice + 1;
  if (this->tamanho < this->tamanhoMaximo) this->tamanho++;
}

float Filtro::lerMedia()
{
  float soma = 0;
  
  for (uint8_t i =0; i < this->tamanho; i++) soma += this->valores[i];
  
  return soma/this->tamanho;
}
