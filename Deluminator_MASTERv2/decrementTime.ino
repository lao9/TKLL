void decrementTime() {

  if (firstTime) {
    startTime = millis();  // set the start time for measuring each tenth-second
    firstTime = !firstTime;
  }

  currTime = millis() - startTime;  // find the current time to count up to a tenth-second

  if (currTime > 82) {  // once the current time reaches the tenth-second point, increment the time
    if (seconds > 0) {
      if (tenthsecs > 0) {
        tenthsecs -= 1;
      }
      else if (tenthsecs == 0) {
        seconds -= 1;
        tenthsecs = 9;
      } 
      stat_time = millis();
      statistics();
    }
    else {  // For robustness, to confirm that timer does not go below 00.0
      if (tenthsecs > 0) {
        tenthsecs -= 1;
        stat_time = millis();
        statistics();
      }
      else if (tenthsecs == 0) {
        tenthsecs = 0;
      } 
    }
    displayDigitalTime(seconds,tenthsecs);  // Display the incremented digital time
    firstTime = !firstTime; 
    first = !first;
  }
}

