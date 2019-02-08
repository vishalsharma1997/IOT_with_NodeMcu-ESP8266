#include<Wire.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,16,2); //first parameter address , and 16 x 2 lcd

char str1[10]="VISHAL123";
char str2[10]="SHARMA";


void setup() {
  // put your setup code here, to run once:
 // lcd.begin(); //to begin the lcd

    lcd.init(); //initial
    lcd.backlight();
    lcd.setCursor(0,0);
    lcd.print(str1);
    lcd.setCursor(0,1);
    lcd.print(str2);
}

void loop() {
  // put your main code here, to  run repeatedly:

}
