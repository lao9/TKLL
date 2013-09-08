void displayDigitalTime(int s, int ts)
{
  char timeChar[4] = {
    'x', 'x', -2, 'x'  };  

  // Turn the values into idividual integers
  timeChar[0] = s/10;
  timeChar[1] = s%10;
  timeChar[3] = ts;

  for (int i=0; i<4; i++) {
    timeChar[i] += 48;
    Serial.print(timeChar[i]);
  }

  /* Print the time on the clock */
  lcd.setStr(timeChar, 55, 30, CORAL, BLACK);
}

