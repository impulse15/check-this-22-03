/*
 * SPI.c
 *
 *  Created on: Dec 28, 2023
 *      Author: 10820302
 */

#include "SPI.h"
#include "GPIO_DRIVER.H"
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 * Initialize SPI by configuring GPIO Pins.
 * %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 */
/*********************************************************************
 * @fn      		  - SPI_EN_DI
 *
 * @brief             -	Checks if the SPI is in running mode / in idle mode
 * 						for setting / disabling SPI respectively
 *
 * @param[in]         -	SPI Configuration Variable
 * @param[in]         -	Enable or Disable
 * @param[in]         -
 *
 * @return            - SUCCESS / ERROR
 *
 * @Note              -

 */
#define ERROR  0x00
#define SUCESS 0x01
uint8_t SPI_EN_DI(SPI_config_t * pSPI_onfig, uint8_t EnorDi)
{
	if(EnorDi == SET)
	{
		if(pSPI_onfig->STATUS == RESET)
		{
			pSPI_onfig->STATUS = SET;
			return SUCESS;
		}
		else
			return ERROR;

	}
	else
	{
		if(pSPI_onfig->STATUS == SET)
		{
			pSPI_onfig->STATUS = RESET;
			return SUCESS;
		}
		else
			return ERROR;
	}
}
/*********************************************************************
 * @fn      		  - SPI_INI
 *
 * @brief             - Initialize pins for respective functions
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -   0 or 1
 *
 * @Note              - Creates a lot of big variables

 */
void SPI_INI (SPI_Handler_t * pSPI_Handler)
{
	/*
	 * GPIO pins initialize
	 */


	//MOSI SETUP
	pSPI_Handler->MOSI.config.Mode = GPIO_MODE_OUT;
	pSPI_Handler->MOSI.config.OSpeed = GPIO_OSPEED_VH;
	pSPI_Handler->MOSI.config.OType = GPIO_OTYPE_PP;
	pSPI_Handler->MOSI.config.PUPD = GPIO_PUPD_NO;
	pSPI_Handler->MOSI.config.Pin = pSPI_Handler->SPI_Config.PIN_MOSI;
	pSPI_Handler->MOSI.config.pPort = pSPI_Handler->SPI_Config.pPort;

	GPIO_INI(&pSPI_Handler->MOSI);

	//MISO SETUP
	pSPI_Handler->MISO.config.Mode = GPIO_MODE_IN;
	pSPI_Handler->MISO.config.OSpeed = GPIO_OSPEED_VH;
	pSPI_Handler->MISO.config.PUPD = GPIO_PUPD_NO;
	pSPI_Handler->MISO.config.Pin = pSPI_Handler->SPI_Config.PIN_MISO;
	pSPI_Handler->MISO.config.pPort = pSPI_Handler->SPI_Config.pPort;

	GPIO_INI(&pSPI_Handler->MISO);

	//CLK SETUP

	pSPI_Handler->CLK.config.Mode = GPIO_MODE_OUT;
	pSPI_Handler->CLK.config.OSpeed = GPIO_OSPEED_VH;
	pSPI_Handler->CLK.config.OType = GPIO_OTYPE_PP;
	pSPI_Handler->CLK.config.PUPD = GPIO_PUPD_NO;
	pSPI_Handler->CLK.config.Pin = pSPI_Handler->SPI_Config.PIN_CLK;
	pSPI_Handler->CLK.config.pPort = pSPI_Handler->SPI_Config.pPort;

	GPIO_INI(&pSPI_Handler->CLK);

	//CHIP SELECT SETUP

	pSPI_Handler->NS.config.Mode = GPIO_MODE_OUT;
	pSPI_Handler->NS.config.OSpeed = GPIO_OSPEED_VH;
	pSPI_Handler->NS.config.OType = GPIO_OTYPE_PP;
	pSPI_Handler->NS.config.PUPD = GPIO_PUPD_NO;
	pSPI_Handler->NS.config.Pin = pSPI_Handler->SPI_Config.PIN_NS;
	pSPI_Handler->NS.config.pPort = pSPI_Handler->SPI_Config.pPort;

	GPIO_INI(&pSPI_Handler->NS);
}

/*
 * %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 *
 * 									Send Receive API
 *
 * %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 */

/*********************************************************************
 * @fn      		  - SPI_Start_End
 *
 * @brief             -	setups clock's initial & Final state with chip select activate & deactivate
 *
 * @param[in]         - SPI Handler pointer
 * @param[in]         -	START / STOP macros
 * @param[in]         -
 *
 * @return            -  None
 *
 * @Note              -

 */
#define START	SET
#define STOP	RESET
void SPI_Start_End(SPI_Handler_t * pSPI_Handler, uint8_t STARTorSTOP)
{if(STARTorSTOP == START)
	{
		if(pSPI_config->STATUS == SET)
		{
			//NS low

			if(pSPI_config->CPOL == SPI_CPOL_EN)
			{
				GPIO_PIN_SEND(pSPI_Handler->CLK.pGPIO, pSPI_Handler->SPI_Config.PIN_CLK, SET);
			}
			else
			{
				GPIO_PIN_SEND(pSPI_Handler->CLK.pGPIO, pSPI_Handler->SPI_Config.PIN_CLK, RESET);

			}
			GPIO_PIN_SEND(pSPI_Handler->NS.pGPIO, pSPI_Handler->SPI_Config.PIN_NS, RESET);
		 }

	}
else
	{
		GPIO_PIN_SEND(pSPI_Handler->NS.pGPIO, pSPI_Handler->SPI_Config.PIN_NS, SET);
	}
}

/*********************************************************************
 * @fn      		  - SPI_Clk_toggle
 *
 * @brief             - Toggles the clock signal
 *
 * @param[in]         -	pointer to the CLK handler
 * @param[in]         -
 * @param[in]         -
 *
 * @return            - None
 *
 * @Note              -

 */
void SPI_Clk_toggle(GPIO_Handler_t * pClk_handler)
{
	GPIO_PIN_Toggle(pClk_handler->pGPIO, pClk_handler->config.Pin);
}

/*********************************************************************
 * @fn      		  - GPIO_ReadFromInputPin
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -   0 or 1
 *
 * @Note              -

 */
uint8_t SPI_Bit_Send_Rec(SPI_Handler_t * pSPI_Handler ,uint8_t SETorReset)
{
	if(pSPI_Handler->SPI_Config.CPHA == RESET)
	{

	}
	else
	{

	}
}

/*********************************************************************
 * @fn      		  -
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -

 */
void SPI_Byte_Send_Rec(SPI_config_t * pSPI_config,uint8_t * MSG_send , uint8_t * MSG_REC);

/*********************************************************************
 * @fn      		  -
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -

 */
void SPI_MSG_Send_Rec(SPI_config_t * pSPI_config, uint8_t * MSG_send , uint8_t * MSG_REC, uint32_t Length );

