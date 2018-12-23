void temperatures(){
  
  temp1c = DS18B20_CELSIUS(0);
 // temp2 = DS18B20_CELSIUS(1);
  dh = dht1.readHumidity();
  dt = dht1.readTemperature();
}

