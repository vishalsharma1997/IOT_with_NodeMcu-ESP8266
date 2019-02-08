#include<Servo.h>
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

Servo  servo;

char auth[] = "fe6d7e330d50483bb46d5f4a54bd0e44";

char ssid[] = "ITS DANGEROUS";
char password[] = "@13111997@";

int i;

void setup() {
  Serial.begin(9600);
  delay(10);
  Blynk.begin(auth,ssid,password);
  servo.attach(2); //D4
  servo.write(0); // set to 0 degree
}

BLYNK_WRITE(V1)
{
  servo.write(param.asInt());
}

void loop() {
  Blynk.run();
  
}
