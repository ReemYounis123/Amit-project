/********************************
 * File  	:  Adc.h
 * Date	 	:  Mar 23, 2021
 * Target	:  ATMEGA32
 * Author	:  Reem Younis
 ********************************/

#ifndef ADC_H_
#define ADC_H_

#include "Std_Types.h"
#include "Bit_Math.h"

#include "Adc_Reg.h"

#define REF           			((u8)1<<6)
#define AVCC5V_REF    			((u8)1)
#define INTERNAL_REF  			((u8)3)

#define ADC_LEFT_ADJUST_RESULT   ((u8)1<<5)     //ADC left adjust result

#define ADC_ENABLE				 ((u8)1<<7)     //ADC Enable
#define ADC_START_CONVERSION     ((u8)1<<6)     //ADC start conversion
#define ADC_INTERRUPT_ENABLE     ((u8)1<<3)     //ADC interrupt enable
/*					ADC prescaler		*/
/*ADC frequency must be between 50KHZ and 200KHZ*/
#define ADCPS_2         (1)
#define ADCPS_4         (2)
#define ADCPS_8         (3)
#define ADCPS_16        (4)
#define ADCPS_32        (5)
#define ADCPS_64        (6)
#define ADCPS_128       (7)
#define ADIF_BIT_NO		(4)


#define ADC_CHNL0		(0)
#define ADC_CHNL1		(1)
#define ADC_CHNL2		(2)
#define ADC_CHNL3		(3)
#define ADC_CHNL4		(4)
#define ADC_CHNL5		(5)
#define ADC_CHNL6		(6)
#define ADC_CHNL7		(7)

#define ADC_STEP		(4.8f)

void adcInit(void);
void adcStartConversion(u8 chnlNo);
boolean adcBusy();
void adcResultFlagCheck(u8 chnlNo);


#endif /* 01_SOURCE_MCAL_ADC_INC_ADC_H_ */
