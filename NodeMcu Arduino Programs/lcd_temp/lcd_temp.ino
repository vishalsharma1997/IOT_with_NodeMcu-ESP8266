#include<Wire.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,16,2); //first parameter address , and 16 x 2 lcd
#include "DHT.h"
#define DHTTYPE DHT11

#define dht_pin 0
DHT dht(dht_pin , DHTTYPE);

//----------------------------------------------------------------------------------------
void setup() {
  // put your setup code here, to run once:
  dht.begin();
  Serial.begin(9600);
  Serial.print("Humidity and Temperature  :- \n\n");
  lcd.init(); //initial
  lcd.backlight();
  delay(700);
}
//----------------------------------------------------------------------------------------
void loop() {
  // put your main code here, to run repeatedly:
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Serial.print("\nCurrent Humidity = ");
  Serial.print(h);
  Serial.print("% ");
  Serial.print("Temperature = ");
  Serial.print(t);
  Serial.print("C");
  lcd.setCursor(0,0);
  lcd.print("Temp = ");
  lcd.print(t);
  lcd.print(" C");
  lcd.setCursor(0,1);
  lcd.print("HUMID = ");
  lcd.print(h);
  lcd.print("% ");
  delay(800);
}
