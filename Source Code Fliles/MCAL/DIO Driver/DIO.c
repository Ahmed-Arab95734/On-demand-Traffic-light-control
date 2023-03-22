/*
 * DIO.c
 *
 * Created: 12/02/2023 08:45:07 م
 *  Author: QaiatY store
 */ 

//include .h
#include "DIO.h"
#include "../Delay Driver/Delay.h"
#include "../Interrupt Driver/Interrupt.h"
//global variables
//function definitions

error DIO_init(uint8_t portNumber,uint8_t pinNumber,uint8_t direction){
	switch (portNumber){
		case PORT_a:
		if (direction ==IN){
			DDR_A &= ~(1<<pinNumber);
			return ok;
		}
		else if (direction == OUT){
			DDR_A |= (1<<pinNumber);
			return ok;
		}
		break;
		
		case PORT_b:
		if (direction ==IN){
			DDR_B &= ~(1<<pinNumber);
			return ok;
			
		}
		else if (direction == OUT){
			DDR_B |= (1<<pinNumber);
			return ok;
		}
		break;
		
		default:
		return not_ok;

	}
	
}

error DIO_write(uint8_t portNumber,uint8_t pinNumber,uint8_t value){
	switch (portNumber){
		case PORT_a:
		if (value==LOW){
			PORT_A &= ~(1<<pinNumber);
			return ok;
			
		}
		else if (value == HIGH){
			PORT_A |= (1<<pinNumber);
			return ok;
		}
		break;
		case PORT_b:
		if (value==LOW){
			PORT_B &= ~(1<<pinNumber);
			return ok;
			
		}
		else if (value == HIGH){
			PORT_B |= (1<<pinNumber);
			return ok;
		}
		break;
		
		default:
		return not_ok;
	}
}

error DIO_read(uint8_t portNumber,uint8_t pinNumber,uint8_t *value){
	switch (portNumber){
		case PORT_a:
		*value = (PIN_A & (1<<pinNumber))>>pinNumber;
		return ok;
		break;
		
		case PORT_b:
		*value = (PIN_B & (1<<pinNumber))>>pinNumber;
		return ok;
		break;
		
		default:
		return not_ok;
		
		
	}
}
