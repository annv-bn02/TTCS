#ifndef _MQTT_H_
#define _MQTT_H_

#include "Arduino.h"

typedef struct{
    float temp;
    int light;
    float gas;
    int prox;
    uint8_t flag_fan_living_room;
    uint8_t flag_light_living_room;
    uint8_t flag_fan_kitchen;
    uint8_t flag_light_kitchen;
    uint8_t auto_mode_kitchen;
    uint8_t auto_mode_living_room;
    uint8_t auto_mode_all;
    uint8_t door;
}mqtt_data_t;

void Setup_Wifi();
void Data_to_Json(mqtt_data_t data_send);
void Detext(String Str);
void MQTT_Pub();
void MQTT_Sub();
void callback(char *topic, byte *payload, unsigned int length);
void MQTT_Connect();
void Client_Loop();


#endif



