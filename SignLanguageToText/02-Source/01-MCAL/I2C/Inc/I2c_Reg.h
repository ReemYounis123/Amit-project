/*
 * I2c_Reg.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: El-Wattaneya
 */

#ifndef _I2C_REG_H_
#define _I2C_REG_H_

#define I2C_TWDR_REG      		(*(volatile u8*)(0x23))
#define I2C_TWAR_REG			(*(volatile u8*)(0x22))
#define I2C_TWCR_REG			(*(volatile u8*)(0x56))
#define I2C_TWSR_REG			(*(volatile u8*)(0x21))
#define I2C_TWBR_REG			(*(volatile u8*)(0x20))

#endif /* 02_SOURCE_01_MCAL_I2C_INC_I2C_REG_H_ */
