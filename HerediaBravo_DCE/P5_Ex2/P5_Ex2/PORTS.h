/*
 * PORTS.h
 *
 * Created: 28/10/2024 11:31:31
 *  Author: miria
 */ 


#ifndef PORTS_H_
#define PORTS_H_

#include <avr/io.h>

#define GPIO_0_mode	DDRB
#define GPIO_0_in	PINB
#define GPIO_0_out	PORTB

#define	 LED PORTB0

static inline void GPIO_init(){
	//--------------------------------------------
	//	1. Set pin as output for the LED
	GPIO_0_mode |= (1 << LED);
	//---------------------------------------------
	/// 2. Enable pull-up for the PUSHBUTTON
	// GPIO_0_out	 |= (1<<PUSHBUTTON);
	//---------------------------------------------
}

#endif /* PORTS_H_ */