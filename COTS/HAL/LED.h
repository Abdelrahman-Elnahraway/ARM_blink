/*_____________________________LED.h_____________________________________________________
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

#ifndef HAL_LED_H_
#define HAL_LED_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "GPIO.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
typedef enum {
	RED=1,
	BLUE,
	GREEN
}LED_Light_colour;
 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/



/**************************************************************************************************
 * Func : LED_Init_ALL / LED_Init_colour /LED_Init_GREEN
 * Args
 * INPUT : None / colour /None / None ............
 *Return : None
 *Brief	 : Initialize the led pin as a DIO output pin 
 ************************************************************************/
void LED_Init_ALL		(void);																				//INIT all builtin leds
void LED_Init_colour		(LED_Light_colour led);										//init a specific led by colour
void LED_Init_RED		(void);																				//init RED led
void LED_Init_BLUE	(void);																				//init BLUE led
void LED_Init_GREEN	(void);																				//init GREEN led




/**************************************************************************************************
 * Func : LED_TurnOn_ALL / LED_TurnOn_colour /LED_TurnOn_GREEN
 * Args
 * INPUT : None / colour /None / None ............
 *Return : None
 *Brief	 : turn the led on
 ************************************************************************/
void LED_TurnOn_colour(LED_Light_colour led);											//Turn on a specific led by colour
void LED_TurnOn_RED(void);																				//Turn on RED led
void LED_TurnOn_BLUE(void);																				//Turn on BLUE led
void LED_TurnOn_GREEN(void);																			//Turn on GREEN led


/**************************************************************************************************
 * Func : LED_TurnOff_ALL / LED_TurnOff_colour /LED_TurnOff_GREEN
 * Args
 * INPUT : None / colour /None / None ............
 *Return : None
 *Brief	 : turn the led off
 ************************************************************************/
void LED_TurnOff_colour(LED_Light_colour led);											//Turn off a specific led by colour
void LED_TurnOff_RED(void);																					//Turn off RED led
void LED_TurnOff_BLUE(void);																				//Turn off BLUE led
void LED_TurnOff_GREEN(void);																				//Turn off GREEN led



/**************************************************************************************************
 * Func : LED_Toggle_ALL / LED_Toggle_colour /LED_Toggle_GREEN
 * Args
 * INPUT : None / colour /None / None ............
 *Return : None
 *Brief	 : toggle the specified led
 ************************************************************************/
void LED_Toggle_colour(LED_Light_colour led);												//toggle a specific led by colour
void LED_Toggle_RED(void);																					//toggle the RED led
void LED_Toggle_BLUE(void);																					//toggle the BLUE led
void LED_Toggle_GREEN(void);																				//toggle the GREEN led
#endif
/**********************************************************************************************************************
 *  END OF FILE: LED.h
 *********************************************************************************************************************/
