#include "DHT.h"
#define DHTTYPE DHT11
#define dht_pin 0
#include<Wire.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,16,2);
DHT dht(dht_pin,DHTTYPE);
void setup() {
  // put your setup code here, to run once:
dht.begin();
Serial.begin(9600);
lcd.init();//initial

}

void loop() {
  // put your main code here, to run repeatedly:
 float h=dht.readHumidity();
  float t=dht.readTemperature();
  lcd.backlight();
lcd.setCursor(0,0);
lcd.print(h);
lcd.setCursor(0,1);
lcd.print("t");
   
}

