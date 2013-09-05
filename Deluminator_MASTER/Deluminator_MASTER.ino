/** Deluminator Device (LED Brighter/Dimmer) Code
 * Created by Tyler Hobbs, Lucy Corippo, Kavitha Prasanna, Lauren Oliveri
 * September 5, 2013
 */

#include ColorLCDShield

void setup() {
  Serial.begin(9600);
  LCDShield lcd;

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

