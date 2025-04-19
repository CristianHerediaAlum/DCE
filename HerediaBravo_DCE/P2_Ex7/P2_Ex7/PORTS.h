/*
 * PORTS.h
 *
 * Created: 03/03/2025 9:22:05
 *  Author: DCE
 */ 


#ifndef PORTS_H_
#define PORTS_H_

#include <avr/io.h>

#define GPIO_0_mode DDRD
#define GPIO_0_in PIND
#define GPIO_0_out PORTD

#define LED 3
#define BUTTON 2
#define PRESSED 0

#endif /* PORTS_H_ */