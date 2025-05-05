/*
 * RobotP1_Ex3.c
 *
 * Created: 05/05/2025 10:45:39
 * Author : DCE
 */ 

// #define F_CPU 16000000UL
// #define __DELAY_BACKWARD_COMPATIBLE__

// #include <util/delay.h>
// #include <avr/io.h>
// #include <avr/interrupt.h>

// #include "../../DCE_libraries/MACROS.h"
// #include "BUZZER.h"
// #include "../../DCE_libraries/TMR0.h"

// #define TICKS_FOR_1MS 249

// volatile uint16_t ms_counter = 0;

// ISR(TIMER0_COMPA_vect) {
// 	TOGGLEBIT(BUZZER_0_out, BUZZER);
// }


// int main(void)
// {
// 	BUZZER_init();
// 	TMR0_CTC_init();
// 	TMR0_CTC_enaInterrupt();
	
// 	TMR0_CTC_Set(TICKS_FOR_1MS);
// 	TMR0_CTC_Start(DIV_CLK_64);
	
// 	sei();
	
//     /* Replace with your application code */
//     while (1) 
//     {
//     }
// }

