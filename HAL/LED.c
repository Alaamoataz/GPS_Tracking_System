#include "../Lib/Bit_utilies.h"
#include "../Lib/TM4C123.h"
#include "../MCAL/GPIO/GPIO.h"
#include "LED.h"

void Led_Switch_Init(void)
{
    GPIO_init_PORTF();
    Set_direction_PORTF(BLUE_LED ,OUTPUT);   
    Set_direction_PORTF(GREEN_LED ,OUTPUT);   
    Set_direction_PORTF(RED_LED ,OUTPUT);   
    Set_direction_PORTF(switch1 ,INPUT);   
    Set_direction_PORTF(switch2 ,INPUT);   
    
}

void LED_On(unsigned char Led_Colour)
{
    
    switch(Led_Colour)
    {
        case BLUE_LED:
        SET_BIT(GPIO_PORTF_DATA_R, BLUE_LED);
        break;
        case GREEN_LED:
        SET_BIT(GPIO_PORTF_DATA_R, GREEN_LED);
        break;
        case RED_LED:
        SET_BIT(GPIO_PORTF_DATA_R, RED_LED);
        break;
    }
}

void LED_Off(unsigned char Led_Colour)
{
    switch(Led_Colour)
    {
        case BLUE_LED:
        CLR_BIT(GPIO_PORTF_DATA_R, BLUE_LED);
        break;

        case GREEN_LED:
        CLR_BIT(GPIO_PORTF_DATA_R, GREEN_LED);
        break;

        case RED_LED:
        CLR_BIT(GPIO_PORTF_DATA_R, RED_LED);
        break;
    }
}


void LED_TOG(unsigned char Led_Colour)
{
    switch(Led_Colour)
    {
        case BLUE_LED:
        TOG_BIT(GPIO_PORTF_DATA_R , BLUE_LED);
        break;

        case GREEN_LED:
        TOG_BIT(GPIO_PORTF_DATA_R , GREEN_LED);
        break;

        case RED_LED:
        TOG_BIT(GPIO_PORTF_DATA_R , RED_LED);
        break;
    }
}


unsigned char Switch_input(unsigned char switch_no)
{
    switch(switch_no)
    {
        case switch1: return GET_BIT(GPIO_PORTF_DATA_R,switch1); break;
        case switch2: return GET_BIT(GPIO_PORTF_DATA_R,switch2); break;
    }   
}
