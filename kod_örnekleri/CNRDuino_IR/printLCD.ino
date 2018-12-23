void printLCD(){
  
  lcd.setCursor(0, 0);
  lcd.print("KOD: ");lcd.print(results.value, HEX);
  
}

