/*
 * registers.h
 *
 * Created: 12/02/2023 08:20:27 م
 *  Author: QaiatY store
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_

#include "types.h"

//DIO registers
/*************************************/

//PORTA registers
#define PORT_A *((volatile uint8_t*)0x3B)
#define DDR_A *((volatile uint8_t*)0x3A)
#define PIN_A *((volatile uint8_t*)0x39)

//PORTB registers
#define PORT_B *((volatile uint8_t*)0x38)
#define DDR_B *((volatile uint8_t*)0x37)
#define PIN_B *((volatile uint8_t*)0x36)

//Timer0 Registers
#define TCCR_0 *((volatile uint8_t*)0x53)
#define TCNT_0 *((volatile uint8_t*)0x52)
#define TIFR_0 *((volatile uint8_t*)0x58)

					#define TCCR_2 *((volatile uint8_t*)0x45)
					#define TCNT_2 *((volatile uint8_t*)0x44)
					#define TIFR_2 *((volatile uint8_t*)0x58)

//Interrupts
#define SREG *((volatile uint8_t*)0x5F)
#define MCUCR *((volatile uint8_t*)0x55)
#define GICR *((volatile uint8_t*)0x5B)

#endif /* REGISTERS_H_ */