/*
 * AVR_PORTS.h
 *
 * Created: 24/02/2025 12:02:20
 *  Author: DCE
 */ 


#ifndef AVR_PORTS_H_
#define AVR_PORTS_H_
#include <stdint.h>


#define PORTD (*((volatile uint8_t *) 0x2B))

#define DDRD (*((volatile uint8_t *) 0x2A))

#define PIND (*((volatile uint8_t *) 0x29))

#define DDD3 3
#define DDD2 2
#define PIND2 2





#endif /* AVR_PORTS_H_ */