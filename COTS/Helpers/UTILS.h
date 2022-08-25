
/*_____________________________Utils.h_____________________________________________________
                                      ___           ___           ___
 Author: Abdelrahman Selim           /\  \         /\  \         /\  \
                                    /::\  \       /::\  \       /::\  \
Created on: Aug 20, 2022           /:/\:\  \     /:/\:\  \     /:/\:\  \
                                  /::\ \:\  \   _\:\ \:\  \   /::\ \:\  \
 Version: 01                     /:/\:\ \:\__\ /\ \:\ \:\__\ /:/\:\ \:\__\
                                 \/__\:\/:/  / \:\ \:\ \/__/ \/__\:\/:/  /
                                      \::/  /   \:\ \:\__\        \::/  /
                                      /:/  /     \:\/:/  /        /:/  /
																		 /:/  /       \::/  /        /:/  /
                                     \/__/         \/__/         \/__/
 _________________________________________________________________________________________*/
#ifndef UTILS_H_
#define UTILS_H_
#include "CONFIG.h"
/**********************************************************
 *  HWREG_S (Hardware register of size S)
 *  input: REG (register) , and the offset (HWREG_OFST)
 *  output: The value in the register with offset offset
 *  used to assign a macro name for the value in a specific address for more readability
 *  Example :3 #define  DDRB  HWREG_(0X34)
 *********************************************************/
#ifndef HWREG_OFST
#define HWREG_OFST 0x0000
#endif

#define HWREG_8(REG)  (*((volatile uint8_t*) ((REG)+HWREG_OFST)))
#define HWREG_16(REG) (*((volatile uint16_t*)((REG)+HWREG_OFST)))
#define HWREG_32(REG) (*((volatile unsigned long*)((REG)+HWREG_OFST)))


#define NULLPTR  ((void *)0)
	
#define HIGH 	1
#define LOW 	0

#define ON		1
#define OFF		0

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7
#ifdef CPU_8BIT
// Bit edit
#define WRITE_BIT(REG,BIT,VALUE) 	(REG=((REG&(~(1<<BIT)))|(VALUE<<BIT))) 	// write (VALUE) (1.0) in bit number (BIT) of the REG
#define CLEAR_BIT(REG,BIT) 			(REG=(REG&(~(1<<BIT))))     			// write (0) in bit number (BIT) of the register (REG)
#define SET_BIT(REG,BIT) 	 		(REG=(REG|(1<<BIT)))     				// write (1) in bit number (BIT) of the register (REG)
#define TOG_BIT(REG,BIT) 	 		(REG^=(1<<BIT))     					// toggle the specified bit(BIT) of the register (REG)
#define GET_BIT(REG,BIT) 	 		((REG >> BIT) & 1)     					// Return the value of the bit

// Port edit
#define WRITE_PORT(REG,VALUE) 		(REG=VALUE) 			// write (VALUE) on the port REG
#define CLEAR_PORT(REG) 			(REG=0X00)     			// write (0x11) on the register (REG)
#define SET_PORT(REG) 	 			(REG=0xFF)     			// write (0x00) on the register (REG)
#define TOG_PORT(REG) 	 			(REG=~REG)     			// toggle the port bits (turn the bit zero into one and vice versa)
#define GET_PORT(REG) 	 			(REG)     				// Return the values of the register
#define PORT_SET_MASK(REG,MASK)		(REG|=MASK)				// Set the high bits in the mask to high
#define PORT_CLEAR_MASK(REG,VAL)    (REG)&=~(VAL)			// Set the high bits in the mask to lOW
#define PORT_MASK(REG,SET_INDEX,CLEAR_INDEX)	REG=(REG&~(CLEAR_INDEX))|(SET_INDEX);



//Nibble edit
#define SWAP_NIBBLES(REG)     (REG=((REG>>4)&0x0F)|((REG<<4)&0xF0))

// HIGHER_NIBBLE MANIPULATION THE MOST 4 bits 0xF0 bits number from 4 to 7
#define WRITE_HIGHER_NIBBLE(REG,VALUE) 				(REG=(REG&0x0F)|(VALUE<<4)) 				// write (VALUE) on the port REG
#define CLEAR_HIGHER_NIBBLE(REG) 					(REG&=0x0F)     							// write (0x11) on the register (REG)
#define SET_HIGHER_NIBBLE(REG) 	 					(REG|=0xF0)     							// write (0x00) on the register (REG)
#define SET_HIGHER_NIBBLE_MASK(REG,VALUE) 	 		(REG=REG|(VALUE<<4))						// write (0x00) on the register (REG)
#define TOG_HIGHER_NIBBLE(REG) 	 					(REG=(REG&0x0F)|((~REG)&0xF0))				// toggle the port bits (turn the bit zero into one and vice versa)
#define GET_HIGHER_NIBBLE(REG) 	 					(REG&0xF0)									// Return the values of the higher nibble of the register
#define GET_HIGHER_NIBBLE_DOWN(REG) 				((REG>>4)&0x0F) // Get Values of the higher nibble then return it as the lower nibble in the byte _ example 0xE3 RETURN E

// LOWER_NIBBLE MANIPULATION THE LEAST 4 bits 0x0F
#define WRITE_LOWER_NIBBLE(REG,VALUE) 	(REG=(REG&0xF0)|(VALUE)) 				// write (VALUE) on the port REG
#define CLEAR_LOWER_NIBBLE(REG) 		(REG&=0xF0)     						// write (0x11) on the register (REG)
#define SET_LOWER_NIBBLE_MASK(REG,VALUE)(REG=REG|(VALUE))
#define SET_LOWER_NIBBLE(REG) 	 		(REG|=0x0F)     						// write (0x00) on the register (REG)
#define TOG_LOWER_NIBBLE(REG) 	 		(REG=(REG&0xF0)|((~REG)&0x0F))     		// toggle the port bits (turn the bit zero into one and vice versa)
#define GET_LOWER_NIBBLE(REG) 	 		(REG&0x0F)     							// Return the values of the higher nibble of the register
#define GET_LOWER_NIBBLE_UP(REG) 		((REG<<4)&0xF0)							// Get Values of the lower nibble then return it as the Higher nibble in the byte  EX: 0xE3 RETURN 30
#endif

#ifdef CPU_32BIT
// Bit edit
#define WRITE_BIT(REG,BIT,VALUE) 	(REG=((REG&(~(1UL<<BIT)))|(VALUE<<BIT))) 	// write (VALUE) (1.0) in bit number (BIT) of the REG
#define CLEAR_BIT(REG,BIT) 			(REG=(REG&(~(1UL<<BIT))))     							// write (0) in bit number (BIT) of the register (REG)
#define SET_BIT(REG,BIT) 	 		(REG=(REG|(1UL<<BIT)))     										// write (1) in bit number (BIT) of the register (REG)
#define TOG_BIT(REG,BIT) 	 		(REG^=(1UL<<BIT))     												// toggle the specified bit(BIT) of the register (REG)
#define GET_BIT(REG,BIT) 	 		((REG >> BIT) & 1)     												// Return the value of the bit

// Port edit
#define WRITE_PORT(REG,VALUE) 		(REG=VALUE) 															// write (VALUE) on the port REG
#define CLEAR_PORT(REG) 			(REG=0X00000000UL)     												// write (0x11) on the register (REG)
#define SET_PORT(REG) 	 			(REG=0xFFFFFFFFUL)     												// write (0x00) on the register (REG)
#define TOG_PORT(REG) 	 			(REG=~REG)     																// toggle the port bits (turn the bit zero into one and vice versa)
#define GET_PORT(REG) 	 			(REG)     																		// Return the values of the register
#define PORT_SET_MASK(REG,MASK)		(REG|=MASK)																// Set the high bits in the mask to high
#define REG_SET_MASK(REG,MASK)		(REG|=MASK)																// Set the high bits in the mask to high
#define PORT_CLEAR_MASK(REG,VAL)    (REG)&=~(VAL)														// Set the high bits in the mask to lOW
#define PORT_MASK(REG,SET_INDEX,CLEAR_INDEX)	REG=(REG&~(CLEAR_INDEX))|(SET_INDEX);



#endif


#endif /* UTILS_H_ */
