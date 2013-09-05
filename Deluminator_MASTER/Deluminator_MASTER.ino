/** Deluminator Device (LED Brighter/Dimmer) Code
 * Created by Tyler Hobbs, Lucy Corippo, Kavitha Prasanna, Lauren Oliveri
 * September 5, 2013
 */

#include <ColorLCDShield.h>

 
 
void setup() {
  Serial.begin(9600);
  LCDShield lcd;
  lcd.init(PHILIPS);  // Initializes lcd, using an PHILIPS driver
  lcd.contrast(-51);
  lcd.clear(BACKGROUND);
}

void loop() {

  lcd_key = userInputs();

  switch (lcd_key)
  {
  case btnNONE:
    {
    }
  case btnS1: 
    {

    }
  case btnS2:
    {

    }
  case btnS3:
    {

    }
  }
}

