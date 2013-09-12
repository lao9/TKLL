void statistics()
{
  /*the stat_time is assumed to updated every .1 second
   therefore, if we compare the previous stat_time to the current time
   we can take the average and standard deviation it should be around 0.1
   */
  stat_time = millis();
  counter = counter + 1;    // Keeps track of # of elements to average
  tenthsec_int = stat_time - previous;  // Length of 0.1 second interval
  previous = stat_time;    // Update the previous time with the "current" time

  // To account for lapses in button pressing, set the first 0.1 second interval length to 100 milliseconds.
  // This decreases statistical accuracy when multiple button presses occur.
  if (tenthsec_int > 102) {
    tenthsec_int = 100;
  }
  
  tot_tenthsec += tenthsec_int;  // Sums the elapsed time intervals over button presses

  //Calculates error of ideal and actual 0.1 second intervals
  error = tenthsec_int - 100;
  error = abs(error);
  error_sum += error;  // sums the errors
}

// Calc() function finally calculates an average of the tenth-seconds intervals and errors over the entire time.
void calc()
{
  avg_tenthsec = tot_tenthsec/counter;
  avg_error = error_sum/counter;
}




