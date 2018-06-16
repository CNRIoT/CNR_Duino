/* CNRDuino 'da kullanilan 4 kanalli 433 Mhz HIB RF Alici icin kullanilabilecek 
 *  basit bir test kodu. 
 *  Kodu kullanmak icin herhangi bir kutuphane gerekmemektedir. 
*/
const int hib_01 = 74;  //74
const int hib_02 = 28; //28
const int hib_03 = 39; 
const int hib_04 = 29; //28

const int buzzer = 33; //28

const int relay01 =  49; 
const int relay02 =  48; 
const int relay03 =  47; 
const int relay04 =  46; 

int hib_01_buttonState = 0;         
int hib_02_buttonState = 0;
int hib_03_buttonState = 0;
int hib_04_buttonState = 0;

void setup() {
   Serial.begin(9600);

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

  hib_01_buttonState = digitalRead(hib_01);
  hib_02_buttonState = digitalRead(hib_02);
  hib_03_buttonState = digitalRead(hib_03);
  hib_04_buttonState = digitalRead(hib_04);
        

  if (hib_01_buttonState == HIGH) {

    Serial.println("HIB_01 ACIK");
    digitalWrite(relay01, HIGH);
    digitalWrite(buzzer, HIGH);
  } else {
    digitalWrite(relay01, LOW);
   
  }


  if (hib_02_buttonState == HIGH) {
   
    Serial.println("HIB_02 ACIK");
    digitalWrite(relay02, HIGH);
  } else {
   
    digitalWrite(relay02, LOW);
 
  }


  if (hib_03_buttonState == HIGH) {
   
    Serial.println("HIB_03 ACIK");
    digitalWrite(relay03, HIGH);
  } else {
    
    digitalWrite(relay03, LOW);

  }


  if (hib_04_buttonState == HIGH) {
   
    Serial.println("HIB_04 ACIK");
    digitalWrite(relay04, HIGH);
  } else {
    
    digitalWrite(relay04, LOW);
  
  }
}
