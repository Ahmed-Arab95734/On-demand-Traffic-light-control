/*
 * IncFile1.h
 *
 * Created: 13/02/2023 06:09:36 ص
 *  Author: QaiatY store
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_

#include "../../Utilities/types.h"

//driver macros

#define Prescaler 1024.0
#define Fclock 1000000.0
#define n 8

//driver function prototypes
error delay(int T_ms_delay);
error delay_INT(int T_ms_delay);
int pow(int base, int exp);
#endif /* INCFILE1_H_ */