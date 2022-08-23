
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
 
#ifndef MCAL_TIMERS_H_
#define MCAL_TIMERS_H_


/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include "CONFIG.h"
#include "UTILS.h"
#include "MEM_MAP.h"
#include <stdint.h>




/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


#define TIMER_CALLIBRATION 		0x9F 
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
 
 
/* ================================================================================ */
/* ================	 SysTick Control and Status Register (STCTRL)  ================ */
/* ================================================================================ */

/*********************************************************************
Bit/Field		Name						Description

2						CLK_SRC					Clock Source



Value			Description
0					Precision internal oscillator (PIOSC) divided by 4
1					System clock
*********************************************************************/
typedef enum {
PIOSC,
SYSTM_CLK
}ST_CLK_SRC_t;
/*********************************************************************
Bit/Field		Name						Description

1						CLK_SRC					Interrupt Enable



Value			Description
0					Interrupt generation is disabled. Software can use the
					COUNT bit to determine if the counter has ever reached 0.
1					An interrupt is generated to the NVIC when SysTick counts to 0.
*********************************************************************/
typedef enum {
INTRPT_OFF,
INTRPT_ON
}ST_INTEN_t;

/*********************************************************************
Bit/Field		Name						Description

0						ENABLE					SYSTICK Enable



Value			Description
0					The counter is disabled.
					COUNT bit to determine if the counter has ever reached 0.
1					Enables SysTick to operate in a multi-shot way. That is, the
					counter loads the RELOAD value and begins counting down.
					On reaching 0, the COUNT bit is set and an interrupt is
					generated if enabled by INTEN. The counter then loads the
					RELOAD value again and begins counting.
*********************************************************************/
typedef enum {
ST_DISABLE,
ST_ENABLE

}ST_EN_t;



/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/



/**************************************************************************************************
 * Func : TIMER_Init_Systick
 * Args
 * INPUT : Timer_Input_Clock ex  	PIOSC / SYSTM_CLK
					 interrupt_en			 ex		INTRPT_OFF / INTRPT_ON
					 FunPtr            ex   ANY_FUNCTION
 *Return : None
 *Brief	 : Initialize the Systic timer with the given parameter
 ************************************************************************/
void TIMER_Init_Systick(uint32_t	Timer_Input_Clock ,uint32_t interrupt_en, void (*FunPtr)(void));


/**************************************************************************************************
 * Func : TIMER_SetCallBack_Systick
 * Args
 * INPUT : FunPtr            ex   ANY_FUNCTION
 *Return : None
 *Brief	 : Set the interrupt function for the systick
 ************************************************************************/
void TIMER_SetCallBack_Systick(void (*FunPtr)(void));


/**************************************************************************************************
 * Func : TIMER_Enable_Systick
 * Args
 * INPUT : None
 *Return : None
 *Brief	 : Enable systick clock decrement
 ************************************************************************/
void TIMER_Enable_Systick(void);

/**************************************************************************************************
 * Func : TIMER_Disable_Systick
 * Args
 * INPUT : None
 *Return : None
 *Brief	 : Disable systick clock decrement
 ************************************************************************/
void TIMER_Disable_Systick(void);


/**************************************************************************************************
 * Func : TIMER_Set_StLoop_ms
 * Args
 * INPUT : msDelay  //the delay in milli seconds
 *Return : None
 * Brief : Set the call back function loop time in ms 
 Note*
			MaxDelay : 357913 ms
			Acuuracy : 1			ms
 ************************************************************************/
void TIMER_Set_StLoop_ms(uint32_t msDelay);

/**************************************************************************************************
 * Func : TIMER_Get_reload_Systick_ms
 * Args
 * INPUT : None
 *Return : uint32_t
 *Brief	 : return the msDelay
 ************************************************************************/
uint32_t TIMER_Get_reload_Systick_ms(void);

/**************************************************************************
 * Func : SysTick_Handler
 * Args
 * INPUT : None
 *Return : None
 *Brief	 : the ISR vector function in the startup code // excuted when the
					 interrupt triggered
 ************************************************************************/
 void SysTick_Handler(void);
#endif
/**********************************************************************************************************************
 *  END OF FILE: TIMERS.h
 *********************************************************************************************************************/
