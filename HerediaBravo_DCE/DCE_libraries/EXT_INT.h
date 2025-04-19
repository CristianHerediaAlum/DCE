/*
 * EXT_INT.h
 *
 * Created: 17/03/2025 9:12:02
 *  Author: DCE
 */ 


#ifndef EXT_INT_H
#define EXT_INT_H

#include <avr/io.h>
#include <avr/interrupt.h>


#define LOW_LEVEL 0
#define CHANGE 1
#define FALLING 2
#define RISING 3

static inline void INT0_config(uint8_t typetrigger) {
    EICRA |= typetrigger;
}

static inline void INT0_enable() {
    EIMSK |= (1<<INT0); // Enable the ISR of INT0;
    // sei();
}

static inline void INT0_disable() {
    EIMSK &= ~(1<<INT0); // Disable the ISR of INT0;
}

static inline void INT1_config (uint8_t typeTrigger)
{
	EICRA |= (typeTrigger << 2);
}

static inline void INT1_enable() {
    EIMSK |= (1<<INT1); // Enable the ISR of INT1;
    // sei();
}

static inline void INT1_disable() {
    EIMSK &= ~(1<<INT1); // Disable the ISR of INT1;
}




#define PCINT_enable(ADDRESS) (PCICR |= (1 << ADDRESS))
#define PCINT_disable(ADDRESS) (PCICR &= ~(1 << ADDRESS))
#define PCINT0_pinSelect(ADDRESS) (PCMSK0 |= (1 << ADDRESS))
#define PCINT1_pinSelect(ADDRESS) (PCMSK1 |= (1 << ADDRESS))
#define PCINT2_pinSelect(ADDRESS) (PCMSK2 |= (1 << ADDRESS))



#endif /* EXT_INT_H */