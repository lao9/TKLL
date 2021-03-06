/* displayDigitalTime function takes time variable inputs and sorts them into a character string
 to print to the LCD screen.
 displayDigitalStats function takes the total tenth-seconds variable and displays statistics to
 the LCD screen
 */

void displayDigitalTime(int s, int ts)
{
  char timeChar[8] = {  // put the time variables in a character string (XX.X)
    s/10, s%10, -2, ts        };

  for (int i=0; i<4; i++) {  // Convert the character string into ASCII numbers
    timeChar[i] += 48;
  }

  /* Print the time on the clock */
  lcd.setStr(timeChar, 70, 50, WHITE, BLACK);
}

void displayDigitalStats(long ts)  // DISPLAYS the elapsed time to the LCD screen
// (total amount of time of combined button presses)
{
  char timeChar[8] = {
    ts/10000, (ts/1000)%10, -2, (ts/100)%10      };

  for (int i=0; i<4; i++){
    timeChar[i] += 48;
  }
  lcd.setStr(timeChar, 15, 50, WHITE, BLACK);
}

void displayDigitalStat2(int ts)  // DISPLAYS the average 0.1 s interval length over the total elapsed time
{
  char timeChar[8] = {
    0, -2, ts/100, (ts%100)/10    };

  for (int i=0; i<4; i++){
    timeChar[i] += 48;
  }
  lcd.setStr(timeChar, 45, 50, WHITE, BLACK);
}

void displayDigitalStat3(int ts)  // DISPLAYS the mean error of 0.1-second interval length
{
  char timeChar[8] = {
    -2, ts/100, (ts%100)/10, (ts%100)%10    };

  for (int i=0; i<4; i++){
    timeChar[i] += 48;
  }
  lcd.setStr(timeChar, 75, 47, WHITE, BLACK);

}


