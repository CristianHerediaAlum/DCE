/*
 * P6_Ex1.c
 *
 * Created: 21/04/2025 11:15:37
 * Author : crist
 */ 

#include <avr/io.h>
#include "../../DCE_libraries/TMR1.h"
#include "../../DCE_libraries/MACROS.h"

// ISR(TIMER1_COMPA_vect) {
//     // Blinking...
//     TOGGLEBIT(PORTB, PB5);
// //    TCNT1 = 0; 
// }

// int main(void)
// {
//     // Led as output
//     DDRB |= (1 << PB5);

//     TMR1_CTC_init();
//     TMR1_CTC_enaInterrupt();
//     TMR1_CTC_Set(7812);
//     TMR1_CTC_Start(DIV_CLK_1024);
//     sei();
//     /* Replace with your application code */
//     while (1) 
//     {
//     }
// }

