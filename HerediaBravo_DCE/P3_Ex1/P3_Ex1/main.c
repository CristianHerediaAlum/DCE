/*
 * P3_Ex1.c
 *
 * Created: 10/03/2025 9:41:34
 * Author : DCE
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "PORTS.h"
#include "MACROS.h"
ISR(INT0_vect) {
    ///--------------------------------------------------------
    /// 1.- Toggle the red LED
    ///--------------------------------------------------------
    TOGGLEBIT (GPIO_0_out, RED_LED_PIN); // Toggle the RED_LED
    //--------------------------------------------------------------------
    // 2. To avoid a new interrupt due to a falling edge caused by bouncing
    //--------------------------------------------------------------------
    _delay_ms (200); // Not recommended!!
}


int main(void)
{
    /// ------------ SETUP ----------------------------------------
    /// -----------------------------------------------------------
    /// 1.- Configure ports
    /// -----------------------------------------------------------
    GPIO_init();
    /// -----------------------------------------------------------
    /// 2.- Configure external interrupt
    /// -----------------------------------------------------------
    EICRA = (1<<ISC01) |(0<<ISC00) | // INT0 is triggered by a falling edge
            (0<<ISC11) |(0<<ISC10); // INT1 is set as default value (0)
    EIMSK |= (1<<INT0); // Enable the ISR of INT0;
    /// -----------------------------------------------------------
    /// 3.- Enable global interrupts
    /// -----------------------------------------------------------
    sei(); // Equivalent to SREG |=(1<<I);
    ///------------ LOOP ----------------------------------------
    while (1) {
        /// -----------------------------------------------------------
        /// 1.- Toggle the green LD
        /// -----------------------------------------------------------
        TOGGLEBIT (GPIO_0_out, GREEN_LED_PIN);
        _delay_ms(500);
    }

}

