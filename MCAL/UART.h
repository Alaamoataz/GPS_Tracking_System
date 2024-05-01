#ifndef UART
#define UART


void UART1_Init();
void UART_Write (char data);
char UART_GetChar  (void);
void UART_recieve_String( char* string , int size);
void UART_Send_String( char* string);

#endif





