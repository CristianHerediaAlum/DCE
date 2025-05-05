/*
 * PORTS.h
 *
 * Created: 28/10/2024 11:31:31
 *  Author: miria
 */ 


#ifndef PORTS_H_
#define PORTS_H_

#include <avr/io.h>

#define GPIO_0_mode	DDRD
#define GPIO_0_in	PIND
#define GPIO_0_out	PORTD

#define BUTTON_INTRO PORTD3
#define BUTTON_MODE PORTD2
#define	LED_MODE PORTB0
#define LED_LIGHT PORTB1

static inline void GPIO_init(){
	//--------------------------------------------
	//	1. Set pin as output for the LED
	PORTB |= (1 << LED_MODE) | (1 << LED_LIGHT);
	//---------------------------------------------
	/// 2. Enable pull-up for the PUSHBUTTON
	GPIO_0_out	 |= (1<<BUTTON_INTRO) | (1 << BUTTON_MODE);
	//---------------------------------------------
}

#endif /* PORTS_H_ */