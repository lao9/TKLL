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
  tot_tenthsec = tot_tenthsec + tenthsec_int;
  Serial.println(tenthsec_int);
  
  //error
  int error = tenthsec_int - 100;
  error = abs(error);
  error_sum = error_sum + error;
}

void calc()
{
  
  avg_tenthsec = tot_tenthsec/counter;
  int avg_error = error_sum/counter;
}
