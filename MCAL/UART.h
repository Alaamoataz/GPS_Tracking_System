#ifndef UART_H
#define UART_H
#include <stdint.h>

void uart2_init();
void uart0_init();
void Uart5_init(void);
void uart5_send_byte(char c);
void Uart5_output_string(char* pt);
void uart2_send_byte(char c);
char uart2_read_byte(void);
void uart0_send_byte(char data);
void Uart0_output_string(char* pt);
void UART0SendFloat(float num);
void UART0SendString(const char *str);


#endif