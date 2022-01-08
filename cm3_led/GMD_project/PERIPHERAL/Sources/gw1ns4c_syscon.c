/*
 * *****************************************************************************************
 *
 * 		Copyright (C) 2014-2021 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file        gw1ns4c_syscon.c
 * @author      Embedded Development Team
 * @version     V1.x.x
 * @date        2021-01-01 09:00:00
 * @brief       This file contains all the functions prototypes for the SYSCON firmware library.
 ******************************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "gw1ns4c_syscon.h"

/** @addtogroup GW1NS4C_StdPeriph_Driver
  * @{
  */

/** @defgroup SYSCON
  * @brief SYSCON driver modules
  * @{
  */

/** @defgroup SYSCON_Private_TypesDefinitions
  * @{
  */

/**
  * @}
  */

/** @defgroup SYSCON_Private_Macros
  * @{
  */

/**
  * @}
  */

/** @defgroup SYSCON_Private_Variables
  * @{
  */

/**
  * @}
  */

/** @defgroup SYSCON_Private_FunctionPrototypes
  * @{
  */

/**
  * @}
  */

/** @defgroup SYSCON_Private_Functions
  * @{
  */

/**
  * @param none
  * @return none
  * @brief Initializes SYSCON
  */
void SYSCON_Init(void)
{
  SYSCON->REMAP = 0;
  SYSCON->PMUCTRL = 0;
  SYSCON->RESETOP = 0;
  SYSCON->RSTINFO = 0;
}

/**
  * @param none
  * @return uint32_t
  * @brief Returns REMAP
  */
uint32_t SYSCON_GetRemap(void)
{
  return SYSCON->REMAP;
}

/**
  * @param none
  * @param uint32_t
  * @brief Returns PMUCTRL Enable
  */
uint32_t SYSCON_GetPmuctrlEnable(void)
{
  return SYSCON->PMUCTRL;
}

/**
  * @param none
  * @return uint32_t
  * @brief Returns RESETOP LOCKUPRST
  */
uint32_t SYSCON_GetResetopLockuprst(void)
{
  return SYSCON->RESETOP;
}

/**
  * @param none
  * @return FlagStatus
  *         @arg SET
  *         @arg RESET
  * @brief Returns RSTINFO SYSRESETREQ
  */
FlagStatus SYSCON_GetRstinfoSysresetreq(void)
{
  return (FlagStatus)((SYSCON->RSTINFO & SYSCON_RSTINFO_SYSRESETREQ) >> SYSCON_RSTINFO_SYSRESETREQ_Pos);
}

/**
  * @param none
  * @return FlagStatus
  *         @arg SET
  *         @arg RESET
  * @brief Returns RSTINFO WDOGRESETREQ
  */
FlagStatus SYSCON_GetRstinfoWdogresetreq(void)
{
  return (FlagStatus)((SYSCON->RSTINFO & SYSCON_RSTINFO_WDOGRESETREQ) >> SYSCON_RSTINFO_WDOGRESETREQ_Pos);
}

/**
  * @param none
  * @return FlagStatus
  *         @arg SET
  *         @arg RESET
  * @brief Returns RSTINFO LOCKRESET
  */
FlagStatus SYSCON_GetRstinfoLockreset(void)
{
  return (FlagStatus)((SYSCON->RSTINFO & SYSCON_RSTINFO_LOCKUPRESET) >> SYSCON_RSTINFO_LOCKUPRESET_Pos);
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
