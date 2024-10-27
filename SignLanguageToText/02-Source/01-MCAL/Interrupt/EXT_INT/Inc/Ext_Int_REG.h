/*
 * Ext_Int_REG.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: El-Wattaneya
 */

#ifndef _EXT_INT_INC_EXT_INT_REG_H_
#define _EXT_INT_INC_EXT_INT_REG_H_

#include "Std_Types.h"

#define MCUCSR_REG (*(volatile u8*)(0x54))  // INT2 Control
#define MCUCR_REG  (*(volatile u8*)(0x55))  // INT0 & INT1 Control
#define GIFR_REG   (*(volatile u8*)(0x5A))  //Interrupt flag
#define GICR_REG   (*(volatile u8*)(0x5B))  //Interrupt enable

#endif /* 02_SOURCE_01_MCAL_INTERRUPT_EXT_INT_INC_EXT_INT_REG_H_ */
