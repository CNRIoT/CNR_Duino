/* CNRDuino 'da kullanilan 4 kanalli 433 Mhz HIB RF Alici icin kullanilabilecek 
 *  basit bir test kodu. 
 *  Uzaktan kumandanin dugmelerine basildikca roleler acilip kapanmakta
 *  ve buzzer otmektedir. 
 *  16*2 LCD ve serial uzerinden rolelerin durumu gorulebilmektedir.  
*/

//#include <LiquidCrystal.h>
#include "src/LiquidCrystal.h"

const int rs = 53, en = 9, d4 = 82, d5 = 81, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


const int hib_01 = 74;  //74
const int hib_02 = 28; //28
const int hib_03 = 39; 
const int hib_04 = 29; //28

const int buzzer = 33; //28

const int relay01 =  49; 
const int relay02 =  48; 
const int relay03 =  47; 
const int relay04 =  46; 

int prevState01 = LOW;
int prevState02 = LOW;
int prevState03 = LOW;
int prevState04 = LOW;
int x = 0;

long lastDebounceTime = 0; 
long debounceDelay = 85;   


void setup() {


lcd.begin(16, 2);
digitalWrite(11, HIGH);

lcd.setCursor(0, 0);
lcd.print("433 Mhz.TEST");
  
Serial.begin(115200);

  pinMode(hib_01, INPUT);
  pinMode(hib_02, INPUT);
  pinMode(hib_03, INPUT);
  pinMode(hib_04, INPUT);

  pinMode(relay01, OUTPUT);
  pinMode(relay02, OUTPUT);
  pinMode(relay03, OUTPUT);
  pinMode(relay04, OUTPUT);
  
  pinMode(buzzer, OUTPUT);
        
}

void loop() {


int currState01 = digitalRead(hib_01);
int currState02 = digitalRead(hib_02);
int currState03 = digitalRead(hib_03);
int currState04 = digitalRead(hib_04);


if ( (millis() - lastDebounceTime) > debounceDelay) { //debounce
   
if (currState01 == HIGH && prevState01 == LOW) {

    if (x == 0) {
      digitalWrite(relay01, HIGH);
       lcd.setCursor(0, 0);
      lcd.print("1. Role ACIK   ");
      delay(200);
      x = 1;
      Serial.println("1. Role ACIK   ");

    } else {
      
      digitalWrite(relay01, LOW);
       lcd.setCursor(0, 0);
      lcd.print("1. Role KAPALI   ");
      delay(200);
      x = 0;
     Serial.println("1. Role KAPALI   ");
    }
     lastDebounceTime = millis();
     buzzer_tone();
 }

   
if (currState02 == HIGH && prevState02 == LOW) {

    if (x == 0) {     
      digitalWrite(relay02, HIGH);
       lcd.setCursor(0, 0);
      lcd.print("2. Role ACIK   ");
      Serial.println("2. Role ACIK   ");
      delay(200);
      x = 1;
   

    } else {
      // Toggle off
      
      digitalWrite(relay02, LOW);
       lcd.setCursor(0, 0);
      lcd.print("2. Role KAPALI   ");
      Serial.println("2. Role KAPALI  ");
      delay(200);
      x = 0;
   
    }
     lastDebounceTime = millis();
      buzzer_tone();
 }

   
if (currState03 == HIGH && prevState03 == LOW) {

    if (x == 0) {
      // Toggle on
     
      digitalWrite(relay03, HIGH);
       lcd.setCursor(0, 0);
      lcd.print("3. Role ACIK   ");
      Serial.println("3. Role ACIK  ");
      delay(200);
      x = 1;
   

    } else {
      // Toggle off
      
      digitalWrite(relay03, LOW);
       lcd.setCursor(0, 0);
      lcd.print("3. Role KAPALI   ");
      Serial.println("3. Role KAPALI");
      delay(200);
      x = 0;

    }
     lastDebounceTime = millis();
      buzzer_tone();
     }


   
if (currState04 == HIGH && prevState04 == LOW) {

    if (x == 0) {
      // Toggle on
     
      digitalWrite(relay04, HIGH);
       lcd.setCursor(0, 0);
      lcd.print("4. Role ACIK   ");
      Serial.println("4. Role ACIK ");
        delay(200);
      x = 1;


    } else {
      
      digitalWrite(relay04, LOW);
      lcd.setCursor(0, 0);
      lcd.print("4. Role KAPALI   ");
      Serial.println("4. Role KAPALI ");
      delay(200);
      x = 0;

    }
     lastDebounceTime = millis();
      buzzer_tone();

    }
 }
  }

  void buzzer_tone() {
     digitalWrite(buzzer, HIGH);
     delay(50);
     digitalWrite(buzzer, LOW);
     delay(50);
  }



