
#define D0 16
const int AnalogInPin=A0;
int potValue;
float volts;


void setup() 
{
  // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(D0,OUTPUT);
 
}

void loop() 
{
  // put your main code here, to run repeatedly:
  potValue=analogRead(AnalogInPin);
  Serial.print("\npotValue is : ");
  Serial.print(potValue);
  volts=(potValue*3.3)/1023; // Here, 3.3 is the voltage.
  Serial.print("\tVolts : ");
  Serial.print(volts);
  if(potValue > 350)
  {
    digitalWrite(D0,HIGH);
    delay(potValue); //delay will change according to the potValue
    digitalWrite(D0,LOW);
    delay(potValue); //delay will change according to the potValue
  }
  else
  {
    digitalWrite(D0,LOW);
  }
}
  

