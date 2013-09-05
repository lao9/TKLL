/*
This code is used to obtain user input from the buttons on the Arduino shield
Each button pin is set HIGH and then the buttons are read and trigger input when in a LOW state (pressed)
There is a delay associated with each button read to eliminate bouncing

Takes no input variables; executes based on reading button pin states
*/

int ButtonPress()
{
  pinMode(Button1,INPUT);
  pinMode(Button2,INPUT);
  pinMode(Button3,INPUT);
  
  digitalWrite(Button1,HIGH);
  digitalWrite(Button2,HIGH);
  digitalWrite(Button3,HIGH);
  
  if(!digitalRead(Button1)) // If the 1st button pin reads LOW, a press of the 1st button is returned
  {
    delay(200);
    return(Button1);
  }
  else if(!digitalRead(Button2)) // If the 2nd button pin reads LOW, a press of the 2nd button is returned
  {
    delay(200);
    return(Button2);
  }
  else if(!digitalRead(Button3)) // If the 3rd button pin reads LOW, a press of the 3rd button is returned
  {
    delay(200);
    return(Button3);
  }
}
