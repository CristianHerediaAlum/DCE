/*
 * main.c
 *
 * Created: 05/05/2025 10:01:08
 * Author : Cristian Heredia Bravo
 */ 


#define F_CPU 16000000UL
#define __DELAY_BACKWARD_COMPATIBLE__ // Para que delay sea compatible

// Incluimos librerias del sistema
#include <util/delay.h>
#include <avr/io.h>

// Incluimos librerias propias
#include "../../DCE_libraries/MACROS.h"
#include "BUZZER.h"

int main(void)
{
	// Configuración inicial BUZZER
	BUZZER_init();

	// <------------------------------> {} <------------------------------>
    
	while (1) 
    {
		BUZZER_playsound(2, 10);
		_delay_ms(100);

		BUZZER_playsound(200, 10);
		_delay_ms(100);
		
		BUZZER_playsound(100, 10);
		_delay_ms(100);
	}
}

