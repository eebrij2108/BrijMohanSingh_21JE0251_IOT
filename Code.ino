#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);


void setup() 
{
  pinMode(5,OUTPUT);
  pinMode(4,INPUT);
  pinMode(3,INPUT);
  pinMode(2, INPUT); 
  Serial.begin(9600);
  lcd.begin(20, 4);
  // set up the LCD's number of columns and rows:
  lcd.setCursor(0,0);
  lcd.print("HOME SECURITY");
  lcd.setCursor(0,1);
  lcd.print("PERSON:");
  lcd.setCursor(0,2);
  lcd.print("DOOR VIB:");
  lcd.setCursor(0,3);
  lcd.print("MOTION :");
}

void loop()
{
  int statusSensorir = digitalRead(2);
  int vib = digitalRead(3);
  int motion = digitalRead(4);
  if (vib == 1)
  {
    lcd.setCursor(10,2);
    lcd.print("YES");
  }
  else{
    lcd.setCursor(10,2);
    lcd.print("NO ");
  }
  if (motion == 1)
  {
    lcd.setCursor(10,3);
    lcd.print("YES");
  }
  else{
    lcd.setCursor(10,3);
    lcd.print("NO ");
  }
  if (statusSensorir == 1){
    lcd.setCursor(10,1);
    lcd.print("YES");
  }
  else
  {
    lcd.setCursor(10,1);
    lcd.print("NO ");
  }
  if (motion==1 && vib==1 && statusSensorir==1){
    digitalWrite(5,HIGH);
  }
  else{
    digitalWrite(5,LOW);
  }  
}
