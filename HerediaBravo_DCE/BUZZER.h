/*
 * BUZZER.h
 *
 * Created: 05/05/2025 10:02:00
 *  Author: Cristian Heredia Bravo
 */ 


#ifndef BUZZER_H_
#define BUZZER_H_

// Incluimos libreria
#include <avr/io.h>

// Definimos para mayor comodidad
#define BUZZER_0_mode DDRB // Modo entrada/salida
#define BUZZER_0_in PINB // Para entrada
#define BUZZER_0_out PORTB // Para salida

#define BUZZER PORTB2 // Puerto donde está el BUZZER

static inline void BUZZER_init() {
	// Ponemos el BUZZER como salida
	BUZZER_0_mode |= (1 << BUZZER);
}

// period_ms es el periodo (según esto suena más agudo o más grave) y n_times es cuantas veces se repite el sonido
void BUZZER_playsound(uint8_t period_ms, uint8_t n_times);




#endif /* BUZZER_H_ */