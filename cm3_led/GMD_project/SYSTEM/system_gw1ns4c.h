/*
 * *****************************************************************************************
 *
 * 		Copyright (C) 2014-2021 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file        system_gw1ns4c.h
 * @author      Embedded Development Team
 * @version     V1.x.x
 * @date        2021-01-01 09:00:00
 * @brief       CMSIS Cortex-M3 Device Peripheral Access Layer Header File for Device GW1NS-4C
 *
 ******************************************************************************************
 */

/** @addtogroup CMSIS
  * @{
  */

/** @addtogroup gw1ns4c_system
  * @{
  */

/**
  * @brief Define to prevent recursive inclusion
  */
#ifndef __SYSTEM_GW1NS4C_H
#define __SYSTEM_GW1NS4C_H

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup GW1NS4C_System_Includes
  * @{
  */

#include <stdint.h>

/**
  * @}
  */

/** @addtogroup GW1NS4C_System_Exported_types
  * @{
  */

extern uint32_t SystemCoreClock;    /*!< Processor Clock Frequency */
extern uint32_t PCLK1;              /*!< APB1 Clock Frequency */
extern uint32_t PCLK2;              /*!< APB2 Clock Frequency */
extern uint32_t HCLK;               /*!< AHB Clock Frequency */

/**
  * @}
  */

/** @addtogroup GW1NS4C_System_Exported_Constants
  * @{
  */

/**
  * @}
  */

/** @addtogroup GW1NS4C_System_Exported_Macros
  * @{
  */

/**
  * @}
  */

/** @addtogroup GW1NS4C_System_Exported_Functions
  * @{
  */

/**
 * Initialize the system
 *
 * @param  none
 * @return none
 *
 * @brief  Setup the mcu system.
 *         Initialize the System and update the SystemCoreClock variable.
 */
extern void SystemInit (void);

/**
 * Update SystemCoreClock variable
 *
 * @param  none
 * @return none
 *
 * @brief  Updates the SystemCoreClock with current core Clock
 *         retrieved from mcu registers.
 */
extern void SystemCoreClockUpdate (void);

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* SYSTEM_GW1NS4C_H */

/**
  * @}
  */
  
/**
  * @}
  */

/**********************GowinSemiconductor**********END OF FILE*****************/
