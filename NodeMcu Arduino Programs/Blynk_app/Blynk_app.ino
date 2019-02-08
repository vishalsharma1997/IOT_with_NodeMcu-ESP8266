#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "20d8cf98365d435591f581532ae3b629";

char ssid[] = "ITS DANGEROUS";
char pass[] = "@13111997@";

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth,ssid,pass);
}

void loop() {
  Blynk.run();

}
