#include "header.h"
#include "control_device.h"

uint8_t auto_mode_living_room = 0;
uint8_t flag_fan_living_room = 0;
uint8_t flag_light_living_room = 0;

void Setup_Device_Living_Room()
{
    pinMode( LIVING_FAN_PIN, OUTPUT);
    // digitalWrite( living_fan, HIGH);

    pinMode( LIVING_LIGHT_PIN, OUTPUT);
    // digitalWrite( living_light, HIGH);

}

void Auto_Living_Room()
{
    if ( Night() == 1)
    {
        flag_light_living_room = 1;
    }
    else 
    {
        flag_light_living_room = 0;
    }
    if ( t >= 30 )
    {
        flag_fan_living_room = 1;
    }
    else 
    {
        flag_fan_living_room = 0;
    }
}

void Manual_Button_Living_Room()
{
    if ( Check_Button2() == 1)
    {
        auto_mode_living_room = 0;
        flag_fan_living_room = !flag_fan_living_room;        
    }
    if ( Check_Button3() == 1)
    {
        auto_mode_living_room = 0;
        flag_light_living_room = !flag_light_living_room;
    }
}

void Control_Device_Living_Room()
{
    if ( flag_fan_living_room == 1 ) digitalWrite( LIVING_FAN_PIN, HIGH);
    else digitalWrite( LIVING_FAN_PIN, LOW);

    if ( flag_light_living_room == 1 ) digitalWrite( LIVING_LIGHT_PIN, HIGH);
    else digitalWrite( LIVING_LIGHT_PIN, LOW);
}


