void displayFun()
{
  lcd.setStr("You did it!", 2, 20, RED, WHITE);
  lcd.setCircle(66, 66, 45, BLACK);  // Circle in the mid, 55 radius
  lcd.setCircle(66, 66, 44, BLACK);  // Circle in the mid, 54 radius
  // Eyes
  lcd.setCircle(50, 50, 5, BLACK);
  lcd.setCircle(50, 50, 4, BLACK);
  lcd.setCircle(50, 80, 5, BLACK);
  lcd.setCircle(50, 80, 4, BLACK);
  //Smile!
  int segmentsBlack[2] = {SSW, SSE};
  lcd.setArc(60, 66, 30, segmentsBlack, sizeof(segmentsBlack), 2, BLACK); 
  lcd.setLine(79, 45, 79, 86, BLACK);
  lcd.setLine(80, 45, 80, 86, BLACK);
  
  // Blinking
  delay(800);
  lcd.setStr("           ", 2, 20, SLATE, WHITE);
  delay(800);
  lcd.setStr("You did it!", 2, 20, RED, WHITE);
  delay(800);
  lcd.setStr("           ", 2, 20, SLATE, WHITE);
  delay(800);
  lcd.setStr("You did it!", 2, 20, BLACK, WHITE);
  delay(800);
  lcd.setStr("           ", 2, 20, SLATE, WHITE);
  delay(800);
  lcd.setStr("You did it!", 2, 20, BLUE, WHITE);
}
