#include <stdio.h>
#include <stdint.h>

#include "INTCTRL.h"

#include "BLINK.h"
#define ON_TIME				10000
#define OFF_TIME			2000

int main(void) {
// mem map 
/*
	0x40000000,0x4F000000
	*/
	
  Blink_LED(GREEN,ON_TIME,OFF_TIME);
 GLOBALINTERRUPT_ENABLE();		 /* global enable interrupt */               

	while(1){}

}
  
