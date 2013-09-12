void statistics()
{
  if (first){
    previous = startTime;
    first = !first;
  }
  //the stat_time is assumed to updated every .1 second
  //therefore, if we compare the previous stat_time to the current time
  //we can take the average and standard deviation it should be around .1
  counter = counter + 1;
  tenthsec_int = stat_time - previous;
  previous = stat_time;
  tot_tenthsec += tenthsec_int;
  Serial.println(tot_tenthsec);
  
  //error
  unsigned long error = tenthsec_int - .1;
  unsigned long square_error = pow(error, 2);
  sq_error_sum += square_error;
}

void calc()
{
  avg_tenthsec = tot_tenthsec/counter;
  unsigned long avg_sq_error = sq_error_sum/counter;
  st_dev = sqrt(avg_sq_error);
}

