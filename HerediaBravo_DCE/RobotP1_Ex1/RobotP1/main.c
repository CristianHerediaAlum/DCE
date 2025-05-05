/*
 * RobotP1.c
 *
 * Created: 05/05/2025 9:36:20
 * Author : crist
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

#include "../../DCE_libraries/MACROS.h"

int main(void)
{
	// Set as output
	SETBIT(DDRB, PORTB2);
    /* Replace with your application code */
    while (1) 
    {
		TOGGLEBIT(PORTB, PORTB2);
		_delay_ms(200);
    }
}

