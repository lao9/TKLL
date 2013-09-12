/* displayDigitalTime function takes time variable inputs and sorts them into a character string
 to print to the LCD screen.
 displayDigitalStats function takes the total tenth-seconds variable and displays statistics to
 the LCD screen
 */

void displayDigitalTime(int s, int ts)
{
  char timeChar[8] = {  // put the time variables in a character string (XX.X)
    s/10, s%10, -2, ts  };

  for (int i=0; i<4; i++) {  // Convert the character string into ASCII numbers
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
<<<<<<< HEAD
    t1, t2, -2, t3};
    
    for (int i=0; i<4; i++){
      timeChar[i] += 48;
    }
    
    lcd.setStr(timeChar, 75, 50, WHITE, BLACK);
=======
    -2, ts  };

  for (int i=0; i<2; i++){
    timeChar[i] += 48;
  }

  lcd.setStr(timeChar, 75, 50, WHITE, BLACK);
>>>>>>> d5905e41a328353d537c675a8d2a22e23cc40176
}

