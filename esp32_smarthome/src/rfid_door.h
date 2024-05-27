#ifndef _RFID_DOOR_H_
#define _RFID_DOOR_H_

#include <Arduino.h>


#define OPEN_DOOR 1
#define CLOSE_DOOR 2
#define DOOR_CLOSE 0

extern uint8_t flag_checkRFID;
extern int count_wrong;
extern uint8_t flag_open_door;
extern uint8_t door;

void Setup_Door();
void Start_RFID();
void Check_RFID();
void Open_Door();
void Close_Door();
void Wrong_RFID();
void Door_Light_Control();  



#endif



