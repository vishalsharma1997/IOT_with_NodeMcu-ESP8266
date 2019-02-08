#include<Servo.h>

Servo  servo;
int i;

void setup() {
  servo.attach(2); //D4
  servo.write(0); // set to 0 degree
  delay(1000);
}

void loop() {
  servo.write(120);
  delay(2000);
  for(i=0;i<=10;i++)
  {
    servo.write(i*10);
    delay(1000);
  }
  for(i=10;i>=0;i--)
  {
    servo.write(i*10);
    delay(1000);
  }
  
}
