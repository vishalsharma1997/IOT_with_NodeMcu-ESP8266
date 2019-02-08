#include<Wire.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,16,2); //first parameter address , and 16 x 2 lcd

char str1[17]="VISHAL";
char str2[17]="SHARMA";


void setup() {
  // put your setup code here, to run once:
 // lcd.begin(); //to begin the lcd
  lcd.init(); //initial
  lcd.backlight();
 
}
int i = 0;
void loop() {
  lcd.clear();
  lcd.setCursor((i++)%16,0);
  lcd.print(str1);
  lcd.setCursor((i-1)%16,1);
  lcd.print(str2);
  delay(400);
}
