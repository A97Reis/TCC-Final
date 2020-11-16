void ProcedimentoDisplay()
{
  char linha[16];
  float valor = conversor.distanciaFiltro2;

  // limpa display
  lcd.clear();

  // mostra linha 1
  lcd.setCursor(0, 0);
  sprintf(&linha[0], "Distancia: %.2f cm", valor);
  lcd.print(linha);
  delay(10);

  // mostra linha 2
  lcd.setCursor(0, 1);
  sprintf(&linha[0], "Volume: %.2f cm3", conversor.volume);
  lcd.print(linha);
  lcd.display();
  delay(10);

  // aonde esta ligado o pino 11??
  // talvez aqui seja necessário verificar a leitura do sensor
  float distancia = conversor.distanciaFiltro2;
  if (distancia <= 0) {
    tone(11, 400, 100);
  }
  else {
    noTone(11);
  }
}
