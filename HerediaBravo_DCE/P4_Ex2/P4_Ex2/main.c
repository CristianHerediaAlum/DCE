/*
 * P4_Ex2.c
 *
 * Created: 17/03/2025 11:33:15
 * Author : DCE
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include "USART.h"


int main(void)
{
    unsigned char c;
    USART0_init();
    USART0_putString("Funciona\n\r");
    while (1) 
    {
        USART0_putchar(USART0_getchar());
    }
}