void displayDigitalTime(int s, int ts)
{
  char timeChar[4] = {
  'x', 'x', -2, 'x'};  
  
  // Turn the values into idividual integers
  timeChar[0] = s/10;
  timeChar[1] = s%10;
  timeChar[3] = ts;


  
  
}
