 /**************************************************
 *  File		: Uart.c
 *	Module		: UART
 *	Target		: ATMEGA32
 *	Author		: Reem Younis
 *  Description	:
 *
 ***************************************************/
#include "Uart.h"
#include "Led.h"
#include <avr/interrupt.h>

volatile u8 uartResult = 0;
volatile u8 UART_RxBuffer[RX_BUFFER_SIZE];
volatile u8 UART_RxBuffer_Index = 0;
volatile boolean Rx_Buffer_Ready = FALSE;
void UART_Init(u16 baudRate)
{
	/* Set baud rate */
	UART_UBRRH_REG = (u8)(baudRate>>8); //LSB is always (0) when baud rate is shifted right 8 Ex:for(9600)-> (0110 0111)>>8=(1100 1110)---> always zeroo
	UART_UBRRL_REG = (u8)baudRate;
	/* Enable receiver and transmitter */
	SET_BIT(UART_UCSRB_REG,RXEN_BIT_NO);  /* Enable Receiver*/
	SET_BIT(UART_UCSRB_REG,TXEN_BIT_NO);  /* Enable Transmitter */
	/* Set frame format: 8data, 1stop bit, Even Parity */
	UART_UCSRC_REG |= (1 << URSEL_BIT_NO)|UART_8_BIT_DATA | UART_EVEN_PARITY;
	SET_BIT(UART_UCSRB_REG,7); /*	Enable Rx Complete Interrupt	*/
}

void UART_TransmitChr(u8 data)
{
	/* Wait for empty transmit buffer */
	while (!(CHK_BIT(UART_UCSRA_REG,UDRE_BIT_NO)))
			;
	/* Put data into buffer, sends the data */
	UART_UDR_REG = data;
}

void UART_TransmitStr(u8 *str)
{
	/* Wait for empty transmit buffer */
	while (*str != '\0')
	{
		UART_TransmitChr(*str);
		str++;
	}
}

void UART_TransmitNum(u16 num)
{
	UART_TransmitChr(num/1000 + '0');
	UART_TransmitChr(num%1000/100 + '0');
	UART_TransmitChr(num%1000%100/10 + '0');
	UART_TransmitChr(num%1000%100%10 + '0');
}

//u8 UART_ReceiveChr(void)
//{
//	/* Wait for data to be received */
//	while (!(CHK_BIT(UART_UCSRA_REG,RXC_BIT_NO)))
//			;
//	/* Get and return received data from buffer */
//	return UART_UDR_REG;
//}

u8 UART_ReceiveChr(void)
{
	/* Wait for data to be received */
	if ((CHK_BIT(UART_UCSRA_REG,RXC_BIT_NO)))
	{
		return UART_UDR_REG;
	}
	else
	{
		return 0;
	}
	/* Get and return received data from buffer */

}
ISR(USART_RXC_vect)
{
	UART_RxBuffer[UART_RxBuffer_Index] = UART_UDR_REG;
	if (UART_RxBuffer[UART_RxBuffer_Index] == '\r') // \r -> enter
	{
		UART_RxBuffer_Index = 0;
		Rx_Buffer_Ready = TRUE;
		LED_TOGGLE(LED1);
	}
	else
	{
		UART_RxBuffer_Index++;
		LED_TOGGLE(LED0);
	}
}


