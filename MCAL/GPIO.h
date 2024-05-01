#ifndef GPIO
#define GPIO



//============================================================================  

/* for pins */

#define PIN0 		0
#define PIN1		1
#define PIN2		2
#define PIN3		3
#define PIN4		4
#define PIN5		5
#define PIN6		6
#define PIN7		7

//============================================================================  

/* Pins Value */

#define OUTPUT		1
#define INPUT		0
#define HIGH		1
#define LOW			0

 
//============================================================================  

#define GPIO_LOCK_KEY				0x4C4F434B
#define GPIO_ENABLE_8_BIT			0x000000FF	
#define GPIO_PCTL_VALUE				0x00000000

//============================================================================

void GPIO_init_PORTF();
void GPIO_init_PORTB();
void Set_direction_PORTF(unsigned char Pin_no , unsigned char Pin_dir);

//============================================================================ 

#endif
