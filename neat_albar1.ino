#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(38,16,2);
byte button1=6;
byte button2=7;
 int counter1=0;
int counter2=0;
int reading1=0;
int reading2=0;
byte array[8]={
  B10000,
  B11000,
  B11100,
  B11110,
  B11110,
  B11100,
  B11000,
  B10000
};
void setup()
{
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  lcd.init();
  lcd.backlight();
  lcd.createChar(0,array);
  lcd.setCursor(0,0);
  lcd.write(byte(0));
  lcd.setCursor(2,0);
  lcd.print("Select Program");
   lcd.setCursor(2,1);
  lcd.print("Settings");
}
void loop()
{
reading1=digitalRead(button1);
reading2=digitalRead(button2);  
  if(!reading2){
 counter2++;
    if(counter2==1){
      lcd.clear();
      lcd.setCursor(0,1);
  lcd.write(byte(0));
  lcd.setCursor(2,0);
  lcd.print("Select Program");
   lcd.setCursor(2,1);
  lcd.print("Settings");
    }
        if(counter2==2){
      lcd.clear();
      lcd.setCursor(0,1);
  lcd.write(byte(0));
  lcd.setCursor(2,0);
  lcd.print("Settings");
   lcd.setCursor(2,1);
  lcd.print("Power Saving");
    }
         if(counter2>=3){
      lcd.clear();
      lcd.setCursor(0,1);
  lcd.write(byte(0));
  lcd.setCursor(2,0);
  lcd.print("Power Saving");
   lcd.setCursor(2,1);
  lcd.print("Shut down");
    }
  delay(250);
  }  
  if(!reading1){
    counter1++;
    if(counter1==1&&counter2>=3){
          lcd.clear();
      lcd.setCursor(0,0);
  lcd.write(byte(0));
  lcd.setCursor(2,0);
  lcd.print("Power Saving");
   lcd.setCursor(2,1);
  lcd.print("Shut down");
    counter2=2;  
    }
      if(counter1==2 && counter2==2){
          lcd.clear();
      lcd.setCursor(0,0);
  lcd.write(byte(0));
  lcd.setCursor(2,0);
  lcd.print("Settings");
   lcd.setCursor(2,1);
  lcd.print("Power Saving");
        counter2=1; 
    }
      if(counter1>=3 && counter2==1){
          lcd.clear();
      lcd.setCursor(0,0);
  lcd.write(byte(0));
  lcd.setCursor(2,0);
  lcd.print("Select Program");
   lcd.setCursor(2,1);
  lcd.print("Settings");
  counter1=0;
         counter2=0;
    }
 delay(250);
  }
  
}