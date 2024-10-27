/*
 * Led.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: El-Wattaneya
 */

#ifndef LED_H_
#define LED_H_

#include "Dio.h"
#include "Led_Types.h"
#include "Led_Cfg.h"

void LED_Init(void);
void LED_ON(Led_Type ledID);
void LED_OFF(Led_Type ledID);
void LED_TOGGLE(Led_Type ledID);

#endif /* LED_H_ */
