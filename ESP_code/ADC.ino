int readADC(int pin){
  float output;
  output = ads1115.readADC_SingleEnded(pin);
  output = calculateTemp(output);
  output = 100 - output;
  return output;
}
