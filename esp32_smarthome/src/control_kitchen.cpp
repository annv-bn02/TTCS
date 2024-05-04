#include "header.h"
#include "control_device.h"

uint8_t auto_mode_kitchen = 0;
uint8_t flag_fan_kitchen = 0;
uint8_t flag_light_kitchen = 0;

void Setup_Device_Kitchen()
{
    pinMode( KITCHEN_FAN_PIN, OUTPUT);
    // digitalWrite( kitchen_fan, HIGH);

    pinMode( KITCHEN_LIGHT_PIN, OUTPUT);
    // digitalWrite( kitchen_light, HIGH);
}
void Auto_Kitchen()
{
    if ( gas >= 20 )
    {
        flag_fan_kitchen = 1;
    }
    if ( gas <= 5)
    {
        flag_fan_kitchen = 0;
    }

    if ( Night() == 1)
    {
        flag_light_kitchen = 1;
    }
    else 
    {
        flag_light_kitchen = 0;
    }
}

void Manual_Button_Kitchen()
{
    if ( Check_Button4() == 1)
    {
        auto_mode_kitchen = 0;
        flag_fan_kitchen = !flag_fan_kitchen;
    }
    if ( Check_Button5() == 1)
    {
        auto_mode_kitchen = 0;
        flag_light_kitchen = !flag_light_kitchen;
    }
}

void Control_Device_Kitchen()
{
    if ( flag_fan_kitchen == 1 ) digitalWrite( KITCHEN_FAN_PIN, HIGH);
    else digitalWrite( KITCHEN_FAN_PIN, LOW);

    if ( flag_light_kitchen == 1 ) digitalWrite( KITCHEN_LIGHT_PIN, HIGH);
    else digitalWrite( KITCHEN_LIGHT_PIN, LOW);
}


