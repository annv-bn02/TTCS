#ifndef _CONTROL_DEVICE_H_
#define _CONTROL_DEVICE_H_

#include <Arduino.h>
extern uint8_t auto_mode_kitchen;
extern uint8_t auto_mode_living_room;
extern uint8_t auto_mode_all;
extern uint8_t flag_fan_living_room;
extern uint8_t flag_light_living_room;
extern uint8_t flag_fan_kitchen;
extern uint8_t flag_light_kitchen;
extern int living_fan;
extern int living_light;
extern int kitchen_fan;
extern int kitchen_light;

void Setup_Device_Kitchen();
void Setup_Device_Living_Room();
void Auto_Living_Room ();
void Auto_Kitchen();
void Manual_Button_Kitchen();
void Manual_Button_Living_Room();
void Control_Device_Kitchen();
void Control_Device_Living_Room();

#endif



