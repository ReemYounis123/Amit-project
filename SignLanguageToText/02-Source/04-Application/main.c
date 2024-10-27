/*
 * main.c
 *
 *  Created on: 12þ/11þ/2021
 *      Author: Reem
 */


#include <util/delay.h>
#include <avr/interrupt.h>
#include "Led.h"
#include "LCD.h"
#include "buzzer.h"
#include "GINT.h"
#include "Ext_Int.h"
#include "Adc.h"
#include "Eeprom24C16.h"
#include "I2c.h"
#include "Uart.h"

extern volatile boolean ADC_CHNL0_Flag;
extern volatile boolean ADC_CHNL4_Flag;
extern volatile boolean ADC_CHNL5_Flag;
extern volatile boolean ADC_CHNL6_Flag;
extern volatile boolean ADC_CHNL7_Flag;

extern volatile boolean ResultADCReadyFlag0;
extern volatile boolean ResultADCReadyFlag4;
extern volatile boolean ResultADCReadyFlag5;
extern volatile boolean ResultADCReadyFlag6;
extern volatile boolean ResultADCReadyFlag7;

//#define bent (90)
//#define half_bent (45)
//#define flat (0)

volatile u8 thumb;
volatile u8 index_F;
volatile u8 middle;
volatile u8 ring;
volatile u8 little;



ISR(ADC_vect)
{
	if(ADC_CHNL0_Flag == TRUE)
	{
		thumb=(ADC_ADCL_REG|(ADC_ADCH_REG<<8));
		ResultADCReadyFlag0 = TRUE;
		ADC_CHNL0_Flag = FALSE;
	}

	else if(ADC_CHNL4_Flag == TRUE)
	{
		index_F=(ADC_ADCL_REG|(ADC_ADCH_REG<<8));
		ResultADCReadyFlag4 = TRUE;
		ADC_CHNL4_Flag = FALSE;
	}

	else if(ADC_CHNL5_Flag == TRUE)
	{
		middle=(ADC_ADCL_REG|(ADC_ADCH_REG<<8));
		ResultADCReadyFlag5 = TRUE;
		ADC_CHNL5_Flag = FALSE;
	}

	else if(ADC_CHNL6_Flag == TRUE)
	{
		ring=(ADC_ADCL_REG|(ADC_ADCH_REG<<8));
		ResultADCReadyFlag6 = TRUE;
		ADC_CHNL6_Flag = FALSE;
	}

	else if(ADC_CHNL7_Flag == TRUE)
	{
		little=(ADC_ADCL_REG|(ADC_ADCH_REG<<8));
		ResultADCReadyFlag7 = TRUE;
		ADC_CHNL7_Flag = FALSE;
	}

}

int main ()
{
	volatile u8 arr1[16]="STOP ";
	volatile u8 arr2[16]="PERFECTOO ";
	volatile u8 arr3[16]="IT HURTS ";
	volatile u8 arr4[16]="I HATE YOU ";
	volatile u8 arr5[16]="I'M OK ";
	volatile u8 arr6[16]="YOU! ";
	volatile u8 arr7[16]="DECOMPRESSION ";
	volatile u8 arr8[16]="THAT'S AMAZING! ";
	volatile u8 arr9[16]="I LOVE YOU ";
	volatile u8 arr10[16]="VICTORY! ";

	volatile u8 ptr[16];
	u8 i=0;

	//UART_Init(UART_BAUDRATE_9600);
	GINT_Enable();
	Lcd_Init();
	Lcd_Goto_Row_Column(0, 0);
	adcInit();
	//UART_TransmitStr("SENSOR READINGS...."); used for calibration of sensors
	//I2C_MasterInit();
	Eeprom24C16_Init();
	while(1)
	{
		adcResultFlagCheck(ADC_CHNL0);
		adcResultFlagCheck(ADC_CHNL4);
		adcResultFlagCheck(ADC_CHNL5);
		adcResultFlagCheck(ADC_CHNL6);
		adcResultFlagCheck(ADC_CHNL7);

		/*if (thumb>=22)
		{
			thumb=flat;
		}
		else {thumb=bent;}

		if (index_F>=22)
		{
			index_F=flat;
		}
		else {index_F=bent;}

		if (middle>=22)
		{
			middle=flat;
		}
		else {middle=bent;}

		if (ring>=22)
		{
			ring=flat;
		}
		else {ring=bent;}

		if (little>=22)
		{
			little=flat;
		}
		else {little=bent;}*/

		//if(((22<=thumb)||(thumb<=25))&&((24<=index_F)||(index_F<=32))&&((27<=middle)||(middle<=30))&&((30<=ring)||(ring<=32))&&((29<=little)||(little<=32)))
		if((thumb>21)&&(index_F>22)&&(middle>22)&&(ring>22)&&(little>22))
		//if((thumb==flat)&&(index_F==flat)&&(middle==flat)&&(ring==flat)&&(little==flat))
		{
			//arr1[16]="STOP ";
			i=0;
			while (arr1[i]!='\0'){
				Eeprom24C16_WriteByte(i,arr1[i]);
				i++;
			}
			i=0;
			while (arr1[i]!='\0'){
				ptr[i]=Eeprom24c16_ReadByte(i);
				i++;
				Lcd_DisplayChr(ptr[i]);
			}
			//Lcd_DisplayStr("STOP ");
			Lcd_Clear_Display();
		}

		//else if(((13<=thumb)||(thumb<=17))&&((16<=index_F)||(index_F<=18))&&((28<=middle)||(middle<=30))&&((25<=ring)||(ring<=30))&&((25<=little)||(little<=30)))
		else if((thumb<21)&&(index_F<22)&&(middle>22)&&(ring>22)&&(little>22))
		//else if((thumb==bent)&&(index_F==bent)&&(middle==flat)&&(ring==flat)&&(little==flat))
		{
			//arr2[16]="PERFECTOO ";
			i=0;
			while (arr2[i]!='\0'){
				Eeprom24C16_WriteByte(i,arr2[i]);
				i++;
			}
			i=0;
			while (arr2[i]!='\0'){
				ptr[i]=Eeprom24c16_ReadByte(i);
				i++;
				Lcd_DisplayChr(ptr[i]);
			}
			//Lcd_DisplayStr("PERFECTOO ");
			Lcd_Clear_Display();
		}

		//else if(((11<=thumb)||(thumb<=13))&&((12<=index_F)||(index_F<=14))&&((14<=middle)||(middle<=16))&&((12<=ring)||(ring<=15))&&((9<=little)||(little<=12)))
		else if((thumb<21)&&(index_F<22)&&(middle<22)&&(ring<22)&&(little<22))
		//else if((thumb==bent)&&(index_F==bent)&&(middle==bent)&&(ring==bent)&&(little==bent))
		{
			//arr3[16]= "IT HURTS ";
			i=0;
			while (arr3[i]!='\0'){
				Eeprom24C16_WriteByte(i,arr3[i]);
				i++;
			}
			i=0;
			while (arr3[i]!='\0'){
				ptr[i]=Eeprom24c16_ReadByte(i);
				i++;
				Lcd_DisplayChr(ptr[i]);
			}
			//Lcd_DisplayStr("IT HURTS ");
			Lcd_Clear_Display();
		}

		//else if(((14<=thumb)||(thumb<=17))&&((26<=index_F)||(index_F<=28))&&((14<=middle)||(middle<=16))&&((13<=little)||(little<=16))&&((13<=ring)||(ring<=16)))
		else if((thumb>21)&&(index_F>22)&&(middle>22)&&(little>22)&&(ring<22))
		//else if((thumb==flat)&&(index_F==flat)&&(middle==flat)&&(ring==bent)&&(little==flat))
		{
			//arr4[16]="I HATE YOU ";
			i=0;
			while (arr4[i]!='\0'){
				Eeprom24C16_WriteByte(i,arr4[i]);
				i++;
			}
			i=0;
			while (arr4[i]!='\0'){
				ptr[i]=Eeprom24c16_ReadByte(i);
				i++;
				Lcd_DisplayChr(ptr[i]);
			}
			//Lcd_DisplayStr("I HATE YOU ");
			Lcd_Clear_Display();
		}

		//else if(((11<=index_F)||(index_F<=13))&&((8<=little)||(little<=10))&&((12<=middle)||(middle<=14))&&((12<=ring)||(ring<=14))&&((23<=thumb)||(thumb<=26)))
		else if((index_F<22)&&(little<22)&&(middle<22)&&(ring<22)&&(thumb>21))
		//else if((thumb==flat)&&(index_F==bent)&&(middle==bent)&&(ring==bent)&&(little==bent))
		{
			//arr5[16]="I'M OK ";
			i=0;
			while (arr5[i]!='\0'){
				Eeprom24C16_WriteByte(i,arr5[i]);
				i++;
			}
			i=0;
			while (arr5[i]!='\0'){
				ptr[i]=Eeprom24c16_ReadByte(i);
				i++;
				Lcd_DisplayChr(ptr[i]);
			}
			//Lcd_DisplayStr("I'M OK ");
			Lcd_Clear_Display();
		}

		//else if(((14<=thumb)||(thumb<=17))&&((7<=little)||(little<=10))&&((14<=middle)||(middle<=16))&&((13<=ring)||(ring<=16))&&((26<=index_F)||(index_F<=28)))
		else if((thumb<21)&&(little<22)&&(middle<22)&&(ring<22)&&(index_F>22))
		//else if((thumb==bent)&&(index_F==flat)&&(middle==bent)&&(ring==bent)&&(little==bent))
		{
			//arr6[16]= "YOU! ";
			i=0;
			while (arr6[i]!='\0'){
				Eeprom24C16_WriteByte(i,arr6[i]);
				i++;
			}
			i=0;
			while (arr6[i]!='\0'){
				ptr[i]=Eeprom24c16_ReadByte(i);
				i++;
				Lcd_DisplayChr(ptr[i]);
			}
			//Lcd_DisplayStr("YOU! ");
			Lcd_Clear_Display();
		}

		//else if(((13<=thumb)||(thumb<=15))&&((12<=index_F)||(index_F<=14))&&((13<=middle)||(middle<=19))&&((15<=ring)||(ring<=17))&&((30<=little)||(little<=33)))
		else if((thumb<21)&&(index_F<22)&&(middle<22)&&(ring<22)&&(little>22))
		//else if((thumb==bent)&&(index_F==bent)&&(middle==bent)&&(ring==bent)&&(little==flat))
		{
			//arr7[16]= "DECOMPRESSION ";
			i=0;
			while (arr7[i]!='\0'){
				Eeprom24C16_WriteByte(i,arr7[i]);
				i++;
			}
			i=0;
			while (arr7[i]!='\0'){
				ptr[i]=Eeprom24c16_ReadByte(i);
				i++;
				Lcd_DisplayChr(ptr[i]);
			}
			//Lcd_DisplayStr("DECOMPRESSION ");
			Lcd_Clear_Display();
		}

		//else if(((12<=thumb)||(thumb<=14))&&((16<=middle)||(middle<=19))&&((19<=ring)||(ring<=21))&&((29<=index_F)||(index_F<=32))&&((29<=little)||(little<=32)))
		else if((thumb<22)&&(middle<22)&&(ring<22)&&(index_F>22)&&(little>22))
		//else if((thumb==bent)&&(index_F==flat)&&(middle==bent)&&(ring==bent)&&(little==flat))

		{
			//arr8[16]="THAT'S AMAZING! ";
			i=0;
			while (arr8[i]!='\0'){
				Eeprom24C16_WriteByte(i,arr8[i]);
				i++;
			}
			i=0;
			while (arr8[i]!='\0'){
				ptr[i]=Eeprom24c16_ReadByte(i);
				i++;
				Lcd_DisplayChr(ptr[i]);
			}
			//Lcd_DisplayStr("THAT'S AMAZING! ");
			Lcd_Clear_Display();
		}

		//else if(((22<=thumb)||(thumb<=24))&&((29<=index_F)||(index_F<=32))&&((24<=little)||(little<=30))&&((18<=middle)||(middle<=20))&&((18<=ring)||(ring<=22)))
		else if((thumb>22)&&(index_F>22)&&(little>22)&&(middle<22)&&(ring<22))
		//else if((thumb==flat)&&(index_F==flat)&&(middle==bent)&&(ring==bent)&&(little==flat))
		{
			//arr9[16]="I LOVE YOU ";
			i=0;
			while (arr9[i]!='\0'){
				Eeprom24C16_WriteByte(i,arr9[i]);
				i++;
			}
			i=0;
			while (arr9[i]!='\0'){
				ptr[i]=Eeprom24c16_ReadByte(i);
				i++;
				Lcd_DisplayChr(ptr[i]);
			}
			//Lcd_DisplayStr("I LOVE YOU ");
			Lcd_Clear_Display();
		}

		/*//else if(((11<=thumb)||(thumb<=13))&&((14<=ring)||(ring<=17))&&((8<=little)||(little<=11))&&((25<=index_F)||(index_F<=27))&&((25<=middle)||(middle<=27)))
		else if(((thumb<=12))&&((ring<=17))&&((little<=11))&&((25<=index_F))&&((25<=middle)))
		{
			Lcd_DisplayStr("I'M WATCHING YOU ");
			Lcd_Clear_Display();
		}*/

		//else if(((12<=thumb)||(thumb<=15))&&((13<=ring)||(ring<=15))&&((10<=little)||(little<=15))&&((29<=index_F)||(index_F<=32))&&((30<=middle)||(middle<=32)))
		else if((thumb<22)&&(ring<22)&&(little<22)&&(index_F>22)&&(middle>22))
		//else if((thumb==bent)&&(index_F==flat)&&(middle==flat)&&(ring==bent)&&(little==bent))
		{
			//arr10[16]="VICTORY! ";
			i=0;
			while (arr10[i]!='\0'){
				Eeprom24C16_WriteByte(i,arr10[i]);
				i++;
			}
			i=0;
			while (arr10[i]!='\0'){
				ptr[i]=Eeprom24c16_ReadByte(i);
				i++;
				Lcd_DisplayChr(ptr[i]);
			}
			//Lcd_DisplayStr("VICTORY! ");
			Lcd_Clear_Display();
		}

		/*else
		{
			Lcd_DisplayStr("NO Sign ");
			Lcd_Clear_Display();
		}*/

	}

	return 0;
}
