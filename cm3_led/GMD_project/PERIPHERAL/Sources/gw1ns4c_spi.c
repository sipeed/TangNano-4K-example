/*
 * *****************************************************************************************
 *
 *         Copyright (C) 2014-2021 Gowin Semiconductor Technology Co.,Ltd.
 * 
 * @file        gw1ns4c_spi.c
 * @author      Embedded Development Team
 * @version     V1.x.x
 * @date        2021-07-01 09:00:00
 * @brief       This file contains all the functions prototypes for the SPI firmware library.
 ******************************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "gw1ns4c_spi.h"

/** @addtogroup GW1NS4C_StdPeriph_Driver
  * @{
  */

/** @defgroup SPI
  * @brief SPI driver modules
  * @{
  */

/** @defgroup SPI_Private_TypesDefinitions
  * @{
  */

/**
  * @}
  */

/** @defgroup SPI_Private_Macros
  * @{
  */

/**
  * @}
  */

/** @defgroup SPI_Private_Variables
  * @{
  */

/**
  * @}
  */

/** @defgroup SPI_Private_FunctionPrototypes
  * @{
  */

/**
  * @}
  */

/** @defgroup SPI_Private_Functions
  * @{
  */

/**
  * @param SPI_InitTypeDef Pointer
  * @return none
  * @brief Initializes SPI
  */
void SPI_Init(SPI_InitTypeDef* SPI_InitStruct)
{
  uint32_t new_ctrl = 0;

  SPI->CTRL = 0;
  SPI->STATUS = 0;

  /* Set Direction */
  if(SPI_InitStruct->DIRECTION == 1)
  {
    new_ctrl |= SPI_CR_DIRECTION;
  }

  /*Set Phase*/
  if(SPI_InitStruct->PHASE == 1)
  {
    new_ctrl |= SPI_CR_PHASE;
  }

  /*Set Polarity*/
  if(SPI_InitStruct->POLARITY == 1)
  {
    new_ctrl |= SPI_CR_POLARITY;
  }

  /*Set ClkSel*/
  new_ctrl |= (SPI_InitStruct->CLKSEL << SPI_CR_CLKSEL_Pos);

  SPI->CTRL = new_ctrl;
}

/**
  * @param none
  * @return none
  * @brief Sets Direction
  */
void SPI_SetDirection(void)
{
  SPI->CTRL |= SPI_CR_DIRECTION;
}

/**
  * @param none
  * @return none
  * @brief Clears Direction
  */
void SPI_ClrDirection(void)
{
  SPI->CTRL &= ~SPI_CR_DIRECTION;
}

/**
  * @param none
  * @return uint32_t
  * @brief Returns Direction
  */
uint32_t SPI_GetDirection(void)
{
  return ((SPI->CTRL&SPI_CR_DIRECTION)==SPI_CR_DIRECTION);
}

/**
  * @param none
  * @return none
  * @brief Sets Phase
  */
void SPI_SetPhase(void)
{
  SPI->CTRL |= SPI_CR_PHASE;
}

/**
  * @param none
  * @return none
  * @brief Clears Phase
  */
void SPI_ClrPhase(void)
{
  SPI->CTRL &= ~SPI_CR_PHASE;
}

/**
  * @param none
  * @return uint32_t
  * @brief Returns Phase
  */
uint32_t SPI_GetPhase(void)
{
  return ((SPI->CTRL&SPI_CR_PHASE)==SPI_CR_PHASE);
}

/**
  * @param none
  * @return none
  * @brief Sets Polarity
  */
void SPI_SetPolarity(void)
{
  SPI->CTRL |= SPI_CR_POLARITY;
}

/**
  * @param none
  * @return none
  * @brief Clears Polarity
  */
void SPI_ClrPolarity(void)
{
  SPI->CTRL &= ~SPI_CR_POLARITY;
}

/**
  * @param none
  * @return uint32_t
  * @brief Returns Polarity
  */
uint32_t SPI_GetPolarity(void)
{
  return ((SPI->CTRL&SPI_CR_POLARITY)==SPI_CR_POLARITY);
}

/**
  * @param uint32_t
  * @return none
  * @brief  Set ClkSel
  */
void SPI_SetClkSel(uint32_t clksel)
{
  SPI->CTRL &= ~SPI_CR_CLKSEL;
  SPI->CTRL |= ((clksel&SPI_CR_CLKSEL_Mask)<<SPI_CR_CLKSEL_Pos);
}

/**
  * @param none
  * @return uint32_t
  * @brief Returns ClkSel
  */
uint32_t SPI_GetClkSel(void)
{
  return ((SPI->CTRL >>SPI_CR_CLKSEL_Pos)&SPI_CR_CLKSEL_Mask);
}

/**
  * @param none
  * @return FlagStatus
  * @brief Reads transmit overrun error status
  */
FlagStatus SPI_GetToeStatus(void)
{
  return (FlagStatus)((SPI->STATUS&SPI_STATUS_TOE)==SPI_STATUS_TOE);
}

/**
  * @param none
  * @return FlagStatus
  * @brief Returns receive overrun error status
  */
FlagStatus SPI_GetRoeStatus(void)
{
  return (FlagStatus)((SPI->STATUS&SPI_STATUS_ROE)==SPI_STATUS_ROE);
}

/**
  * @param none
  * @return FlagStatus
  * @brief Returns transmitting status
  */
FlagStatus SPI_GetTmtStatus(void)
{
  return (FlagStatus)((SPI->STATUS&SPI_STATUS_TMT)==SPI_STATUS_TMT);
}

/**
  * @param none
  * @return FlagStatus
  * @brief Return transmit ready status
  */
FlagStatus SPI_GetTrdyStatus(void)
{
  return (FlagStatus)((SPI->STATUS & SPI_STATUS_TRDY) == SPI_STATUS_TRDY);
}

/**
  * @param none
  * @return FlagStatus
  * @brief Returns receive ready status
  */
FlagStatus SPI_GetRrdyStatus(void)
{
  return (FlagStatus)((SPI->STATUS&SPI_STATUS_RRDY)==SPI_STATUS_RRDY);
}

/**
  * @param none
  * @return FlagStatus
  * @brief Returns error Status
  */
FlagStatus SPI_GetErrStatus(void)
{
  return (FlagStatus)((SPI->STATUS&SPI_STATUS_ERR)==SPI_STATUS_ERR);
}

/**
  * @param none
  * @return none
  * @brief Clears transmit overrun error status
  */
void SPI_ClrToeStatus(void)
{
  SPI->STATUS |= SPI_STATUS_TOE;
}

/**
  * @param none
  * @return none
  * @brief Clears receive overrun error status
  */
void SPI_ClrRoeStatus(void)
{
  SPI->STATUS |= SPI_STATUS_ROE;
}

/**
  * @param none
  * @return none
  * @brief Clears error status
  */
void SPI_ClrErrStatus(void)
{
  SPI->STATUS |= SPI_STATUS_ERR; 
}

/**
  * @param uint8_t cmd
  * @return uint8_t
  * @brief Reads and writes byte data
  */
uint8_t SPI_ReadWriteByte(uint8_t cmd)
{
  uint32_t master_rx_data;

  while (!(SPI->STATUS & (1UL << 5)));
  SPI->WDATA = cmd;
  while (!(SPI->STATUS & (1UL << 6)));
  master_rx_data = SPI->RDATA;

  return master_rx_data & 0xff;
}

/**
  * @param uint8_t data
  * @return none
  * @brief Writes Data
  */
void SPI_WriteData(uint8_t data)
{
  SPI_ReadWriteByte(data);
}

/**
  * @param none
  * @return uint8_t
  * @brief Reads Data
  */
uint8_t SPI_ReadData(void)
{
  return (SPI_ReadWriteByte(0x00));
}

/**
  * @param uint32_t slave address
  * @return none
  * @brief Select Slave
  */
void SPI_Select_Slave(uint32_t Slave_address)
{
  SPI->SSMASK = Slave_address;
}

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/************************GowinSemiconductor******END OF FILE*******************/
