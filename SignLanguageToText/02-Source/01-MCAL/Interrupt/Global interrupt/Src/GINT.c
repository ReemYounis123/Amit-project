/*
 * GINT.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: El-Wattaneya
 */



#include "GINT.h"

void GINT_Enable(void)
{
	SET_BIT(GINT_SREG,7);
}

void GINT_Disable(void)
{
	CLR_BIT(GINT_SREG,7);
}
