#include "header.h"

// ntc
const double VCC = 3.3; 
const double R2 = 10000;
const double adc_resolution = 4095; 
const double A = 0.001129148;
const double B = 0.000234125;
const double C = 0.0000000876741; 
float t = 0; 
float gas = 0;
uint8_t light = 0;
uint8_t prox = 0;
float cnt_temp_data = 0, cnt_gas_data = 0;


void Setup_Sensor()
{
    pinMode(PIN_LIGHT, INPUT);
    pinMode(PIN_PROX, INPUT);
}
void Temp ()
{
    float Vout, Rth, adc_value; 
    adc_value = analogRead(PIN_NTC);
    Vout = (adc_value * VCC) / adc_resolution;
    Rth = (VCC * R2 / Vout) - R2;
    adc_value = (1 / (A + (B * log(Rth)) + (C * pow((log(Rth)),3))));  
    adc_value = adc_value - 273.15;
    cnt_temp_data += adc_value;
}

void Temp_Update(){
  t = cnt_temp_data / 50;
  cnt_temp_data = 0;
}

void Gas()
{
  int x = analogRead(PIN_GAS) - 2095; // 2095 ~ 4095
  cnt_gas_data += x;
}

void Gas_Update()
{
  cnt_gas_data /= 50;
  if ( cnt_gas_data <= 0)
  {
    gas = 0;
  }
  else 
  {
    gas = cnt_gas_data / 20;
  }
  cnt_gas_data = 0;
}

int Night()
{
  light = digitalRead(PIN_LIGHT);
    if (light == 1) // trời tối
    {
        return 1;
    }
    return 0;
}
