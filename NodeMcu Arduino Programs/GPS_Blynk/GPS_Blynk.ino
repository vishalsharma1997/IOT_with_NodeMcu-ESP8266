#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

static const int RXPin = 4, TXPin = 5;
static const uint32_t GPSBaud = 9600;
TinyGPSPlus gps;; // The TinyGPS++ Project
WidgetMap myMap(V5); // V0 for virtual pin of map Widget
SoftwareSerial ss(RXPin,TXPin);
BlynkTimer timer;
float spd;
float sats;
String bearing;
char auth[] = "981435b61f724552bc51ba6ab865d968";
char ssid[] = "ITS DANGEROUS";
char pass[] = "@13111997@";
unsigned int move_index = 1;

void setup()
{
  Serial.begin(115200);
  Serial.println();
  ss.begin(GPSBaud);
  Blynk.begin(auth,ssid,pass);
  timer.setInterval(5000L, checkGPS);
  Serial.print("No. of connected satellites : ");
  Serial.println(gps.charsProcessed() );
   Serial.print("ss.availbale() : ");
  Serial.println(ss.available() );
   Serial.print("gps.location.isValid() : ");
  Serial.println(gps.location.isValid());
}

void checkGPS()
{
  if(gps.charsProcessed() < 10)
  {
    Serial.println(F("No GPS Detected : check wiring..."));
    Blynk.virtualWrite(V4, "GPS ERROR " );
  }
}

void loop()
{
  while(ss.available() > 0)
  {
    if(gps.encode(ss.read()))
    displayInfo();
  }
  Blynk.run();
  timer.run();
}

void displayInfo()
{
  if(gps.location.isValid())
  {
    float latitude = (gps.location.lat());
    float longitude = (gps.location.lng());
    Serial.print("\nLAT : ");
    Serial.println(latitude,6);
    Serial.print("\LONG : ");
    Serial.println(longitude,6);
    Blynk.virtualWrite(V0,String(latitude,6));
    Blynk.virtualWrite(V1,String(longitude,6));
    myMap.location(move_index , latitude ,longitude , "GPS_Located");
    spd = gps.speed.kmph();
    Blynk.virtualWrite(V2,spd);

    sats=gps.satellites.value();
    Blynk.virtualWrite(V3,sats);

    bearing = TinyGPSPlus::cardinal(gps.course.value());
    Blynk.virtualWrite(V4,bearing);
  }
  Serial.print("");
}
