/*
 * LED.h
 *
 * Created: 12/02/2023 10:55:56 م
 *  Author: QaiatY store
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO Driver/DIO.h"
//internal driver typedefs
//driver macros

#define LED_CAR_RED_PORT PORT_a
#define LED_CAR_YELLOW_PORT PORT_a
#define LED_CAR_GREEN_PORT PORT_a

#define LED_Pedestrians_RED_PORT PORT_b
#define LED_Pedestrians_YELLOW_PORT PORT_b
#define LED_Pedestrians_GREEN_PORT PORT_b

#define LED_CAR_RED_PIN 2
#define LED_CAR_YELLOW_PIN 1
#define LED_CAR_GREEN_PIN 0

#define LED_Pedestrians_RED_PIN 2
#define LED_Pedestrians_YELLOW_PIN 1
#define LED_Pedestrians_GREEN_PIN 0



//driver function prototypes
error LED_init(uint8_t ledPort,uint8_t ledPin);
error LED_on(uint8_t ledPort,uint8_t ledPin);
error LED_off(uint8_t ledPort,uint8_t ledPin);




#endif /* LED_H_ */