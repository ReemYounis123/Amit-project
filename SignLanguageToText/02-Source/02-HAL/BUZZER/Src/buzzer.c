/*
 * buzzer.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: El-Wattaneya
 */

#include"buzzer.h"

void BUZZER_Init(void)
{
	Dio_ConfigChannel(BUZZER_PORT,BUZZER_PIN,OUTPUT);
}

void BUZZER_ON(void)
{
	Dio_WriteChannel(BUZZER_PORT,BUZZER_PIN,STD_HIGH);
}

void BUZZER_OFF(void)
{
	Dio_WriteChannel(BUZZER_PORT,BUZZER_PIN,STD_LOW);
}

void BUZZER_TOGGLE(void)
{
	Dio_ToggleChannel(BUZZER_PORT,BUZZER_PIN);
}
