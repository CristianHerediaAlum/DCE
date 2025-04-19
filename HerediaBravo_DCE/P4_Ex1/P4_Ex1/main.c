/*
 * P4_Ex1.c
 *
 * Created: 17/03/2025 10:18:46
 * Author : DCE
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define BAUD 9600
#define UBRR_VALUE ((F_CPU/(16UL*BAUD)) - 1)

void USART0_putchar(unsigned char data);
void USART0_putString(char *strPointer);

int main(void)
{
	UBRR0H = (unsigned char)(UBRR_VALUE >> 8);
    UBRR0L = (unsigned char) UBRR_VALUE;

    UCSR0B |= (1 << RXEN0) | (1 << TXEN0);

    UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);
    while (1) 
    {
        USART0_putString("Hello world \n\r");
    }
}

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