
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "DHT.h"
#define DHTTYPE DHT11

#define dht_pin 0
DHT dht(dht_pin , DHTTYPE);

char auth[] = "71e6c99b08fc412f864415e075c28c77";

char ssid[] = "ITS DANGEROUS";
char password[] = "@13111997@";
float h,t;

//----------------------------------------------------------------------------------------
void setup() {
  // put your setup code here, to run once:
  dht.begin();
  Serial.begin(9600);
  delay(10);
  Blynk.begin(auth,ssid,password);
  Serial.print("Humidity and Temperature  :- \n\n");
  delay(700);
}
//----------------------------------------------------------------------------------------

BLYNK_READ(V1) //Blynk app has something on V5
{
  if(!isnan(h))
  Blynk.virtualWrite(V1, h); //sending to Blynk
  else
  Blynk.virtualWrite(V1, "Failed to read the value");
}
BLYNK_READ(V2) //Blynk app has something on V5
{
  if(!isnan(t))
  Blynk.virtualWrite(V2, t);
  else
  Blynk.virtualWrite(V2, "Failed to read the value");//sending to Blynk
}
void loop() {
  Blynk.run();
  // put your main code here, to run repeatedly:
  h = dht.readHumidity();
  t = dht.readTemperature();
  Serial.print("\nCurrent Humidity = ");
  Serial.print(h);
  Serial.print("% ");
  Serial.print("Temperature = ");
  Serial.print(t);
  Serial.print("C");
 // Blynk.virtualWrite(V1, h);
 // Blynk.virtualWrite(V2, t);
  delay(800);
}
