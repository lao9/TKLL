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

  lcd.setStr("Press Button S1 to increment time",10,10,BLACK,WHITE);
  lcd_key = buttonPress();

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
      break;
    }
  case btnS3:
    {
      break;
    }
  }
}










