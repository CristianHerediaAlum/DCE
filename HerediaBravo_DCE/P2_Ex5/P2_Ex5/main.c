/*
 * P2_Ex5.c
 *
 * Created: 24/02/2025 12:00:23
 * Author : DCE
 */ 

//#include <avr/io.h>
#define F_CPU 16000000UL
#include "AVR_PORTS.h"
#include <util/delay.h>


int main(void)
{
	DDRD |= (1 << DDD3);
	PORTD |= (1 << 2);
    
	while (1) 
    {
		if(!(PIND & (1 << DDD2)))
			PORTD ^= (1 << DDD3);
		_delay_ms(500);
    }
    /* 168 Bytes en total */
}

