/*
 * Dio.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: El-Wattaneya
 */

#ifndef DIO_H_
#define DIO_H_

#include "Bit_Math.h"
#include "DIO_REG.h"
#include "Dio_Types.h"
#include "Std_Types.h"



/* Functions Prototypes*/
void Dio_ConfigChannel(port_type port,pin_type pin,direction_type direction);
void Dio_WriteChannel(port_type port,pin_type pin,level_type level);
void Dio_WriteGroup(port_type port,u8 mask,u8 data);
void Dio_ToggleChannel(port_type port,pin_type pin);
level_type Dio_ReadChannel(port_type port,pin_type pin);


#endif /* DIO_H_ */
