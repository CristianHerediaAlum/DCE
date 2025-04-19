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

#define	 FIRST_LED_PIN 6
#define	 SECOND_LED_PIN 5
#define	 THIRD_LED_PIN 4
#define	 LAST_LED_PIN 3
#define	 PUSHBUTTON	2
#define	 PRESSED	0

static inline void GPIO_init(){
	//--------------------------------------------
	//	1. Set pin as output for the LED
	GPIO_0_mode	 |= (1<<LAST_LED_PIN) | (1 <<THIRD_LED_PIN) | (1 << SECOND_LED_PIN) | (1 << FIRST_LED_PIN);
	//---------------------------------------------
	/// 2. Enable pull-up for the PUSHBUTTON
	GPIO_0_out	 |= (1<<PUSHBUTTON);
	//---------------------------------------------
}

#endif /* PORTS_H_ */