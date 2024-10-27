/*
 * LCD.c
 *
 *  Reem Younis Muhammed */

/*
 * RS -> PB1
 * RW -> PB2
 * EN -> PB3
 * D4 -> PA4
 * D5 -> PA5
 * D6 -> PA6
 * D7 -> PA7
 *
 */

#include"LCD.h"
extern u8 customChar[NO_CUSTOM_CHAR][NO_CUSTOM_CHAR_BYTES];

static void Lcd_WriteCustom(void)  //LOADS CUSTOM CHRCTERS IN CGRAM
{
	u8 loc_ByteIndex=0;
	u8 loc_CharIndex=0;
	for(loc_CharIndex=0;loc_CharIndex<NO_CUSTOM_CHAR;loc_CharIndex++)
	{
		Lcd_Cmd( _LCD_CGRAM_START_ADDRESS+(loc_CharIndex*8));
		for (loc_ByteIndex=0;loc_ByteIndex<NO_CUSTOM_CHAR_BYTES;loc_ByteIndex++)
		{
			Lcd_DisplayChr(customChar[loc_CharIndex][loc_ByteIndex]);
			// WILL NOT DiSPLAY THE CHARACTER SINCE IT IS NOT YET SAVED IN THE DDRAM BUT SVED IN THE CGRAM
			//AND WE COULD HAVE USED Lcd_Data instead
			// WORKS AS Lcd_Data BECAUSE IT CALLS IT IMPLICITLY
		}
	}
}// WILL DiSPLAY THE CHARACTER SINCE IT IS NOW YET SAVED IN THE CGRAM WHEN THE Lcd_DisplayChr IS CLLED ON THE MAIN

void Lcd_Init(void)
{
	// Configure data lines as output
	Dio_ConfigChannel(LCD_PORT_Dataln,LCD_PIN_Dataln0,OUTPUT);
	Dio_ConfigChannel(LCD_PORT_Dataln,LCD_PIN_Dataln1,OUTPUT);
	Dio_ConfigChannel(LCD_PORT_Dataln,LCD_PIN_Dataln2,OUTPUT);
	Dio_ConfigChannel(LCD_PORT_Dataln,LCD_PIN_Dataln3,OUTPUT);

	//Configure control lines as output
	Dio_ConfigChannel(LCD_PORT_Controlln,LCD_PIN_RS,OUTPUT);
	Dio_ConfigChannel(LCD_PORT_Controlln,LCD_PIN_RW,OUTPUT);
	Dio_ConfigChannel(LCD_PORT_Controlln,LCD_PIN_EN,OUTPUT);

	Dio_WriteChannel (LCD_PORT_Controlln,LCD_PIN_RW,STD_LOW); //Write on LCD

	//From Datasheet initialization function
	_delay_ms(15);
	Lcd_Cmd(3);//set interface to 8 bits
	_delay_ms(5);
	Lcd_Cmd(3);
	_delay_us(100);
	Lcd_Cmd(3);
	Lcd_Cmd(2);//set interface to 4 bits enabled

	Lcd_Cmd(_LCD_4BIT_MODE);
	Lcd_WriteCustom();

}

//void Enable_Pulse(void); not general function but private function (static) not written in .h file
static void Enable_Pulse(void)
{
	Dio_WriteChannel (LCD_PORT_Controlln,LCD_PIN_EN,STD_HIGH);
	_delay_us(1);
	Dio_WriteChannel (LCD_PORT_Controlln,LCD_PIN_EN,STD_LOW);

	_delay_ms(2); //wait enough time between each character to be sent then received
}

static void Lcd_Data(u8 data) //Saved in CGROM
{
	u8 High_Nibble = data>>4; //MSB
	u8 Low_Nibble = data;     //LSB
	Dio_WriteChannel (LCD_PORT_Controlln,LCD_PIN_RS,STD_HIGH); // Data Mode
	Dio_WriteGroup(LCD_PORT_Dataln,LCD_Mask,High_Nibble);
	Enable_Pulse();

	Dio_WriteGroup(LCD_PORT_Dataln,LCD_Mask,Low_Nibble);
	Enable_Pulse();
}


void Lcd_Cmd(Lcd_Cmd_types cmd)
{
	u8 High_Nibble = cmd>>4; //MSB
	u8 Low_Nibble = cmd;     //LSB
	Dio_WriteChannel (LCD_PORT_Controlln,LCD_PIN_RS,STD_LOW); // Command Mode
	Dio_WriteGroup(LCD_PORT_Dataln,LCD_Mask,High_Nibble);
	Enable_Pulse();

	Dio_WriteGroup(LCD_PORT_Dataln,LCD_Mask,Low_Nibble);
	Enable_Pulse();
}

void Lcd_DisplayNUM(u16 num)
{
	if(num<1000)
	{
		Lcd_DisplayChr(' ');
		Lcd_DisplayChr(num%1000/100 + '0');
		Lcd_DisplayChr(num%1000%100/10 + '0');
		Lcd_DisplayChr(num%1000%100%10 + '0');
	}

	else if(num<100)
	{
		Lcd_DisplayChr(' ');
		Lcd_DisplayChr(' ');
		Lcd_DisplayChr(num%1000%100/10 + '0');
		Lcd_DisplayChr(num%1000%100%10 + '0');
	}

	else if(num<100)
	{
		Lcd_DisplayChr(' ');
		Lcd_DisplayChr(' ');
		Lcd_DisplayChr(num%1000%100/10 + '0');
		Lcd_DisplayChr(num%1000%100%10 + '0');
	}

	else
	{
		Lcd_DisplayChr(num/1000 + '0');
		Lcd_DisplayChr(num%1000/100 + '0');
		Lcd_DisplayChr(num%1000%100/10 + '0');
		Lcd_DisplayChr(num%1000%100%10 + '0');
	}
}

void Lcd_DisplayChr(u8 chr)
{
	Lcd_Data(chr);
}


void Lcd_DisplayStr(u8* str)
{
	while(*str !='\0')
	{
		Lcd_Data(*str);
		str++;
	}
}


void Lcd_Goto_Row_Column(u8 row, u8 col)
{
	switch(row)
	{
	case 0:
		Lcd_Cmd(0x80+col); //DDRAM address
		break;

	case 1:
		Lcd_Cmd(0xC0+col);
		break;
	}
}

void Lcd_Clear_Display(void)
{
	Lcd_Cmd(_LCD_CLEAR);
}


