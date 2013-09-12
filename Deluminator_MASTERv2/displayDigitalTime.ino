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
  int t1 = ts/10000;
  int t2 = (ts/1000)%10;
  int t3 = (ts/100)%10;
  
  char timeChar[8] = {
    t1, t2, -2, t3};
    
    for (int i=0; i<4; i++){
      timeChar[i] += 48;
    }
    
    lcd.setStr(timeChar, 75, 50, WHITE, BLACK);
}
