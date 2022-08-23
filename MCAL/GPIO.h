
/*__________________File:  GPIO.h_____________________________________________________
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

#ifndef MCAL_GPIO_H_
#define MCAL_GPIO_H_


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


#define INPUT 	0
#define OUTPUT 	1


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

typedef enum {
GPIO_A,
GPIO_B,
GPIO_C,
GPIO_D,
GPIO_E,
GPIO_F}
GPIO_port_name_t;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/




/********************************************************************
 * Func : GPIO_Enable_Clock
 * Args
 * INPUT : port name ex 	GPIO_A
 *Return : None
 *Brief	 : Enable the clock to the gpio then wait four clocks for the prepheral to work
 **********************************************************************/
void GPIO_Enable_Clock(GPIO_port_name_t Port_Name);



/********************************************************************
 * Func : GPIO_Disable_Clock
 * Args
 * INPUT : port name ex 	GPIO_A
 *Return : None
 *Brief: Disable the clock to the gpio then wait four clocks for the prepheral to work
 **********************************************************************/
void GPIO_Disable_Clock(GPIO_port_name_t Port_Name);

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
GPIO UnLock
Port Pins C0-3, D7 and F0/E7 are locked pins
A write of the value 0x4C4F.434B unlocks the GPIO Commit (GPIOCR)
register for write access.A write of any other value or a write to the
GPIOCR register reapplies the lock, preventing any register updates.
A read of this register returns the following values:


Value		Description
0x1			The GPIOCR register is locked and may not be modified.

0x0			The GPIOCR register is unlocked and may be modified.
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/********************************************************************
 * Func : GPIO_Unlock
 * Args
  * INPUT : port name ex 	GPIO_A
 *Return : None
 *Brief:  UnLock Port Pins C0-3, D7 and F0/E7 are locked pins
 **********************************************************************/
void GPIO_Unlock_Port(GPIO_port_name_t Port_Name);



/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
GPIO Commit  GPIO_Enable_pin enable manipulating the pin data
Value			Description
0					The corresponding GPIOAFSEL, GPIOPUR, GPIOPDR, or
					GPIODEN bits cannot be written.

1					The corresponding GPIOAFSEL, GPIOPUR, GPIOPDR, or
					GPIODEN bits can be written.
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/***********************************************************************
 * Func : GPIO_Enable_pin
 * Args
 * INPUT : port name  ex 	GPIO_A
 * 				 Pin 	 			ex  PIN7
 *Return : None
 *Brief	 :  enable manipulating the PIOAFSEL, GPIOPUR, GPIOPDR, or GPIODEN
  	  	  for the specified pin
 ************************************************************************/
void GPIO_Enable_pin_Edit(GPIO_port_name_t Port_Name,uint8_t pin);
void GPIO_Disable_pin_Edit(GPIO_port_name_t Port_Name,uint8_t pin);
void GPIO_Enable_pinMask_Edit(GPIO_port_name_t Port_Name,uint8_t pins_Set_mask);
void GPIO_Disable_PinMask_Edit(GPIO_port_name_t Port_Name,uint8_t pins_Clear_mask);






/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
GPIO Analog Mode Select
Value		Description
0				The analog function of the pin is Disabled, the isolation is
				Enabled, and the pin is capable of digital functions as specified
				by the other GPIO configuration registers.


1				The analog function of the pin is Enabled, the isolation is
				Disabled, and the pin is capable of analog functions.

Note:
This register and bits are only valid for GPIO signals that
share analog function through a unified I/O pad.
The reset state of this register is 0 for all signals.
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/***********************************************************************
 * Func : GPIO_SETAS_DIO_pin
 * Args
  * INPUT : port name ex 	GPIO_A
 * 					Pin 	 		ex 	PIN7
 *Return : None
 *Brief	 :  Set pin as digital input-output pin at the AMSEL REGISTER
			rather than as analog
 ************************************************************************/
void GPIO_Set_AMSEL_As_DIO_pin(GPIO_port_name_t Port_Name,uint8_t pin);


/***********************************************************************
 * Func : GPIO_SETAS_ANALOG_pin
 * Args
  * INPUT : port name ex 	GPIO_A
 * 			Pin 	 ex  	PIN7
 *Return : None
 *Brief	 :  Set pin as analog pin at the AMSEL REGISTER
			rather than as digital input-output
 ************************************************************************/
void GPIO_Set_AMSEL_As_ANALOG_pin(GPIO_port_name_t Port_Name,uint8_t pin);


/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
GPIO Port Control (GPIOPCTL)
Bit/Field					Name						Type				Reset					Description

31:28							PMC7						RW						__					Port Mux Control 7
																														his field controls the configuration for GPIO pin 7.
27:24							PMC6						RW						__					Port Mux Control 6
																														This field controls the configuration for GPIO pin 6.
23:20							PMC5						RW						__					Port Mux Control 5
																														This field controls the configuration for GPIO pin 5.
19:16							PMC4						RW						__					Port Mux Control 4
																														This field controls the configuration for GPIO pin 4.
15:12							PMC3						RW						__					Port Mux Control 3
																														This field controls the configuration for GPIO pin 3.
11:8							PMC2						RW						__					Port Mux Control 2
																														This field controls the configuration for GPIO pin 2.
7:4								PMC1						RW						__					Port Mux Control 1
																														This field controls the configuration for GPIO pin 1.
3:0								PMC0						RW						__					Port Mux Control 0
																														This field controls the configuration for GPIO pin 0.
===================================================================================
 * Func : GPIO_Set_MUXAs_DIO_pin
 * Args
  * INPUT : port name ex 	GPIO_A
 * 			Pin 	 ex  	PIN7
 *Return : None
 *Brief	 :  Set pin corresponding GPIOPCTL bit as DIO
 ************************************************************************/
void GPIO_Set_MuxAs_DIO_pin(GPIO_port_name_t Port_Name,uint8_t pin);

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Value			Description
0					The associated pin functions as a GPIO and is controlled by
					the GPIO registers.

1					The associated pin functions as a peripheral signal and is
					controlled by the alternate hardware function.
===================================================================================
 * Func : GPIO_Set_FUNCTION_AS_DIO_pin //  GPIO_Set_FUNCTION_AS_ALTERNITIVE_pin
 * Args
 * INPUT : port name ex 	GPIO_A
 * 			Pin 	 ex  	PIN7
 *Return : None
 *Brief	 :  Write pin corresponding AFSEL as alternative function  bit
 ************************************************************************/
void GPIO_Set_AlFun_As_DIO_pin(GPIO_port_name_t Port_Name,uint32_t pin);
void GPIO_Set_AlFun_As_Alternative_pin(GPIO_port_name_t Port_Name,uint32_t pin);

/*+++++++++++++++++++++++++++++++++++++++++++++++++++
		GPIODIR
Value			Description
0					Corresponding pin is an input.
1					Corresponding pins is an output.

===================================================================================
 * Func : GPIO_Set_DIRECTION_DIO_pin
 * Args
  * INPUT : port name 		ex 	GPIO_A
 * 					Pin 					ex  PIN7
 * 					Direction     ex   Input
 *Return : None
 *Brief	 :  Write pin corresponding GPIODIR bit input or output
 ************************************************************************/
void DIO_Set_Direction_pin(GPIO_port_name_t Port_Name,uint32_t pin,uint32_t direction);





/*+++++++++++++++++++++++++++++++++++++++++GPIOPUR+++++++++++++++++++++++++++++++++++++++++++++++++++++
Value			Description
0					The corresponding pin's weak pull-up resistor is Disabled.
1					The corresponding pin's weak pull-up resistor is Enabled.

===================================================================================
 * Func : GPIO_Disable_PULLUP_DIO_pin
 * Args
  * INPUT : port name ex 	GPIO_A
 * 					Pin 	 		ex  	PIN7
 *Return : None
 *Brief	 :  Write pin corresponding GPIOPUR
 ************************************************************************/
void DIO_Disable_PullUp_pin(GPIO_port_name_t Port_Name,uint32_t pin);
void DIO_Enable_PullUp_pin(GPIO_port_name_t Port_Name,uint32_t pin);



/*+++++++++++++++++++++++++++++++++++++++++GPIOPDR+++++++++++++++++++++++++++++++++++++++++++++++++++++
Value			Description
0					The corresponding pin's weak pull-down resistor is Disabled.
1					The corresponding pin's weak pull-down resistor is Enabled.

===================================================================================
 * Func : GPIO_Disable_PULLDOWN_DIO_pin
 * Args
  * INPUT : port name ex 	GPIO_A
 * 			Pin 	 ex  	PIN7
 *Return : None
 *Brief	 :  Write pin corresponding GPIOPDR
 ************************************************************************/
void DIO_Disable_PullDown_pin(GPIO_port_name_t Port_Name,uint32_t pin);
void DIO_Enable_PullDown_pin(GPIO_port_name_t Port_Name,uint32_t pin);

/****************************************GPIODEN**********************************************************
Value			Description
0					The digital functions for the corresponding pin are disabled.
1					The digital functions for the corresponding pin are Enabled.
===================================================================================
 * Func : GPIO_Disable_DIO_pin // GPIO_Enable_DIO_pin
 * Args
 * INPUT : port name ex 	GPIO_A
 * 			Pin 	 ex  	PIN7
 *Return : None
 *Brief	 :   Enable or Disable The digital functions for the corresponding pin.
 ************************************************************************/
void GPIO_Disable_DIO_pin(GPIO_port_name_t Port_Name,uint32_t pin);
void GPIO_Enable_DIO_pin(GPIO_port_name_t Port_Name,uint32_t pin);


void DIO_Init_Pin(GPIO_port_name_t Port_Name,uint8_t pin,uint32_t direction);
/****************************************GPIODATA**********************************************************
Description
GPIO Data
This register is virtually mapped to 256 locations in the address space.
To facilitate the reading and writing of data to these registers by
independent drivers, the data read from and written to the registers are
masked by the eight address lines [9:2]. Reads from this register return
its current state. Writes to this register only affect bits that are not masked
by ADDR[9:2] and are configured as outputs. See “Data Register
Operation” on page 654 for examples of reads and writes.
===================================================================================
 * Func : DIO_Write_pin // DIO_Toggle_pin // DIO_Set_pin_HIGH // DIO_Set_pin_LOW
 * Args
 * INPUT : port name ex 	GPIO_A
 * 				 Pin 	 		 ex  	PIN7
 * 				 value     ex   HIGH
 *Return : None
 *Brief	 :   Manipulating the pin level.
 *Note 	 : DIO_Init_Pin(GPIO_port_name_t Port_Name,uint8_t pin,uint32_t direction);
 ************************************************************************/
void DIO_Write_pin(GPIO_port_name_t Port_Name,uint32_t pin,uint32_t value);
void DIO_Toggle_pin(GPIO_port_name_t Port_Name,uint32_t pin);
void DIO_Set_pin_HIGH(GPIO_port_name_t Port_Name,uint32_t pin);
void DIO_Set_pin_LOW(GPIO_port_name_t Port_Name,uint32_t pin);

	#endif

/**********************************************************************************************************************
 *  END OF FILE: GPIO.h
 *********************************************************************************************************************/
