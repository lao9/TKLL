void incrementTime() { //INCREASE TIME CODE

  if (firstTime) {
    startTime = millis();  // set the start time for measuring each tenth-second
    firstTime = !firstTime;
  }

  currTime = millis() - startTime;  // find the current time to count up to a tenth-second

  if (currTime > 82) {  // once the current time reaches the tenth-second point, increment the time
    if (tenthsecs < 9) {
      tenthsecs += 1;
    }
    else {
      seconds += 1;
      tenthsecs = 0;
    }
    statistics();  // Run the statistics flow code to calculate stats at each increment
    displayDigitalTime(seconds,tenthsecs);  // Display the incremented digital time 
    firstTime = !firstTime;
  }

  // Once 30 seconds is reached, display the "FUN" code and reset the clock with the command strings.
  if (seconds >= 30) {
    displayDigitalTime(30,0);  // Keep the digital Time to display 30.0 seconds 
    delay(500);
    lcd.clear(WHITE);
    displayFun();   // Display the FUN MESSAGE AND DISPLAY STATISTICS
    delay(2000);

    // Reset the LCD screen, display the command messages, and reset the time and variables to 0 
    lcd.clear(BLACK);
    userCommandMsg();
    seconds = 0;
    tenthsecs = 0;
    int stat_time, previous;
    int counter = 0;
    long tenthsec_int;
    long tot_tenthsec = 0;
    int error_sum = 0;
    int avg_tenthsec, error, avg_error;
  }
}


