/*
 * Eeprom24C16.h
 *
Reem Younis
 */

#ifndef __EEPROM24C16_H_
#define __EEPROM24C16_H_

#include "I2c.h"

void Eeprom24C16_Init(void);
void Eeprom24C16_WriteByte(u16 addr, u8 data);
u8 Eeprom24C16_ReadByte(u16 addr);
void Eeprom24C16_WriteStr(u8* str);

#endif /* 02_SOURCE_01_MCAL_EEPROM24C16_INC__EEPROM24C16_H_ */
