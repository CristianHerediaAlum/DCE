/*
 * P3_Ex3.c
 *
 * Created: 10/03/2025 10:18:27
 * Author : DCE
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "PORTS.h"
#include "MACROS.h"

#define MAX_INCREMENT 4

volatile uint8_t cont = 0;
volatile uint8_t increment = 1;

ISR(INT0_vect) {
	
    cont += increment;
	if(increment >= 4)
		increment = 1;
	increment++;	
	
    _delay_ms (200); // Not recommended!!
}

int main(void)
{
    /// ------------ SETUP ----------------------------------------
    /// -----------------------------------------------------------
    /// 1.- Configure ports
    /// -----------------------------------------------------------
    GPIO_init();
    /// -----------------------------------------------------------
    /// 2.- Configure external interrupt
    /// -----------------------------------------------------------
    EICRA = (1<<ISC01) |(0<<ISC00) | // INT0 is triggered by a falling edge
    (0<<ISC11) |(0<<ISC10); // INT1 is set as default value (0)
    EIMSK |= (1<<INT0); // Enable the ISR of INT0;
    /// -----------------------------------------------------------
    /// 3.- Enable global interrupts
    /// -----------------------------------------------------------
    sei(); // Equivalent to SREG |=(1<<I);
    ///------------ LOOP ----------------------------------------
    while (1) {
		if(cont > 15) {
			cont = 0;
            PORTD = PUSHBUTTON;
        }
	    /// -----------------------------------------------------------
	    /// 1.- Toggle the green LD
	    /// 
		PORTD = (PORTD & 0x00)|(cont << 4);

	    SETBIT(GPIO_0_out, PUSHBUTTON);
	    cont++;
		
	    _delay_ms(500);
    }
}

