
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
  delay(800);
}
