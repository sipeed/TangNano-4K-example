/*
 * *****************************************************************************************
 *
 * 		Copyright (C) 2014-2021 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file        gw1ns4c_gpio.c
 * @author      Embedded Development Team
 * @version     V1.x.x
 * @date        2021-01-01 09:00:00
 * @brief       This file contains all the functions prototypes for the GPIO firmware library.
 ******************************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "gw1ns4c_gpio.h"

/** @addtogroup GW1NS4C_StdPeriph_Driver
  * @{
  */

/** @defgroup GPIO 
  * @brief GPIO driver modules
  * @{
  */

/** @defgroup GPIO_Private_TypesDefinitions
  * @{
  */

/**
  * @}
  */

/** @defgroup GPIO_Private_Macros
  * @{
  */

/**
  * @}
  */

/** @defgroup GPIO_Private_Variables
  * @{
  */

/**
  * @}
  */

/** @defgroup GPIO_Private_FunctionPrototypes
  * @{
  */

/**
  * @}
  */

/** @defgroup GPIO_Private_Functions
  * @{
  */

/**
  * @param GPIO_TypeDef Pointer
  * @param GPIO_InitTypeDef Pointer
  * @return none 
  * @brief Initials GPIO.
  */
void GPIO_Init(GPIO_TypeDef* GPIOx,GPIO_InitTypeDef* GPIO_InitStruct)
{
  uint32_t pos = 0;
  uint32_t GPIO_Pin = GPIO_InitStruct->GPIO_Pin;
  GPIOMode_TypeDef GPIO_Mode = GPIO_InitStruct->GPIO_Mode;
  GPIOInt_TypeDef GPIO_Int = GPIO_InitStruct->GPIO_Int;

  /* Initial all register to zero */
  GPIOx->DATA = 0;
  GPIOx->DATAOUT = 0;
  GPIOx->OUTENSET = 0;
  GPIOx->OUTENCLR = 0;
  GPIOx->ALTFUNCSET = 0;
  GPIOx->ALTFUNCCLR = 0;
  GPIOx->INTENSET = 0;
  GPIOx->INTENCLR = 0;
  GPIOx->INTTYPESET = 0;
  GPIOx->INTTYPECLR = 0;
  GPIOx->INTPOLSET = 0;
  GPIOx->INTPOLCLR = 0;
  GPIOx->INTCLEAR = 0;
  for(pos = 0;pos < 256;pos++)
  {
   GPIOx->MASKLOWBYTE[pos] = 0;
   GPIOx->MASKHIGHBYTE[pos] = 0;
  }

  /* Set GPIO Mode registers */
  if(GPIO_Mode == GPIO_Mode_IN)
  {
    GPIOx->OUTENSET &= (~GPIO_Pin);//Clear Out Enable
  }
  else if(GPIO_Mode == GPIO_Mode_OUT)
  {
    GPIOx->OUTENSET |= GPIO_Pin;//Set Out Enable
  }
  else if(GPIO_Mode == GPIO_Mode_AF)
  {
    GPIOx->ALTFUNCSET |= GPIO_Pin;
  }

  /* Set GPIO Interrupt registers */
  if(GPIO_Int == GPIO_Int_Low_Level)
  {
    GPIOx->INTENSET |= GPIO_Pin;
    GPIOx->INTTYPECLR |= GPIO_Pin;
    GPIOx->INTPOLCLR |= GPIO_Pin;
  }
  else if(GPIO_Int == GPIO_Int_High_Level)
  {
    GPIOx->INTENSET |= GPIO_Pin;
    GPIOx->INTTYPECLR |= GPIO_Pin;
    GPIOx->INTPOLSET |= GPIO_Pin;
  }
  else if(GPIO_Int == GPIO_Int_Falling_Edge)
  {
    GPIOx->INTENSET |= GPIO_Pin;
    GPIOx->INTTYPESET |= GPIO_Pin;
    GPIOx->INTPOLCLR |= GPIO_Pin;
  }
  else if(GPIO_Int == GPIO_Int_Rising_Edge)
  {
    GPIOx->INTENSET |= GPIO_Pin;
    GPIOx->INTPOLSET |= GPIO_Pin;
    GPIOx->INTTYPESET |= GPIO_Pin;
  }
}

/**
  * @param GPIO_TypeDef Pointer
  * @param uint32_t GPIO Pin
  *        @arg GPIO_Pin_0...GPIO_Pin_15
  * @return none
  * @brief Sets pins on a port as an output.
  *        Set the bit corresponding to the pin number to 1 for output.
  *        Set bit 1 of outenset to 1 to set pin 1 as an output.
  *        This function is thread safe.
  */
void GPIO_SetOutEnable(GPIO_TypeDef* GPIOx,uint32_t GPIO_Pin)
{
  GPIOx->OUTENSET |= GPIO_Pin;
}

/**
  * @param GPIO_TypeDef Pointer
  * @param uint32_t GPIO Pin
  *        @arg GPIO_Pin_0...GPIO_Pin_15
  * @return none
  * @brief Sets pins on a port as an input.
  *        Set the bit corresponding to the pin number to 1 for input.
  *        Set bit 1 of outenclr to 1 to set pin 1 as an input.
  *        This function is thread safe.
  */
void GPIO_ClrOutEnable(GPIO_TypeDef* GPIOx,uint32_t GPIO_Pin)
{
  GPIOx->OUTENCLR = GPIO_Pin;
}

/**
  * @brief Set GPIO Output = "1"
  */
void GPIO_SetBit(GPIO_TypeDef* GPIOx,uint32_t GPIO_Pin)
{
  GPIOx->DATAOUT |= GPIO_Pin;
}

/**
  * @brief Set GPIO Output = "0"
  */
void GPIO_ResetBit(GPIO_TypeDef* GPIOx,uint32_t GPIO_Pin)
{
  GPIOx->DATAOUT &= ~GPIO_Pin;
}

/**
  * @brief Write GPIO Output
  */
void GPIO_WriteBits(GPIO_TypeDef* GPIOx,uint32_t value)
{
  GPIOx->DATAOUT = value;
}

/**
  * @brief Read GPIO Input
  */
uint32_t GPIO_ReadBits(GPIO_TypeDef* GPIOx)
{
  return GPIOx->DATA; 
}

/**
  * @param GPIO_TypeDef Pointer
  * @return Output status
  * @brief Returns whether pins on a port are set as inputs or outputs.
  *        If bit 1 of the returned is 1,this is an output.
  */
uint32_t GPIO_GetOutEnable(GPIO_TypeDef* GPIOx)
{
  return GPIOx->OUTENSET;
}

/**
  * @param GPIO_TypeDef Pointer
  * @param uint32_t GPIO Pin
  *        @arg GPIO_Pin_0...GPIO_Pin_15
  * @return none
  * @brief Enables the alternative function for pins.
  *        Set the bit corresponding to the pin number to 1 for alternate function.
  *        Set bit 1 of ALtFunc to 1 to set pin 1 to its alternative function.
  *        This function is thread safe.
  */
void GPIO_SetAltFunc(GPIO_TypeDef* GPIOx,uint32_t GPIO_Pin)
{
  GPIOx->ALTFUNCSET |= GPIO_Pin;
}

/**
  * @param GPIO_TypeDef Pointer
  * @param uint32_t GPIO Pin
  *        @arg GPIO_Pin_0...GPIO_Pin_15
  * @return none
  * @brief Disables the alternative function for pins.
  *        Set the bit corresponding to the pin number to 1 to disable alternate function. 
  *        Set bit 1 of ALtFunc to 1 to set pin 1 to the orignal output function.
  *        This function is thread safe.
  */
void GPIO_ClrAltFunc(GPIO_TypeDef* GPIOx,uint32_t GPIO_Pin)
{
  GPIOx->ALTFUNCCLR = GPIO_Pin;
}

/**
  * @param GPIO_TypeDef Pointer
  * @return AltFunc status
  * @brief Returns whether pins on a port are set to their alternative or their original output functionality.
  *        If bit 1 of the returned is 1,this is alternative function.
  */
uint32_t GPIO_GetAltFunc(GPIO_TypeDef* GPIOx)
{
  return GPIOx->ALTFUNCSET;
}

/**
  * @param GPIO_TypeDef Pointer
  * @param uint32_t GPIO Pin
  *        @arg GPIO_Pin_0...GPIO_Pin_15
  * @return none
  * @brief Clears the interrupt flag for the specified pin.
  */
void GPIO_IntClear(GPIO_TypeDef* GPIOx,uint32_t GPIO_Pin)
{
  GPIOx->INTCLEAR |= GPIO_Pin;
}

/**
  * @param GPIO_TypeDef Pointer
  * @return Interrupt status
  * @brief Returns GPIO Interrupt request status.
  */
uint32_t GPIO_GetIntStatus(GPIO_TypeDef* GPIOx)
{
  return GPIOx->INTSTATUS;
}

/**
  * @param GPIO_TypeDef Pointer
  * @param uint32_t GPIO Pin
  *        @arg GPIO_Pin_0...GPIO_Pin_15
  * @return Interrupt enable set
  * @brief Enables interrupts for the specified pin.
  *        Returns the new interrupt enable status of the pin.
  *        This function is thread safe.
  */
uint32_t GPIO_SetIntEnable(GPIO_TypeDef* GPIOx,uint32_t GPIO_Pin)
{
  GPIOx->INTENSET |= GPIO_Pin;
  return GPIOx->INTENSET;
}

/**
  * @param GPIO_TypeDef Pointer
  * @param GPIO Pin
  *        @arg GPIO_Pin_0...GPIO_Pin_15
  * @return Interrupt enable clear
  * @brief Disables interrupts for the specified pin.
  *        Returns the new interrupt enable status of the pin.
  *        This function is thread safe.
  */
uint32_t GPIO_ClrIntEnable(GPIO_TypeDef* GPIOx,uint32_t GPIO_Pin)
{
  GPIOx->INTENCLR |= GPIO_Pin;
  return GPIOx->INTENCLR;
}

/**
  * @param GPIO_TypeDef Pointer
  * @param GPIO Pin
  *        @arg GPIO_Pin_0...GPIO_Pin_15
  * @return none
  * @brief Changes the interrupt type for the specified pin to a high level interrupt. 
  *        This function is thread safe.
  */
void GPIO_SetIntHighLevel(GPIO_TypeDef* GPIOx,uint32_t GPIO_Pin)
{
  GPIOx->INTENSET |= GPIO_Pin;    /* Set INT Enable bit */
  GPIOx->INTTYPECLR |= GPIO_Pin; /* Clear INT TYPE bit */
  GPIOx->INTPOLSET |= GPIO_Pin;  /* Set INT POLarity bit */
}

/**
  * @param GPIO_TypeDef Pointer
  * @param GPIO Pin
  *        @arg GPIO_Pin_0...GPIO_Pin_15
  * @return none
  * @brief Changes the interrupt type for the specified pin to a rising edge interrupt.
  *        This function is thread safe.
  */
void GPIO_SetIntRisingEdge(GPIO_TypeDef* GPIOx,uint32_t GPIO_Pin)
{
  GPIOx->INTENSET |= GPIO_Pin;   /* Set INT Enable bit */
  GPIOx->INTTYPESET |= GPIO_Pin; /* Set INT TYPE bit */
  GPIOx->INTPOLSET |= GPIO_Pin;  /* Set INT POLarity bit */
}

/**
  * @param GPIO_TypeDef Pointer
  * @param GPIO Pin
  *        @arg GPIO_Pin_0...GPIO_Pin_15
  * @return none
  * @brief Changes the interrupt type for the specified pin to a low level interrupt.
  *        This function is thread safe.
  */
void GPIO_SetIntLowLevel(GPIO_TypeDef* GPIOx,uint32_t GPIO_Pin)
{
  GPIOx->INTENSET |= GPIO_Pin;    /* Set INT Enable bit */
  GPIOx->INTTYPECLR |= GPIO_Pin;  /* Clear INT TYPE bit */
  GPIOx->INTPOLCLR |= GPIO_Pin;   /* Clear INT POLarity bit */
}

/**
  * @param GPIO_TypeDef Pointer
  * @param GPIO Pin
  *        @arg GPIO_Pin_0...GPIO_Pin_15
  * @return none
  * @brief Changes the interrupt type for the specified pin to a falling edge interrupt.
  *        This function is thread safe.
  */
void GPIO_SetIntFallingEdge(GPIO_TypeDef* GPIOx,uint32_t GPIO_Pin)
{
  GPIOx->INTENSET |= GPIO_Pin;    /* Set INT Enable bit */
  GPIOx->INTTYPESET |= GPIO_Pin;  /* Set INT TYPE bit */
  GPIOx->INTPOLCLR |= GPIO_Pin;   /* Clear INT POLarity bit */
}

/**
  * @param GPIO_TypeDef Pointer
  * @param uint32_t mask The output port mask.
  * @param uint32_t value The value to output to the specified port.
  * @return none
  * @brief Outputs the specified value on the desired port using the user defined mask to perform Masked access.
  */
void GPIO_MaskedWrite(GPIO_TypeDef* GPIOx,uint32_t value,uint32_t mask)
{
  GPIOx->MASKLOWBYTE[0x00FF & mask] = value;
  GPIOx->MASKHIGHBYTE[((0xFF00 & mask) >> 8)] = value;
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
