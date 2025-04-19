/*
 * INTERRUPTS.h
 *
 * Created: 17/03/2025 9:12:02
 *  Author: DCE
 */ 


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

#define PCINT_enable(ADDRESS) (PCICR |= (1 << ADDRESS))
#define PCINT2_pinSelect(ADDRESS) (PCMSK2 |= (1 << ADDRESS))



#endif /* INTERRUPTS_H_ */