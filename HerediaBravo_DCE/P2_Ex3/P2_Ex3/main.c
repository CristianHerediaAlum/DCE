/*
 * P2_Ex3.c
 *
 * Created: 24/02/2025 8:54:43
 * Author : DCE
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRD |= (1<<DDD3);	PORTD |= (1<<PORTD2);
	
    /* Replace with your application code */
    while (1) 
    {
		if(!(PIND & (1 << PIND2)))
			PORTD |= (1<<PORTD3);
		else
			PORTD &= (~(1<<PORTD3));
    }
}

