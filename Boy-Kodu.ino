#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int  trig = 6;
const int   echo = 7;
const int kalibButon = 8;
const int olcmeButon  =9;
int sure = 0;
int mesafe = 0;
int ilkmesafe;

void setup() {
  Serial.begin(9600);
   lcd.begin(16, 2);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(kalibButon, INPUT);
  pinMode(olcmeButon, INPUT);

  while (digitalRead(kalibButon) == LOW) 
{
    lcd.setCursor(2, 0);
    lcd.print("KALiBRASYON iCiN");
    lcd.setCursor(2, 1);
    lcd.print(" BUTONA BASINIZ ");
    delay(100);

    if (digitalRead(kalibButon) == HIGH) 
{
      delay(50);
      ilkmesafe = mesafeolc();
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("KALiBRASYON");
      lcd.setCursor(0, 1);
      lcd.print("YAPILDI");
      delay(2000);
      lcd.clear();
      break;
    }
  }
}


void loop() 
{
  if (digitalRead(olcmeButon) == HIGH) 
{
    int boy = 202 - mesafeolc();
    if(boy < 130 or boy > 200){
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Lutfen Butona");
      lcd.setCursor(0, 1);
      lcd.print("Tekrar basInIz"); 
      delay(2000);
    }
    else{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("BOYUNUZ");
    lcd.setCursor(0, 1);
    lcd.print(boy);
    lcd.setCursor(0, 2);
    delay(2000);
    lcd.clear();
    } 
  }
    else 
{
      lcd.setCursor(0, 0);
      lcd.print("   OLCUM iCiN   ");
      lcd.setCursor(0, 1);
      lcd.print(" BUTONA BASINIZ ");
      delay(100);
      lcd.clear();
    }
  }

  int mesafeolc() 
{
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig,LOW);
    sure = pulseIn(echo, HIGH);
    Serial.println(sure);
    mesafe = (sure / 2) / 28.25;
    return mesafe;
  }
