/********************************
 * File  	:  Adc.c
 * Date	 	:  Mar 23, 2021
 * Target	:  ATMEGA32
 * Author	:  Reem Younis
 ********************************/

#include "Adc.h"
#include <avr/interrupt.h>

volatile boolean ADC_CHNL0_Flag = FALSE;
volatile boolean ADC_CHNL1_Flag = FALSE;
volatile boolean ADC_CHNL2_Flag = FALSE;
volatile boolean ADC_CHNL3_Flag = FALSE;
volatile boolean ADC_CHNL4_Flag = FALSE;
volatile boolean ADC_CHNL5_Flag = FALSE;
volatile boolean ADC_CHNL6_Flag = FALSE;
volatile boolean ADC_CHNL7_Flag = FALSE;

volatile u16 result_ADC_CHNL0=0;
volatile u16 result_ADC_CHNL1=0;
volatile u16 result_ADC_CHNL2=0;
volatile u16 result_ADC_CHNL3=0;
volatile u16 result_ADC_CHNL4=0;
volatile u16 result_ADC_CHNL5=0;
volatile u16 result_ADC_CHNL6=0;
volatile u16 result_ADC_CHNL7=0;

volatile boolean ResultADCReadyFlag0 = FALSE;
volatile boolean ResultADCReadyFlag1 = FALSE;
volatile boolean ResultADCReadyFlag2 = FALSE;
volatile boolean ResultADCReadyFlag3 = FALSE;
volatile boolean ResultADCReadyFlag4 = FALSE;
volatile boolean ResultADCReadyFlag5 = FALSE;
volatile boolean ResultADCReadyFlag6 = FALSE;
volatile boolean ResultADCReadyFlag7 = FALSE;

void adcInit(void)
{
	ADC_ADMUX_REG|=(AVCC5V_REF<<6);  /*	AVCC as Vref	*/
	ADC_ADCSRA_REG=(ADC_ENABLE)|(ADCPS_128);
	ADC_ADCSRA_REG=(ADC_ADCSRA_REG)|(ADC_INTERRUPT_ENABLE);
}

void adcStartConversion(u8 chnlNo)
{
	switch(chnlNo)
	{
	case ADC_CHNL0:
		ADC_ADMUX_REG = (ADC_ADMUX_REG & 0xF8)|(ADC_CHNL0);
		ADC_ADCSRA_REG|=(ADC_START_CONVERSION);
		ADC_CHNL0_Flag = TRUE;
		break;

	case ADC_CHNL1:
		ADC_ADMUX_REG = (ADC_ADMUX_REG & 0xF8)|(ADC_CHNL1);
		ADC_ADCSRA_REG|=(ADC_START_CONVERSION);
		ADC_CHNL1_Flag = TRUE;
		break;

	case ADC_CHNL2:
		ADC_ADMUX_REG = (ADC_ADMUX_REG & 0xF8)|(ADC_CHNL2);
		ADC_ADCSRA_REG|=(ADC_START_CONVERSION);
		ADC_CHNL2_Flag = TRUE;
		break;

	case ADC_CHNL3:
		ADC_ADMUX_REG = (ADC_ADMUX_REG & 0xF8)|(ADC_CHNL3);
		ADC_ADCSRA_REG|=(ADC_START_CONVERSION);
		ADC_CHNL3_Flag = TRUE;
		break;

	case ADC_CHNL4:
		ADC_ADMUX_REG = (ADC_ADMUX_REG & 0xF8)|(ADC_CHNL4);
		ADC_ADCSRA_REG|=(ADC_START_CONVERSION);
		ADC_CHNL4_Flag = TRUE;
		break;

	case ADC_CHNL5:
		ADC_ADMUX_REG = (ADC_ADMUX_REG & 0xF8)|(ADC_CHNL5);
		ADC_ADCSRA_REG|=(ADC_START_CONVERSION);
		ADC_CHNL5_Flag = TRUE;
		break;

	case ADC_CHNL6:
		ADC_ADMUX_REG = (ADC_ADMUX_REG & 0xF8)|(ADC_CHNL6);
		ADC_ADCSRA_REG|=(ADC_START_CONVERSION);
		ADC_CHNL6_Flag = TRUE;
		break;

	case ADC_CHNL7:
		ADC_ADMUX_REG = (ADC_ADMUX_REG & 0xF8)|(ADC_CHNL7);
		ADC_ADCSRA_REG|=(ADC_START_CONVERSION);
		ADC_CHNL7_Flag = TRUE;
		break;
	}
}

boolean adcBusy()
{
	boolean state;
	if ((ADC_CHNL0_Flag||ADC_CHNL1_Flag||ADC_CHNL2_Flag||ADC_CHNL3_Flag||ADC_CHNL4_Flag||ADC_CHNL5_Flag||ADC_CHNL6_Flag||ADC_CHNL7_Flag)==TRUE)
	{
		state=TRUE;
	}

	else state=FALSE;

	return state;
}

void adcResultFlagCheck(u8 chnlNo)
{
	switch(chnlNo)
	{
	case ADC_CHNL0:

		if(adcBusy()==FALSE)
		{
			adcStartConversion(ADC_CHNL0);
			if (ResultADCReadyFlag0 == TRUE)
			{
				//Sensors calibration using LCD
				//thumb=result_ADC_CHNL7;  // why is it wrong?
				//UART_TransmitNum(values);
				//Lcd_Goto_Row_Column(0, 6);
				//Lcd_DisplayNUM(thumb)
				ResultADCReadyFlag0 = FALSE;
			}
		}
		break;

	case ADC_CHNL1:

		if(adcBusy()==FALSE)
		{
			adcStartConversion(ADC_CHNL1);
			if (ResultADCReadyFlag1 == TRUE)
			{
				ResultADCReadyFlag1 = FALSE;
			}
		}
		break;

	case ADC_CHNL2:

		if(adcBusy()==FALSE)
		{
			adcStartConversion(ADC_CHNL2);
			if (ResultADCReadyFlag2 == TRUE)
			{
				ResultADCReadyFlag2 = FALSE;
			}
		}
		break;

	case ADC_CHNL3:

		if(adcBusy()==FALSE)
		{
			adcStartConversion(ADC_CHNL3);
			if (ResultADCReadyFlag3 == TRUE)
			{
				ResultADCReadyFlag3 = FALSE;
			}
		}
		break;

	case ADC_CHNL4:

		if(adcBusy()==FALSE)
		{
			adcStartConversion(ADC_CHNL4);
			if (ResultADCReadyFlag4 == TRUE)
			{
				//UART_TransmitNum(values);
				//Lcd_Goto_Row_Column(0, 10);
				//Lcd_DisplayNUM(index_F);
				ResultADCReadyFlag4 = FALSE;
			}
		}
		break;

	case ADC_CHNL5:

		if(adcBusy()==FALSE)
		{
			adcStartConversion(ADC_CHNL5);
			if (ResultADCReadyFlag5 == TRUE)
			{
				//UART_TransmitNum(values);
				//Lcd_Goto_Row_Column(1, 0);
				//Lcd_DisplayNUM(middle);
				ResultADCReadyFlag5 = FALSE;
			}
		}
		break;

	case ADC_CHNL6:

		if(adcBusy()==FALSE)
		{
			adcStartConversion(ADC_CHNL6);
			if (ResultADCReadyFlag6 == TRUE)
			{
				//UART_TransmitNum(values);
				//Lcd_Goto_Row_Column(1, 4);
				//Lcd_DisplayNUM(ring);
				ResultADCReadyFlag6 = FALSE;
			}
		}
		break;

	case ADC_CHNL7:

		if(adcBusy()==FALSE)
		{
			//UART_TransmitNum(values);
			//Lcd_Goto_Row_Column(1, 8);
			//Lcd_DisplayNUM(little);
			adcStartConversion(ADC_CHNL7);
			if (ResultADCReadyFlag7 == TRUE)
			{
				ResultADCReadyFlag7 = FALSE;
			}
		}
		break;
	}
}
