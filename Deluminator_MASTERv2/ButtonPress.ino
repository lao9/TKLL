/* Button Press
 This code is used to obtain user input from the buttons on the Arduino Color LCD shield
 Each button pin is set HIGH and then the buttons are read and trigger input when in a LOW state (pressed)
 
 Takes no input variables; executes based on reading button pin states
 */

int buttonPress()
{  
  // Write all of the buttons HIGH first to check if they have been turned low == "pressed"
  digitalWrite(btnS1,HIGH);
  digitalWrite(btnS2,HIGH);
  digitalWrite(btnS3,HIGH);

  if(!digitalRead(btnS1)) 
    // If the S1 button pin reads LOW, a press of the S1 button is returned
  {
    return(btnS1);
  }
  else if(!digitalRead(btnS2)) 
    // If the S2 button pin reads LOW, a press of the S2 button is returned
  {
    return(btnS2);
  }
  else if(!digitalRead(btnS3)) 
    // If the S3 button pin reads LOW, a press of the S3 button is returned
  {
    return(btnS3);
  }
  else if(!digitalRead(btnS1) && !digitalRead(btnS2))
    // If the S1 & S2 button pins read LOW, no button press is returned
  {
    return(btnNONE);
  }
  else  // default: return NO button press
  {
    return(btnNONE);
  }
}

