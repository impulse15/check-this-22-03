/*
 * GPIO_DRIVER.c
 *
 *  Created on: Dec 12, 2023
 *      Author: 10820302
 */
#include "GPIO_DRIVER.H"				//doubt


/*
 * 			Initializing API
 */
void GPIO_EN (GPIO_Regdef_t * pGPIO, uint8_t ENorDI)
{
	//enable this in RCC


}
void GPIO_INI (GPIO_Handler_t * pHandler)
{	//select the port
	pHandler->pGPIO=pHandler->config.pPort;

	//Enable the input

	//SET PUPD
	pHandler->pGPIO->PUPD |= pHandler->config.PUPD << 2*(pHandler->config.Pin);
	//SET ACCORDING TO MODE
	pHandler->pGPIO->Mode |= pHandler->config.Mode << 2*(pHandler->config.Mode);
	if(pHandler->config.Mode == GPIO_MODE_IN)
	{
		//do nothing
	}
	else if(pHandler->config.Mode == GPIO_MODE_OUT)
	{
		pHandler->pGPIO->OutType |= pHandler->config.OType << pHandler->config.Pin;
	}
	else if(pHandler->config.Mode == GPIO_MODE_AN)
	{
		//Analog Function
	}
	else if(pHandler->config.Mode == GPIO_MODE_AF)
	{
		//Alternate fucntion
	}
}
/*
 * 			Send data receive data
 */
void GPIO_PIN_SEND(GPIO_Regdef_t * pGPIO, uint8_t PIN, uint8_t SETorRESET)
{
	if( SETorRESET == ENABLE)
	 pGPIO->Data_OUT |= 1 << PIN ;
	else
		pGPIO->Data_OUT &= ~(1 << PIN);
}

uint8_t GPIO_PIN_READ(GPIO_Regdef_t * pGPIO, uint8_t PIN)
{
	if ((1<<PIN)& pGPIO->Data_IN)
		return 0x01;
	else
		return 0x00;
}
void GPIO_PORT_SEND(GPIO_Regdef_t * pGPIO, uint16_t Data)
{
	pGPIO->Data_IN= Data;
}
uint16_t GPIO_PORT_READ(GPIO_Regdef_t * pGPIO)
{
	return pGPIO->Data_IN;
}
void GPIO_PIN_Toggle(GPIO_Regdef_t * pGPIO, uint8_t PIN)
{
	pGPIO->Data_OUT ^= (0x01 << PIN);
}

