 /******************************************
 *  File		: Uart.h
 *	Module		: UART
 *	Target		: ATMEGA32
 *	Author		: Reem Younis
 *  Description	:
 *******************************************/
#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

#include "Std_Types.h"
#include "Uart_Private.h"

#define UART_UDR_REG				(*(volatile u8* const)0x2C)
#define UART_UCSRA_REG				(*(volatile u8* const)0x2B)
#define UART_UCSRB_REG				(*(volatile u8* const)0x2A)
#define UART_UBRRH_REG				(*(volatile u8* const)0x40)
#define UART_UCSRC_REG				(*(volatile u8* const)0x40)
#define UART_UBRRL_REG				(*(volatile u8* const)0x29)

#define RXEN_BIT_NO						(4)
#define TXEN_BIT_NO						(3)
#define URSEL_BIT_NO					(7)
#define USBS_BIT_NO						(3)
#define UCSZ0_BIT_NO					(1)
#define UPM0_BIT_NO						(4)
#define UDRE_BIT_NO						(5)
#define RXC_BIT_NO						(7)

#endif  /* UART_PRIVATE_H */
