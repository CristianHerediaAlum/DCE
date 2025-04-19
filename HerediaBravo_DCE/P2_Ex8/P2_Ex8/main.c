/*
 * P2_Ex8.c
 *
 * Created: 03/03/2025 10:35:29
 * Author : DCE
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>



#include "MACROS.h"
#include "PORTS.h"
typedef enum {
	ST_INITIAL,			// A setup state
	ST_LED_TOGGLE,		// Action
	ST_DELAY			// Assure the right behavior of the pushbutton
} FSM_States_t;

int main(void)
{
	FSM_States_t currentState	= ST_INITIAL;
	FSM_States_t nextState		= ST_INITIAL;
	uint8_t statePushbutton		= !PRESSED;
	
	//===============  SETUP ==============================
	GPIO_init();
	//-----------------------------------------------------
	
	//============  SUPER-LOOP =============================
	while (1)
	{
		//------------------------------------------------
		// 1.- Check the events (input )
		statePushbutton = READ_PIN(GPIO_0_in,PUSHBUTTON);
		//---------------------------------------------------
		// 2.- Set the TRANSITIONS based upon events:
		// * Pushbutton is pressed
		// * Delay time is expired
		//------------------------------------------------
		switch (currentState)
		{
			case ST_INITIAL:
			GPIO_init();	//Redundant for safety
			// System starts in a low-power state.
			CLEARBIT(GPIO_0_out,LED);
			if (statePushbutton==PRESSED)
			{
				nextState = ST_LED_TOGGLE;
			}
			break;
			
			case ST_LED_TOGGLE:
			TOGGLEBIT(GPIO_0_out,LED);
			nextState = ST_DELAY;
			break;
			
			case ST_DELAY:
			_delay_ms(300);
			if (statePushbutton==PRESSED)
			{
				nextState = ST_LED_TOGGLE;
			}
			break;
			
			default:
			// Whatever unknown state/value the system goes
			// to the known and safe state (ST_INITIAL)
			nextState = ST_INITIAL;
			break;
		}
		//-----------------------------------------------
		// 4.- Update the current state
		//-----------------------------------------------
		currentState = nextState;
		//-----------------------------------------------

	}
}

