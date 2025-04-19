/*
 * P2_Ex1.c
 *
 * Created: 10/02/2025 12:23:44
 * Author : DCE
 */ 
// Define CPU frequency as 16 MHz
#define F_CPU 16000000UL
// Registers definition
#include <avr/io.h>
// Time utilities
#include <util/delay.h>
#include "SETUP.h"

int main(void)
{
	DDRD |=(1<<DDD3);
    /* Replace with your application code */
    while (1) 
    {
		PORTD &=~(1<<PORTD3);
		
		_delay_ms(BLINK_TIME + 1000);
		
		PORTD |=(1<<PORTD3);
		
		_delay_ms(BLINK_TIME);		
    }
}