/*
 * TEST_Buzzer.c
 *
 * Created: 05/05/2025 10:01:08
 * Author : DCE
 */ 


#define F_CPU 16000000UL
#define __DELAY_BACKWARD_COMPATIBLE__
#include <util/delay.h>
#include <avr/io.h>

#include "../../DCE_libraries/MACROS.h"
#include "BUZZER.h"

int main(void)
{
	BUZZER_init();
    /* Replace with your application code */
    while (1) 
    {
		BUZZER_playsound(2, 10);
		_delay_ms(100);
		BUZZER_playsound(200, 10);
		_delay_ms(100);
		BUZZER_playsound(100, 10);
	}
}

