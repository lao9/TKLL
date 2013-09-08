/** Deluminator Device (LED Brighter/Dimmer) Code
 * Created by Tyler Hobbs, Lucy Corippo, Kavitha Prasanna, Lauren Oliveri
 * September 5, 2013
 */

#include <ColorLCDShield.h>
int lcd_key;
int seconds, tenthsecs;

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

  switch (lcd_key)
  {
  case btnNONE:
    {
      displayDigitalTime(seconds,tenthsecs);
      break;
    }
  case btnS1: 
    { //TIME INCREASE
      startTime = millis();
            
      if (tenthsecs < 9) {
        tenthsecs += 1;
      }
      else if (tenthsecs >= 9) {
        seconds += 1;
        tenthsecs = 0;
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
      if (seconds > 0) {
        if (tenthsecs > 0) {
          tenthsecs -= 1;
        }
        else if (tenthsecs == 0) {
          seconds -= 1;
          tenthsecs = 9;
        } 
      }
      else if (seconds == 0) {
        if (tenthsecs > 0) {
          tenthsecs -= 1;
        }
        else if (tenthsecs == 0) {
          tenthsecs = 0;
        } 
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





