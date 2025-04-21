#ifndef TMR1_H
#define TMR1_H

#define DIV_CLK_1 1
#define DIV_CLK_8 2
#define DIV_CLK_64 3
#define DIV_CLK_256 4
#define DIV_CLK_1024 5

#include <avr/io.h>
#include <avr/interrupt.h>
#include "MACROS.h"

void static inline TMR1_CTC_init() {
    // Compare match
    // TCCR1A |= (1 << COM1A0);

    // CTC
    TCCR1B &= ~(1 << WGM13);
    TCCR1B |= (1 << WGM12);
    TCCR1A &= ~(1 << WGM11) & ~(1 << WGM10);

    TCNT1 = 0;
}

void static inline TMR1_CTC_enaInterrupt() {
    TIMSK1 |= (1 << OCIE1A);
}

void static inline TMR1_CTC_disInterrupt() {
    TIMSK1 &= ~(1 << OCIE1A);
}

void static inline TMR1_CTC_Start(uint8_t divClock) {
    // TCNT1 = 0;
    
    // Clear
    TCCR1B &= 0xF8;
    TCCR1B |= (divClock & 0x07);
}

void static inline TMR1_CTC_Stop() {
    TCCR1B &= 0xF8;
}

void static inline TMR1_CTC_Set(uint16_t valueCounterA) {
    OCR1A = valueCounterA;
}

void static inline TMR1_HW_toggleOC1A() {
    TOGGLEBIT(TCCR1A, COM1A0);
}


#endif // TMR1_H