#include "header.h"

void Auto_Mode_Logical()
{
  if(auto_mode_kitchen != auto_mode_living_room) auto_mode_all = 0;
  else if(auto_mode_kitchen == 1 && auto_mode_living_room == 1) auto_mode_all = 1;
  if ( Check_Button1() == 1) auto_mode_all = 1;
  if (auto_mode_all == 1)
  {
    auto_mode_kitchen = 1;
    auto_mode_living_room = 1;
  }
  if ( auto_mode_kitchen == 1) Auto_Kitchen();
  if ( auto_mode_living_room == 1) Auto_Living_Room();
}

void setup() 
{
  Serial.begin(115200);
  Setup_Timer();
  Start_RFID ();
  Setup_Door();
  Start_Lcd();
  Setup_Button();
  Setup_Sensor();
  Setup_Device_Kitchen();
  Setup_Device_Living_Room();
  Setup_Wifi();
  MQTT_Connect();
  MQTT_Sub();
}
int count = millis(), count_sensor_update = 0;
uint8_t auto_mode_all = 0;
void loop() 
{
  count_sensor_update++;
  Sensor_Read_All();
  if(count_sensor_update == 50)
  {
    count_sensor_update = 0;
    Print_Temp();
    Print_Gas();
  }
  if(count + 1000 < millis())
  {
    count = millis();
    MQTT_Pub();
  }
  Client_Loop();
  Auto_Mode_Logical();
  if ( flag_pause == 1)
  {
    Check_RFID();
    Wrong_RFID();
    Door_Light_Control();
    // MQTT_Pub(); 
    if ( flag_open_door == OPEN_DOOR)
    {
      Open_Door();
    }
    else if(flag_open_door == CLOSE_DOOR && prox == 1)
    {
      Close_Door();
    }
    flag_pause = 0;
  }
  Print_Funtion();
  Manual_Button_Kitchen();
  Manual_Button_Living_Room();
  Control_Device_Kitchen();
  Control_Device_Living_Room();
}
