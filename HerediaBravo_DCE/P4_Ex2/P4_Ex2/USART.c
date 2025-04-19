/*
 * USART.c
 *
 * Created: 17/03/2025 11:34:21
 *  Author: DCE
 */ 

#include "USART.h"


void USART0_putchar(unsigned char data) {
    while(!(UCSR0A & (1 << UDRE0)));
    UDR0 = data;
}

void USART0_putString(char *strPointer) {
    while(*strPointer) {
        USART0_putchar(*strPointer);
        strPointer++;
    }
}

unsigned char USART0_getchar() {
    while(!(UCSR0A & (1 << RXC0)));
    return UDR0;
}
