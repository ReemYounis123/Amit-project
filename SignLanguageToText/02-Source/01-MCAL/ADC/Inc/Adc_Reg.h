/********************************
 * File  	:  Adc_Reg.h
 * Date	 	:  Mar 23, 2021
 * Target	:  ATMEGA32
 * Author	:  Reem Younis
 ********************************/

#ifndef _ADC_REG_H_
#define _ADC_REG_H_

#include "Std_Types.h"

#define ADC_ADMUX_REG  (*(volatile u8*)(0x27))
#define ADC_ADCSRA_REG (*(volatile u8*)(0x26))
#define ADC_ADCH_REG   (*(volatile u8*)(0x25))
#define ADC_ADCL_REG   (*(volatile u8*)(0x24))


#endif /* 02_SOURCE_01_MCAL_ADC_INC_ADC_REG_H_ */
