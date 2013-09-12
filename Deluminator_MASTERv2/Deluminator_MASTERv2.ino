/** Deluminator Device (LED Brighter/Dimmer) Code
 * Created by Tyler Hobbs, Lucy Corippo, Kavitha Prasanna, Lauren Oliveri
 * September 5, 2013
 */

#include <ColorLCDShield.h>
int lcd_key;
int seconds, tenthsecs;
boolean firstTime = true;
int startTime, currTime;

#define SECONDS 00
#define TENTHSECS 0

#define btnNONE 2
#define btnS1 3
#define btnS2 4
#define btnS3 5

LCDShield lcd;

void setup() {
  Serial.begin(9600);
  /* Initialize the LCD, set the contrast, clear the screen */
  lcd.init(PHILIPS);
  lcd.contrast(-51);
  lcd.clear(BLACK);

  // Set the input Pins
  pinMode(btnS1,INPUT);
  pinMode(btnS2,INPUT);
  pinMode(btnS3,INPUT);

  // Set the time variables
  seconds = SECONDS;
  tenthsecs = TENTHSECS;
}

void loop() {

  lcd_key = buttonPress();
  lcd.setStr("Press S1 to ",1,1,WHITE,BLACK);
  lcd.setStr("increase time",14,1,WHITE,BLACK);
  lcd.setStr("Press S2 to ",40,1,WHITE,BLACK);
  lcd.setStr("decrease time",53,1,WHITE,BLACK);

  switch (lcd_key)
  {
  case btnNONE:
    {
      displayDigitalTime(seconds,tenthsecs);
      break;
    }
  case btnS1: 
    { //TIME INCREASE
      if (firstTime) {
        startTime = millis();
        firstTime = !firstTime;
      }

      currTime = millis() - startTime;

      if (currTime > 76) {
        if (tenthsecs < 9) {
          tenthsecs += 1;
        }
        else {
          seconds += 1;
          tenthsecs = 0;
        }
        firstTime = !firstTime; 
      }
      displayDigitalTime(seconds,tenthsecs);
      if (seconds >= 30) {
        displayDigitalTime(30,0);
        delay(500);
        lcd.clear(WHITE);
        displayFun();
        delay(2000);
        lcd.clear(BLACK);
        seconds = 0;
        tenthsecs = 0;
      }
      break;
    }
  case btnS2:
    { //TIME DECREASE
      if (firstTime) {
        startTime = millis();
        firstTime = !firstTime;
      }

      currTime = millis() - startTime;

      if (currTime > 76) {
        if (seconds > 0) {
          if (tenthsecs > 0) {
            tenthsecs -= 1;
          }
          else if (tenthsecs == 0) {
            seconds -= 1;
            tenthsecs = 9;
          } 
        }
        else {
          if (tenthsecs > 0) {
            tenthsecs -= 1;
          }
          else if (tenthsecs == 0) {
            tenthsecs = 0;
          } 
        }
        firstTime = !firstTime; 
      }
      displayDigitalTime(seconds,tenthsecs);
      break;
    }
  case btnS3:
    {
      break;
    }
  }
}










