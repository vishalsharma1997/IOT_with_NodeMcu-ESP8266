
#define D0 16

void setup() {
  // put your setup code here, to run once:
  
}

void loop() {
  // put your main code here, to run repeatedly:

  for(int i=0;i<=255;i+=5)
  {
    analogWrite(D0,i);
    delay(30);
  }
  
  for(int i=255;i>=0;i-=5)
  {
    analogWrite(D0,i);
    delay(30);
  }

}
