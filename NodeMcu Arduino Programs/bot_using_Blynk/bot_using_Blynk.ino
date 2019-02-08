#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define ledPin1 16
#define ledPin2 5
#define ledPin3 4
#define ledPin4 0

char auth[] = "54bfa60254dc49c5b0ec267a72859472";

char ssid[] = "aec";
char password[] = "";

void setup() 
{
  Serial.begin(9600);
  delay(10);
  Blynk.begin(auth,ssid,password);
  pinMode(ledPin1 , OUTPUT);
  pinMode(ledPin2 , OUTPUT);
  pinMode(ledPin3 , OUTPUT);
  pinMode(ledPin4 , OUTPUT);
}
BLYNK_WRITE(V1)
{
  int x = param[0].asInt();
  int y = param[1].asInt();
  if(y > 650)
  {
    forward();
  }
  else if(y < 400)
  {
    backward();
  }
  else if(x > 650)
  {
    right();
  }
  else if(x < 400)
  {
    left();
  }
  else
  {
    stop1();
  }
}
void loop() 
{
  Blynk.run();
}

void forward()
{
 digitalWrite(ledPin1 , HIGH);
 digitalWrite(ledPin2 , LOW);
 digitalWrite(ledPin3 , HIGH);
 digitalWrite(ledPin4 , LOW);
}
void backward()
{
 digitalWrite(ledPin1 , LOW);
 digitalWrite(ledPin2 , HIGH);
 digitalWrite(ledPin3 , LOW);
 digitalWrite(ledPin4 , HIGH);
}
void right()
{
 digitalWrite(ledPin1 , HIGH);
 digitalWrite(ledPin2 , LOW);
 digitalWrite(ledPin3 , LOW);
 digitalWrite(ledPin4 , LOW);
}
void left()
{
 digitalWrite(ledPin1 , LOW);
 digitalWrite(ledPin2 , LOW);
 digitalWrite(ledPin3 , HIGH);
 digitalWrite(ledPin4 , LOW);
}
void stop1()
{
 digitalWrite(ledPin1 , LOW);
 digitalWrite(ledPin2 , LOW);
 digitalWrite(ledPin3 , LOW);
 digitalWrite(ledPin4 , LOW);
}
