/*
 * P4_Ex5.c
 *
 * Created: 06/04/2025 17:57:57
 * Author : crist
 */ 
#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include "PORTS.h"
#include "../../DCE_libraries/USART.h"
#include "../../DCE_libraries/EXT_INT.h"
#include "../../DCE_libraries/MACROS.h"

volatile char *message = "Hello world\n\r";
volatile uint8_t tx_index = 0;

ISR(INT0_vect) {
	// Parte a)
	// USART0_putString("Hello world\r\n");
	// Parte b)
	tx_index = 0;
	 //UDR0 = message[tx_index];
	//tx_index++;
	USART_TX_enable();
}

ISR(USART_UDRE_vect) {
	if (message[tx_index] != '\0') {
		USART0_putchar(message[tx_index]);
		tx_index++;
	}
	else {
		USART_TX_disable();  // Mensaje terminado, desactivamos interrupción
	}
}


int main(void)
{
	USART0_init();
	GPIO_init();
	
	INT0_enable();
	INT0_config(FALLING);
	
	sei();
	
    /* Replace with your application code */
    while (1) 
    {
    }
}

