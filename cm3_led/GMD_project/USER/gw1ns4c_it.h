/*
 * *****************************************************************************************
 *
 * 		Copyright (C) 2014-2021 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file		gw1ns4c_it.h
 * @author		Embedded Development Team
 * @version		V1.x.x
 * @date		2021-01-01 09:00:00
 * @brief		This file contains the headers of the interrupt handlers.
 ******************************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GW1NS4C_IT_H
#define __GW1NS4C_IT_H

#ifdef __cplusplus
	extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "gw1ns4c.h"

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/

/* Exported functions ------------------------------------------------------- */

/* Core Exceptions Handler */
void NMI_Handler(void);
void HardFault_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
void SVC_Handler(void);
void DebugMon_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);

/* StdPeriph Interrupts Handler */
void USER_INT0_Handler(void);
void USER_INT1_Handler(void);
void USER_INT2_Handler(void);
void USER_INT3_Handler(void);
void USER_INT4_Handler(void);
void USER_INT5_Handler(void);
void UART0_Handler(void);
void UART1_Handler(void);
void TIMER0_Handler(void);
void TIMER1_Handler(void);
void I2C_Handler(void);
void RTC_Handler(void);
void PORT0_0_Handler(void);
void PORT0_1_Handler(void);
void PORT0_2_Handler(void);
void PORT0_3_Handler(void);
void PORT0_4_Handler(void);
void PORT0_5_Handler(void);
void PORT0_6_Handler(void);
void PORT0_7_Handler(void);
void PORT0_8_Handler(void);
void PORT0_9_Handler(void);
void PORT0_10_Handler(void);
void PORT0_11_Handler(void);
void PORT0_12_Handler(void);
void PORT0_13_Handler(void);
void PORT0_14_Handler(void);
void PORT0_15_Handler(void);

#ifdef __cplusplus
}
#endif

#endif /* __GW1NS4C_IT_H */

/*************************GowinSemiconductor*****END OF FILE*********************/
