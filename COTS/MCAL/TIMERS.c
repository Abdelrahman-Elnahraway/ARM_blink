
/*_____________________________TIMERS.h_____________________________________________________
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

 #include "TIMERS.h"
 
 
 
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

static void (*SysTick_Handler_Ptr) (void)=NULLPTR;   	// A function pointer for the Callback function of the systick interrupt



/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
static uint32_t TIMER_ST_looptime_Tick;							 	// The time interval of excution for systick function 
static uint32_t TIMER_32Bit_STCounter_Ticks;								 	//A decrementing counter inside the systick interrupt for long interivals 



/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
 void TIMER_Init_Systick(uint32_t	Timer_Input_Clock ,uint32_t interrupt_en, void (*FunPtr)(void)){
SysTick_Handler_Ptr=FunPtr; 												// Assigne the given ptr to the systick
WRITE_BIT(TIMER_STCTRL_R,2,Timer_Input_Clock); 			// set the clock type bit in STCTRL register
WRITE_BIT(TIMER_STCTRL_R,1,interrupt_en);						// enable / disable the interrupt routine for systick
 }
 
 
 
 void TIMER_SetCallBack_Systick(void (*FunPtr)(void)){
SysTick_Handler_Ptr=FunPtr;													// Assigne the given ptr to the systick
 }
 
 
void TIMER_Enable_Systick(void){
	WRITE_BIT(TIMER_STCTRL_R,0,ST_ENABLE);						// Enable systic decrement timer STCTRL_R
}


void TIMER_Disable_Systick(void){
WRITE_BIT(TIMER_STCTRL_R,0,ST_DISABLE);							// Disable systic decrement timer STCTRL_R
}
 
void TIMER_Set_StLoop_ms(uint32_t msDelay){

TIMER_ST_looptime_Tick =(((SYSTM_CLK_FRQ/1000)*msDelay)-TIMER_CALLIBRATION); // calculating the number of ticks in the given delay
TIMER_32Bit_STCounter_Ticks=TIMER_ST_looptime_Tick;									// Assign the counter inside the interrupt to the value the ticks required
	if(TIMER_ST_looptime_Tick>0xFFFFFFUL){ 										// IF THE delay is more than the max size of the counter register
		NVIC_STRELOAD_R = 0XFFFFFFUL;														// Make the reload bits the maximum  it can hold
		NVIC_STCURRENT_R=TIMER_32Bit_STCounter_Ticks;										// assign a dummy value to reset the counter 
		TIMER_32Bit_STCounter_Ticks-=0XFFFFFFUL;												// decrement our counter by the loop 
	}
		else{																										// if the number of ticks is withthin the 24 bits 
			NVIC_STRELOAD_R = (((SYSTM_CLK_FRQ/1000)*msDelay)-TIMER_CALLIBRATION); // Assignt he ticks in the reload counter
				NVIC_STCURRENT_R=TIMER_32Bit_STCounter_Ticks;								// assign a dummy value to reset the counter 
		}

}


uint32_t TIMER_Get_reload_Systick_ms(void){
return (((TIMER_ST_looptime_Tick+1)*1000)/SYSTM_CLK_FRQ) ; // return the delay in ms 
}



void SysTick_Handler(void)
{ 	
	
	if((TIMER_32Bit_STCounter_Ticks)>0xFFFFFFUL){ // if the counter is still more than the 24 bit of the reload
	TIMER_32Bit_STCounter_Ticks-=0xFFFFFF;    		// decrement the counter and loop again
	
}
	else if(TIMER_32Bit_STCounter_Ticks>0&&TIMER_32Bit_STCounter_Ticks!=NVIC_STRELOAD_R){	// Case the last loop as the full reload value
			NVIC_STRELOAD_R =TIMER_32Bit_STCounter_Ticks;															// make the reload time equal to the remaining time in the counter
		NVIC_STCURRENT_R=TIMER_32Bit_STCounter_Ticks;																// reset the counter witl a dummy value
		TIMER_32Bit_STCounter_Ticks=0;																							// make the counter equal zero "the last loop" 
	}
	else{
TIMER_32Bit_STCounter_Ticks=TIMER_ST_looptime_Tick;															// the last loop  reset everything as the initialization
	if(TIMER_ST_looptime_Tick>0xFFFFFFUL){ // IF THE delay is more than the max size of the counter register
		NVIC_STRELOAD_R = (0XFFFFFFUL-TIMER_CALLIBRATION);
		NVIC_STCURRENT_R=TIMER_32Bit_STCounter_Ticks;		
		TIMER_32Bit_STCounter_Ticks-=0XFFFFFFUL;
	}
	SysTick_Handler_Ptr(); 																			//trigger the interrupt function
	}


}
/**********************************************************************************************************************
 *  END OF FILE: TIMERS.c
 *********************************************************************************************************************/

