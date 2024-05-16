#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../MCAL/GPIO.h"/
#include "../HAL/LED.h"
#include "../MCAL/UART.h"
#include "../MCAL/SYSTICK.h"
#include "../HAL/GPS.H" 
#include "../LIB/tm4c123gh6pm.h"



double tot_distance=0;
double DISTANCE=0;

// points coordinates
double lat1=0;
double long1=0;
extern float currentLat;
extern float currentLong;
extern float Speed ; 

	int main(){
		
    SYSTICKTIMER_init();
    portF_init();
    uart2_init();
    uart0_init();

    RGB_set(0x2);
    delayMillis(3000);
    RGB(0X00);
    delayMillis(1000*15);
    RGB(0x0E);
    delayMillis(3000);
    RGB(0X00);

    // get start point
    RGB(RED_LED);

    GPS_read();
    GPS_format();
    lat1 = to_degree(currentLat);
    long1 = to_degree(currentLong);

    while(1) {
        GPS_read();
        GPS_format();
			
				currentLat = to_degree(currentLat);
        currentLong = to_degree(currentLong);
			
				UART0SendFloat(currentLat);	
				UART0SendString(",");
				UART0SendFloat(currentLong);	
				UART0SendString("\n");
			
	      if(Speed > 2){
				DISTANCE = distance(lat1 , long1 , currentLat , currentLong);
				if (DISTANCE < 5 ){
        tot_distance += DISTANCE;
        lat1 = currentLat;
        long1 = currentLong;
				}
				}
				
			

        if (tot_distance >= 100 || (GPIO_PORTF_DATA_R & SW1) == 0) {
            RGB(GREEN_LED);
       
        }
    }
}

