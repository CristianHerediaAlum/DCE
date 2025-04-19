/*
 * P2_Ex6.c
 *
 * Created: 24/02/2025 12:31:58
 * Author : DCE
 */ 
#define F_CPU 16000000UL 
#include <avr/io.h>
#include "GPIO.h"
#include <util/delay.h>

int main(void)
{
	GPIO_init(&DDRD, 3, OUTPUT);
	GPIO_pullup(&PORTD, 2, ON);
    // Parte 1, uso 148 Bytes
    while (1) 
    {
		//if(GPIO_read(&PIND,2))
			//GPIO_write(&PORTD, 3, HIGH);
		//else
			//GPIO_write(&PORTD, 3, LOW);		
		if(GPIO_read(&PIND,2))
			GPIO_toggle(&PORTD, 3);
    }
}


void GPIO_init(volatile uint8_t *port, uint8_t pin, GPIO_direction_t direction) {
	if (direction == INPUT)
		*port &= ~(1 << pin);
	else if (direction == OUTPUT)
		*port |= (1 << pin);
}

void GPIO_pullup(volatile uint8_t *port, uint8_t pin, GPIO_pullup_t pull) {
	if(pull == ON)
		*port |= (1 << pin);
	else if(pull == OFF)
		*port &= ~(1 << pin);
}

uint8_t GPIO_read(volatile uint8_t *port, uint8_t pin) {
	return !(*port &(1 << pin));
}

void GPIO_write(volatile uint8_t *port, uint8_t pin, GPIO_value_t digitalValue) {
	if(digitalValue == LOW)
		*port &= ~(1 << pin);
	else if(digitalValue == HIGH)
		*port |= (1 << pin);
}

void GPIO_toggle(volatile uint8_t *port, uint8_t pin) {
	*port ^= (1 << pin);
}