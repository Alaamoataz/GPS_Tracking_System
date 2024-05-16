#include "SYSTICK.h"
#include "../../LIB/Bit_utilies.h"
#include "../../LIB/TM4C123.h"


void Delay_s(unsigned int time)
{
    unsigned int ticks = 0;
    NVIC_ST_CTRL_R = 0;
    NVIC_ST_RELOAD_R = 16000000 - 1;
    NVIC_ST_CURRENT_R = 0;
    NVIC_ST_CTRL_R = 0x5;
    while(ticks > 0)
    {
        if((NVIC_ST_CTRL_R & 0x10000) != 0){
            ticks--;
        }
    }
}

void Delay_ms(unsigned int time)
{
    unsigned int ticks = 0;
    NVIC_ST_CTRL_R = 0;
    NVIC_ST_RELOAD_R = 16000 - 1;
    NVIC_ST_CURRENT_R = 0;
    NVIC_ST_CTRL_R = 0x5;
    while(ticks > 0)
    {
        if((NVIC_ST_CTRL_R & 0x10000) != 0){
            ticks--;
        }
    }
}

void Delay_us(unsigned int time)
{
    unsigned int ticks = 0;
    NVIC_ST_CTRL_R = 0;
    NVIC_ST_RELOAD_R = 16 - 1;
    NVIC_ST_CURRENT_R = 0;
    NVIC_ST_CTRL_R = 0x5;
    while(ticks > 0)
    {
        if((NVIC_ST_CTRL_R & 0x10000) != 0){
            ticks--;
        }
    }
}














