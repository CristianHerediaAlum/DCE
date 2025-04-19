/*
 * P4_Ex4.c
 *
 * Created: 17/03/2025 12:50:33
 * Author : DCE
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include "PORTS.h"
#include "../../DCE_libraries/USART.h"
#include "../../DCE_libraries/EXT_INT.h"
#include "../../DCE_libraries/MACROS.h"


ISR(INT0_vect) {
	static char c = 0x20;
	if(c > 0x7E)
		c = 0x20;
	else {
		USART0_putchar(c);
		c++;
	}
}

ISR(USART_RX_vect) {
	// uint8_t data = USART0_getchar();
	// USART0_putchar(data);
	// // Mantenemos lo que habia en los 3 bits anteriores
	// PORTD = (PORTD & 0x0F) | ((data & 0x0F) << 3);
	// PORTD = (data << 4);
}

int main(void)
{
	GPIO_init();
	USART0_init();
	
	USART0_putString("Funciona\n\r");
	INT0_enable();
	INT0_config(FALLING);
	USART_RX_enable();
	
	sei();
    /* Replace with your application code */
	while (1) 
	{
	   uint8_t data = USART0_getchar();
	   USART0_putchar(data);
	   // Mantenemos lo que habia en los 3 bits anteriores
	   // PORTD = (PORTD & 0x0F) | ((data & 0x0F) << 3);
   }
}

