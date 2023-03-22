/*
 * Button.h
 *
 * Created: 12/02/2023 11:21:49 م
 *  Author: QaiatY store
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO Driver/DIO.h"
//internal driver typedefs
//driver macros
#define Button1_PORT PORT_b
#define Button1_PIN 2

#define LOW 0
#define HIGH 1

//driver function prototypes
error Button_init(uint8_t buttonPort,uint8_t buttonPin);

error Button_read(uint8_t buttonPort,uint8_t buttonPin,uint8_t *value);




#endif /* BUTTON_H_ */