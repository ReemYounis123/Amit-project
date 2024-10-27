/*
 * Led.c
 *Reem Younis
 */


#include "Led.h"

void LED_Init(void)
{
	Dio_ConfigChannel(LED0_PORT,LED0_PIN,OUTPUT);
	Dio_ConfigChannel(LED1_PORT,LED1_PIN,OUTPUT);
	Dio_ConfigChannel(LED2_PORT,LED2_PIN,OUTPUT);
}

void LED_ON(Led_Type ledID)
{
	switch(ledID)
	{
	case LED0:
		Dio_WriteChannel(LED0_PORT,LED0_PIN,STD_HIGH);
		break;

	case LED1:
		Dio_WriteChannel(LED1_PORT,LED1_PIN,STD_HIGH);
		break;

	case LED2:
		Dio_WriteChannel(LED2_PORT,LED2_PIN,STD_HIGH);
		break;

	}
}

void LED_OFF(Led_Type ledID)
{
	switch(ledID)
	{
	case LED0:
		Dio_WriteChannel(LED0_PORT,LED0_PIN,STD_LOW);
		break;

	case LED1:
		Dio_WriteChannel(LED1_PORT,LED1_PIN,STD_LOW);
		break;

	case LED2:
		Dio_WriteChannel(LED2_PORT,LED2_PIN,STD_LOW);
		break;

	}
}

void LED_TOGGLE(Led_Type ledID)
{
	switch(ledID)
	{
	case LED0:
		Dio_ToggleChannel(LED0_PORT,LED0_PIN);
		break;

	case LED1:
		Dio_ToggleChannel(LED1_PORT,LED1_PIN);
		break;

	case LED2:
		Dio_ToggleChannel(LED2_PORT,LED2_PIN);
		break;

	}
}

