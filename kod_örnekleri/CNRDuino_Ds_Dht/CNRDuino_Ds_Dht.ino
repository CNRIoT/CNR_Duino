//#include <Wire.h>
#include <LiquidCrystal.h>
//#include "src/LiquidCrystal.h"
//#include "src/OneWire.h"
#include <DHT.h>
#include  <OneWire.h>
//#include "src/DallasTemperature.h"
//#include "src/DHT.h"
#include <DallasTemperature.h>



#define TEMPERATURE_PRECISION 10


const int rs = 53, en = 9, d4 = 82, d5 = 81, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#define DS18B20_BUS     72
#define DHT1PIN         71
#define DHT1TYPE DHT22
DHT dht1(DHT1PIN, DHT1TYPE);
OneWire  oneWire(DS18B20_BUS);
DallasTemperature  temperatureSensors(&oneWire);
DeviceAddress  DS18B20[1]; 


float temp1c;
int dh;
float dt;

////Setup//////////
void setup() {
INIT_DS18B20(9);

lcd.begin(16, 2);
pinMode(11, OUTPUT);  //LCD BACKLIGHT
digitalWrite(11, HIGH);


lcd.setCursor(0, 0);
lcd.print("Ds18-DHT22-TEST");
delay(2000);
lcd.clear();

}

 void loop() {
  
temperatures();

lcd.setCursor(0, 0);
lcd.print("Ds18B20: ");lcd.print(temp1c);lcd.print(" C");
lcd.setCursor(0, 1);  
lcd.print("DHT:");lcd.print(dt);lcd.print("C / ");lcd.print(dh);lcd.print("%");
 }

