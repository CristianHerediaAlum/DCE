/*
 * P6_Ex1.c
 *
 * Created: 21/04/2025 11:15:37
 * Author : crist
 */ 

 #include <avr/io.h>
 #include "../../DCE_libraries/TMR1.h"
 #include "../../DCE_libraries/MACROS.h"
//  #include "../../DCE_libraries/ADC.h"
 #include "ADC.h"
 
 volatile uint16_t adc_result = 0;

ISR(TIMER1_COMPA_vect) {
    // Toggle PB0 para ver en osciloscopio
    TOGGLEBIT(PORTB, PB0);

    // Habilitar interrupción ADC y empezar conversión
    ADC_enableINT();
    ADCSRA |= (1 << ADSC);
}

ISR(ADC_vect) {
    // Leer resultado (alineado a la derecha)
    adc_result = ADC_read(channel0);

    // Deshabilitar interrupción ADC
    ADC_disableINT();
}


 int main(void)
 {
    // Led as output
    DDRB |= (1 << PB5);

    //  Osciloscopio
    DDRB |= (1 << PB0);
 
    // Timer settings
    TMR1_CTC_init();
    TMR1_CTC_enaInterrupt();
    TMR1_CTC_Set(7812);
    TMR1_CTC_Start(DIV_CLK_1024);
    
    // ADC settings
    ADC_init(AVCC, ALIGN_RIGHT);

    ADC_select_channel(channel0);

    sei();
    /* Replace with your application code */
    while (1) 
    {
        if(adc_result > 512) {
            SETBIT(PORTB, PB5); // Encendemos el led
        }
        else
            CLEARBIT(PORTB, PB5); // Apagamos el led
    }
 }
 
 