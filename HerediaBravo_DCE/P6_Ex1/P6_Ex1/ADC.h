#ifndef ADC_H_
#define ADC_H_

#ifndef F_CPU
#undef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>


#define channel0 0
#define channel1 1
#define channel2 2
#define channel3 3
#define channel4 4
#define channel5 5

#define AVCC 1
#define AREF 0

#define ALIGN_LEFT 1
#define ALIGN_RIGHT 0

uint16_t ADC_read(uint16_t channel);

static inline void ADC_init(uint16_t Vref, uint16_t alignment) {
    ADMUX &= (0b00110000);

    ADMUX |= (Vref << REFS0); 
    ADMUX |= (alignment << ADLAR);

    ADCSRA = 0;
    ADCSRA |= (1 << ADEN);
    ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // Prescaler
}

static inline void ADC_select_channel(uint16_t channel) {
    ADMUX &= (0b11110000);
    ADMUX |= (channel << MUX0);
    ADCSRA |= (1 << ADSC);
}

static inline void ADC_enableINT() {
	ADCSRA |= (1<<ADIE);
}

static inline void ADC_disableINT() {
	ADCSRA &= ~(1<<ADIE);
}

#endif /* ADC_H_ */