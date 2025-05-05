/*
 * BUZZER.h
 *
 * Created: 05/05/2025 10:02:00
 *  Author: DCE
 */ 


#ifndef BUZZER_H_
#define BUZZER_H_

#include <avr/io.h>

#define BUZZER_0_mode DDRB
#define BUZZER_0_in PINB
#define BUZZER_0_out PORTB

#define BUZZER PORTB2

static inline void BUZZER_init() {
	BUZZER_0_mode |= (1 << BUZZER);
}

void BUZZER_playsound(uint8_t period_ms, uint8_t n_times);




#endif /* BUZZER_H_ */