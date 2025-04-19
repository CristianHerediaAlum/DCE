/*
 * USART.h
 *
 * Created: 17/03/2025 11:34:08
 *  Author: DCE
 */ 


#ifndef USART_H_
#define USART_H_

#define F_CPU 16000000UL


#include <avr/io.h>

#define BAUD 9600
#define UBRR_VALUE ((F_CPU/(16UL*BAUD)) - 1)

void USART0_putchar(unsigned char data);
void USART0_putString(char *strPointer);
unsigned char USART0_getchar();

static inline void USART0_init() {
    UBRR0H = (unsigned char)(UBRR_VALUE >> 8);
    UBRR0L = (unsigned char) UBRR_VALUE;

    UCSR0B |= (1 << RXEN0) | (1 << TXEN0);

    UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);
}


#endif /* USART_H_ */