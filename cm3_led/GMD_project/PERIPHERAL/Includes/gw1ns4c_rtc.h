/*
 * *****************************************************************************************
 *
 * 		Copyright (C) 2014-2021 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file        gw1ns4c_rtc.h
 * @author      Embedded Development Team
 * @version     V1.x.x
 * @date        2021-01-01 09:00:00
 * @brief       This file contains all the functions prototypes for the RTC firmware library.
 ******************************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GW1NS4C_RTC_H
#define __GW1NS4C_RTC_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include "gw1ns4c.h"

/* Functions ------------------------------------------------------------------*/
extern uint32_t Get_Current_Value(void);
extern void Set_Match_Value(uint32_t match_value);
extern uint32_t Get_Match_Value(void);
extern void Set_Load_Value(uint32_t load_value);
extern uint32_t Get_Load_Value(void);
extern void Start_RTC(void);
extern void Close_RTC(void);
extern void RTC_Inter_Mask_Set(void);
extern uint8_t Get_RTC_Control_value(void);
extern void RTC_Inter_Mask_Clr(void);
extern uint8_t Get_RTC_Inter_Mask_value(void);
extern void Clear_RTC_interrupt(void);
extern void RTC_init(void);

#ifdef __cplusplus
}
#endif

#endif /* __GW1NS4C_RTC_H */
