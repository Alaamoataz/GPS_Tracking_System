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
GPS_read();
        GPS_format();

        currentLat = to_degree(currentLat);
        currentLong = to_degree(currentLong);

        tot_distance += distance(lat1, long1, currentLat, currentLong);
        lat1 = currentLat;
        long1 = currentLong;

        if (tot_distance >= 100 || (GPIO_PORTF_DATA_R & SW1) == 0) {
            RGB(GREEN_LED);
            break;
        }