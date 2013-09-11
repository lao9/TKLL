/* Button Press
 This code is used to obtain user input from the buttons on the Arduino Color LCD shield
 Each button pin is set HIGH and then the buttons are read and trigger input when in a LOW state (pressed)
 There is a delay associated with each button read to eliminate bouncing
 
 Takes no input variables; executes based on reading button pin states
 */

int buttonPress()
{  
  digitalWrite(btnS1,HIGH);
  digitalWrite(btnS2,HIGH);
  digitalWrite(btnS3,HIGH);

  if(!digitalRead(btnS1)) // If the 1st button pin reads LOW, a press of the 1st button is returned
  {
   // delay(50);
    return(btnS1);
  }
  else if(!digitalRead(btnS2)) // If the 2nd button pin reads LOW, a press of the 2nd button is returned
  {
  //  delay(100);
    return(btnS2);
  }
  else if(!digitalRead(btnS3)) // If the 3rd button pin reads LOW, a press of the 3rd button is returned
  {
    delay(100);
    return(btnS3);
  }
  else if(!digitalRead(btnS1) && !digitalRead(btnS2))
  {
    delay(100);
    return(btnNONE);
  }
  else
  {
    return(btnNONE);
  }
}
