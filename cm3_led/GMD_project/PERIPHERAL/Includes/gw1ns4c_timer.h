/*
 * *****************************************************************************************
 *
 * 		Copyright (C) 2014-2021 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file        gw1ns4c_timer.h
 * @author      Embedded Development Team
 * @version     V1.x.x
 * @date        2021-01-01 09:00:00
 * @brief       This file contains all the functions prototypes for the TIMER firmware library.
 ******************************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GW1NS4C_TIMER_H
#define __GW1NS4C_TIMER_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "gw1ns4c.h"

/** @addtogroup GW1NS4C_StdPeriph_Driver
  * @{
  */

/** @addtogroup TIMER
  * @{
  */

/** @defgroup TIMER_Exported_Types
  * @{
  */

/* TIMER interrupt typedef */
typedef FunctionalState TIMERInt_TypeDef;  /* ENABLE/DISABLE */

/* TIMER External input typedef */
typedef enum
{
  TIMER_DISABLE = 0,  /* External Disable */
  TIMER_EXTI_EN,      /* Select external input as enable */
  TIMER_EXTI_CLK      /* Select external input as clock */
}TIMERExti_TypeDef;

/** 
  * @brief TIMER Init Structure definition  
  */
typedef struct
{
  uint32_t Reload;                 /* Reload value, sets the current value */

  TIMERInt_TypeDef TIMER_Int;      /* Timer interrupt */

  TIMERExti_TypeDef TIMER_Exti;    /* Select timer external input */

}TIMER_InitTypeDef;

/**
  * @}
  */

/** @defgroup TIMER_Exported_Macros
  * @{
  */

#define TIMER_CTRL_EN_Pos         0  /* TIMER CTRL: Enable Position */
#define TIMER_CTRL_SELEXTEN_Pos   1  /* TIMER CTRL: External Enable Position */
#define TIMER_CTRL_SELEXTCLK_Pos  2  /* TIMER CTRL: External Clock Position */
#define TIMER_CTRL_IRQEN_Pos      3  /* TIMER CTRL: Interrupt Enable Position */

/**
  * @}
  */

/** @defgroup TIMER_Exported_Functions
  * @{
  */

/**
  * @brief Initializes Timer module.
  */
extern void TIMER_Init(TIMER_TypeDef* TIMERx,TIMER_InitTypeDef* TIMER_InitStruct);

/**
  * @brief Starts Timer.
  */
extern void TIMER_StartTimer(TIMER_TypeDef* TIMERx);

/**
  * @brief Stops Timer.
  */
extern void TIMER_StopTimer(TIMER_TypeDef* TIMERx);

/**
  * @brief Returns timer IRQ status
  */
extern ITStatus TIMER_GetIRQStatus(TIMER_TypeDef* TIMERx);

/**
  * @brief Timer interrupt clear
  */
extern void TIMER_ClearIRQ(TIMER_TypeDef* TIMERx);

/**
  * @brief Returns Timer Reload value.
  */
extern uint32_t TIMER_GetReload(TIMER_TypeDef* TIMERx);

/**
  * @brief Sets Timer Reload value.
  */
extern void TIMER_SetReload(TIMER_TypeDef* TIMERx,uint32_t value);

/**
  * @brief Returns Timer current value.
  */
extern uint32_t TIMER_GetValue(TIMER_TypeDef* TIMERx);

/**
  * @brief Sets Timer current value.
  */
extern void TIMER_SetValue(TIMER_TypeDef* TIMERx,uint32_t value);

/**
  * @brief Enables Timer Interrupt requests.
  */
extern void TIMER_EnableIRQ(TIMER_TypeDef* TIMERx);

/**
  * @brief Disables Timer Interrupt requests.
  */
extern void TIMER_DisableIRQ(TIMER_TypeDef* TIMERx);

/**
  * @brief Select Ext input Enable.
  */
extern void TIMER_SelExtEnable(TIMER_TypeDef *TIMER);

/**
  * @brief Select Ext input Clock.
  */
extern void TIMER_SelExtClock(TIMER_TypeDef *TIMER);

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif  /* __GW1NS4C_TIMER_H */

/**
  * @}
  */ 

/**
  * @}
  */ 

/************************GowinSemiconductor******END OF FILE*******************/
