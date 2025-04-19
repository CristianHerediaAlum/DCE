/*
 * P2_Ex4.c
 *
 * Created: 24/02/2025 9:43:49
 * Author : DCE
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRD |= (1 << DDD1) | (1 << DDD2) | (1 << DDD3) | (1 << DDD4);
	
	PORTD |= (1 << PORTD0);
    /* Replace with your application code */
    while (1) 
    {
		if(! (PIND & (1 << PIND0)))
		{
			PORTD |= (1 << PORTD1) | (1 << PORTD2) | (1 << PORTD3) | (1 << PORTD4);
			_delay_ms(500);
			PORTD &= (~(1 << PORTD1)) & (~(1 << PORTD2)) & (~(1 << PORTD3)) & (~(1 << PORTD4));
			//PORTD ^= (1 << PORTD1) | (1 << PORTD2) | (1 << PORTD3) | (1 << PORTD4);
			_delay_ms(500);
						
		}
		else {
			PORTD &= (~(1 << PORTD2)) & (~(1 << PORTD4));	
			PORTD |= (1 << PORTD1) | (1 << PORTD3);
		}
    }
}

