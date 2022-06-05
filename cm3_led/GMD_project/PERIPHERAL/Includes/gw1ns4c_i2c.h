/*
 * *****************************************************************************************
 *
 * 		Copyright (C) 2014-2021 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file      gw1ns4c_i2c.h
 * @author    Embedded Development Team
 * @version   V1.x.x
 * @date      2021-01-01 09:00:00
 * @brief     This file contains all the functions prototypes for the I2C firmware library.
 ******************************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GW1NS4C_I2C_H
#define __GW1NS4C_I2C_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "gw1ns4c.h"

#define I2C_CTR_EN     ((uint32_t)0x00000080)  /* Control Register : Enable I2C Core [7] 	               */
#define I2C_CTR_IEN    ((uint32_t)0x00000040)
#define I2C_CTR_PERE   ((uint32_t)0x0000FFFF)  /* Prescale Register : prescale value [15:0]               */
#define I2C_CMD_IACK   ((uint32_t)0x00000001)  /* Command Register : Interrupt acknowledage [0]           */
#define I2C_CMD_ACK    ((uint32_t)0x00000008)  /* Command Register : acknowledage [3]                     */
#define I2C_CMD_WR     ((uint32_t)0x00000010)  /* Command Register : write data to slave [4]              */
#define I2C_CMD_RD     ((uint32_t)0x00000020)  /* Command Register : read data from slave [5]             */
#define I2C_CMD_STO    ((uint32_t)0x00000040)  /* Command Register : end to transmit[6]                   */
#define I2C_CMD_STA    ((uint32_t)0x00000080)  /* Command Register : begin to transmit [7]                */
#define I2C_SR_TIP     ((uint32_t)0x00000002)  /* Status Register : data transmit status flag [1]         */
#define I2C_SR_AL      ((uint32_t)0x00000020)  /* Status Register : arbitration lose [5]                  */
#define I2C_SR_BUSY    ((uint32_t)0x00000040)  /* Status Register : I2C busy status [6]                   */
#define I2C_SR_RXACK   ((uint32_t)0x00000080)  /* Status Register : receive slave acknowledge signal [7]  */

/**
  * @brief Initialize I2C.
  */ 
extern ErrorStatus I2C_Init(I2C_TypeDef * i2c, uint16_t speed);

/**
  * @brief  Send byte to I2C serial bus
  */
extern void I2C_SendByte(I2C_TypeDef *i2c ,uint8_t slv_data,uint8_t data_address,uint8_t data);

/**
  * @brief Send the data to the serial bus.
  */
extern void I2C_SendBytes(I2C_TypeDef *i2c ,uint8_t slv_address,uint8_t data_start_address,uint8_t *data,int32_t data_num);

/**
  * @brief Send the data to the serial bus.
  */
extern void I2C_ReadBytes(I2C_TypeDef *i2c ,uint8_t slv_address,uint8_t data_start_address,uint8_t *data,int32_t data_num);

/**
  * @brief Receives 8-bits data from the serial bus.
  */
extern uint8_t I2C_ReceiveByte(I2C_TypeDef *i2c ,uint8_t slv_addr,uint8_t mem_addr);

/**
  * @brief Receive several bytes data a time from the serial bus.
  */
extern void I2C_ReceiveData(I2C_TypeDef *i2c ,uint8_t slv_addr,uint8_t data_addr,uint8_t *data,uint32_t data_size);

/**
  * @brief Send several bytes data a time to the serial bus.
  */
extern void I2C_SendData(I2C_TypeDef *i2c ,uint8_t slv_addr,uint8_t data_addr,uint8_t* data,uint32_t data_size);

/**
  * @brief Delay .
  */ 
extern void Delay_ms_i2c(__IO uint32_t delay_ms);

/**
  * @brief Initialize I2C Rate.
  */ 
extern uint16_t I2C_Rate_Set(I2C_TypeDef * i2c,uint16_t Rate);

/**
  * @brief Enable the I2C Core 
  */ 
extern void I2C_Enable(I2C_TypeDef * i2c);

/**
  * @brief Close the I2C Core
  */ 
extern void I2C_UnEnable(I2C_TypeDef * i2c);

/**
  * @brief Open the i2C Interrupt.
  */
extern void I2C_InterruptOpen(I2C_TypeDef *i2c);

/**
  * @brief close the i2C Interrupt.
  */
extern void I2C_InterruptClose(I2C_TypeDef *i2c);

#ifdef __cplusplus
}
#endif

#endif /* __GW1NS4C_I2C_H */

/*************************GowinSemiconductor*****END OF FILE*********************/
