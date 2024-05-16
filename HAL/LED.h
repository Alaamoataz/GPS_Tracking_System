#ifndef LED_H
#define LED_H

#define RED_LED         0x02
#define BLUE_LED        0x04
#define GREEN_LED       0x08
#define RGB_LED         0x0E 
#define SW1             0x10 
#define SW2             0x01 

void RGB_set(char mask);
void RGB_clear(char mask);
void RGB(char colour);


#endif