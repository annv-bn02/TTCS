#include "header.h"

hw_timer_t *Timer0_Cfg = NULL;
uint32_t Freq = 0;
uint8_t flag_pause = 0;
uint32_t count_timer = 0;

void IRAM_ATTR check_status()
{
  flag_pause = 1;
  count_timer++;
  if ( count_timer == 10000)
  {
    count_timer = 0;
  }
}

void Setup_Timer()
{
  Timer0_Cfg = timerBegin(0, 8000, true);
  timerAttachInterrupt(Timer0_Cfg, &check_status, true);
  timerAlarmWrite(Timer0_Cfg, 100, true); //100ms
  timerAlarmEnable(Timer0_Cfg);
}
