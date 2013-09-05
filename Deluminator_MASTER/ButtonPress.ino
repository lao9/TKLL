/* Button Press
This code is used to obtain user input from the buttons on the Arduino Color LCD shield
Each button pin is set HIGH and then the buttons are read and trigger input when in a LOW state (pressed)
There is a delay associated with each button read to eliminate bouncing

Takes no input variables; executes based on reading button pin states
*/

int ButtonPress()
{
  pinMode(BtnS1,INPUT);
  pinMode(BtnS2,INPUT);
  pinMode(BtnS3,INPUT);
  
  digitalWrite(BtnS1,HIGH);
  digitalWrite(BtnS2,HIGH);
  digitalWrite(BtnS3,HIGH);
  
  if(!digitalRead(BtnS1)) // If the 1st button pin reads LOW, a press of the 1st button is returned
  {
    delay(200);
    return(BtnS1);
  }
  else if(!digitalRead(BtnS2)) // If the 2nd button pin reads LOW, a press of the 2nd button is returned
  {
    delay(200);
    return(BtnS2);
  }
  else if(!digitalRead(BtnS3)) // If the 3rd button pin reads LOW, a press of the 3rd button is returned
  {
    delay(200);
    return(BtnS3);
  }
}
