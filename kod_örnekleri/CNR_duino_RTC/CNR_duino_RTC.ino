/*
 * 
CNR Duino RTC .... 
2x16 LCD uzerinde RTC'den aldigi tarih ve saat bilgilerini gösterir.
Tarih ve saat ayarina girmek icin board uzerinde OK butonuna basin. 
+ butonu ile degerleri yükseltin 
- butuno ile duşurun. 
En son OK tusu ile kayit yapilarak cikilir. 


:Project:Clock_Set_Date_Time
:Author: Tiziano Bianchettin
:Date: 13/01/2017
:Revision: 1
:License: Public Domain
thanks to:
  http://arduinoenonsolo.blogspot.it/2012/12/orologio-con-arduino-e-il-ds1307.html
  http://www.mauroalfieri.it/
  http://www.danielealberti.it/
  http://www.maffucci.it/
  My electronics laboratory professor "Perito Carli"  


*/
//************libraries**************//
#include <Wire.h>
//#include "src/RTClib.h"
#include "src/RTClib.h"
#include "src/LiquidCrystal.h"
const int rs = 53, en = 9, d4 = 82, d5 = 81, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


//************************************//

RTC_DS1307 RTC;

//************Button*****************//
const int buttonPinUp = 38; 
const int buttonPinDown = 40; 
const int buttonPinOk = 36; 

//************Degiskenler**************//
int hourupg;
int minupg;
int yearupg;
int monthupg;
int dayupg;
int menu =0;




void setup()
{

  lcd.begin(16, 2); // set up the LCD's number of columns and rows:

    
  pinMode(11, OUTPUT); 
    digitalWrite(11, HIGH);

  pinMode(buttonPinUp,INPUT);
  pinMode(buttonPinDown,INPUT);
  pinMode(buttonPinOk,INPUT);

  Serial.begin(9600);
  Wire.begin();
  RTC.begin();

  if (! RTC.isrunning()) {
    Serial.println("RTC is NOT running!");
    // Set the date and time at compile time
   // RTC.adjust(DateTime(__DATE__, __TIME__));
  }
  // RTC.adjust(DateTime(__DATE__, __TIME__)); //removing "//" to adjust the time
    // The default display shows the date and time
  int menu=0;

 lcd.setCursor(0, 0);
 lcd.print("CNR_Duino RTC:");
 lcd.setCursor(0, 1);
 lcd.print("OK --> AYAR");

delay(3000);
lcd.clear();
}
 
void loop()
{ 

// OK butonuna basilip basilmadigini kontrol et
  if(digitalRead(buttonPinOk))
  {
   lcd.clear();
   menu=menu+1;
  }
// in which subroutine should we go?
  if (menu==0)
    {
     DisplayDateTime(); // void DisplayDateTime

    }
  if (menu==1)
    {
    DisplaySetHour();
    }
  if (menu==2)
    {
    DisplaySetMinute();
    }
  if (menu==3)
    {
    DisplaySetYear();
    }
  if (menu==4)
    {
    DisplaySetMonth();
    }
  if (menu==5)
    {
    DisplaySetDay();
    }
  if (menu==6)
    {
    StoreAgg(); 
    delay(500);
    menu=0;
    }
    delay(100);
}

void DisplayDateTime ()
{
// Tarih ve saat gosterimi
  DateTime now = RTC.now();

  lcd.setCursor(0, 1);
  lcd.print("Saat: ");
  if (now.hour()<=9)
  {
    lcd.print("0");
  }
  lcd.print(now.hour(), DEC);
  hourupg=now.hour();
  lcd.print(":");
  if (now.minute()<=9)
  {
    lcd.print("0");
  }
  lcd.print(now.minute(), DEC);
  minupg=now.minute();
  lcd.print(":");
  if (now.second()<=9)
  {
    lcd.print("0");
  }
  lcd.print(now.second(), DEC);

  lcd.setCursor(0, 0);
  lcd.print("Tarih:");
  if (now.day()<=9)
  {
    lcd.print("0");
  }
  lcd.print(now.day(), DEC);
  dayupg=now.day();
  lcd.print("/");
  if (now.month()<=9)
  {
    lcd.print("0");
  }
  lcd.print(now.month(), DEC);
  monthupg=now.month();
  lcd.print("/");
  lcd.print(now.year(), DEC);
  yearupg=now.year();
}

void DisplaySetHour()
{
// saat ayari

  DateTime now = RTC.now();
  if(digitalRead(buttonPinUp)==HIGH)
  {
    if(hourupg==23)
    {
      hourupg=0;
    }
    else
    {
      hourupg=hourupg+1;
    }
  }
   if(digitalRead(buttonPinDown)==HIGH)
  {
    if(hourupg==0)
    {
      hourupg=23;
    }
    else
    {
      hourupg=hourupg-1;
    }
  }
  lcd.setCursor(0,0);
  lcd.print("Saat ayari:");
  lcd.setCursor(0,1);
  lcd.print(hourupg,DEC);
  delay(200);
}

void DisplaySetMinute()
{
// Dakika ayari 
  if(digitalRead(buttonPinUp)==HIGH)
  {
    if (minupg==59)
    {
      minupg=0;
    }
    else
    {
      minupg=minupg+1;
    }
  }
   if(digitalRead(buttonPinDown)==HIGH)
  {
    if (minupg==0)
    {
      minupg=59;
    }
    else
    {
      minupg=minupg-1;
    }
  }
  lcd.setCursor(0,0);
  lcd.print("Dakika:");
  lcd.setCursor(0,1);
  lcd.print(minupg,DEC);
  delay(200);
}
  
void DisplaySetYear()
{
// sene ayari
  if(digitalRead(buttonPinUp)==HIGH)
  {    
    yearupg=yearupg+1;
  }
   if(digitalRead(buttonPinDown)==HIGH)
  {
    yearupg=yearupg-1;
  }
  lcd.setCursor(0,0);
  lcd.print("Yili girin:");
  lcd.setCursor(0,1);
  lcd.print(yearupg,DEC);
  delay(200);
}

void DisplaySetMonth()
{
// ay ayari
  if(digitalRead(buttonPinUp)==HIGH)
  {
    if (monthupg==12)
    {
      monthupg=1;
    }
    else
    {
      monthupg=monthupg+1;
    }
  }
   if(digitalRead(buttonPinDown)==HIGH)
  {
    if (monthupg==1)
    {
      monthupg=12;
    }
    else
    {
      monthupg=monthupg-1;
    }
  }
  lcd.setCursor(0,0);
  lcd.print("Ayi girin:");
  lcd.setCursor(0,1);
  lcd.print(monthupg,DEC);
  delay(200);
}

void DisplaySetDay()
{
// gun ayari
  if(digitalRead(buttonPinUp)==HIGH)
  {
    if (dayupg==31)
    {
      dayupg=1;
    }
    else
    {
      dayupg=dayupg+1;
    }
  }
   if(digitalRead(buttonPinDown)==HIGH)
  {
    if (dayupg==1)
    {
      dayupg=31;
    }
    else
    {
      dayupg=dayupg-1;
    }
  }
  lcd.setCursor(0,0);
  lcd.print("Gunu girin:");
  lcd.setCursor(0,1);
  lcd.print(dayupg,DEC);
  delay(200);
}

void StoreAgg()
{
// RTC'ye kayit
  lcd.setCursor(0,0);
  lcd.print("Kaydediyor");
  lcd.setCursor(0,1);
  lcd.print("...........");
  delay(1000);
  RTC.adjust(DateTime(yearupg,monthupg,dayupg,hourupg,minupg,0));
  delay(200);
}

