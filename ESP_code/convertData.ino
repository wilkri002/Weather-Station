int calculateTemp(float temp){
  temp = (temp / 1024) * 5.0;
  temp = (temp - 0.5);
  return temp;
}
