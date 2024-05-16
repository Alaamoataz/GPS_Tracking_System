#ifndef LED
#define LED


#define RED_LED 	 	1
#define BLUE_LED		2
#define GREEN_LED	    3

#define switch1         4
#define switch2         0

void Led_Switch_Init(void);
void LED_On(unsigned char Led_Colour);
void LED_Off(unsigned char Led_Colour);	
void LED_Tog(unsigned char Led_Colour); 
unsigned char Switch_input(unsigned char switch_no);  
    
