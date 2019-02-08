#include<ESP8266WiFi.h>
#include "ThingSpeak.h"
#include <DHT.h>
#define DHTPIN 0
DHT dht(DHTPIN,DHT11);

unsigned long myChannelNumber = 481906;
const char* myWriteAPIKey = "K9L0NYN3P6E93SH2";
const char* server = "api.thingspeak.com";
const char* ssid = "Moto G (5) Plus 3604";
const char* password="krishnradha";

WiFiClient client;

void setup() {
  Serial.begin(115200);
  delay(10);
  dht.begin();
  
  Serial.print("\n\nConnecting to...");
  Serial.println(ssid);

  WiFi.begin(ssid,password);
  
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi Connected");
  ThingSpeak.begin(client);


}

void loop() {
  delay(1500);
  float dht_t = dht.readHumidity();
  float dht_h = dht.readTemperature();
  if(isnan(dht_t) || isnan(dht_h))
  {
    Serial.println("\nFailed to read from DHT11");
    delay(1000);
    return;
  }
  else
  {
    Serial.print("\nDHT11 Temperature = ");
    Serial.print( dht_t );
    Serial.print(" C ");
    Serial.print("\tDHT11 Humidity = ");
    Serial.print( dht_h );
    Serial.println(" % ");
  }
  if(client.connect(server , 80))
  {
    ThingSpeak.setField(1,dht_t);
    ThingSpeak.setField(2,dht_h);
    ThingSpeak.writeFields(myChannelNumber , myWriteAPIKey);
    delay(1000);
  }
}
