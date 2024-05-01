#include "../../LIB/Bit_utilies.h"
#include "../../LIB/TM4C123.h"
#include "UART.h"

void UART1_Init(){
	SYSCTL_PRUART_R |= SYSCTL_PRUART_R1;
	SYSCTL_RCGCGPIO_R |=SYSCTL_RCGCGPIO_R1;
	while((SYSCTL_PRUART_R & SYSCTL_PRUART_R1) == 0);
	GPIO_PORTA_AFSEL_R |= 0x3;
	GPIO_PORTA_PCTL_R |= GPIO_PCTL_PB0_U1RX | GPIO_PCTL_PB1_U1TX;
	GPIO_PORTA_DEN_R |= 0x3;
	UART1_CTL_R &= ~UART_CTL_UARTEN;
	UART1_IBRD_R = 104;
	UART1_FBRD_R = 11;
	UART1_LCRH_R = (UART_LCRH_WLEN_8 | UART_LCRH_FEN);
	UART1_CTL_R |= (UART_CTL_RXE | UART_CTL_TXE | UART_CTL_UARTEN);
}




void UART_Write (char data)
{
	 while ((UART5_FR_R&0x0020) !=0){};
	 UART5_DR_R = data;
}

void UART_Send_String( char* string )
{                       
	 while (*string){		 
		UART_Write(*string);
		string++;
	 }	
}

char UART_GetChar(void)
{
	while ((UART5_FR_R&0x0010) !=0){}; // waits until reciever FIFO is full to recieve the data
	return (char)(UART5_DR_R & 0xFF);  // returns the 8 bits of the data
}	

 void UART_recieve_String( char* string, int size ) 
{                 
	 int i;
	 for ( i = 0 ; i < size; i++)
		string [i] = UART_GetChar();											 									
}
 










