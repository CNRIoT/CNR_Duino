
#include <LiquidCrystal.h>
#include <IRremote.h>

int RECV_PIN = 34;
IRrecv irrecv(RECV_PIN);
decode_results results;

const int rs = 53, en = 9, d4 = 82, d5 = 81, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int buzzer = 33; //28

void setup() {

Serial.begin(115200);
lcd.begin(16, 2);
irrecv.enableIRIn(); // Start the receiver
pinMode(11, OUTPUT);  //LCD BACKLIGHT
digitalWrite(11, HIGH);
pinMode(buzzer, OUTPUT);

lcd.setCursor(0, 0);
lcd.print("IR - TEST");
delay(2000);
lcd.clear();

}

 void buzzer_tone() {
     digitalWrite(buzzer, HIGH);
     delay(50);
     digitalWrite(buzzer, LOW);
     delay(50); }

 void loop() {
  
if (irrecv.decode(&results)) {
    buzzer_tone();
    lcd.clear();
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
 }
 printLCD();
 }

