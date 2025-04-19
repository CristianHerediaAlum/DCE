/*
 * P2_Ex5.c
 *
 * Created: 24/02/2025 12:00:23
 * Author : DCE
 */ 

//#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "PORTS.h"


int main(void)
{
	GPIO_0_mode |= (1 << LED);
	GPIO_0_out |= (1 << BUTTON);
    
	while (1) 
    {
		if(!(GPIO_0_in & (1 << BUTTON)))
			GPIO_0_out ^= (1 << LED);
		_delay_ms(500);
    }
    /* 168 Bytes en total */
}

