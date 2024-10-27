/*
 * Ext_Int.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: El-Wattaneya
 */

#include "Ext_Int.h"

void Ext_Interrupt_Enable(ext_int_type intID)
{
	switch(intID)
	{
	case EXT_INT0:
		SET_BIT(GICR_REG,6);
		break;

	case EXT_INT1:
		SET_BIT(GICR_REG,7);
		break;

	case EXT_INT2:
		SET_BIT(GICR_REG,5);
		break;
	}
}

void Ext_Interrupt_Disable(ext_int_type intID)
{
	switch(intID)
	{
	case EXT_INT0:
		CLR_BIT(GICR_REG,6);
		break;

	case EXT_INT1:
		CLR_BIT(GICR_REG,7);
		break;

	case EXT_INT2:
		CLR_BIT(GICR_REG,5);
		break;
	}
}

void Ext_Interrupt_Sense_Control(ext_int_type intID, sense_mode mode)
{
	switch(intID)
	{
	case EXT_INT0:
		MCUCR_REG |=(mode<<0);
		break;

	case EXT_INT1:
		MCUCR_REG |=(mode<<2);
		break;

	case EXT_INT2:
		if(mode == FALLING_EDGE)
		{
			CLR_BIT(MCUCSR_REG,6);
		}
		else if(mode == RISING_EDGE)
		{
			SET_BIT(MCUCSR_REG,6);
		}
		else
		{
			// do nothing
		}
		break;
	}
}
