/*
 * Interrupt.c
 *
 * Created: 13/02/2023 01:27:56 م
 *  Author: QaiatY store
 */ 

//include .h
#include "interrupt.h"
#include "../../Utilities/registers.h"
#include "../../ECUAL/LED Driver/LED.h"

//global variables
int *mode_state;

//function definitions
void __vector_1 (void){


					LED_off(LED_CAR_GREEN_PORT,LED_CAR_GREEN_PIN);
					LED_off(LED_Pedestrians_RED_PORT,LED_Pedestrians_RED_PIN);
					LED_off(LED_CAR_YELLOW_PORT,LED_CAR_YELLOW_PIN);
					LED_off(LED_Pedestrians_YELLOW_PORT,LED_Pedestrians_YELLOW_PIN);
					LED_off(LED_CAR_RED_PORT,LED_CAR_RED_PIN);
					LED_off(LED_Pedestrians_GREEN_PORT,LED_Pedestrians_GREEN_PIN);
	  
	switch (*mode_state){

		case stop_walking_green:
		
		LED_on(LED_CAR_GREEN_PORT,LED_CAR_GREEN_PIN);
		LED_on(LED_Pedestrians_RED_PORT,LED_Pedestrians_RED_PIN);
		delay_INT(5000);
		LED_off(LED_CAR_GREEN_PORT,LED_CAR_GREEN_PIN);
		LED_off(LED_Pedestrians_RED_PORT,LED_Pedestrians_RED_PIN);
		
		for (int i =0;i<5;i++)
		{
			
			LED_on(LED_CAR_YELLOW_PORT,LED_CAR_YELLOW_PIN);
			LED_on(LED_Pedestrians_YELLOW_PORT,LED_Pedestrians_YELLOW_PIN);
			delay_INT(500);
			LED_off(LED_CAR_YELLOW_PORT,LED_CAR_YELLOW_PIN);
			LED_off(LED_Pedestrians_YELLOW_PORT,LED_Pedestrians_YELLOW_PIN);
			delay_INT(500);
		}
		
		
		LED_on(LED_CAR_RED_PORT,LED_CAR_RED_PIN);
		LED_on(LED_Pedestrians_GREEN_PORT,LED_Pedestrians_GREEN_PIN);
		delay_INT(5000);
		LED_off(LED_CAR_RED_PORT,LED_CAR_RED_PIN);
		LED_off(LED_Pedestrians_GREEN_PORT,LED_Pedestrians_GREEN_PIN);
		
		for (int i =0;i<5;i++)
		{
	
			LED_on(LED_CAR_YELLOW_PORT,LED_CAR_YELLOW_PIN);
			delay_INT(500);
			LED_off(LED_CAR_YELLOW_PORT,LED_CAR_YELLOW_PIN);
			delay_INT(500);
		}
		LED_on(LED_CAR_GREEN_PORT,LED_CAR_GREEN_PIN);
		
		
		
		break;

		case stop_walking_yellow:
		for (int i =0;i<5;i++)
		{
			
			LED_on(LED_CAR_YELLOW_PORT,LED_CAR_YELLOW_PIN);
			LED_on(LED_Pedestrians_YELLOW_PORT,LED_Pedestrians_YELLOW_PIN);
			delay_INT(500);
			LED_off(LED_CAR_YELLOW_PORT,LED_CAR_YELLOW_PIN);
			LED_off(LED_Pedestrians_YELLOW_PORT,LED_Pedestrians_YELLOW_PIN);
			delay_INT(500);
		}
		
		
		LED_on(LED_CAR_RED_PORT,LED_CAR_RED_PIN);
		LED_on(LED_Pedestrians_GREEN_PORT,LED_Pedestrians_GREEN_PIN);
		delay_INT(5000);
		LED_off(LED_CAR_RED_PORT,LED_CAR_RED_PIN);
		LED_off(LED_Pedestrians_GREEN_PORT,LED_Pedestrians_GREEN_PIN);
		

		break;
		
		case walk_red:
		LED_on(LED_CAR_RED_PORT,LED_CAR_RED_PIN);
		LED_on(LED_Pedestrians_GREEN_PORT,LED_Pedestrians_GREEN_PIN);
		delay_INT(5000);
		LED_off(LED_CAR_RED_PORT,LED_CAR_RED_PIN);
		LED_off(LED_Pedestrians_GREEN_PORT,LED_Pedestrians_GREEN_PIN);
		
				for (int i =0;i<5;i++)
				{
					
					LED_on(LED_CAR_YELLOW_PORT,LED_CAR_YELLOW_PIN);
					delay_INT(500);
					LED_off(LED_CAR_YELLOW_PORT,LED_CAR_YELLOW_PIN);
					delay_INT(500);
				}
							LED_on(LED_CAR_GREEN_PORT,LED_CAR_GREEN_PIN);
							delay_INT(5000);
							LED_off(LED_CAR_GREEN_PORT,LED_CAR_GREEN_PIN);
							
				for (int i =0;i<5;i++)
				{
					
					LED_on(LED_CAR_YELLOW_PORT,LED_CAR_YELLOW_PIN);
					delay_INT(500);
					LED_off(LED_CAR_YELLOW_PORT,LED_CAR_YELLOW_PIN);
					delay_INT(500);
				}
				
				LED_on(LED_CAR_RED_PORT,LED_CAR_RED_PIN);
		
		break;

		
		default:
		//do nothing

		break;
		
		
	}



  }
 
error INT0_init(int *INT_State){
	if (*INT_State==1 || *INT_State==2 || *INT_State==3){
		mode_state=INT_State;
		//Enable global interrupts
		SREG |= (1<<7);
		
		//Choose external interrupts sense (INT0 Rising Edge)
		MCUCR |=(1<<0);
		MCUCR |=(1<<1);
		
		//Enable INT0
		GICR |= (1<<6);
		return ok;
	}
	else{
		return not_ok;
	}
		
		
}