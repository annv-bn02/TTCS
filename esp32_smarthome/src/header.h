#ifndef _HEADER_H_
#define _HEADER_H_

#include <Arduino.h>
#include "RTClib.h"
#include <LiquidCrystal_I2C.h>


#include "rfid_door.h"
#include "button.h"
#include "control_device.h"
#include "mqtt.h"

#define PIN_GAS 36
#define PIN_LIGHT 25
#define PIN_NTC 39
#define PIN_PROX 2

#define SS_PIN 5
#define RST_PIN 0
#define DOOR_SERVO_PIN 12
#define DOOR_LIGHT_PIN 27
#define DOOR_BUZZER_PIN 14

#define BUTTON_PIN_1 35
#define BUTTON_PIN_2 26
#define BUTTON_PIN_3 32
#define BUTTON_PIN_4 33
#define BUTTON_PIN_5 34

#define LIVING_FAN_PIN 15
#define LIVING_LIGHT_PIN 4
#define KITCHEN_FAN_PIN 16
#define KITCHEN_LIGHT_PIN 17
extern uint8_t flag_pause;
extern uint32_t count_timer;

extern float t; 
extern float gas;
extern uint8_t light;
extern uint8_t prox;

extern String Home_Data;
extern String receive;
void IRAM_ATTR check_status();
void Setup_Timer();

void Setup_Sensor();
void Temp ();
void Temp_Update();
void Gas();
void Gas_Update();
int Night();

void Start_Lcd();
void Print_Temp();
void Print_Gas();
void Print_Funtion();




#endif



