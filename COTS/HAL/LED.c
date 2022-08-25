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
 
 /**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

 #include "LED.h"

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

void LED_Init_ALL		(void){
		DIO_Init_Pin(GPIO_F,PIN1,OUTPUT);
		DIO_Init_Pin(GPIO_F,PIN2,OUTPUT);
		DIO_Init_Pin(GPIO_F,PIN3,OUTPUT);
}
void LED_Init_RED		(void){
	DIO_Init_Pin(GPIO_F,PIN1,OUTPUT);
}
void LED_Init_BLUE	(void){
	DIO_Init_Pin(GPIO_F,PIN2,OUTPUT);
}
void LED_Init_GREEN	(void){
	DIO_Init_Pin(GPIO_F,PIN3,OUTPUT);
}
void LED_Init_colour		(LED_Light_colour led){
DIO_Init_Pin(GPIO_F,led,OUTPUT);
}



void LED_TurnOn_colour(LED_Light_colour led){
	DIO_Set_pin_HIGH(GPIO_F,led);
}
void LED_TurnOn_RED(void){
	DIO_Set_pin_HIGH(GPIO_F,PIN1);
}
void LED_TurnOn_BLUE(void){
	DIO_Set_pin_HIGH(GPIO_F,PIN2);
}
void LED_TurnOn_GREEN(void){
	DIO_Set_pin_HIGH(GPIO_F,PIN3);
}





void LED_TurnOff_colour(LED_Light_colour led){
	DIO_Set_pin_LOW(GPIO_F,led);
}
void LED_TurnOff_RED(void){
	DIO_Set_pin_LOW(GPIO_F,PIN1);
}
void LED_TurnOff_BLUE(void){
	DIO_Set_pin_LOW(GPIO_F,PIN2);
}
void LED_TurnOff_GREEN(void){
	DIO_Set_pin_LOW(GPIO_F,PIN3);
}





void LED_Toggle_colour(LED_Light_colour led){
DIO_Toggle_pin(GPIO_F,led);
}
void LED_Toggle_RED(void){
	DIO_Toggle_pin(GPIO_F,PIN1);
}
void LED_Toggle_BLUE(void){
	DIO_Toggle_pin(GPIO_F,PIN2);
}
void LED_Toggle_GREEN(void){
	DIO_Toggle_pin(GPIO_F,PIN3);
}
 
/**********************************************************************************************************************
 *  END OF FILE: LED.c
 *********************************************************************************************************************/
