/*
 *  Eeprom24C16.c
 *
 *      Author: Reem Younis
 */

#include "Eeprom24C16.h"

void Eeprom24C16_Init(void)
{
	I2C_MasterInit();
}

/*addr =0 to 2047*/
void Eeprom24C16_WriteByte(u16 addr , u8 data)
{
	u8 loc_pageNo = addr/256;
	u8 loc_byteNo = addr%256;
	I2C_StartCondition();
	I2C_Send_SlaveAddressWriteOperation((0xA0)|(loc_pageNo<<1));
	I2C_WriteByte(loc_byteNo);
	I2C_WriteByte(data);
	I2C_StopCondition();

}
u8 Eeprom24c16_ReadByte(u16 addr)
{
	u8 loc_pageNo = addr/256;
	u8 loc_byteNo = addr%256;
	u8 loc_dataRead=0;
	I2C_StartCondition();
	I2C_Send_SlaveAddressWriteOperation((0xA0)|(loc_pageNo<<1));
	I2C_WriteByte(loc_byteNo);
	I2C_RepeatedStartCondition();
	I2C_Send_SlaveAddressReadOperation((0xA0)|(loc_pageNo<<1));
	loc_dataRead =I2C_ReadByte();
	I2C_StopCondition();
	return loc_dataRead;

}

/*void Eeprom24C16_WriteStr(u8* str)
{
	static int i = 0;
	while(str [i] !='\0')
	{
		Eeprom24C16_WriteByte(i,str [i]);
		//str++;
		i++;
	}
}*?

