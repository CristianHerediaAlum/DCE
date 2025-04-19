/*
 * MACROS.h
 *
 * Created: 28/10/2024 12:02:44
 *  Author: miria
 */ 


#ifndef MACROS_H_
#define MACROS_H_

// Writing bits in I/O registers
#define SETBIT(ADDRESS,BIT)		(ADDRESS |= (1<<BIT))
#define CLEARBIT(ADDRESS,BIT)	(ADDRESS &= ~(1<<BIT))
#define TOGGLEBIT(ADDRESS,BIT)	(ADDRESS ^= (1<<BIT))
// Reading bits in I/O registers
#define READ_PIN(ADDRESS,BIT)		(ADDRESS & (1<<BIT))


#endif /* MACROS_H_ */