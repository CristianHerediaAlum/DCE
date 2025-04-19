/*
 * P2_Ex2.c
 *
 * Created: 17/02/2025 12:10:11
 * Author : DCE
 */ 

#define F_CPU 16000000UL // Define CPU frequency as 16 MHz


#include <avr/io.h>

#include <util/delay.h>

#include "SETUP.h"

int main(void)
{
	DDRD |= (1 << DDD0) | (1 << DDD1) | (1 << DDD2) | (1 << DDD3);
	PORTD = 0;
    /* Replace with your application code */
	uint8_t cont = 0;
    while (1) 
    {
		if(cont > 15)
			cont = 0;
		PORTD = cont;
		_delay_ms(BLINK_TIME);
// 		PORTD = 0;
// 		_delay_ms(BLINK_TIME);
		cont++;
	}
}

