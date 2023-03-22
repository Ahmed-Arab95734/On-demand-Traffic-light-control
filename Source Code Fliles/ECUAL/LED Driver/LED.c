/*
 * LED.c
 *
 * Created: 12/02/2023 10:56:07 م
 *  Author: QaiatY store
 */ 
//include .h
#include "LED.h"
//global variables
//function definitions
error LED_init(uint8_t ledPort,uint8_t ledPin){
	if (DIO_init(ledPort,ledPin,OUT)==ok){
		DIO_init(ledPort,ledPin,OUT);
		return ok;
	}
	else if(DIO_init(ledPort,ledPin,OUT)==not_ok){
		return not_ok;
	}
}
error LED_on(uint8_t ledPort,uint8_t ledPin){
	if (DIO_write(ledPort,ledPin,HIGH)==ok){
		DIO_write(ledPort,ledPin,HIGH);
		return ok;
	}
	
	else if (DIO_write(ledPort,ledPin,HIGH)==not_ok){
		return not_ok;
	}
}
error LED_off(uint8_t ledPort,uint8_t ledPin){
	if (DIO_write(ledPort,ledPin,LOW)==ok){
		DIO_write(ledPort,ledPin,LOW);
		return ok;
	}
	else if (DIO_write(ledPort,ledPin,LOW)==not_ok){
		return not_ok;
	}
}
