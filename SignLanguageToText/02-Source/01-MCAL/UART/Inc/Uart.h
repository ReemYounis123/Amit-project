 /***************************************
 *  File		: Uart.h
 *	Module		: UART
 *	Target		: ATMEGA32
 *	Author		: Reem Younis
 *  Description	:
 ****************************************/
#ifndef UART_H
#define UART_H

#include "Std_Types.h"
#include "Bit_Math.h"
#include "Uart_Private.h"

#define RX_BUFFER_SIZE			    (25) // max sting size

#define UART_BAUDRATE_1200			(0x340)
#define UART_BAUDRATE_2400			(0x19F)
#define UART_BAUDRATE_4800			(0xCF)
#define UART_BAUDRATE_9600			(0x67)
#define UART_BAUDRATE_19200			(0x51)
#define UART_BAUDRATE_115200		(0x8)


#define UART_5_BIT_DATA				(0<<UCSZ0_BIT_NO)
#define UART_6_BIT_DATA				(1<<UCSZ0_BIT_NO)
#define UART_7_BIT_DATA				(2<<UCSZ0_BIT_NO)
#define UART_8_BIT_DATA				(3<<UCSZ0_BIT_NO)

#define UART_1_STOP_BIT				(0<<USBS_BIT_NO)
#define UART_2_STOP_BIT				(1<<USBS_BIT_NO)

#define UART_EVEN_PARITY			(2<<UPM0_BIT_NO)
#define UART_ODD_PARITY				(3<<UPM0_BIT_NO)

void UART_Init(u16 baudRate);
void UART_TransmitChr(u8 data);
void UART_TransmitStr(u8 *str);
void UART_TransmitNum(u16 num);
u8 UART_ReceiveChr(void);

#endif  /* UART_H */
