#include <avr/io.h>
#include <avr/interrupt.h>
#include "../../DCE_libraries/TMR0.h"  // Usamos las funciones ya definidas para Timer0
#include "../../DCE_libraries/TMR1.h"  // Usamos las funciones ya definidas para Timer1
#include "BUZZER.h"

#define TICKS_FOR_1MS 249  // Para 1ms a 16MHz con prescaler 64
#define TICKS_FOR_1S 15624 // Para 1s con prescaler 64

#define TICKS_FOR_2MS 499
#define TICKS_FOR_3MS 749

// // ISR de Timer1 Compare Match A (Para contar)
// ISR(TIMER1_COMPA_vect) {
// 	TMR0_CTC_Stop();
// 	TMR0_CTC_disInterrupt();
// 	TMR1_CTC_disInterrupt();
// }

// // ISR de Timer0 Compare Match A (Para periodo)
// ISR(TIMER0_COMPA_vect) {
// 	TOGGLEBIT(BUZZER_0_out, BUZZER);
// }

int main(void) {
	BUZZER_init();
	BUZZER_TM_init();
	// Configurar pin como salida
	// BUZZER_init();

	// // Inicializar Timer1 en modo CTC
	// TMR1_CTC_init();

	// // Establecer OCR1A para 1s (a 16MHz con prescaler 1024)
	// TMR1_CTC_Set(TICKS_FOR_1S);

	// // Habilitar interrupci�n de Timer1
	// TMR1_CTC_enaInterrupt();

	// // Iniciar Timer1 con prescaler 1024
	// TMR1_CTC_Start(DIV_CLK_1024);

	// // Inicializar Timer0 en modo CTC
	// TMR0_CTC_init();

	// // Establecer OCR0A para 1ms (a 16MHz con prescaler 64)
	// TMR0_CTC_Set(TICKS_FOR_1MS);

	// // Habilitar interrupci�n de Timer0
	// TMR0_CTC_enaInterrupt();
	
	// TMR0_CTC_Start(DIV_CLK_64);

	// // Habilitar interrupciones globales
	// sei();

	while (1) {
		BUZZER_playsound(TICKS_FOR_1MS, TICKS_FOR_1S);
		BUZZER_playsound(TICKS_FOR_2MS, TICKS_FOR_1S);
		BUZZER_playsound(TICKS_FOR_3MS, TICKS_FOR_1S);
	}
}
