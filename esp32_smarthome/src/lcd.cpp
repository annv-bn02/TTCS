#include "header.h"

LiquidCrystal_I2C lcd(0x27, 16, 2); 
void Start_Lcd()
{ 
    lcd.init();            
    lcd.backlight();
}

void Print_Temp()
{
  Temp_Update();
  lcd.setCursor(0, 0);
  lcd.print("Temp:");
  if ( t < 10 && t > -10)
  {
    lcd.print(" ");
  }
  lcd.print(t);
  lcd.print("C  ");
}

void Print_Gas()
{
  Gas_Update();
  lcd.setCursor(0, 1);
  lcd.print("Gas:");
  if ( gas < 10 )
  {
    lcd.print(" 0");
  }
  else if ( gas >= 10 && gas <= 99)
  {
    lcd.print(" ");
  }
  lcd.print(gas);
  lcd.print("%");
}

void Print_Funtion()
{
  lcd.setCursor(11, 1);
  if ( auto_mode_kitchen == 1 && auto_mode_living_room == 1)
  {
    lcd.print(" ATA");
  }
  else if ( auto_mode_kitchen == 1)
  {
    lcd.print(" ATKC");
  }
  else if ( auto_mode_living_room == 1)
  {
    lcd.print(" ATLR");
  }
  else
  {
    lcd.setCursor(11, 1);
    lcd.print("TC   ");
  }
}