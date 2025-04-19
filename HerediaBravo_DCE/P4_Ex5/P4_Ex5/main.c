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

ISR(INT0_vect) {
	USART0_putString("Hello world\r\n");
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

