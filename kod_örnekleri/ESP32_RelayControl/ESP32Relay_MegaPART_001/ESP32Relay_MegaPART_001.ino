 
#include <LiquidCrystal.h>
const int rs = 53, en = 9, d4 = 82, d5 = 81, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


const int buzzer = 33; //28
char inchar;  //Will hold the incoming character from the Serial Port.


 int relay1 = 49;
 int relay2 = 48;
 int relay3 = 47;
 int relay4 = 46;

 void setup()
 {
 Serial.begin(115200);
 Serial2.begin(115200);
 lcd.begin(16, 2);
pinMode(11, OUTPUT);  //LCD BACKLIGHT
digitalWrite(11, HIGH);
pinMode(buzzer, OUTPUT);


 pinMode(relay1, OUTPUT);
 pinMode(relay2, OUTPUT);
 pinMode(relay3, OUTPUT);
 pinMode(relay4, OUTPUT);

 digitalWrite(relay1, LOW);
 digitalWrite(relay2, LOW);
 digitalWrite(relay3, LOW);
 digitalWrite(relay4, LOW);

Serial.println("ESP32 - Relay Control");
lcd.setCursor(0, 0);
lcd.print("ESP32 - Relay");
delay(2000);
lcd.clear();



 
}

void buzzer_tone() {
digitalWrite(buzzer, HIGH);
delay(50);
digitalWrite(buzzer, LOW);
delay(50); }
 void loop() {

if(Serial2.available() >0) //2 olacak
 {
 inchar=Serial2.read(); 
 Serial.println("ESP32: ");Serial.print(inchar);
 Serial.println();
if (inchar=='1')
   {
   delay(10);
   digitalWrite(relay1, HIGH);
  Serial.println("1. ROLE ACILDI");
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("1. ROLE ACILDI ");
   }

if (inchar=='2')
   {
   delay(10);
   digitalWrite(relay1, LOW);
      Serial.println("1. ROLE KAPANDI");
        lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("1. ROLE KAPANDI ");
   }   

if (inchar=='3')
   {
   delay(10);
   digitalWrite(relay2, HIGH);
      Serial.println("2. ROLE ACILDI");
        lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("2. ROLE ACILDI ");
   }   

 if (inchar=='4')
   {
   delay(10);
   digitalWrite(relay2, LOW);
      Serial.println("2. ROLE KAPANDI");
        lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("2. ROLE KAPANDI ");
   }   

if (inchar=='5')
   {
   delay(10);
   digitalWrite(relay3, HIGH);
      Serial.println("3. ROLE ACILDI");
        lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("3. ROLE ACILDI ");
   }   

if (inchar=='6')
   {
   delay(10);
   digitalWrite(relay3, LOW);
      Serial.println("3. ROLE KAPANDI");
        lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("3. ROLE KAPANDI ");
   } 

if (inchar=='7')
   {
   delay(10);
   digitalWrite(relay4, HIGH);
      Serial.println("4. ROLE ACILDI");
        lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("4. ROLE ACILDI ");
   } 

 if (inchar=='8')
   {
   delay(10);
   digitalWrite(relay4, LOW);
      Serial.println("4. ROLE KAPANDI");
        lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("4. ROLE KAPANDI ");
   }   
 
  
     } 
   }
    
