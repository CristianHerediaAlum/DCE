/*
 * BUZZER.c
 *
 * Created: 05/05/2025 10:04:33
 *  Author: Cristian Heredia Bravo
 */ 

#define F_CPU 16000000UL
#define __DELAY_BACKWARD_COMPATIBLE__

#include <util/delay.h>

// Inclusión de librerías propias
#include "BUZZER.h"
#include "../../DCE_libraries/MACROS.h"

void BUZZER_playsound(uint8_t period_ms, uint8_t n_times) {
	for(int i = 0; i < n_times; i++) {
		
		// Encendemos el BUZZER
		SETBIT(BUZZER_0_out, BUZZER);		// PORTB |= (1 << PORTB2);
		_delay_ms(period_ms);

		// Apagamos el BUZZER
		CLEARBIT(BUZZER_0_out, BUZZER);		// PORTB &= ~(1 << PORTB2);	
		_delay_ms(period_ms);
	}
}