/*
 * I2c_Private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: El-Wattaneya
 */

#ifndef _I2C_PRIVATE_H_
#define _I2C_PRIVATE_H_

#include "Std_Types.h"

/****************************************
 *  GLOBAL CONSTANT MACROS
 ***************************************/

#define I2C_START_COND					(1<<5)
#define I2C_STOP_COND					(1<<4)
#define I2C_ENABLE						(1<<2)
#define I2C_INTERRUPT_FLAG				(1<<7)
#define I2C_ENABLE_ACK					(1<<6)
#define I2C_INTERRUPT_FLAG_BIT_NO		 (7)
#define I2C_SLAVE_RESPONSE_BIT_NO		 (0)

#endif /* I2C_PRIVATE_H_ */
