/*
 * P1_Ex1.c
 *
 * Created: 10/02/2025 10:06:40
 * Author : DCE
 */ 

#define F_CPU 16000000UL // Define CPU frequency as 16 MHz 

#include <avr/io.h>
#include <util/delay.h>
#include "SETUP.h"


int main(void) {
	// --------------------------- SETUP ----------------------------
	//---------------------------------------
	// 1. Set pin 5 in port “B” as output pin
	//---------------------------------------
	DDRB |=(1<<DDB5);
	//----------------------------- LOOP ------------------- --------
	while (1) {
		//--------------------------------------------
		// 1.- LED OFF by clearing the pin 5 in port B
		//--------------------------------------------
		PORTB &=~ (1<<PORTB5);
		//---------------------------------------
		// 2.- Delay of BLINK_TIME milli-seconds
		//---------------------------------------
		_delay_ms(BLINK_TIME);
		//------------------------------------------------
		// 3.- LED ON by setting the pin 5 in port B
		//------------------------------------------------
		PORTB |=(1<<PORTB5);
		//---------------------------------------
		// 4.- Delay of BLINK_TIME milli-seconds
		//---------------------------------------
		_delay_ms(BLINK_TIME);
		//---------------------------------------
	}
}
