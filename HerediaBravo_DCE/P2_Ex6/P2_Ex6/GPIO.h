/*
 * GPIO.h
 *
 * Created: 24/02/2025 12:36:11
 *  Author: DCE
 */ 

#include <avr/io.h>
#include <stdint.h>

#ifndef GPIO_H_
#define GPIO_H_

typedef enum {INPUT, OUTPUT} GPIO_direction_t;
typedef enum {HIGH, LOW} GPIO_value_t;
typedef enum {ON, OFF} GPIO_pullup_t;
	
void GPIO_init(volatile uint8_t *port, uint8_t pin, GPIO_direction_t direction);

void GPIO_pullup(volatile uint8_t *port, uint8_t pin, GPIO_pullup_t pull);

uint8_t GPIO_read(volatile uint8_t *port, uint8_t pin);

void GPIO_write(volatile uint8_t *port, uint8_t pin, GPIO_value_t digitalValue);

void GPIO_toggle(volatile uint8_t *port, uint8_t pin);
 

#endif /* GPIO_H_ */