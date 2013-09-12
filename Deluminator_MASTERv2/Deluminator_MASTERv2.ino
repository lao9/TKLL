/** Deluminator Device (LED Brighter/Dimmer) Code
 * Created by Tyler Hobbs, Lucy Corippo, Kavitha Prasanna, Lauren Oliveri
 * September 5, 2013
 */

#include <ColorLCDShield.h>

// Initiate time and state variables for code 
int lcd_key;
int seconds, tenthsecs;
boolean firstTime = true;
int startTime, currTime;

// Define variables for statistcs calculations
int stat_time, previous;
int counter = 0;
long tenthsec_int;
long tot_tenthsec = 0;
int error_sum = 0;
int avg_tenthsec, error, avg_error;

// Define the button pin numbers and the baseline seconds/tenth-seconds numbers 
#define SECONDS 00
#define TENTHSECS 0
#define btnNONE 2
#define btnS1 3
#define btnS2 4
#define btnS3 5

// Initiate the LCD Shield constructor
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

  // Set the time variables to Initial zero
  seconds = SECONDS;
  tenthsecs = TENTHSECS;

  //Print the user command strings
  userCommandMsg();

}

void loop() {

  lcd_key = buttonPress();  // READ if a button is pressed

  switch (lcd_key)
  {
  case btnNONE:
    {
      // when no button is pressed, display current Time status
      displayDigitalTime(seconds,tenthsecs);
      break;
    }
  case btnS1: 
    {
      incrementTime();   //TIME INCREASE FUNCTION
      break;
    }
  case btnS2:
    {
      decrementTime();  //TIME DECREASE FUNCTION
      break;
    }
  case btnS3:
    {  // When S3 button is pressed, reset the time and variables to 0
      seconds = 0;
      tenthsecs = 0;
      int counter = 0;
      long tot_tenthsec = 0;
      int error_sum = 0;
      break;
    }
  }
}

