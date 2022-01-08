/*
 * *****************************************************************************************
 *
 * 		Copyright (C) 2014-2021 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file			gw1ns4c_i2c.c
 * @author		Embedded Development Team
 * @version		V1.x.x
 * @date			2021-01-01 09:00:00
 * @brief			This file contains all the functions prototypes for the I2C firmware library.
 ******************************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "gw1ns4c_i2c.h"

/** @addtogroup GW1NS4C_StdPeriph_Driver
  * @{
  */

/**
  * @param i2c is I2C Master address
  * @return none
  * @brief Close the I2C Core
  */ 
void I2C_UnEnable(I2C_TypeDef * i2c)
{
	i2c->CTR = ~I2C_CTR_EN;
}

/**
  * @param i2c is I2C Master address
  * @return none
  * @brief Enable the I2C Core 
  */ 
void I2C_Enable(I2C_TypeDef * i2c)
{
	i2c->CTR |= I2C_CTR_EN;
}

/**
  * @param The Rate of the I2C Range
  * @param i2c is I2C Master address
  * @return ErrorStatus indicate the State of the Init program
  * @brief Initialize I2C.
  */ 
uint16_t I2C_Rate_Set(I2C_TypeDef * i2c,uint16_t Rate)
{
	uint16_t prescal = 0;
	
	prescal =    (uint32_t) (SystemCoreClock/(5000*Rate)-1);
	i2c->PRER = (prescal&I2C_CTR_PERE);
	
	return prescal;
}

/**
  * @param the ms will be delay
  * @return none
  * @brief Delay .
  */ 
void Delay_ms_i2c(__IO uint32_t delay_ms)
{
  for(delay_ms=delay_ms*(SystemCoreClock>>13); delay_ms != 0; delay_ms--);
}

/**
  * @param none
  * @param i2c is I2C Master address
  * @return ErrorStatus indicate the State of the Init program
  * @brief Initialize I2C.
  */ 
ErrorStatus I2C_Init(I2C_TypeDef * i2c, uint16_t Rate)
{
	uint16_t temp_save;
	
	I2C_Enable(i2c);
	temp_save=I2C_Rate_Set(i2c,Rate);
	
	if((i2c->CTR&I2C_CTR_EN)&&(i2c->PRER == (uint32_t) (temp_save&I2C_CTR_PERE)))
	{
		return SUCCESS;
	}
	else
	{
		return ERROR;
	}
}

/**
  * @param none
  * @param i2c is I2C Master address
	* @param slv_address is slave peripheral address
	* @param data_address is the address which we will send data
	* @param data is a byte data
  * @return none
  * @brief  Send byte to I2C serial bus
  */ 
void I2C_SendByte(I2C_TypeDef *i2c ,uint8_t slv_address,uint8_t data_address,uint8_t data)
{
	i2c->TXR = (slv_address <<1) |0;
	i2c->CR = I2C_CMD_STA|I2C_CMD_WR;
	while(i2c->SR&I2C_SR_TIP);//wait TIP
	while(i2c->SR&I2C_SR_RXACK);//wait ack-----Over Here

	i2c->TXR = data_address;	
	i2c->CR = (I2C_CMD_WR);
	while(i2c->SR&I2C_SR_TIP);//wait TIP
	while(i2c->SR&I2C_SR_RXACK);//wait ack
	
	i2c->TXR = data;
	i2c->CR = (I2C_CMD_STO|I2C_CMD_WR);
	while(i2c->SR&I2C_SR_TIP);//wait TIP
	while(i2c->SR&I2C_SR_RXACK);//wait ack
	while(i2c->SR&I2C_SR_BUSY);
	
	Delay_ms_i2c(3);//Wait the data to I2C Ready
}

/**
  * @param none
  * @param i2c is I2C Master address
  * @param slv_addr is slave peripheral address
  * @param data is several bytes data
  * @param data_size is byte number
  * @return none
  * @brief  Send several bytes a time to I2C serial bus
  */ 
void I2C_SendData(I2C_TypeDef *i2c ,uint8_t slv_addr,uint8_t data_addr,uint8_t* data,uint32_t data_size)
{
	uint32_t i;
	
	i2c->TXR = (slv_addr <<1) |0;
	i2c->CR = I2C_CMD_STA|I2C_CMD_WR;
	while(i2c->SR&I2C_SR_TIP);//wait TIP
	while(i2c->SR&I2C_SR_RXACK);//wait ack-----Over Here

	i2c->TXR = data_addr;	
	i2c->CR = (I2C_CMD_WR);
	while(i2c->SR&I2C_SR_TIP);//wait TIP
	while(i2c->SR&I2C_SR_RXACK);//wait ack
	
	for(i=0;i<data_size;i++)
	{
		i2c->TXR = data[i];
		if((data_size-1) == i)
		{
			i2c->CR = (I2C_CMD_STO|I2C_CMD_WR);
		}
		else
		{
			i2c->CR = (I2C_CMD_WR);
		}
		
		while(i2c->SR&I2C_SR_TIP);//wait TIP
		while(i2c->SR&I2C_SR_RXACK);//wait ack
	}
	
	while(i2c->SR&I2C_SR_BUSY);
	Delay_ms_i2c(3);//Wait the data to I2C Ready
}

/**
  * @param i2c is I2C Master address
  * @param slv_addr is I2C slave address
  * @param data_addr is The data which we will read address
  * @return uint8_t receives character
  * @brief Receives 8-bits data from the serial bus.
  */
uint8_t I2C_ReceiveByte(I2C_TypeDef *i2c ,uint8_t slv_addr,uint8_t data_addr)
{
	uint8_t data=0;
	
	i2c->TXR = (slv_addr <<1) |0;
	i2c->CR = I2C_CMD_STA|I2C_CMD_WR;	
	while(i2c->SR&I2C_SR_TIP);
	while(i2c->SR&I2C_SR_RXACK);//wait ack-----Over Here
	
	i2c->TXR = data_addr;
	i2c->CR = I2C_CMD_WR;//stop
	while(i2c->SR&I2C_SR_TIP);//wait TIP
	while(i2c->SR&I2C_SR_RXACK);//wait ack
	
	i2c->TXR = (slv_addr <<1) |1;	
	i2c->CR = (I2C_CMD_STA|I2C_CMD_WR);
	while(i2c->SR&I2C_SR_TIP);
	while(i2c->SR&I2C_SR_RXACK);//wait ack	

	i2c->CR = (I2C_CMD_ACK|I2C_CMD_STO|I2C_CMD_RD);//send nack
	while(i2c->SR&I2C_SR_TIP);
	data = i2c->RXR;
	Delay_ms_i2c(3);
	
  return data;
}

/**
  * @param i2c is I2C Master address
  * @param slv_addr is I2C slave address
  * @param data_addr is The data which we will read address
	* @param data_size is received data number
  * @param data is what we receive several bytes data
  * @brief Receives several bytes data a time from the serial bus.
  */
void I2C_ReceiveData(I2C_TypeDef *i2c ,uint8_t slv_addr,uint8_t data_addr,uint8_t *data,uint32_t data_size)
{
	uint32_t i;
	
	i2c->TXR = (slv_addr <<1) |0;
	i2c->CR = I2C_CMD_STA|I2C_CMD_WR;	
	while(i2c->SR&I2C_SR_TIP);
	while(i2c->SR&I2C_SR_RXACK);//wait ack-----Over Here

	i2c->TXR = data_addr;
	i2c->CR = I2C_CMD_WR;//stop
	while(i2c->SR&I2C_SR_TIP);//wait TIP
	while(i2c->SR&I2C_SR_RXACK);//wait ack

	i2c->TXR = (slv_addr <<1) |1;	
	i2c->CR = (I2C_CMD_STA|I2C_CMD_WR);
	while(i2c->SR&I2C_SR_TIP);
	while(i2c->SR&I2C_SR_RXACK);//wait ack	
	
  for(i=0;i<data_size;i++)
	{
		if((data_size-1) == i)
		{
			i2c->CR = (I2C_CMD_ACK|I2C_CMD_STO|I2C_CMD_RD);//send nack
		}
		else
		{
			i2c->CR = (~I2C_CMD_ACK&I2C_CMD_RD);//send ack
		}
		
		while(i2c->SR&I2C_SR_TIP);
		data[i] = i2c->RXR;
	}
	
	while(i2c->SR&I2C_SR_BUSY);
}

/**
  * @param i2c is I2C Master address
  * @param slv_addr is I2C slave address
  * @param data_start_address is The first data address
  * @param data is the buff of the send bytes
  * @return No returns
  * @brief Send the data to the serial bus.
  */
void I2C_SendBytes(I2C_TypeDef *i2c ,uint8_t slv_address,uint8_t data_start_address,uint8_t *data,int32_t data_num)
{
	int32_t i;
	
	for(i=0;i<data_num;i++)
	{
		I2C_SendByte(i2c,slv_address,data_start_address+i,data[i]);
	}
}

/**
  * @param i2c is I2C Master address
  * @param slv_addr is I2C slave address
  * @param data_start_address is The first data address
  * @param data is the buff of the read bytes
  * @param data_num is the number of the data will be read
  * @return uint8_t receives character
  * @brief Send the data to the serial bus.
  */
void I2C_ReadBytes(I2C_TypeDef *i2c ,uint8_t slv_address,uint8_t data_start_address,uint8_t *data,int32_t data_num)
{
	int32_t i;
	
	for(i=0;i<data_num;i++)
	{
		data[i]=I2C_ReceiveByte(i2c,slv_address,data_start_address+i);
	}
}

/**
  * @param I2Cx is I2C Master address
  * @brief Open the i2C Interrupt.
  */
void I2C_InterruptOpen(I2C_TypeDef *i2c)
{
	i2c->CTR = I2C_CTR_IEN | i2c->CTR;
}

/**
  * @param I2Cx is I2C Master address
  * @brief close the i2C Interrupt.
  */
void I2C_InterruptClose(I2C_TypeDef *i2c)
{
	i2c->CTR &= ~I2C_CTR_IEN;
}

/************************GowinSemiconductor******END OF FILE*******************/
