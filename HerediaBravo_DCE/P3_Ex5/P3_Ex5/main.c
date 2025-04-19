/*
 * P3_Ex5.c
 *
 * Created: 17/03/2025 8:55:58
 * Author : DCE
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "PORTS.h"
#include "MACROS.h"
#include "INTERRUPTS.h"


ISR(PCINT2_vect) {
    if(READ_PIN(GPIO_0_in, PUSHBUTTON) == PRESSED)
        TOGGLEBIT(GPIO_0_out, LED_PIN);
}


int main(void)
{
	GPIO_init();
	
	// PCICR |= (1 << PCIE2);
	// PCMSK2 |= (1 << PCINT18);

    PCINT_enable(PCIE2);
    PCINT2_pinSelect(PCINT18);

    sei();

    while (1) 
    {
        _delay_ms(200);
        TOGGLEBIT(GPIO_0_out, GREEN_LED_PIN);
    }
}

