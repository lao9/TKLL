void decrementTime() {

  if (firstTime) {
    startTime = millis();  // set the start time for measuring each tenth-second
    firstTime = !firstTime;
  }

  currTime = millis() - startTime;  // find the current time to count up to a tenth-second

  if (currTime > 98) {  // once the current time reaches the tenth-second point, increment the time
    if (seconds > 0) {
      if (tenthsecs > 0) {
        tenthsecs -= 1;
      }
      else if (tenthsecs == 0) {
        seconds -= 1;
        tenthsecs = 9;
      }
      statistics();  // Run the statistics flow code to calculate stats at each decrement
    }
    else {  // For robustness, to confirm that timer does not go below 00.0
      if (tenthsecs > 0) {
        tenthsecs -= 1;
        statistics();  // Run the statistics flow code to calculate stats at each decrement
      }
      else if (tenthsecs == 0) {
        tenthsecs = 0;
      } 
    }
    displayDigitalTime(seconds,tenthsecs);  // Display the incremented digital time
    firstTime = !firstTime; 
  }
}
