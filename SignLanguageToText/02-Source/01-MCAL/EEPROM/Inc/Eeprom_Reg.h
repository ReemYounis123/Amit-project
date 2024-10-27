/*
 * Eeprom.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: El-Wattaneya
 */

#ifndef _EEPROM_REG_H_
#define _EEPROM_REG_H_

#define EEPROM_ARH_REG				(*(volatile u8*)(0x3F))
#define EEPROM_ARL_REG				(*(volatile u8*)(0x3E))
#define EEPROM_DR_REG				(*(volatile u8*)(0x3D))
#define EEPROM_CR_REG				(*(volatile u8*)(0x3C))

#define EERE				(0u)
#define EEWE             	(1u)
#define EEMWE				(2u)


#endif /* EEPROM_REG_H_ */
