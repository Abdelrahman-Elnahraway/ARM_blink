
/*_____________________________GPIO.c_____________________________________________________
                                      ___           ___           ___
 Author: Abdelrahman Selim           /\  \         /\  \         /\  \
                                    /::\  \       /::\  \       /::\  \
Created on: Aug 20, 2022           /:/\:\  \     /:/\:\  \     /:/\:\  \
                                  /::\ \:\  \   _\:\ \:\  \   /::\ \:\  \
 Version: 01                     /:/\:\ \:\__\ /\ \:\ \:\__\ /:/\:\ \:\__\
                                 \/__\:\/:/  / \:\ \:\ \/__/ \/__\:\/:/  /
                                      \::/  /   \:\ \:\__\        \::/  /
                                      /:/  /     \:\/:/  /        /:/  /
 Brief : making my libraries         /:/  /       \::/  /        /:/  /
                                     \/__/         \/__/         \/__/
 _________________________________________________________________________________________*/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "GPIO.h"


/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

static volatile unsigned long *GPIO_LOCK_ADRESS[]={&GPIO_PORTA_LOCK,
&GPIO_PORTB_LOCK,
&GPIO_PORTC_LOCK,
&GPIO_PORTD_LOCK,
&GPIO_PORTE_LOCK,
&GPIO_PORTF_LOCK
};


static volatile unsigned long *GPIOCR_ADRESS[]={
&GPIO_PORTA_CR,
&GPIO_PORTB_CR,
&GPIO_PORTC_CR,
&GPIO_PORTD_CR,
&GPIO_PORTE_CR,
&GPIO_PORTF_CR
};

static volatile unsigned long *GPIOAMSEL_ADRESS[]={
&GPIO_PORTA_AMSEL,
&GPIO_PORTB_AMSEL,
&GPIO_PORTC_AMSEL,
&GPIO_PORTD_AMSEL,
&GPIO_PORTE_AMSEL,
&GPIO_PORTA_AMSEL,

};


static volatile unsigned long *GPIOPCTL_ADRESS[]={
	&GPIO_PORTA_PCTL,
	&GPIO_PORTB_PCTL,
	&GPIO_PORTC_PCTL,
	&GPIO_PORTD_PCTL,
	&GPIO_PORTE_PCTL,
	&GPIO_PORTF_PCTL,
};

static volatile unsigned long *GPIODEN_ADRESS[]={
		&GPIO_PORTA_DEN,
		&GPIO_PORTB_DEN,
		&GPIO_PORTC_DEN,
		&GPIO_PORTD_DEN,
		&GPIO_PORTE_DEN,
		&GPIO_PORTF_DEN,

};
/*
static volatile unsigned long *GPIODATA_ADRESS[]={

	&GPIO_PORTA_DATA,
	&GPIO_PORTB_DATA,
	&GPIO_PORTC_DATA,
	&GPIO_PORTD_DATA,
	&GPIO_PORTE_DATA,
	&GPIO_PORTF_DATA,

};
*/
static volatile unsigned long *GPIODATA_UNLOCKED_ADRESS[]={

	&GPIO_PORTA_DATA_UNLOCKED,
	&GPIO_PORTB_DATA_UNLOCKED,
	&GPIO_PORTC_DATA_UNLOCKED,
	&GPIO_PORTD_DATA_UNLOCKED,
	&GPIO_PORTE_DATA_UNLOCKED,
	&GPIO_PORTF_DATA_UNLOCKED,
};


static volatile unsigned long *GPIODIR_ADRESS[]={
	  &GPIO_PORTA_DIR,
		&GPIO_PORTB_DIR,
		&GPIO_PORTC_DIR,
		&GPIO_PORTD_DIR,
		&GPIO_PORTE_DIR,
		&GPIO_PORTF_DIR,

};
static volatile unsigned long *GPIOAFSEL_ADRESS[]={
		&GPIO_PORTA_AFSEL,
		&GPIO_PORTB_AFSEL,
		&GPIO_PORTC_AFSEL,
		&GPIO_PORTD_AFSEL,
		&GPIO_PORTE_AFSEL,
		&GPIO_PORTF_AFSEL,

};
static volatile unsigned long *GPIOPUR_ADRESS[]={
	&GPIO_PORTA_PUR,
	&GPIO_PORTB_PUR,
	&GPIO_PORTC_PUR,
	&GPIO_PORTD_PUR,
	&GPIO_PORTE_PUR,
	&GPIO_PORTF_PUR,
};

static volatile unsigned long *GPIOPDR_ADRESS[]={
	&GPIO_PORTA_PDR,
	&GPIO_PORTB_PDR,
	&GPIO_PORTC_PDR,
	&GPIO_PORTD_PDR,
	&GPIO_PORTE_PDR,
	&GPIO_PORTF_PDR,
};


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/



 void GPIO_Enable_Clock(GPIO_port_name_t Port_Name){
	SET_BIT(GPIO_RCGC2,Port_Name); //ENABLING THE clock to port Port_name
	 GPIO_RCGC2=GPIO_RCGC2; //dummy delay  will be excuted as the register is volatile
	}
 
	
  void GPIO_Disable_Clock(GPIO_port_name_t Port_Name){
	CLEAR_BIT(GPIO_RCGC2,Port_Name); //Disable THE clock to port Port_name
		GPIO_RCGC2=GPIO_RCGC2; //dummy delay  will be excuted as the register is volatile
	}




void GPIO_Unlock_Port(GPIO_port_name_t Port_Name){
	WRITE_PORT(*GPIO_LOCK_ADRESS[Port_Name],0x4C4F434BUL);		//Write the key in the specific unlock port
	}




void GPIO_Enable_pin_Edit(GPIO_port_name_t Port_Name,uint8_t pin){
SET_BIT(*GPIOCR_ADRESS[Port_Name],pin); // GPIOAFSEL, GPIOPUR, GPIOPDR
}

void GPIO_Disable_pin_Edit(GPIO_port_name_t Port_Name,uint8_t pin){
CLEAR_BIT(*GPIOCR_ADRESS[Port_Name],pin); // GPIOAFSEL, GPIOPUR, GPIOPDR
}

void GPIO_Enable_pinMask_Edit(GPIO_port_name_t Port_Name,uint8_t pins_Set_mask){
PORT_SET_MASK(*GPIOCR_ADRESS[Port_Name],pins_Set_mask);// set the high bits in the GPIOCR
}

void GPIO_Disable_PinMask_Edit(GPIO_port_name_t Port_Name,uint8_t pins_mask){
PORT_CLEAR_MASK(*GPIOCR_ADRESS[Port_Name],pins_mask); // Clear the low bits in the GPIOCR
}


void GPIO_Set_AMSEL_As_DIO_pin(GPIO_port_name_t Port_Name,uint8_t pin){
CLEAR_BIT(*GPIOAMSEL_ADRESS[Port_Name],pin); // clear the bit in the AMSEL to set as digital
}
void GPIO_Set_AMSEL_As_ANALOG_pin(GPIO_port_name_t Port_Name,uint8_t pin){   //Enable ANALOG INPUT
SET_BIT(*GPIOAMSEL_ADRESS[Port_Name],pin);// Set the bit in the AMSEL to set as analog
}





void GPIO_Set_MuxAs_DIO_pin(GPIO_port_name_t Port_Name,uint8_t pin){   //GPIO CONTROL MUX
	
*GPIOPCTL_ADRESS[Port_Name]&=(~(0xFUL<<(pin*4)));  //CLEAR the 3 bits of the mux to connect the pin to the dio only
		}

		

void GPIO_Set_AlFun_As_DIO_pin(GPIO_port_name_t Port_Name,uint32_t pin){
CLEAR_BIT(*GPIOAFSEL_ADRESS[Port_Name],pin); //clear alternitive function bit in AFSEL
}
void GPIO_Set_AlFun_As_Alternative_pin(GPIO_port_name_t Port_Name,uint32_t pin){
SET_BIT(*GPIOAFSEL_ADRESS[Port_Name],pin);  //set alternitive function bit in AFSEL
}


void DIO_Set_Direction_pin(GPIO_port_name_t Port_Name,uint32_t pin,uint32_t direction){
WRITE_BIT(*GPIODIR_ADRESS[Port_Name],pin,direction); //write the direction bit in GPIODIR 

}

void DIO_Enable_PullUp_pin(GPIO_port_name_t Port_Name,uint32_t pin){
	GPIO_Unlock_Port(Port_Name); // UNLOCKING THE PORT
SET_BIT(*GPIOPUR_ADRESS[Port_Name],pin); // setting the bit in GPIOPUR 
}
void DIO_Disable_PullUp_pin(GPIO_port_name_t Port_Name,uint32_t pin){
		GPIO_Unlock_Port(Port_Name); // UNLOCKING THE PORT
CLEAR_BIT(*GPIOPUR_ADRESS[Port_Name],pin); // clear the bit in GPIOPUR 
}




void DIO_Enable_PullDown_pin(GPIO_port_name_t Port_Name,uint32_t pin){
	GPIO_Unlock_Port(Port_Name); // UNLOCKING THE PORT
SET_BIT(*GPIOPDR_ADRESS[Port_Name],pin);
}
void DIO_Disable_PullDown_pin(GPIO_port_name_t Port_Name,uint32_t pin){
		GPIO_Unlock_Port(Port_Name); // UNLOCKING THE PORT
CLEAR_BIT(*GPIOPDR_ADRESS[Port_Name],pin);
}
/****************************************GPIODEN**********************************************************
Value			Description
0					The digital functions for the corresponding pin are disabled.
1					The digital functions for the corresponding pin are Enabled.
*******************************************************************************************************/
void GPIO_Enable_DIO_pin(GPIO_port_name_t Port_Name,uint32_t pin){
	GPIO_Unlock_Port(Port_Name); // UNLOCKING THE PORT
SET_BIT(*GPIODEN_ADRESS[Port_Name],pin);
	
}
void GPIO_Disable_DIO_pin(GPIO_port_name_t Port_Name,uint32_t pin){
		GPIO_Unlock_Port(Port_Name); // UNLOCKING THE PORT
CLEAR_BIT(*GPIODEN_ADRESS[Port_Name],pin);
}




void DIO_Set_pin_HIGH(GPIO_port_name_t Port_Name,uint32_t pin){
SET_BIT(*GPIODATA_UNLOCKED_ADRESS[Port_Name],pin);
}
void DIO_Set_pin_LOW(GPIO_port_name_t Port_Name,uint32_t pin){
CLEAR_BIT(*GPIODATA_UNLOCKED_ADRESS[Port_Name],pin);
}	
void DIO_Toggle_pin(GPIO_port_name_t Port_Name,uint32_t pin){
TOG_BIT(*GPIODATA_UNLOCKED_ADRESS[Port_Name],pin);
}
void DIO_Write_pin(GPIO_port_name_t Port_Name,uint32_t pin,uint32_t value){
WRITE_BIT(*GPIODATA_UNLOCKED_ADRESS[Port_Name],pin,value);
}

void DIO_Init_Pin(GPIO_port_name_t Port_Name,uint8_t pin,uint32_t direction){
	GPIO_Enable_Clock(Port_Name);						
	GPIO_Unlock_Port(Port_Name); // UNLOCKING THE PORT
GPIO_Enable_pin_Edit(Port_Name,pin);
	GPIO_Set_AMSEL_As_DIO_pin(Port_Name,pin);
	GPIO_Set_MuxAs_DIO_pin(Port_Name,pin);
		DIO_Set_Direction_pin(Port_Name,pin,direction);
	GPIO_Set_AlFun_As_DIO_pin(Port_Name,pin);
		GPIO_Enable_DIO_pin(Port_Name,pin);
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/

