#include "../../Lib/Bit_utilies.h"
#include "../../Lib/TM4C123.h"
#include "GPIO.h"
//============================================================================  

void GPIO_init_PORTF()
{
  SYSCTL_RCGCGPIO_R |= 0x20;   // Enable clock for Port F
  while((SYSCTL_PRGPIO_R & 0x20) == 0);   // Wait for Port F to be ready
	GPIO_PORTF_LOCK_R  = GPIO_LOCK_KEY;   							
	GPIO_PORTF_CR_R    = GPIO_ENABLE_8_BIT;						
	GPIO_PORTF_AFSEL_R = 0x00;  //Disable AFSEL
	GPIO_PORTF_AMSEL_R = 0x00;	//Disable AMSEL											
	GPIO_PORTF_PCTL_R  = GPIO_PCTL_VALUE; 						 
	GPIO_PORTF_DEN_R   = 0xFF;	//Digital Enable All Pins
	GPIO_PORTF_PUR_R = 0x11;	//Enable pull up to Pin0-4
}

//============================================================================

void GPIO_init_PORTB()
{
  SYSCTL_RCGCGPIO_R |= 0x02;   // Enable clock for Port B
  while((SYSCTL_PRGPIO_R & 0x02) == 0);   // Wait for Port B to be ready
	GPIO_PORTF_LOCK_R  = GPIO_LOCK_KEY; 							
	GPIO_PORTF_CR_R    = GPIO_ENABLE_8_BIT;						
	GPIO_PORTF_AFSEL_R = 0x00;	//Disable AFSEL
	GPIO_PORTF_AMSEL_R = 0x00;	//Disable AMSEL											
	GPIO_PORTF_PCTL_R  = GPIO_PCTL_VALUE; 						 
	GPIO_PORTF_DEN_R   = 0xFF;		//Digital Enable All Pins
}
   
//============================================================================  

void Set_direction_PORTF(unsigned char Pin_no , unsigned char Pin_dir)
{
	switch (Pin_dir)
	{
	//Make Pin Digital output
	case OUTPUT:
	SET_BIT(GPIO_PORTF_DIR_R , Pin_no);
	break;

	//Make Pin Digital input
	case INPUT :
	CLR_BIT(GPIO_PORTF_DIR_R , Pin_no);
	break;
	
	default:
	break;
	}
}