
/*_____________________________MEM_MAP.h_____________________________________________________
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
#ifndef MCAL_REGISTERS_MEM_MAP_H_
#define MCAL_REGISTERS_MEM_MAP_H_

#include "TM4C123GH6PM.h"
#include "UTILS.h"

#include "CONFIG.h"
#include "UTILS.h"
#include "MEM_MAP.h"
#include <stdint.h>

/* ================================================================================ */
/* ================    						 GPIO_x REGISTERS    						 ================ */
/* ================================================================================ */


#define GPIODATA_OFFSET									0x000UL		//GPIO Data 0x000
#define GPIODATA_OFFSET_ULOCKALL				0x3FCUL		//GPIO Data 
#define GPIODIR_OFFSET									0x400UL		//GPIO Direction
#define GPIOIS_OFFSET										0x404UL		//GPIO Interrupt Sense
#define GPIOIBE_OFFSET									0x408UL		//GPIO Interrupt Both Edges
#define GPIOIEV_OFFSET									0x40CUL		//GPIO Interrupt Event
#define GPIOIM_OFFSET										0x410UL		//GPIO Interrupt Mask
#define GPIORIS_OFFSET									0x414UL		//GPIO Raw Interrupt Status
#define GPIOMIS_OFFSET									0x418UL		//GPIO Masked Interrupt Status
#define GPIOICR_OFFSET									0x41CUL		//GPIO Interrupt Clear
#define GPIOAFSEL_OFFSET								0x420UL		//GPIO Alternate Function Select
#define GPIODR2R_OFFSET									0x500UL		//GPIO 2-mA Drive Select
#define GPIODR4R_OFFSET									0x504UL		//GPIO 4-mA Drive Select
#define GPIODR8R_OFFSET									0x508UL		//GPIO 8-mA Drive Select
#define GPIOODR_OFFSET									0x50CUL		//GPIO Open Drain Select
#define GPIOPUR_OFFSET									0x510UL		//GPIO Pull-Up Select
#define GPIOPDR_OFFSET									0x514UL		//GPIO Pull-Down Select
#define GPIOSLR_OFFSET									0x518UL		//GPIO Slew Rate Control Select
#define GPIODEN_OFFSET									0x51CUL		//GPIO Digital Enable
#define GPIOLOCK_OFFSET									0x520UL		//GPIO Lock
#define GPIOCR_OFFSET										0x524UL		//GPIO Commit	clock enable RCGC
#define GPIOCR2_OFFSET									0x108UL		//GPIO Commit clock enable RCGC2
#define GPIOAMSEL_OFFSET								0x528UL		//GPIO Analog Mode Select
#define GPIOPCTL_OFFSET									0x52CUL		//GPIO Port Control
#define GPIOADCCTL_OFFSET								0x530UL		//GPIO ADC Control
#define GPIODMACTL_OFFSET								0x534UL		//GPIO DMA Control
#define GPIOPeriphID4_OFFSET						0xFD0UL		//GPIO Peripheral Identification 4
#define GPIOPeriphID5_OFFSET						0xFD4UL		//GPIO Peripheral Identification 5
#define GPIOPeriphID6_OFFSET						0xFD8UL		//GPIO Peripheral Identification 6
#define GPIOPeriphID7_OFFSET						0xFDCUL		//GPIO Peripheral Identification 7
#define GPIOPeriphID0_OFFSET						0xFE0UL		//GPIO Peripheral Identification 0
#define GPIOPeriphID1_OFFSET						0xFE4UL		//GPIO Peripheral Identification 1
#define GPIOPeriphID2_OFFSET						0xFE8UL		//GPIO Peripheral Identification 2
#define GPIOPeriphID3_OFFSET						0xFECUL		//GPIO Peripheral Identification 3
#define GPIOPCellID0_OFFSET							0xFF0UL		//GPIO PrimeCell Identification 0
#define GPIOPCellID1_OFFSET							0xFF4UL		//GPIO PrimeCell Identification 1
#define GPIOPCellID2_OFFSET							0xFF8UL		//GPIO PrimeCell Identification 2
#define GPIOPCellID3_OFFSET							0xFFCUL		//GPIO PrimeCell Identification 3





//GPIO Data

//#define SYSCTL_RCGCGPIO										(*((volatile SYSCTL_RCGCGPIO_Tag*)(SYSCTL_BASE+0x608)))
#define GPIORCGC2_OFFSET							0x108UL

#define GPIO_RCGC       			HWREG_32((SYSCTL_BASE	 +GPIOCR_OFFSET)) // only the last 5 bits avilable fro 0 to 4 0 for gpioA 1 is enable

#define GPIO_RCGC2       			HWREG_32((SYSCTL_BASE	 +GPIOCR2_OFFSET)) // only the last 5 bits avilable fro 0 to 4 0 for gpioA 1 is enable



#define GPIO_PORTA_DATA       HWREG_32((GPIOA_BASE +GPIODATA_OFFSET))
#define GPIO_PORTB_DATA       HWREG_32((GPIOB_BASE +GPIODATA_OFFSET))
#define GPIO_PORTC_DATA       HWREG_32((GPIOC_BASE +GPIODATA_OFFSET))
#define GPIO_PORTD_DATA       HWREG_32((GPIOD_BASE +GPIODATA_OFFSET))
#define GPIO_PORTE_DATA       HWREG_32((GPIOE_BASE +GPIODATA_OFFSET))
#define GPIO_PORTF_DATA       HWREG_32((GPIOF_BASE +GPIODATA_OFFSET))

#define GPIO_PORTA_DATA_UNLOCKED       HWREG_32((GPIOA_BASE +GPIODATA_OFFSET_ULOCKALL))
#define GPIO_PORTB_DATA_UNLOCKED       HWREG_32((GPIOB_BASE +GPIODATA_OFFSET_ULOCKALL))
#define GPIO_PORTC_DATA_UNLOCKED       HWREG_32((GPIOC_BASE +GPIODATA_OFFSET_ULOCKALL))
#define GPIO_PORTD_DATA_UNLOCKED       HWREG_32((GPIOD_BASE +GPIODATA_OFFSET_ULOCKALL))
#define GPIO_PORTE_DATA_UNLOCKED       HWREG_32((GPIOE_BASE +GPIODATA_OFFSET_ULOCKALL))
#define GPIO_PORTF_DATA_UNLOCKED       HWREG_32((GPIOF_BASE +GPIODATA_OFFSET_ULOCKALL))

#define GPIO_PORTA_DIR        HWREG_32((GPIOA_BASE +GPIODIR_OFFSET))
#define GPIO_PORTB_DIR        HWREG_32((GPIOB_BASE +GPIODIR_OFFSET))
#define GPIO_PORTC_DIR        HWREG_32((GPIOC_BASE +GPIODIR_OFFSET))
#define GPIO_PORTD_DIR        HWREG_32((GPIOD_BASE +GPIODIR_OFFSET))
#define GPIO_PORTE_DIR        HWREG_32((GPIOE_BASE +GPIODIR_OFFSET))
#define GPIO_PORTF_DIR        HWREG_32((GPIOF_BASE +GPIODIR_OFFSET))

#define GPIO_PORTA_AFSEL      HWREG_32((GPIOA_BASE +GPIOAFSEL_OFFSET))
#define GPIO_PORTB_AFSEL      HWREG_32((GPIOB_BASE +GPIOAFSEL_OFFSET))
#define GPIO_PORTC_AFSEL      HWREG_32((GPIOC_BASE +GPIOAFSEL_OFFSET))
#define GPIO_PORTD_AFSEL      HWREG_32((GPIOD_BASE +GPIOAFSEL_OFFSET))
#define GPIO_PORTE_AFSEL      HWREG_32((GPIOE_BASE +GPIOAFSEL_OFFSET))
#define GPIO_PORTF_AFSEL      HWREG_32((GPIOF_BASE +GPIOAFSEL_OFFSET))

#define GPIO_PORTA_PUR        HWREG_32((GPIOA_BASE +GPIOPUR_OFFSET))
#define GPIO_PORTB_PUR        HWREG_32((GPIOB_BASE +GPIOPUR_OFFSET))
#define GPIO_PORTC_PUR        HWREG_32((GPIOC_BASE +GPIOPUR_OFFSET))
#define GPIO_PORTD_PUR        HWREG_32((GPIOD_BASE +GPIOPUR_OFFSET))
#define GPIO_PORTE_PUR        HWREG_32((GPIOE_BASE +GPIOPUR_OFFSET))
#define GPIO_PORTF_PUR        HWREG_32((GPIOF_BASE +GPIOPUR_OFFSET))

#define GPIO_PORTA_PDR        HWREG_32((GPIOA_BASE +GPIOPDR_OFFSET))
#define GPIO_PORTB_PDR        HWREG_32((GPIOB_BASE +GPIOPDR_OFFSET))
#define GPIO_PORTC_PDR        HWREG_32((GPIOC_BASE +GPIOPDR_OFFSET))
#define GPIO_PORTD_PDR        HWREG_32((GPIOD_BASE +GPIOPDR_OFFSET))
#define GPIO_PORTE_PDR        HWREG_32((GPIOE_BASE +GPIOPDR_OFFSET))
#define GPIO_PORTF_PDR        HWREG_32((GPIOF_BASE +GPIOPDR_OFFSET))

#define GPIO_PORTA_DEN        HWREG_32((GPIOA_BASE +GPIODEN_OFFSET))
#define GPIO_PORTB_DEN        HWREG_32((GPIOB_BASE +GPIODEN_OFFSET))
#define GPIO_PORTC_DEN        HWREG_32((GPIOC_BASE +GPIODEN_OFFSET))
#define GPIO_PORTD_DEN        HWREG_32((GPIOD_BASE +GPIODEN_OFFSET))
#define GPIO_PORTE_DEN        HWREG_32((GPIOE_BASE +GPIODEN_OFFSET))
#define GPIO_PORTF_DEN        HWREG_32((GPIOF_BASE +GPIODEN_OFFSET))

#define GPIO_PORTA_LOCK       HWREG_32((GPIOA_BASE +GPIOLOCK_OFFSET))
#define GPIO_PORTB_LOCK       HWREG_32((GPIOB_BASE +GPIOLOCK_OFFSET))
#define GPIO_PORTC_LOCK       HWREG_32((GPIOC_BASE +GPIOLOCK_OFFSET))
#define GPIO_PORTD_LOCK       HWREG_32((GPIOD_BASE +GPIOLOCK_OFFSET))
#define GPIO_PORTE_LOCK       HWREG_32((GPIOE_BASE +GPIOLOCK_OFFSET))
#define GPIO_PORTF_LOCK       HWREG_32((GPIOF_BASE +GPIOLOCK_OFFSET))

#define GPIO_PORTA_CR         HWREG_32((GPIOA_BASE +GPIOCR_OFFSET))
#define GPIO_PORTB_CR         HWREG_32((GPIOB_BASE +GPIOCR_OFFSET))
#define GPIO_PORTC_CR         HWREG_32((GPIOC_BASE +GPIOCR_OFFSET))
#define GPIO_PORTD_CR         HWREG_32((GPIOD_BASE +GPIOCR_OFFSET))
#define GPIO_PORTE_CR         HWREG_32((GPIOE_BASE +GPIOCR_OFFSET))
#define GPIO_PORTF_CR         HWREG_32((GPIOF_BASE +GPIOCR_OFFSET))


#define GPIO_PORTA_AMSEL      HWREG_32((GPIOA_BASE +GPIOAMSEL_OFFSET))
#define GPIO_PORTB_AMSEL      HWREG_32((GPIOB_BASE +GPIOAMSEL_OFFSET))
#define GPIO_PORTC_AMSEL      HWREG_32((GPIOC_BASE +GPIOAMSEL_OFFSET))
#define GPIO_PORTD_AMSEL      HWREG_32((GPIOD_BASE +GPIOAMSEL_OFFSET))
#define GPIO_PORTE_AMSEL      HWREG_32((GPIOE_BASE +GPIOAMSEL_OFFSET))
#define GPIO_PORTF_AMSEL      HWREG_32((GPIOF_BASE +GPIOAMSEL_OFFSET))


#define GPIO_PORTA_PCTL       HWREG_32((GPIOA_BASE +GPIOPCTL_OFFSET))
#define GPIO_PORTB_PCTL       HWREG_32((GPIOB_BASE +GPIOPCTL_OFFSET))
#define GPIO_PORTC_PCTL       HWREG_32((GPIOC_BASE +GPIOPCTL_OFFSET))
#define GPIO_PORTD_PCTL       HWREG_32((GPIOD_BASE +GPIOPCTL_OFFSET))
#define GPIO_PORTE_PCTL       HWREG_32((GPIOE_BASE +GPIOPCTL_OFFSET))
#define GPIO_PORTF_PCTL       HWREG_32((GPIOF_BASE +GPIOPCTL_OFFSET))

//#define SYSCTL_RCGC2          HWREG_32(0x400FE 108UL)
	


/* ================================================================================ */
/* ================    						 		SysyticK		    						 ================ */
/* ================================================================================ */

#ifndef SCS_BASE 
#define SCS_BASE            (0xE000E000UL)                            /*!< System Control Space Base Address */
#endif


#define STCTRL_OFFSET												0x010UL		//SysTick Control and Status Register (STCTRL)
#define STRELOAD_OFFSET											0x014UL		//Register 2: SysTick Reload Value Register (STRELOAD), offset 0x014
#define STCURRENT_OFFSET										0x018UL		//SysTick Control and Status Register (STCTRL)


#define TIMER_STCTRL_R									HWREG_32((SCS_BASE	 +STCTRL_OFFSET   ))
#define NVIC_STRELOAD_R								HWREG_32((SCS_BASE	 +STRELOAD_OFFSET ))
#define NVIC_STCURRENT_R							HWREG_32((SCS_BASE	 +STCURRENT_OFFSET))


/* ================================================================================= */
/* ================    						 	 INTERRUPTS     						 		================ */
/* ================================================================================= */
#define INTCTRL_OFFSET											0xD04


#define INTCTRL_R							HWREG_32((SCS_BASE	 +INTCTRL_OFFSET))

#endif
