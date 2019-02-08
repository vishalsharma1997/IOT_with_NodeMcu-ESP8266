#include<ESP8266WiFi.h>

const char* ssid = "Moto G (5) Plus 3604";
const char* password="krishnradha";

int ledPin = 16;
WiFiServer server(80);

void setup() { 
  Serial.begin(115200);
  delay(10);

  pinMode(ledPin,OUTPUT);
  digitalWrite(ledPin,LOW);

  Serial.print("\n\nConnecting to...");
  Serial.println(ssid);

  WiFi.begin(ssid,password);
  
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi Connected");

  server.begin();
  Serial.print("Server Started\n");

  Serial.print("Use this URL to Connect : ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
}

void loop() {
 WiFiClient client = server.available();
 if(!client)
 {
  return;
 }

 Serial.println("New Client");
 while(!client.available())
 {
  delay(1);
 }

 String request = client.readStringUntil('\r');
 Serial.println(request);
 client.flush();

 int value=LOW;
 if(request.indexOf("/LED=ON")!=-1)
 {
  digitalWrite(ledPin , HIGH);
  value=HIGH;
 }
 if(request.indexOf("/LED=OFF")!=-1)
 {
  digitalWrite(ledPin , LOW);
  value=LOW;
 }
 client.println("HTTP/1.1 200 OK");
 client.println("Content-Type: text/html");
 client.println("");
 client.println("<!DOCTYPE HTML>");
 client.println("<html>");

 client.print("LED pin is now : ");

 if(value==HIGH)
 {
  client.print("ON");
 }
 else
 {
  client.print("OFF");
 }
 client.println("<br><br>");
 client.println("<a href=\"/LED=ON\"\"><button>Turn ON </button></a>");
 client.println("<a href=\"/LED=OFF\"\"><button>Turn OFF </button></a><br/>");
 client.println("</html>");

  delay(1);
  Serial.println("Client Disconnected !!!");
  Serial.println("");
  
}
