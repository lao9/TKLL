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
  }
  timeChar[4] = ' ';
  timeChar[5] = ' ';
  timeChar[6] = ' ';
  timeChar[7] = ' ';
  timeChar[8] = ' ';

  /* Print the time on the clock */
  lcd.setStr(timeChar, 55, 50, CORAL, BLACK);
}

