/*
 * P4_Ex6.c
 *
 * Created: 26/04/2025 18:26:54
 * Author : crist
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "../../DCE_libraries/USART.h"

volatile char tx_data;

ISR(USART_RX_vect) {
    char received = USART0_getchar();
	
	if(received >= 'a' && received <= 'z' ) {
		received -= ('a' - 'A');
	}
	tx_data = received;
	USART_TX_enable();
}

ISR(USART_UDRE_vect) {
	USART0_putchar(tx_data);
	USART_TX_disable();
}

int main(void)
{
	USART0_init();
	sei();
	USART_RX_enable();
    /* Replace with your application code */
    while (1) 
    {
    }
}

