/*
 * DIO.h
 *
 * Created: 12/02/2023 08:45:30 م
 *  Author: QaiatY store
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "../../Utilities/registers.h"
#include "../../Utilities/types.h"
//internal driver typedefs 
//driver macros
#define PORT_a 'A' 
#define PORT_b 'B' 

#define IN 0
#define OUT 1

#define LOW 0
#define HIGH 1

//driver function prototypes
error DIO_init(uint8_t portNumber,uint8_t pinNumber,uint8_t direction);

error DIO_write(uint8_t portNumber,uint8_t pinNumber,uint8_t value);

error DIO_read(uint8_t portNumber,uint8_t pinNumber,uint8_t *value);

#endif /* DIO_H_ */