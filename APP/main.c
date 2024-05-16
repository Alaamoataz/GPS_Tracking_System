#include "../MCAL/GPIO/GPIO.h"
#include "../MCAL/UART/UART.h"
#include "../HAL/LED/LED.h"

int main()
{
    unsigned char SW1_button_in;
    unsigned char SW2_button_in;
    Led_Switch_Init();
    while (1)
    {
      SW1_button_in=Switch_input(switch1);
      SW2_button_in=Switch_input(switch2);

      if(SW1_button_in==0 || SW2_button_in==0)
      {
        LED_On(BLUE_LED);
      }
      else {LED_Off(BLUE_LED);}      
		}
    
}