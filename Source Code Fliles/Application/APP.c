/*
 * APP.c
 *
 * Created: 13/02/2023 09:42:59 م
 *  Author: QaiatY store
 */ 
//include .h
#include "../ECUAL/LED Driver/LED.h"
#include "APP.h"

//global variables
int Current_State=stop_walking_green;
//function definitions
error app(void){
	
	if (INT0_init(&Current_State)==ok && LED_on(LED_CAR_GREEN_PORT,LED_CAR_GREEN_PIN)==ok && LED_off(LED_CAR_GREEN_PORT,LED_CAR_GREEN_PIN)==ok && delay(500)==ok){
	INT0_init(&Current_State);
	
	while (1)
	{
		Current_State=stop_walking_green;
		LED_on(LED_CAR_GREEN_PORT,LED_CAR_GREEN_PIN);
		delay(5000);
		LED_off(LED_CAR_GREEN_PORT,LED_CAR_GREEN_PIN);
		
		for (int i =0;i<5;i++)
		{
			Current_State=stop_walking_yellow;
			LED_on(LED_CAR_YELLOW_PORT,LED_CAR_YELLOW_PIN);
			delay(500);
			LED_off(LED_CAR_YELLOW_PORT,LED_CAR_YELLOW_PIN);
			delay(500);
		}
		
		Current_State=walk_red;
		LED_on(LED_CAR_RED_PORT,LED_CAR_RED_PIN);
		delay(5000);
		LED_off(LED_CAR_RED_PORT,LED_CAR_RED_PIN);
		
		for (int i =0;i<5;i++)
		{
			Current_State=stop_walking_yellow;
			LED_on(LED_CAR_YELLOW_PORT,LED_CAR_YELLOW_PIN);
			delay(500);
			LED_off(LED_CAR_YELLOW_PORT,LED_CAR_YELLOW_PIN);
			delay(500);
		}

	}
	return ok;}
	
	else{
		return not_ok;		
	}
}