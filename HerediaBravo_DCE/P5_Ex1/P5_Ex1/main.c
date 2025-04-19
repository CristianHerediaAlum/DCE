/*
 * P5_Ex1.c
 *
 * Created: 07/04/2025 10:26:20
 * Author : DCE
 */ 

#define F_CPU 16000000UL

#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "../../DCE_libraries/USART.h"
#include "../../DCE_libraries/EXT_INT.h"
#include "../../DCE_libraries/MACROS.h"
#include "../../DCE_libraries/ADC.h"
#include "PORTS.h"


int main(void)
{
	//Configuracion
	GPIO_init();
	ADC_init(AVCC, ALIGN_RIGHT);
	USART0_init();
	ADC_select_channel(channel1);
	
	/* Replace with your application code */
    while (1) 
    {
		uint16_t adc_value = ADC_read(channel1);
		// parte 1
		// if (adc_value >= 0 && adc_value <= 255) {
		// 	GPIO_0_out |= (1 << FIRST_LED_PIN);  // LED0 on
		// 	} else if (adc_value >= 256 && adc_value <= 512) {
		// 	GPIO_0_out |= (1 << SECOND_LED_PIN);  // LED1 on
		// 	} else if (adc_value >= 513 && adc_value <= 768) {
		// 	GPIO_0_out |= (1 << THIRD_LED_PIN);  // LED2 on
		// 	} else if (adc_value >= 769 && adc_value <= 1023) {
		// 	GPIO_0_out |= (1 << LAST_LED_PIN);  // LED3 on
		// }
		// parte 2
		char buffer[6];
		ultoa(adc_value, buffer, 10);
		USART0_putString(buffer);
		USART0_putString("\n\r");
		_delay_ms(500);
    }
}

