/*
 * USART.h
 *
 * Created: 17/03/2025 11:34:08
 *  Author: DCE
 */ 


#ifndef USART_H_
#define USART_H_

#ifndef F_CPU
#undef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <stdbool.h>

#define BAUD 9600
#define UBRR_VALUE ((F_CPU/(16UL*BAUD)) - 1)

void USART0_putchar(unsigned char data);
void USART0_putString(char *strPointer);
unsigned char USART0_getchar();
bool USART0_getchar_not_blocking(unsigned char *data);

static inline void USART0_init() {
    UBRR0H = (unsigned char)(UBRR_VALUE >> 8);
    UBRR0L = (unsigned char) UBRR_VALUE;

    UCSR0B |= (1 << RXEN0) | (1 << TXEN0);

    UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);
}

static inline void USART_TX_enable() {
    UCSR0B |= (1<<UDRIE0); // Enable the ISR of TX;
    // sei();
}

static inline void USART_TX_disable() {
    UCSR0B &= ~(1<<UDRIE0); // Enable the ISR of TX;

}


static inline void USART_RX_enable() {
    UCSR0B |= (1<<RXCIE0); // Enable the ISR of RX;
    // sei();
}

static inline void USART_RX_disable() {
    UCSR0B &= ~(1<<RXCIE0); // Enable the ISR of RX;
    // sei();
}


#endif /* USART_H_ */