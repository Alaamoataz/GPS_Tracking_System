#ifndef UART_H
#define UART_H

#include "../LIB/tm4c123gh6pm.h"
#include "UART.h"
#include "SYSTICK.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

	



void uart2_init(){ // for gps
	unsigned BRD;
	
    SYSCTL_RCGCUART_R |= 0X04; // activate UART2
    SYSCTL_RCGCGPIO_R |= 0X08; //  activate port D
        
    UART2_CTL_R &= ~(0X0001);   // disable UART
    UART2_IBRD_R = 104;  
    UART2_FBRD_R = 11;
	
	GPIO_PORTD_LOCK_R = GPIO_LOCK_KEY;  // Unlock port D
    GPIO_PORTD_CR_R |= 0xC0;  // Allow changes to PD7-PD6
	GPIO_PORTD_AFSEL_R |= 0XC0; // enable alt function PD7, PD6
	GPIO_PORTD_PCTL_R = (GPIO_PORTD_PCTL_R & 0X00FFFFFF) | 0X11000000; // configure uart for pa0,pa1
	  
    UART2_CC_R = 0; 	   // use system clock
	UART2_LCRH_R = 0x60; // 8-bit word length, no Fifo , no parity, 1 stop bit
	UART2_CTL_R = 0X0301;  // enable RXE,TXE AND UART
	
	GPIO_PORTD_DEN_R |= 0XC0;  // enable digital IO on PD6,PD7
	GPIO_PORTD_AMSEL_R &= ~0XC0; // disable analog function on PD6, PD7
		
	delayMillis(1);
		 
}

void uart0_init(){
 SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART_R0;
 SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R0;

UART0_CTL_R &= ~ UART_CTL_UARTEN;
UART0_IBRD_R = 104;  
UART0_FBRD_R = 11;
UART0_LCRH_R |= (UART_LCRH_WLEN_8 | UART_LCRH_FEN)  ;
UART0_CTL_R = (UART_CTL_RXE | UART_CTL_TXE | UART_CTL_UARTEN);
  
GPIO_PORTA_AFSEL_R |= 0x03;
GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R &= ~0xFF)|(GPIO_PCTL_PA1_U0TX|GPIO_PCTL_PA0_U0RX);
GPIO_PORTA_DEN_R |= 0x03;
GPIO_PORTA_AMSEL_R &= ~0x03;  
}





void uart2_send_byte(char c)
{
	while((UART2_FR_R & 0x20) != 0);  
	UART2_DR_R = c; 					
}


char uart2_read_byte(void)
{
	char c;
	
	while((UART2_FR_R & 0x10) != 0);  
	c = UART2_DR_R; 					
	
	return c; 
}

void uart0_send_byte(char data){
  while((UART0_FR_R & UART_FR_TXFF)==UART_FR_TXFF){};
    UART0_DR_R = data;
}

void Uart0_output_string(char* pt){
	while(*pt){
		uart0_send_byte(*pt);
		pt++;
	}
}

// fun to send string to UART0
void UART0SendString(const char *str) {
    while (*str) {
        while ((UART0_FR_R & UART_FR_TXFF) != 0);  // Wait until the transmitter is not full
        UART0_DR_R = *str;  // Transmit the character
        str++;
    }
}

// fun to send float to UART0
void UART0SendFloat(float num) {
		
    int i;
    char buffer[50];
    snprintf(buffer, sizeof(buffer), "%f", num);

   for( i=0 ; buffer[i] != '\0'; i++) {
        while((UART0_FR_R & UART_FR_TXFF)==UART_FR_TXFF); // Wait until the transmitter is not full
        UART0_DR_R = buffer[i]; // Transmit the character
    }
}

#endif