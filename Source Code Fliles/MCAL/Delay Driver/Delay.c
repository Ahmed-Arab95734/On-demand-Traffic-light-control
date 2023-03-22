/*
 * Delay.c
 *
 * Created: 13/02/2023 06:09:17 ص
 *  Author: QaiatY store
 */ 
//include .h
#include "Delay.h"
#include "../../Utilities/registers.h"
//global variables
//function definitions
int pow(int base, int exp)
{
	if(exp < 0)
	return -1;

	int result = 1;
	while (exp)
	{
		if (exp & 1)
		result *= base;
		exp >>= 1;
		base *= base;
	}

	return result;
}

error delay(int T_ms_delay){
	float T_tic,T_max_delay,Timer_intial_value, N_overflows;
	T_tic=Prescaler/Fclock;
	T_max_delay=T_tic*pow(2,n);
	float T_delay=T_ms_delay/1000.0;
	
	if (T_delay>T_max_delay)
	{
		if (((T_delay/T_max_delay)-(int)(T_delay/T_max_delay))>=0.5){
			N_overflows=(int)(T_delay/T_max_delay)+1;
		}
		else{
			N_overflows=(int)(T_delay/T_max_delay);
		}
		
		Timer_intial_value=pow(2,n)-((T_delay/T_tic)/N_overflows);
		
		if (((Timer_intial_value)-(int)(Timer_intial_value))>=0.5){
			Timer_intial_value=(int)(Timer_intial_value)+1;
		}
		else{
			Timer_intial_value=(int)(Timer_intial_value);
		}
		TCCR_0=0x00; //Normal Mode
		
				//Set Timer Initial Value
				TCNT_0=(uint8_t)Timer_intial_value;
				
				// Timer Start (1024 Prescaler)
				TCCR_0 |= (1<<0);
				TCCR_0 |= (1<<2);
				
				unsigned int overFolowsConter =0;
				while(overFolowsConter<N_overflows)
				{
					//wait until overflow flag to be set
					while((TIFR_0 & (1<<0))==0);
					
					//clear over flow flag
					TIFR_0 |=(1<<0);
					
					overFolowsConter++;
				}
				overFolowsConter=0;
				
				//Timer Stop
				TCCR_0=0x00;
				
				return ok;}
			else{
				return not_ok;
			}
				
			
}

error delay_INT(int T_ms_delay){
	float T_delay=T_ms_delay/1000.0;
	
	float T_tic,T_max_delay,Timer_intial_value, N_overflows;

	T_tic=Prescaler/Fclock;
	T_max_delay=T_tic*pow(2,n);
	
	if (T_delay>T_max_delay){
		
	
	if (((T_delay/T_max_delay)-(int)(T_delay/T_max_delay))>=0.5){
		N_overflows=(int)(T_delay/T_max_delay)+1;
	}
	else{
		N_overflows=(int)(T_delay/T_max_delay);
	}
	
	Timer_intial_value=pow(2,n)-((T_delay/T_tic)/N_overflows);
	
	if (((Timer_intial_value)-(int)(Timer_intial_value))>=0.5){
		Timer_intial_value=(int)(Timer_intial_value)+1;
	}
	else{
		Timer_intial_value=(int)(Timer_intial_value);
	}
	TCCR_2=0x00; //Normal Mode
	
	//Set Timer Initial Value
	TCNT_2=(uint8_t)Timer_intial_value;
	
	// Timer Start (1024 Prescaler)
	TCCR_2 |= (1<<0);
	TCCR_2 |= (1<<1);
	TCCR_2 |= (1<<2);
	
	unsigned int overFolowsConter =0;
	while(overFolowsConter<N_overflows)
	{
		//wait until overflow flag to be set
		while((TIFR_2 & (1<<6))==0);
		
		//clear over flow flag
		TIFR_2 |=(1<<6);
		
		overFolowsConter++;
	}
	overFolowsConter=0;
	
	//Timer Stop
	TCCR_2=0x00;
	
	return ok;}
	
	else{
		return not_ok;
	}
}