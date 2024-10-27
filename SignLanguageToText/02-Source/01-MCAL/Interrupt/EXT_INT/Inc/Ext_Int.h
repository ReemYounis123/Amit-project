/*
 * Ext_Int.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: El-Wattaneya
 */

#ifndef _INTERRUPT_EXT_INT_INC_EXT_INT_H_
#define _INTERRUPT_EXT_INT_INC_EXT_INT_H_

#include "Ext_Int_REG.h"
#include "Ext_Int_Types.h"
#include "Bit_Math.h"

void Ext_Interrupt_Enable(ext_int_type intID);
void Ext_Interrupt_Disable(ext_int_type intID);
void Ext_Interrupt_Sense_Control(ext_int_type intID, sense_mode t_mode);

#endif /* 02_SOURCE_01_MCAL_INTERRUPT_EXT_INT_INC_EXT_INT_H_ */
