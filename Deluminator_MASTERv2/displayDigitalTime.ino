void displayDigitalTime(int s, int ts)
{
  char timeChar[8] = {
    'x', 'x', -2, 'x'};  

  // Turn the values into idividual integers
  timeChar[0] = s/10;
  timeChar[1] = s%10;
  timeChar[3] = ts;

  for (int i=0; i<4; i++) {
    timeChar[i] += 48;
  }

  /* Print the time on the clock */
  lcd.setStr(timeChar, 85, 50, CORAL, BLACK);
}

