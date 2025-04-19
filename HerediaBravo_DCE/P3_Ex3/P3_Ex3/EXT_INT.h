/*
 * EXT_INT.h
 *
 * Created: 10/03/2025 12:01:37
 *  Author: DCE
 */ 


#ifndef EXT_INT_H_
#define EXT_INT_H_

#include <avr/io.h>
#include <avr/interrupt.h>

#define LOW_LEVEL 0 // Decimal value equivalent to ICS01=0 and ICS00=0
#define CHANGE 1 // Decimal value equivalent to ICS01=0 and ICS00=1
#define FALLING 2 // Decimal value equivalent to ICS01=1 and ICS00=0
#define RISING 3 // Decimal value equivalent to ICS01=1 and ICS00=1

static inline void INT0_config (uint8_t typeTrigger)
{
	EICRA |= typeTrigger;
}

static inline void INT0_enable() {
    EIMSK |= (1<<INT0); // Enable the ISR of INT0;
    sei();
}

static inline void INT0_disable() {
    EIMSK &= ~(1<<INT0); // Disable the ISR of INT0;
}

static inline void INT1_config (uint8_t typeTrigger)
{
	EICRA |= (typeTrigger << 2);
}

static inline void INT1_enable() {
    EIMSK |= (1<<INT1); // Enable the ISR of INT0;
    sei();
}

static inline void INT1_disable() {
    EIMSK &= ~(1<<INT1); // Disable the ISR of INT0;
}



#endif /* EXT_INT_H_ */