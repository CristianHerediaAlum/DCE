/*
 * P2_Ex10.c
 *
 * Created: 03/03/2025 12:44:43
 * Author : DCE
 */ 

#define F_CPU 16000000UL

#include <stdbool.h>
#include <util/delay.h>
#include <avr/io.h>

#include "PORTS.h"
#include "MACROS.h"

typedef enum {
	ST_INITIAL,			// A setup state
    ST_LED_ON,
	ST_LED_TOGGLE,		// Action
	ST_DELAY			// Assure the right behavior of the pushbutton
} FSM_States_t;

int main(void)
{
	FSM_States_t currentState	= ST_INITIAL;
	FSM_States_t nextState		= ST_INITIAL;
	uint8_t statePushbutton		= !PRESSED;
    bool parpadeo = false;

	GPIO_init();

    /* Replace with your application code */
    while (1) 
    {
		statePushbutton = READ_PIN(GPIO_0_in,PUSHBUTTON);
        switch (currentState)
        {
        case ST_INITIAL:
            GPIO_init();
            CLEARBIT(GPIO_0_out, LED);
            if(statePushbutton == PRESSED)
                nextState = ST_LED_ON;
        break;
        case ST_LED_ON:
            SETBIT(GPIO_0_out, LED);
            if(statePushbutton == PRESSED)
                nextState = ST_LED_TOGGLE;
        case ST_LED_TOGGLE:
            CLEARBIT(GPIO_0_out, LED);
            if(!parpadeo) {
                CLEARBIT(GPIO_0_out, LED);
                for(int i = 0; i < 3; i++) {
                    TOGGLEBIT(GPIO_0_out, LED);
                    _delay_ms(300);
                }
                parpadeo = true;
            }
            if(statePushbutton == PRESSED) {
                parpadeo = false;
                nextState = ST_LED_ON;
            }
        break;
        default:
            nextState = ST_INITIAL;
        break;
        }
        currentState = nextState;
        _delay_ms(300);
    }
}

