/*
 * Button.c
 *
 * Created: 12/02/2023 11:21:11 م
 *  Author: QaiatY store
 */ 
//include .h
#include "Button.h"
//global variables
//function definitions
error Button_init(uint8_t buttonPort,uint8_t buttonPin){
	if(DIO_init(buttonPort,buttonPin,IN)==ok){
		DIO_init(buttonPort,buttonPin,IN);
		return ok;
	}
	else if(DIO_init(buttonPort,buttonPin,IN)==not_ok){
		return not_ok;
	}
}

error Button_read(uint8_t buttonPort,uint8_t buttonPin,uint8_t *value){
	if (DIO_read(buttonPort,buttonPin,value)==ok){
		DIO_read(buttonPort,buttonPin,value);
		return ok;
	}
	else if (DIO_read(buttonPort,buttonPin,value)==not_ok){
		return not_ok;
	}
}