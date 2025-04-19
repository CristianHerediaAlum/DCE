/*
 * P2_Ex9.c
 *
 * Created: 03/03/2025 11:34:05
 * Author : DCE
 */ 
#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

#include "PORTS.h"
#include "MACROS.h"

typedef enum {
	ST_INITIAL,			// A setup state
	ST_RED_LED_TOGGLE,	// Action
	ST_GREEN_LED_TOGGLE,// Action
	ST_OFF_LED_TOGGLE,	// Action
	ST_BOTH_LED_TOGGLE,
	ST_DELAY			// Assure the right behavior of the pushbutton
} FSM_States_t;

typedef enum {
	RED,
	GREEN,
	OFF,
	BOTH
} COLOUR_LED_t;

int main(void)
{
	FSM_States_t current_state = ST_INITIAL;
	FSM_States_t next_state = ST_INITIAL;
	uint8_t statePushbutton = !PRESSED;
	
	COLOUR_LED_t next_colour = GREEN;

	GPIO_init();
    
	/* Replace with your application code */
    while (1) 
    {
		statePushbutton = READ_PIN(GPIO_0_in,PUSHBUTTON);
		
		switch (current_state)
		{
		case ST_INITIAL:
			GPIO_init();
			CLEARBIT(GPIO_0_out, RED_LED);
			CLEARBIT(GPIO_0_out, GREEN_LED);
			next_colour = GREEN;
			if(statePushbutton == PRESSED)
				next_state = ST_GREEN_LED_TOGGLE;
		break;
		case ST_GREEN_LED_TOGGLE:
			CLEARBIT(GPIO_0_out, RED_LED);
			SETBIT(GPIO_0_out, GREEN_LED);
			next_colour = RED;
			next_state = ST_DELAY;
		break;
		case ST_DELAY:
			_delay_ms(300);
			if(statePushbutton == PRESSED) {
				if(next_colour == GREEN)
					next_state = ST_GREEN_LED_TOGGLE;
				else if(next_colour == RED)
					next_state = ST_RED_LED_TOGGLE;
				else if(next_colour == OFF)
					next_state = ST_OFF_LED_TOGGLE;
				else
					next_state = ST_BOTH_LED_TOGGLE;
			}
		break;
		case ST_RED_LED_TOGGLE:
			CLEARBIT(GPIO_0_out, GREEN_LED);
			SETBIT(GPIO_0_out, RED_LED); // Y encendemos el rojo
			next_colour = OFF;
			next_state = ST_DELAY;
		break;
		case ST_OFF_LED_TOGGLE:
			CLEARBIT(GPIO_0_out, GREEN_LED);
			CLEARBIT(GPIO_0_out, RED_LED);
			next_colour = BOTH;
			next_state = ST_DELAY;
		break;
		case ST_BOTH_LED_TOGGLE:
			SETBIT(GPIO_0_out, GREEN_LED);
			SETBIT(GPIO_0_out, RED_LED);
			next_colour = GREEN;
			next_state = ST_DELAY;
		break;
		default:
			next_state = ST_INITIAL;
			break;
		}
		current_state = next_state;
    }
}

