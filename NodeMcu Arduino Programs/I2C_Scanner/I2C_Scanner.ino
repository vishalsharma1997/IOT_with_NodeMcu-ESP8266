#include<Wire.h>


void setup() {
  Serial.begin(9600);
  while(!Serial)
  {
    
  }
  Serial.println("I2C Scanner . Scanning...");
  byte count=0;
  Wire.begin();
  for(byte i=0;i<128+;i++)
  {
    Wire.beginTransmission(i);
    if(Wire.endTransmission()==0)
    {
      Serial.print("\nFound Address : ");
      Serial.print(i,DEC);
      Serial.print("(0x");
      Serial.print(i,HEX);
      Serial.print(")");
      count++;
      delay(1);
    }
    
  }
    Serial.print("\n\t\t\tDONE !!!"); 
    Serial.print("\nFound ");
    Serial.print(count,DEC);
    Serial.print(" No. of Devices.");
    
}

void loop() {
  // put your main code here, to run repeatedly:

}
