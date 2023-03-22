/*
 * Interrupt.h
 *
 * Created: 13/02/2023 01:27:35 م
 *  Author: QaiatY store
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include "../../Utilities/types.h"
//driver macros
#define stop_walking_green 1
#define stop_walking_yellow 2
#define walk_red 3


//driver function prototypes
void __vector_1 (void) __attribute__ ((signal,used)) ; 
error INT0_init(int *INT_State);

#endif /* INTERRUPT_H_ */