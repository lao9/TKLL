/** Deluminator Device (LED Brighter/Dimmer) Code
 * Created by Tyler Hobbs, Lucy Corippo, Kavitha Prasanna, Lauren Oliveri
 * September 5, 2013
 */

#include <ColorLCDShield.h>
int lcd_key;
int seconds, tenthsecs;
boolean firstTime = true;
int startTime, currTime;

// for statistcs calculations
unsigned long stat_time;
boolean first = true;
unsigned long previous;
int counter = 0;
unsigned long tenthsec_int;
unsigned long tot_tenthsec;
unsigned long sq_error_sum;
unsigned long avg_tenthsec;
unsigned long st_dev;

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
  lcd.setStr("Press:",1,1,WHITE,BLACK);
  lcd.setStr("S1 to increase",15,1,WHITE,BLACK);
  lcd.setStr("S2 to decrease",29,1,WHITE,BLACK);
  lcd.setStr("S3 to reset",43,1,WHITE,BLACK);
  
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
      if (firstTime) {
        startTime = millis();
        firstTime = !firstTime;
      }

      currTime = millis() - startTime;

      if (currTime > 76) {
        if (tenthsecs < 9) {
          tenthsecs += 1;
          stat_time = millis();
          statistics();
        }
        else {
          seconds += 1;
          tenthsecs = 0;
          stat_time = millis();
          statistics();
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
         lcd.setStr("Press:",1,1,WHITE,BLACK);
         lcd.setStr("S1 to increase",15,1,WHITE,BLACK);
         lcd.setStr("S2 to decrease",29,1,WHITE,BLACK);
         lcd.setStr("S3 to reset",43,1,WHITE,BLACK);
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
            stat_time = millis();
            statistics();
          }
          else if (tenthsecs == 0) {
            seconds -= 1;
            tenthsecs = 9;
            stat_time = millis();
            statistics();
          } 
        }
        else {
          if (tenthsecs > 0) {
            tenthsecs -= 1;
            stat_time = millis();
            statistics();
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
      seconds = 0;
      tenthsecs = 0;
      break;
    }
  }
}
