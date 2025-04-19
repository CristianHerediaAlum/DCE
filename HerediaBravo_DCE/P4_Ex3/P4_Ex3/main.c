/*
 * P4_Ex2.c
 *
 * Created: 17/03/2025 11:33:15
 * Author : DCE
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include "USART.h"

static inline void mainMenu();

int main(void)
{
    unsigned char c;
    USART0_init();
    USART0_putString("Funciona\n\r");
	mainMenu();
    while (1) 
    {
        // c = USART0_getchar();
        if(USART0_getchar_not_blocking(&c)) {
            switch (c)
            {
            case 'a':
            case 'b':
                USART0_putchar(c);
                break;
            case 'h':
                USART0_putchar('\f');
                mainMenu();
                break;
            default:
                USART0_putString("I don't know what key is it\n\r");
                break;
            }
        }
    }
}

static inline void mainMenu() {
    USART0_putString("-----------------------------------\n\r");
    USART0_putString("Select one choice:\n\r");
    USART0_putString("-----------------------------------\n\r");
    USART0_putString("a.- Choice a\n\r");
    USART0_putString("b.- Choice b\n\r");
    USART0_putString("\n\r");
    USART0_putString("h.- Show the menu again\n\r");
    USART0_putString("-----------------------------------\n\r");
}
