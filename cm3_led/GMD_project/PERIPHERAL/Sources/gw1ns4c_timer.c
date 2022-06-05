/*
 * *****************************************************************************************
 *
 * 		Copyright (C) 2014-2021 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file        gw1ns4c_timer.c
 * @author      Embedded Development Team
 * @version     V1.x.x
 * @date        2021-01-01 09:00:00
 * @brief       This file contains all the functions prototypes for the TIMER firmware library.
 ******************************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "gw1ns4c_timer.h"

/** @addtogroup GW1NS4C_StdPeriph_Driver
  * @{
  */

/** @defgroup TIMER 
  * @brief TIMER driver modules
  * @{
  */

/** @defgroup TIMER_Private_TypesDefinitions
  * @{
  */

/**
  * @}
  */

/** @defgroup TIMER_Private_Macros
  * @{
  */

/**
  * @}
  */

/** @defgroup TIMER_Private_Variables
  * @{
  */

/**
  * @}
  */

/** @defgroup TIMER_Private_FunctionPrototypes
  * @{
  */

/**
  * @}
  */

/** @defgroup TIMER_Private_Functions
  * @{
  */

/**
  * @param TIMER_TypeDef Pointer
  * @param TIMER_InitTypeDef Pointer
  * @return none 
  * @brief Initializes Timer module.
  *        TIMERInt_TypeDef : Interrupt enable.
  *        TIMERExti_TypeDef : Select external input;
  *        Or Initializes the timer to user the internal clock.
  */
void TIMER_Init(TIMER_TypeDef* TIMERx,TIMER_InitTypeDef* TIMER_InitStruct)
{
  /* Initial all register to zero */
  TIMERx->CTRL = 0;
  TIMERx->VALUE = 0;
  TIMERx->RELOAD = 0;
  TIMERx->INTCLEAR = 0;

  /* VALUE register */
  TIMERx->VALUE = TIMER_InitStruct->Reload;

  /* RELOAD register */
  TIMERx->RELOAD = TIMER_InitStruct->Reload;

  /* CTRL register timer enable */
  TIMERx->CTRL |= TIMER_CTRL_EN;

  /* if TIMER_Int enable */
  if(TIMER_InitStruct->TIMER_Int == ENABLE)
  {
    TIMERx->CTRL |= TIMER_CTRL_IRQEN;
  }

/* disable external input */
  if(TIMER_InitStruct->TIMER_Exti == TIMER_DISABLE)
  {
    /*  external input as disable */
    TIMERx->CTRL &= ~(TIMER_CTRL_SELEXTEN |TIMER_CTRL_SELEXTEN );
  }

  /* select external input */
  if(TIMER_InitStruct->TIMER_Exti == TIMER_EXTI_EN)
  {
    /*  select external input as enable */
    TIMERx->CTRL |= TIMER_CTRL_SELEXTEN;
  }
  else if(TIMER_InitStruct->TIMER_Exti == TIMER_EXTI_CLK)
  {
    /* select external input as clock */
    TIMERx->CTRL |= TIMER_CTRL_SELEXTCLK;
  }
}

/**
  * @param TIMER_TypeDef Pointer
  * @return none 
  * @brief Starts Timer.
  */
void TIMER_StartTimer(TIMER_TypeDef* TIMERx)
{
  TIMERx->CTRL |= TIMER_CTRL_EN;
}

/**
  * @param TIMER_TypeDef Pointer
  * @return none 
  * @brief Stops Timer.
  */
void TIMER_StopTimer(TIMER_TypeDef* TIMERx)
{
  TIMERx->CTRL &= ~TIMER_CTRL_EN;
}

/**
  * @param TIMER_TypeDef Pointer
  * @return Interrupt Status
  *         @arg SET
  *         @arg RESET
  * @brief Returns timer IRQ status.
  */
ITStatus TIMER_GetIRQStatus(TIMER_TypeDef* TIMERx)
{
  return (ITStatus)(TIMERx->INTSTATUS);
}

/**
  * @param TIMER_TypeDef Pointer
  * @return none
  * @brief Timer interrupt clear.
  */
void TIMER_ClearIRQ(TIMER_TypeDef* TIMERx)
{
  TIMERx->INTCLEAR = TIMER_INTCLEAR;
}

/**
  * @param TIMER_TypeDef Pointer
  * @return reload value
  * @brief Returns Timer Reload value.
  *        The reload value is the value which the timer is set to after an underflow occurs.
  */
uint32_t TIMER_GetReload(TIMER_TypeDef* TIMERx)
{
  return TIMERx->RELOAD;
}

/**
  * @param TIMER_TypeDef Pointer
  * @param uint32_t value to set reload
  * @return none
  * @brief Sets Timer Reload value.
  *        The reload value is the value which the timer is set to after an underflow occurs.
  */
void TIMER_SetReload(TIMER_TypeDef* TIMERx,uint32_t value)
{
  TIMERx->RELOAD = value;
}

/**
  * @param TIMER_TypeDef Pointer
  * @return current value
  * @brief Returns Timer current value.
  */
uint32_t TIMER_GetValue(TIMER_TypeDef* TIMERx)
{
  return TIMERx->VALUE;
}

/**
  * @param TIMER_TypeDef Pointer
  * @param uint32_t value to set current value
  * @return none
  * @brief Sets Timer current value.
  */
void TIMER_SetValue(TIMER_TypeDef* TIMERx,uint32_t value)
{
  TIMERx->VALUE = value;
}

/**
  * @param TIMER_TypeDef Pointer
  * @return none
  * @brief Enables Timer Interrupt requests.
  */
void TIMER_EnableIRQ(TIMER_TypeDef* TIMERx)
{
  TIMERx->CTRL |= TIMER_CTRL_IRQEN;
}

/**
  * @param TIMER_TypeDef Pointer
  * @return none
  * @brief Disables Timer Interrupt requests.
  */
void TIMER_DisableIRQ(TIMER_TypeDef* TIMERx)
{
  TIMERx->CTRL &= ~TIMER_CTRL_IRQEN;
}

/**
  * @param TIMER_TypeDef Pointer
  * @return none
  * @brief  Select Ext input Enable.
  */
void TIMER_SelExtEnable(TIMER_TypeDef *TIMER)
{
  TIMER->CTRL = ~(TIMER_CTRL_SELEXTEN |TIMER_CTRL_SELEXTCLK );
  TIMER->CTRL |= TIMER_CTRL_SELEXTEN;    
}

/**
  * @param TIMER_TypeDef Pointer
  * @return none
  * @brief  Select Ext input Clock.
  */
void TIMER_SelExtClock(TIMER_TypeDef *TIMER)
{
  TIMER->CTRL = ~(TIMER_CTRL_SELEXTEN |TIMER_CTRL_SELEXTCLK );
  TIMER->CTRL |= TIMER_CTRL_SELEXTCLK;    
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
