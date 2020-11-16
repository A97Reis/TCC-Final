void ProcedimentoDisplay()
{
  char linha[16];
  float distancia = filtro1.lerMedia();

  // limpa display
  lcd.clear();

  // mostra linha 1
  lcd.setCursor(0, 0);
  sprintf(&linha[0], "Distancia: %.2f cm", distancia);
  lcd.print(linha);
  delay(10);

  // mostra linha 2
  lcd.setCursor(0, 1);
  sprintf(&linha[0], "Volume: %.2f cm3", conversor.volume);
  lcd.print(linha);
  lcd.display();
  delay(10);
  if (distancia <= 0) {
    tone(11, 400, 100);
  }
  else {
    noTone(11);
  }
}
