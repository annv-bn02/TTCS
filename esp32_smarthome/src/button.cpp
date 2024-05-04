#include "header.h"
#include "button.h"

uint8_t sttnew1 = 1;
uint8_t sttnew2 = 1;
uint8_t sttnew3 = 1;
uint8_t sttnew4 = 1;
uint8_t sttnew5 = 1;

void Setup_Button()
{
  pinMode(BUTTON_PIN_1, INPUT);
  pinMode(BUTTON_PIN_2, INPUT);
  pinMode(BUTTON_PIN_3, INPUT);
  pinMode(BUTTON_PIN_4, INPUT);
  pinMode(BUTTON_PIN_5, INPUT);
}

uint8_t Check_Button1()
{
  uint8_t sttold = sttnew1;
  sttnew1 = digitalRead(BUTTON_PIN_1);
  if ( sttold == 1 && sttnew1 == 0)
  {
    return 1;
  }
  return 0;
}

uint8_t Check_Button2()
{
  uint8_t sttold = sttnew2;
  sttnew2 = digitalRead(BUTTON_PIN_2);
  if ( sttold == 1 && sttnew2 == 0)
  {
    return 1;
  }
  return 0;
}

uint8_t Check_Button3()
{
  uint8_t sttold = sttnew3;
  sttnew3 = digitalRead(BUTTON_PIN_3);
  if ( sttold == 1 && sttnew3 == 0)
  {
    return 1;
  }
  return 0;
}

uint8_t Check_Button4()
{
  uint8_t sttold = sttnew4;
  sttnew4 = digitalRead(BUTTON_PIN_4);
  if ( sttold == 1 && sttnew4 == 0)
  {
    return 1;
  }
  return 0;
}

uint8_t Check_Button5()
{
  uint8_t sttold = sttnew5;
  sttnew5 = digitalRead(BUTTON_PIN_5);
  if ( sttold == 1 && sttnew5 == 0)
  {
    return 1;
  }
  return 0;
}
