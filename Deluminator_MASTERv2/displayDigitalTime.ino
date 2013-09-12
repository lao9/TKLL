void displayDigitalTime(int s, int ts)
{
  char timeChar[8] = {
    s/10, s%10, -2, ts};

  for (int i=0; i<4; i++) {
    timeChar[i] += 48;
  }
  
  /* Print the time on the clock */
  lcd.setStr(timeChar, 75, 50, WHITE, BLACK);
}

void displayDigitalStats(int ts)
{
  char timeChar[8] = {
    -2, ts};
    
    for (int i=0; i<2; i++){
      timeChar[i] += 48;
    }
    
    lcd.setStr(timeChar, 75, 50, WHITE, BLACK);
}
