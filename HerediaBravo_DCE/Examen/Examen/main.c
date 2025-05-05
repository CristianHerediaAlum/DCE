/*
 * Examen.c
 *
 * Created: 28/04/2025 9:06:29
 * Author : crist
 */ 

#define F_CPU 16000000UL
#define DEFAULT_SET_POINT 512


#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>
#include <avr/eeprom.h>

#include "../../DCE_libraries/EXT_INT.h"
#include "../../DCE_libraries/ADC.h"
#include "../../DCE_libraries/MACROS.h"
#include "../../DCE_libraries/USART.h"
#include "PORTS.h"

typedef enum{
	PRODUCCION,
	CONFIGURACION
} ModoSistema;

typedef enum {
	STATE_MODE,
	STATE_LDR,
	STATE_POT	
} EstadoSistema;

volatile ModoSistema modo = PRODUCCION;
volatile EstadoSistema estado = STATE_MODE;

volatile uint16_t setpoint = 512;
volatile uint16_t lectura_LDR = 0;
volatile uint16_t lectura_pot = 0;

ISR(ADC_vect) {
	if (modo == PRODUCCION) {
		lectura_LDR = ADC_read(channel1);
		if (lectura_LDR < setpoint)
			PORTD |= (1 << PORTD1);  // LED_LIGHT ON
		else
			PORTD &= ~(1 << PORTD1); // LED_LIGHT OFF
	}
	else if (modo == CONFIGURACION) {
			lectura_pot = ADC_read(channel2);
		}
}

ISR(INT0_vect) {  // Pulsador de cambio de modo
	if (modo == PRODUCCION) {
		modo = CONFIGURACION;
	}
}

ISR(INT1_vect) {  // Pulsador de confirmar setpoint
	if (modo == CONFIGURACION) {
		setpoint = lectura_pot;
		eeprom_update_word((uint16_t*)0, setpoint);
		modo = PRODUCCION;
	}
}

int main(void)
{
	// Persistencia
	setpoint = eeprom_read_word((uint16_t*)0);
	
	if (setpoint == 0xFFFF) {
		setpoint = DEFAULT_SET_POINT;
	}
	
	char s[10];	
	uint16_t ldr_actual;
	// Configuracion inicial	
	GPIO_init();
		
	// Configuracion ADC
	ADC_init(AVCC, ALIGN_RIGHT);
	ADC_enableINT();
	ADC_select_channel(channel1);
	ADC_select_channel(channel2);
	
	// Configuracion USART
	USART0_init();
	
	//Configuracion interrupciones externas (botones)
	INT0_config(FALLING);
	INT0_enable();
	INT1_config(FALLING);
	INT1_enable();
	
	// Habilitamos interrupciones globales
	sei();
	
	// Parpadeamos el LED tres veces
	for(int i = 0; i < 3; i++) {
		// PORTB |= (1 << PORTB0);
		SETBIT(PORTB, LED_MODE);
		_delay_ms(500);
//		PORTB &= ~(1 << PORTB0);
		CLEARBIT(PORTB, LED_MODE);
		_delay_ms(500);
	}
	
    /* Replace with your application code */
    while (1)
    {
		switch (estado)
		{
			case STATE_MODE:
			if (modo == PRODUCCION) {
				// Encendemos LED_MODE
				SETBIT(PORTB, PORTB0);
				estado = STATE_LDR;
			}
			else if (modo == CONFIGURACION) {
				CLEARBIT(PORTB, LED_MODE);
				estado = STATE_POT;
			}
			break;
			
			case STATE_LDR:
			ldr_actual = ADC_read(channel1);
			_delay_ms(500); // Tiempo de muestreo
			utoa(ldr_actual, s, 10);
			USART0_putString("LDR en produccion, actual : ");
			USART0_putString(s);
			utoa(setpoint, s, 10);
			USART0_putString(", consigna: ");
			USART0_putString(s);
			USART0_putString("\n\r");
			estado = STATE_MODE;
			break;

			case STATE_POT:
			lectura_pot = ADC_read(channel2);
			USART0_putString("Potenciometro en configuracion: ");
			utoa(lectura_pot, s, 10);
			USART0_putString(s);
			USART0_putString("\n\r");
			_delay_ms(500); // Tiempo de muestreo
			estado = STATE_MODE;
			break;
		}
    }
}

