/** Deluminator Device (LED Brighter/Dimmer) Code
 * Created by Tyler Hobbs, Lucy Corippo, Kavitha Prasanna, Lauren Oliveri
 * September 5, 2013
 */
#include <ColorLCDShield.h>
int lcd_key;

//Defines buttons for user interface
#define btnNONE 0
#define btnS1 1
#define btnS2 2
#define btnS3 3

LCDShield lcd;

 
 
void setup() {
  Serial.begin(9600);
  /* Initialize the LCD, set the contrast, clear the screen */
  lcd.init(PHILIPS);
  lcd.contrast(-51);
  lcd.clear(BLACK);
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


