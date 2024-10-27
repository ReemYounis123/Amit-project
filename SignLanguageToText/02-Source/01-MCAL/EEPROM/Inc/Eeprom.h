/*
 * Eeprom.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: El-Wattaneya
 */

#ifndef _EEPROM_H_
#define _EEPROM_H_

#include "Eeprom_Reg.h"
#include "Std_Types.h"

void EEPROM_Write(u16 address,u8 data);
u8 EEPROM_Read(u16 address);

#endif /* EEPROM_H_ */
