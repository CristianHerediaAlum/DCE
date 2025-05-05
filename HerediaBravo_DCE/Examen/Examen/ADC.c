#include "ADC.h"

uint16_t ADC_read(uint16_t channel) {
    ADCSRA |= (1 << ADIF);
    ADMUX &= (0b11110000);
    ADMUX |= (1 << channel);
    ADCSRA |= (1 << ADSC);
	while (ADCSRA & (1 << ADIF));
    return ADC;
}