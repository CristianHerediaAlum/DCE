/*
 * P5_Ex2.c
 *
 * Created: 27/04/2025 17:51:33
 * Author : crist
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "../../DCE_libraries/ADC.h"
#include "../../DCE_libraries/MACROS.h"
#include "PORTS.h"

#define SETPOINT 500
#define DELAY_TIME 200

ISR(ADC_vect) {
	uint16_t adc_result = ADC;
	
	if(adc_result < SETPOINT)
		SETBIT(PORTB, LED);
	else
		CLEARBIT(PORTB, LED);
}

int main(void)
{
	GPIO_init();
	ADC_init(AVCC, ALIGN_RIGHT);
	ADC_select_channel(channel1);
	ADC_enableINT();
	sei();
    /* Replace with your application code */
    while (1) 
    {	
		// Comienza conversión
		ADCSRA |= (1 << ADSC);
		_delay_ms(DELAY_TIME);
    }
}

