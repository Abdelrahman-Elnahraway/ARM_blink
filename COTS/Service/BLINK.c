
/*_____________________________LED.c_____________________________________________________
                                      ___           ___           ___
 Author: Abdelrahman Selim           /\  \         /\  \         /\  \
                                    /::\  \       /::\  \       /::\  \
Created on: Aug 20, 2022           /:/\:\  \     /:/\:\  \     /:/\:\  \
                                  /::\ \:\  \   _\:\ \:\  \   /::\ \:\  \
 Version: 01                     /:/\:\ \:\__\ /\ \:\ \:\__\ /:/\:\ \:\__\
                                 \/__\:\/:/  / \:\ \:\ \/__/ \/__\:\/:/  /
                                      \::/  /   \:\ \:\__\        \::/  /
                                      /:/  /     \:\/:/  /        /:/  /
 Brief : EGfwd_project_1		         /:/  /       \::/  /        /:/  /
                                     \/__/         \/__/         \/__/
 _________________________________________________________________________________________*/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "BLINK.h"



/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
static uint8_t BLINK_Loop_Type ;
static	LED_Light_colour Blink_led_colour ;
static uint32_t BLINK_OnTime;
static uint32_t BLINK_OffTime;


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
static void SysTick_Blink_Interrupt(void); // the blink function assigned to the systick
/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

void SysTick_Blink_Interrupt(void)
{
	if(BLINK_Loop_Type==OFF){ 		// the last loop was off
		BLINK_Loop_Type=ON;		 		// make the new reload interval the turn on time
	TIMER_Set_StLoop_ms(BLINK_OnTime);	 		// assign the on time to the systick timer
		LED_TurnOn_colour(Blink_led_colour); 	// turn the led on
	}
		else{
			BLINK_Loop_Type=OFF;
	TIMER_Set_StLoop_ms(BLINK_OffTime);					// assign the off time as the new time interval
			LED_TurnOff_colour(Blink_led_colour);		//turn the led off	
		}
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

void Blink_LED(LED_Light_colour led,uint32_t ontime_ms ,uint32_t offtime_ms){
	LED_Init_colour(led);																															//intialize the led pin
	Blink_led_colour=led;																															// assign the given led colour to this code led colour
	BLINK_OnTime=ontime_ms;																														// assign the given on time to the static on time variable in this code
	BLINK_OffTime=offtime_ms;																													// assign the given off time to the static off time variable in this code
	 BLINK_Loop_Type=ON;																															// assign the loop type to on loop
	LED_TurnOn_colour(Blink_led_colour);
	TIMER_Set_StLoop_ms(ontime_ms);
	TIMER_Init_Systick(SYSTM_CLK,INTRPT_ON,* SysTick_Blink_Interrupt);                // intialize the timer
	TIMER_Enable_Systick();																														// enable the timer counter
}

void SysTick_StopBlink_LED(void){
	TIMER_Disable_Systick();																													//disable the systic timer
}

/**********************************************************************************************************************
 *  END OF FILE: BLINK.c
 *********************************************************************************************************************/
