#include<ESP8266WiFi.h>

const char* ssid = "ITS DANGEROUS";
const char* password="@13111997@";

int ledPin1 = 16;
int ledPin2= 5;
int ledPin3 = 4;
int ledPin4 = 0;

WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  delay(10);

  pinMode(ledPin1,OUTPUT);
  pinMode(ledPin2,OUTPUT);
  pinMode(ledPin3,OUTPUT);
  pinMode(ledPin4,OUTPUT);
  digitalWrite(ledPin1,LOW);
  digitalWrite(ledPin2,LOW);
  digitalWrite(ledPin3,LOW);
  digitalWrite(ledPin4,LOW);

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

if(request.indexOf("/MOVE=UP")!=-1)
 {
  digitalWrite(ledPin1 , HIGH);
  digitalWrite(ledPin2 , LOW);
  digitalWrite(ledPin3 , HIGH);
  digitalWrite(ledPin4 , LOW);
 }
if(request.indexOf("/MOVE=DOWN")!=-1)
 {
  digitalWrite(ledPin1 , LOW);
  digitalWrite(ledPin2 , HIGH);
  digitalWrite(ledPin3 , LOW);
  digitalWrite(ledPin4 , HIGH);
 }
if(request.indexOf("/MOVE=RIGHT")!=-1)
 {
  digitalWrite(ledPin1 , HIGH);
  digitalWrite(ledPin2 , LOW);
  digitalWrite(ledPin3 , LOW);
  digitalWrite(ledPin4 , LOW);
 }
if(request.indexOf("/MOVE=LEFT")!=-1)
 {
  digitalWrite(ledPin1 , LOW);
  digitalWrite(ledPin2 , LOW);
  digitalWrite(ledPin3 , HIGH);
  digitalWrite(ledPin4 , LOW);
 }
 if(request.indexOf("/MOVE=STOP")!=-1)
 {
  digitalWrite(ledPin1 , LOW);
  digitalWrite(ledPin2 , LOW);
  digitalWrite(ledPin3 , LOW);
  digitalWrite(ledPin4 , LOW);
 }
 client.println("HTTP/1.1 200 OK");
 client.println("Content-Type: text/html");
 client.println("");
 client.println("<!DOCTYPE HTML>");
 client.println("<html>");
 client.println("<head><title>My Node Mcu Project </title>");

client.println("<style>");
client.println(".button {");
    client.println("background-color: #4CAF50; /* Green */");
    client.println("border: none;");
    client.println("color: white;");
    client.println("padding: 16px 32px;");
    client.println("text-align: center;");
    client.println("text-decoration: none;");
    client.println("display: inline-block;");
    client.println("font-size: 16px;");
    client.println("margin: 4px 2px;");
    client.println("-webkit-transition-duration: 0.4s; /* Safari */");
    client.println("transition-duration: 0.4s;");
    client.println("cursor: pointer;");
    client.println("}");
    

client.println(".button1 {");
    client.println("background-color: white; ");
    client.println("color: black; ");
    client.println("border: 2px solid #4CAF50;");
client.println("}");

client.println(".button1:hover {");
    client.println("background-color: #4CAF50;");
    client.println("color: white;");
client.println("box-shadow: 0 12px 16px 0 rgba(0,0,0,0.24), 0 17px 50px 0 rgba(0,0,0,0.19);");
client.println("}");

client.println(".button2 {");
    client.println("background-color: white; ");
    client.println("color: black; ");
    client.println("border: 2px solid #008CBA;");

client.println("}");

client.println(".button2:hover {");
    client.println("background-color: #008CBA;");
client.println("color: white;");
client.println("box-shadow: 0 12px 16px 0 rgba(0,0,0,0.24), 0 17px 50px 0 rgba(0,0,0,0.19);");

client.println("}");

client.println(".button3 {");
    client.println("background-color: white; ");
    client.println("color: black; ");
    client.println("border: 2px solid #f44336;");
client.println("}");

client.println(".button3:hover {");
    client.println("background-color: #f44336;");
    client.println("color: white;");
client.println("box-shadow: 0 12px 16px 0 rgba(0,0,0,0.24), 0 17px 50px 0 rgba(0,0,0,0.19);");
client.println("}");

client.println(".button4 {");
    client.println("background-color: white;");
    client.println("color: black;");
    client.println("border: 2px solid #e7e7e7;");
client.println("}");

client.println(".button4:hover {background-color: #e7e7e7;");
client.println("box-shadow: 0 12px 16px 0 rgba(0,0,0,0.24), 0 17px 50px 0 rgba(0,0,0,0.19);}");

client.println(".button5 {");
    client.println("background-color: white;");
    client.println("color: black;");
    client.println("border: 2px solid #555555;");
client.println("}");

client.println(".button5:hover {");
    client.println("background-color: #555555;");
    client.println("color: white;");
client.println("box-shadow: 0 12px 16px 0 rgba(0,0,0,0.24), 0 17px 50px 0 rgba(0,0,0,0.19);");
client.println("}");
client.println("</style>");

client.println("</head>");
client.println("<body bgcolor=\"yellow\">");
client.println("<h2>The Buttons Are :-</h2>");
client.println("<br><br>");
client.println("<center>");
client.println("<img src= \"http://i.imgur.com//uZFCLgS.gif\" width=\"400\" height=\"200\">");
client.println("<br>");
client.println("<Font size = \"100\">");
client.println("<a href=\"/MOVE=UP\"\"><button class=\"button button1\"> UP </button></a> ");
client.println("<br>");
client.println("<a href=\"/MOVE=LEFT\"\"><button class=\"button button3\"> LEFT</button></a>");
client.println("<a href=\"/MOVE=STOP\"\"><button class=\"button button2\"> STOP</button></a>");
client.println("<a href=\"/MOVE=RIGHT\"\"><button class=\"button button4\"> RIGHT</button></a>");
client.println("<br>");
client.println("<a href=\"/MOVE=DOWN\"\"><button class=\"button button5\"> DOWN</button></a>");
client.println("<br>");

client.println("</center>");

client.println("</Font>");

client.println("</body>");
client.println("</html>");
  delay(1);
  Serial.println("Client Disconnected !!!");
  Serial.println("");
}

