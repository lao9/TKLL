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
    }
  case btnS1: 
    { //TIME INCREASE

    }
  case btnS2:
    { //TIME DECREASE

    }
  case btnS3:
    {

    }
  }
}


