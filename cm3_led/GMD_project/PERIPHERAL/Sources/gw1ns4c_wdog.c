/*
 * *****************************************************************************************
 *
 * 		Copyright (C) 2014-2021 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file        gw1ns4c_wdog.c
 * @author      Embedded Development Team
 * @version     V1.x.x
 * @date        2021-01-01 09:00:00
 * @brief       This file contains all the functions prototypes for the WatchDog firmware library.
 ******************************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "gw1ns4c_wdog.h"

/** @addtogroup GW1NS4C_StdPeriph_Driver
  * @{
  */

/** @defgroup WDOG
  * @brief WDOG driver modules
  * @{
  */

/** @defgroup WDOG_Private_TypesDefinitions
  * @{
  */

/**
  * @}
  */

/** @defgroup WDOG_Private_Macros
  * @{
  */

/**
  * @}
  */

/** @defgroup WDOG_Private_Variables
  * @{
  */

/**
  * @}
  */

/** @defgroup WDOG_Private_FunctionPrototypes
  * @{
  */

/**
  * @}
  */

/** @defgroup WDOG_Private_Functions
  * @{
  */

/**
  *
  * @param WDOG_InitTypeDef Pointer
  * @return ErrorStatus 
  *         @arg ERROR
  *         @arg SUCCESS
  * @brief Initials WatchDog.
  */ 
ErrorStatus WDOG_Init(WDOG_InitTypeDef* WDOG_InitStruct)
{
  WDOG->LOAD = 0;
  WDOG->CTRL = 0;
  WDOG->INTCLR = 0;
  WDOG->LOCK = 0;
  WDOG->ITCR = 0;
  WDOG->ITOP = 0;
  
  /* Set LOCK register */
  if(WDOG_InitStruct->WDOG_Lock == DISABLE)
  {
    WDOG->LOCK = 0xFFFFFFFF; /* lock : [0] bit is 1, disable write access register */
    return ERROR;	
  }
  
  /* unlock : Enable write access all register */
  WDOG->LOCK = 0xACCE551 << WDOG_LOCK_EN_Pos;  /* [0] bit is 0 */
  
  /* Set Control register Reset bit */
  if(WDOG_InitStruct->WDOG_Res == ENABLE)
  {
    WDOG->CTRL |= WDOG_CTRL_RESEN;
	
	/* Set Integration Test Mode register */
	if(WDOG_InitStruct->WDOG_ITMode == ENABLE)
	{
      WDOG->ITCR |= WDOG_ITCR_INTEGTESTEN;
	  
	  /* Set ITOP register WDOGRES bit */
	  WDOG->ITOP |= WDOG_ITOP_WDOGRES;
	}
  }
  
  /* Set Control register Interrupt bit */
  if(WDOG_InitStruct->WDOG_Int == ENABLE)
  {
    WDOG->CTRL |= WDOG_CTRL_INTEN;
	
	/* Set Integration Test Mode register */
	{
      WDOG->ITCR |= WDOG_ITCR_INTEGTESTEN;
	  
	  /* Set ITOP register WDOGINT bit */
	  WDOG->ITOP |= WDOG_ITOP_WDOGINT;
	}
  }
  
  /* RIS register only read */
  
  /* Set MIS register only read */
  
  /* Set Reload register */
  WDOG->LOAD = WDOG_InitStruct->WDOG_Reload;
  
  /* Set Value register only read */
  
  return SUCCESS;
}

/**
  * @param uint32_t load
  * @return none
  * @brief Restart counter, reload value.
  */
void WDOG_RestartCounter(uint32_t reload)
{
  WDOG->LOAD = reload;
}

/**
  * @param none
  * @return uint32_t value
  * @brief Returns current counter value.
  */
uint32_t WDOG_GetCounterValue(void)
{
  return WDOG->VALUE;
}

/**
  * @param none
  * @return none
  * @brief Sets reset enable.
  */
void WDOG_SetResetEnable(void)
{
  WDOG->CTRL |= WDOG_CTRL_RESEN;
}

/**
  * @param none
  * @return FlagStatus
  *         @arg SET
  *         @arg RESET
  * @brief Returns reset status.
  */
FlagStatus WDOG_GetResStatus(void)
{
  return (FlagStatus)(WDOG->CTRL==WDOG_CTRL_RESEN);
}

/**
  * @param none
  * @return none
  * @brief Sets interrupt enable.
  */
void WDOG_SetIntEnable(void)
{
  WDOG->CTRL |= WDOG_CTRL_INTEN;
}

/**
  * @param none
  * @return FlagStatus
  *         @arg SET
  *         @arg RESET
  * @brief Returns interrupt status.
  */
FlagStatus WDOG_GetIntStatus(void)
{
  return (FlagStatus)(WDOG->CTRL==WDOG_CTRL_INTEN);
}

/**
  * @param none
  * @return none
  * @brief Clears interrupt enable.
  */
void WDOG_ClrIntEnable(void)
{
  /* Write any value to INTCLR clears the interrupt */
  WDOG->INTCLR = WDOG_INTCLR;
}

/**
  * @param none
  * @return FlagStatus
  *         @arg SET
  *         @arg RESET
  * @brief Returns raw interrupt status.
  */
FlagStatus WDOG_GetRawIntStatus(void)
{
  return (FlagStatus)(WDOG->RIS==WDOG_RAWINTSTAT);
}

/**
  * @param none
  * @return FlagStatus
  *         @arg SET
  *         @arg RESET
  * @brief Return masked interrupt status.
  */
FlagStatus WDOG_GetMaskIntStatus(void)
{
  return (FlagStatus)(WDOG->MIS==WDOG_MASKINTSTAT);
}

/**
  * @param none
  * @return none
  * @brief Disable write access all registers.
  */
void WDOG_LockWriteAccess(void)
{
  WDOG->LOCK = 0;
}

/**
  * @param none
  * @return none
  * @brief Enable write access all registers.
  */
void WDOG_UnlockWriteAccess(void)
{
  WDOG->LOCK = 0x1ACCE551;  
}

/**
  * @param none
  * @return none
  * @brief Sets integration test mode enable.
  */
void WDOG_SetITModeEnable(void)
{
  WDOG->ITCR |= WDOG_ITCR_INTEGTESTEN;
}

/**
  * @param none
  * @return none
  * @brief Clears integration test mode enable.
  */
void WDOG_ClrITModeEnable(void)
{
  WDOG->ITCR &= ~WDOG_ITCR_INTEGTESTEN;
}

/**
  * @param none
  * @return FlagStatus
  *         @arg SET
  *         @arg RESET
  * @brief Returns integration test mode status.
  */
FlagStatus WDOG_GetITModeStatus(void)
{
  return (FlagStatus)(WDOG->ITCR==WDOG_ITCR_INTEGTESTEN);
}

/**
  * @param uint32_t
  * @return none
  * @brief Sets integration test output reset or interrupt.
  */
void WDOG_SetITOP(uint32_t itop)
{
  WDOG->ITOP = itop;
}
/**
  * @param uint32_t
  * @return none
  * @brief Clear integration test output reset or interrupt.
  */
void WDOG_ClrITOP(uint32_t itop)
{
  WDOG->ITOP &= ~itop; 
}

/**
  * @param none
  * @return FlagStatus
  *         @arg SET
  *         @arg RESET
  * @brief Returns integration test output reset status.
  */
FlagStatus WDOG_GetITOPResStatus(void)
{
  return (FlagStatus)(WDOG->ITOP==WDOG_ITOP_WDOGRES);
}

/**
  * @param none
  * @return FlagStatus
  *         @arg SET
  *         @arg RESET
  * @brief Returns integration test output interrupt status.
  */
FlagStatus WDOG_GetITOPIntStatus(void)
{
  return (FlagStatus)(WDOG->ITOP==WDOG_ITOP_WDOGINT);
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
