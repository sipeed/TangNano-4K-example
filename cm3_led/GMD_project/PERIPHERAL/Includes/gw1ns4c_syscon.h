/*
 * *****************************************************************************************
 *
 * 		Copyright (C) 2014-2021 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file      gw1ns4c_syscon.h
 * @author    Embedded Development Team
 * @version   V1.x.x
 * @date      2021-01-01 09:00:00
 * @brief     This file contains all the functions prototypes for the SYSCON firmware library.
 ******************************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GW1NS4C_SYSCON_H
#define __GW1NS4C_SYSCON_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "gw1ns4c.h"

/** @addtogroup GW1NS4C_StdPeriph_Driver
  * @{
  */

/** @addtogroup SYSCON
  * @{
  */

/** @defgroup SYSCON_Exported_Types
  * @{
  */

/**
  * @}
  */

/** @defgroup SYSCON_Exported_Macros
  * @{
  */

#define SYSCON_RSTINFO_SYSRESETREQ_Pos   0    /* System Reset Request bit position */
#define SYSCON_RSTINFO_WDOGRESETREQ_Pos  1    /* WatchDog Reset Requestt bit position */
#define SYSCON_RSTINFO_LOCKUPRESET_Pos   2    /* Lockup Resett bit position */

/**
  * @}
  */

/** @defgroup SYSCON_Exported_Functions
  * @{
  */

/**
  * @brief Initializes SYSCON
  */
void SYSCON_Init(void);

/**
  * @brief Returns REMAP
  */
uint32_t SYSCON_GetRemap(void);

/**
  * @brief Returns PMUCTRL Enable
  */
uint32_t SYSCON_GetPmuctrlEnable(void);

/**
  * @brief Returns RESETOP LOCKUPRST
  */
uint32_t SYSCON_GetResetopLockuprst(void);

/**
  * @brief Returns RSTINFO SYSRESETREQ
  */
FlagStatus SYSCON_GetRstinfoSysresetreq(void);

/**
  * @brief Returns RSTINFO WDOGRESETREQ
  */
FlagStatus SYSCON_GetRstinfoWdogresetreq(void);

/**
  * @brief Returns RSTINFO LOCKRESET
  */
FlagStatus SYSCON_GetRstinfoLockreset(void);

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __GW1NS4C_SYSCON_H */

/**
  * @}
  */ 

/**
  * @}
  */ 

/************************GowinSemiconductor******END OF FILE*******************/
