/*
 * *****************************************************************************************
 *
 * 		Copyright (C) 2014-2021 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file			gw1ns4c_rtc.c
 * @author		Embedded Development Team
 * @version		V1.x.x
 * @date			2021-01-01 09:00:00
 * @brief			This file contains all the functions prototypes for the RTC firmware library.
 ******************************************************************************************
 */

 /* Includes ------------------------------------------------------------------*/
#include "gw1ns4c_rtc.h"

//THE CLOCK OF RTC is 1HZ
uint32_t Get_Current_Value(void)
{
	return RTC->RTC_CURRENT_DATA;
}

void Set_Match_Value(uint32_t match_value)
{
	RTC->RTC_MATCH_VALUE =match_value;
}

uint32_t Get_Match_Value(void)
{
	return RTC->RTC_MATCH_VALUE;
}

void Set_Load_Value(uint32_t load_value)
{
	RTC->RTC_LOAD_VALUE = load_value;
}

uint32_t Get_Load_Value(void)
{
	return RTC->RTC_LOAD_VALUE;
}

void Start_RTC(void)
{
	RTC->RTC_CTROLLER_REG =0x01;
}

void Close_RTC(void)
{
	RTC->RTC_CTROLLER_REG =0x00;
}

uint8_t Get_RTC_Control_value(void)
{
	return RTC->RTC_CTROLLER_REG;
}

void RTC_Inter_Mask_Set(void)
{
	RTC->RTC_IMSC = 0x01;
}

void RTC_Inter_Mask_Clr(void)//MASK Interrupt FLAG
{
	RTC->RTC_IMSC = 0x00;
}

uint8_t Get_RTC_Inter_Mask_value(void)
{
	return RTC->RTC_IMSC;
}

void Clear_RTC_interrupt(void)
{
	RTC->RTC_INTR_CLEAR = 0x01;
}

void RTC_init(void)
{
	Set_Match_Value(30);//Match 30
	Set_Load_Value(0);//0 Statr 
	RTC_Inter_Mask_Set();
	//RTC_Inter_Mask_Clr();
	Start_RTC();
}

/************************GowinSemiconductor******END OF FILE*******************/
