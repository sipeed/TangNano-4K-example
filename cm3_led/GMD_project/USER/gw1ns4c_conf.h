/*
 * *****************************************************************************************
 *
 * 		Copyright (C) 2014-2021 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file        gw1ns4c_conf.h
 * @author      Embedded Development Team
 * @version     V1.x.x
 * @date        2021-01-01 09:00:00
 * @brief       Library configuration file.
 ******************************************************************************************
 */

/* Define to prevent recursive inclusion--------------------------------------*/
#ifndef __GW1NS4C_CONF_H
#define __GW1NS4C_CONF_H

/* Includes ------------------------------------------------------------------*/
/* Uncomment/Comment the line below to enable/disable peripheral header file inclusion */
#include "gw1ns4c_gpio.h"         /* GPIO              */
#include "gw1ns4c_wdog.h"         /* WatchDog          */
#include "gw1ns4c_uart.h"         /* UART              */
#include "gw1ns4c_timer.h"        /* TIMER             */
#include "gw1ns4c_spi.h"          /* SPI               */
#include "gw1ns4c_i2c.h"          /* I2C               */
#include "gw1ns4c_misc.h"         /* NVIC and SysTick  */
#include "gw1ns4c_syscon.h"       /* System Control    */
#include "gw1ns4c_rtc.h"          /* RTC               */

/* Exported macro ------------------------------------------------------------*/

//#define USE_FULL_ASSERT
#ifdef  USE_FULL_ASSERT

/**
  * @brief  The assert_param macro is used for function's parameters check.
  * @param  expr: If expr is false, it calls assert_failed function which reports 
  *         the name of the source file and the source line number of the call 
  *         that failed. If expr is true, it returns no value.
  * @retval None
  */
  #define assert_param(expr) ((expr) ? (void)0 : assert_failed((uint8_t *)__FILE__, __LINE__))
/* Exported functions ------------------------------------------------------- */
void assert_failed(uint8_t* file, uint32_t line);
#else
  #define assert_param(expr) ((void)0)
#endif /* USE_FULL_ASSERT */

#endif /* __GW1NS4C_CONF_H */

/*************************GowinSemiconductor*****END OF FILE*********************/
