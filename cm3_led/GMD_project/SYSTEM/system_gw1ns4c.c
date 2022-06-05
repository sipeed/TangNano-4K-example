/*
 * *****************************************************************************************
 *
 * 		Copyright (C) 2014-2021 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file        system_gw1ns4c.c
 * @author      Embedded Development Team
 * @version     V1.x.x
 * @date        2021-01-01 09:00:00
 * @brief       CMSIS Cortex-M3 Device Peripheral Access Layer System Source File.
 *              This file contains the system clock configuration for GW1NS-4C device.
 *
 *              This file provides two functions and one global variable to be called from
 *              user application:
 *                - SystemInit(): Setups the system clock.
 *                                 This function is called at startup just after reset and
 *                                 before branch to main program. This call is mad inside
 *                                 the "startup_gw1ns4c.s" file.
 *                - SystemCoreClock variable: Contains the core clock, it can be used
 *                                 by the user application to setup the SysTick 
 *                                 timer or configure other parameters.
 *                - SystemCoreClockUpdate(): Updates the variable SystemCoreClock and must
 *                                 be called whenever the core clock is changed
 *                                 during program execution.
 ******************************************************************************************
 */

/** @addtogroup CMSIS
  * @{
  */

/** @addtogroup gw1ns4c_system
  * @{
  */  
  
/** @addtogroup GW1NS4C_System_Private_Includes
  * @{
  */

#include "gw1ns4c.h"

/**
  * @}
  */

/** @addtogroup GW1NS4C_System_Private_TypesDefinitions
  * @{
  */

/**
  * @}
  */

/** @addtogroup GW1NS4C_System_Private_Defines
  * @{
  */

/**
  * @}
  */

/** @addtogroup GW1NS4C_System_Private_Macros
  * @{
  */

/*----------------------------------------------------------------------------
  Define clocks
 *----------------------------------------------------------------------------*/
#define __XTAL            (160000000UL)    /* Oscillator frequency */

#define __SYSTEM_CLOCK    (__XTAL / 2)	   /* 80MHz */

/**
  * @}
  */

/** @addtogroup GW1NS4C_System_Private_Variables
  * @{
  */

/*----------------------------------------------------------------------------
  Clock Variable definitions
 *----------------------------------------------------------------------------*/
uint32_t SystemCoreClock = __SYSTEM_CLOCK;/*!< System Clock Frequency (Core Clock)*/
uint32_t PCLK1 = __SYSTEM_CLOCK;          /*!< APB1 Clock Frequency */
uint32_t PCLK2 = __SYSTEM_CLOCK;          /*!< APB2 Clock Frequency */
uint32_t HCLK = __SYSTEM_CLOCK;           /*!< AHB Clock Frequency */

/**
  * @}
  */

/** @addtogroup GW1NS4C_System_Private_Functions
  * @{
  */

/*----------------------------------------------------------------------------
  Clock functions
 *----------------------------------------------------------------------------*/
/**
 * Update SystemCoreClock variable
 *
 * @param  none
 * @return none
 * @brief  Updates the SystemCoreClock with current core Clock
 *         retrieved from mcu registers.
 */
void SystemCoreClockUpdate (void)
{
  SystemCoreClock = __SYSTEM_CLOCK;
  PCLK1 = SystemCoreClock;
  PCLK2 = SystemCoreClock;
  HCLK = SystemCoreClock;
}

/**
 * @param  none
 * @return none
 * @brief  Setup the mcu system.
 *         Initialize the System.
 */
void SystemInit (void)
{
#ifdef UNALIGNED_SUPPORT_DISABLE
  SCB->CCR |= SCB_CCR_UNALIGN_TRP_Msk;
#endif

  SystemCoreClock = __SYSTEM_CLOCK;
  PCLK1 = SystemCoreClock;
  PCLK2 = SystemCoreClock;
  HCLK = SystemCoreClock;
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

/***********************GowinSemiconductor*******END OF FILE***************/
