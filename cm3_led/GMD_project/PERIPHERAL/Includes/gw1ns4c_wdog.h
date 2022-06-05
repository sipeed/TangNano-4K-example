/*
 * *****************************************************************************************
 *
 * 		Copyright (C) 2014-2021 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file        gw1ns4c_wdog.h
 * @author      Embedded Development Team
 * @version     V1.x.x
 * @date        2021-01-01 09:00:00
 * @brief       This file contains all the functions prototypes for the WatchDog firmware library.
 ******************************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GW1NS4C_WDOG_H
#define __GW1NS4C_WDOG_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "gw1ns4c.h"

/** @addtogroup GW1NS4C_StdPeriph_Driver
  * @{
  */

/** @addtogroup WatchDog
  * @{
  */

/** @defgroup WDOG_Exported_Types
  * @{
  */

/**
 * @brief WatchDog Lock TypeDef.
 */
typedef FunctionalState WDOGLock_TypeDef;

/**
 * @brief WatchDog Interrupt TypeDef.
 */
typedef FunctionalState WDOGInt_TypeDef;

/**
 * @brief WatchDog Reset TypeDef.
 */
typedef FunctionalState WDOGRes_TypeDef;

/**
 * @brief WatchDog Integration Test Mode TypeDef.
 */
typedef FunctionalState WDOGMode_Typedef;

/**
 * @brief WatchDog Initialization TypeDef.
 */
typedef struct
{
  uint32_t WDOG_Reload;         /* WatchDog Reload value */
  
  WDOGLock_TypeDef WDOG_Lock;   /* WatchDog Lock register write access */
  
  WDOGInt_TypeDef WDOG_Int;     /* WatchDog Interrupt enable flag */
  
  WDOGRes_TypeDef WDOG_Res;     /* WatchDog Reset enable flag */
  
  WDOGMode_Typedef WDOG_ITMode; /* WatchDog Integration Test Mode enable flag */
  
}WDOG_InitTypeDef;

/**
  * @}
  */

/** @defgroup WDOG_Exported_Macros
  * @{
  */

#define WDOG_LOCK_EN_Pos 1           /*[31:1] write register access enable   */
#define WDOG_CTRL_INTEN_Pos 0        /* CTRL register INTEN bit position     */
#define WDOG_CTRL_RESEN_Pos 1        /* CTRL register RESEN bit position     */
#define WDOG_RAWINTSTAT_Pos 0        /* Raw Interrupt Status bit position    */
#define WDOG_MASKINTSTAT_Pos 0       /* Masked Interrupt Status bit position */
#define WDOG_ITCR_INTEGTESTEN_Pos 0  /* Integration Test Mode bit position   */
#define WDOG_ITOP_WDOGRES_Pos 0      /* ITOP WDOGRES bit position            */
#define WDOG_ITOP_WDOGINT_Pos 1      /* ITOP WDOGINT bit position            */

/**
  * @}
  */

/** @defgroup WDOG_Exported_Functions
  * @{
  */

/**
 * @brief WatchDog initialization.
 */
extern ErrorStatus WDOG_Init(WDOG_InitTypeDef* WDOG_InitStruct);

/**
 * @brief Restart watchdog counter.
 */
extern void WDOG_RestartCounter(uint32_t reload);

/**
 * @brief Returns counter value.
 */
extern uint32_t WDOG_GetCounterValue(void);

/**
 * @brief Sets reset enable.
 */
extern void WDOG_SetResetEnable(void);

/**
 * @brief Returns reset status.
 */
extern FlagStatus WDOG_GetResStatus(void);

/**
 * @brief Sets interrupt enable.
 */
extern void WDOG_SetIntEnable(void);

/**
 * @brief Returns interrupt status.
 */
extern FlagStatus WDOG_GetIntStatus(void);

/**
 * @brief Clears interrupt enable.
 */
extern void WDOG_ClrIntEnable(void);

/**
 * @brief Returns raw interrupt status.
 */
extern FlagStatus WDOG_GetRawIntStatus(void);

/**
 * @brief Returns masked interrupt status.
 */
extern FlagStatus WDOG_GetMaskIntStatus(void);

/**
 * @brief Disable write access all registers.
 */
extern void WDOG_LockWriteAccess(void);

/**
 * @brief Enable write access all registers.
 */
extern void WDOG_UnlockWriteAccess(void);

/**
 * @brief Sets integration test mode enable.
 */
extern void WDOG_SetITModeEnable(void);

/**
 * @brief Clears integration test mode enable.
 */
extern void WDOG_ClrITModeEnable(void);

/**
 * @brief Returns integration test mode status.
 */
extern FlagStatus WDOG_GetITModeStatus(void);

/**
 * @brief Sets integration test output WDOGINT or WDOGRES.
 */
extern void WDOG_SetITOP(uint32_t itop);

/**
 * @brief Returns integration test output WDOGRES status.
 */
extern FlagStatus WDOG_GetITOPResStatus(void);

/**
 * @brief Returns integration test output WDOGINT status.
 */
extern FlagStatus WDOG_GetITOPIntStatus(void);

/**
 * @brief Clear integration test output WDOGINT or WDOGRES.
 */
extern void WDOG_ClrITOP(uint32_t itop);

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif  /* __GW1NS4C_WDOG_H */

/**
  * @}
  */ 

/**
  * @}
  */ 

/************************GowinSemiconductor******END OF FILE*******************/
