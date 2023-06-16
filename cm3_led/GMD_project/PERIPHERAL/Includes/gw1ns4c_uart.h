/*
 * *****************************************************************************************
 *
 * 		Copyright (C) 2014-2021 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file        gw1ns4c_uart.h
 * @author      Embedded Development Team
 * @version     V1.x.x
 * @date        2021-01-01 09:00:00
 * @brief       This file contains all the functions prototypes for the UART firmware library.
 ******************************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GW1NS4C_UART_H
#define __GW1NS4C_UART_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "gw1ns4c.h"

/** @addtogroup GW1NS4C_StdPeriph_Driver
  * @{
  */

/** @addtogroup UART
  * @{
  */

/** @defgroup UART_Exported_Types
  * @{
  */

/**
  * @brief UART mode typedef
  */
typedef struct
{
  FunctionalState UARTMode_Tx;  /* TX Enable */
  FunctionalState UARTMode_Rx;  /* RX Enable */
}UARTMode_TypeDef;

/**
  * @brief UART interrupt typedef
  */
typedef struct
{
  FunctionalState UARTInt_Tx;  /* Tx Interrupt Enable */
  FunctionalState UARTInt_Rx;  /* Rx Interrupt Enable */
}UARTInt_TypeDef;

/**
 * @brief UART overrun typedef
 */
typedef struct
{
  FunctionalState UARTOvr_Tx;  /* Tx Overrun Interrupt Enable */
  FunctionalState UARTOvr_Rx;  /* Rx Overrun Interrupt Enable */
}UARTOvr_TypeDef;

/** 
  * @brief UART Initialization Structure definition  
  */ 
typedef struct
{
  uint32_t UART_BaudRate;         /* Baud Rate                 */

  UARTMode_TypeDef UART_Mode;     /* UART Mode                 */

  UARTInt_TypeDef UART_Int;       /* UART Interrupt            */

  UARTOvr_TypeDef UART_Ovr;       /* UART Overrun              */

  FunctionalState UART_Hstm;      /* UART High Speed Test Mode */

}UART_InitTypeDef;

/**
  * @}
  */

/** @defgroup UART_Exported_Macros
  * @{
  */

#define UART_STATE_TXBF_Pos     0  /* UART STATE: TXBF Position            */
#define UART_STATE_RXBF_Pos     1  /* UART STATE: RXBF Position            */
#define UART_STATE_TXOR_Pos     2  /* UART STATE: TXOR Position            */
#define UART_STATE_RXOR_Pos     3  /* UART STATE: RXOR Position            */

#define UART_CTRL_TXEN_Pos      0  /* UART CTRL: TXEN Position             */
#define UART_CTRL_RXEN_Pos      1  /* UART CTRL: RXEN Position             */
#define UART_CTRL_TXIRQEN_Pos   2  /* UART CTRL: TXIRQEN Position          */
#define UART_CTRL_RXIRQEN_Pos   3  /* UART CTRL: RXIRQEN Position          */
#define UART_CTRL_TXORIRQEN_Pos 4  /* UART CTRL: TXORIRQEN Position        */
#define UART_CTRL_RXORIRQEN_Pos 5  /* UART CTRL: RXORIRQEN Position        */
#define UART_CTRL_HSTM_Pos      6  /* UART CTRL: HSTM Position             */

#define UART_INTSTATUS_TXIRQ_Pos     0  /* UART INTSTATUS: TXIRQ Position  */
#define UART_INTSTATUS_RXIRQ_Pos    1  /* UART INTSTATUS: RXIRQ Position   */
#define UART_INTSTATUS_TXORIRQ_Pos  2  /* UART INTSTATUS: TXORIRQ Position */
#define UART_INTSTATUS_RXORIRQ_Pos  3  /* UART INTSTATUS: RXORIRQ Position */

#define UART_INTCLEAR_TXIRQ_Pos     0  /* UART INTCLEAR: TXIRQ Position    */
#define UART_INTCLEAR_RXIRQ_Pos     1  /* UART INTCLEAR: RXIRQ Position    */
#define UART_INTCLEAR_TXORIRQ_Pos   2  /* UART INTCLEAR: TXORIRQ Position  */
#define UART_INTCLEAR_RXORIRQ_Pos   3  /* UART INTCLEAR: RXORIRQ Position  */

/**
  * @}
  */

/** @defgroup UART_Exported_Functions
  * @{
  */

/**
  * @brief Initializes UART module.
  */
extern ErrorStatus UART_Init(UART_TypeDef* UARTx, UART_InitTypeDef* UART_InitStruct);

/**
  * @brief Returns whether the UART RX Buffer is Full.
  */
extern FlagStatus UART_GetRxBufferFull(UART_TypeDef* UARTx);

/**
  * @brief Returns whether the UART TX Buffer is Full.
  */
extern FlagStatus UART_GetTxBufferFull(UART_TypeDef* UARTx);

/**
  * @brief Returns whether the UART RX Buffer is Overrun.
  */
extern FlagStatus UART_GetRxBufferOverrunStatus(UART_TypeDef* UARTx);

/**
  * @brief Returns whether the UART TX Buffer is Overrun.
  */
extern FlagStatus UART_GetTxBufferOverrunStatus(UART_TypeDef* UARTx);

/**
  * @brief Clears RxBuffer overrun status.
  */ 
extern void UART_ClearRxBufferOverrunStatus(UART_TypeDef* UARTx);

/**
  * @brief Clears TxBuffer overrun status.
  */ 
extern void UART_ClearTxBufferOverrunStatus(UART_TypeDef* UARTx);

/**
  * @brief Sends a character to the UART TX Buffer.
  */
extern void UART_SendChar(UART_TypeDef* UARTx, char txchar);

/**
  * @brief Sends a string to the UART TX Buffer.
  */
extern void UART_SendString(UART_TypeDef* UARTx, char *str);

/**
  * @brief Receives a character from the UART RX Buffer.
  */
extern char UART_ReceiveChar(UART_TypeDef* UARTx);

/**
  * @brief Returns UART Baud rate Divider value.
  */
extern uint32_t UART_GetBaudDivider(UART_TypeDef* UARTx);

/**
  * @brief Return UART TX Interrupt Status.
  */
extern ITStatus UART_GetTxIRQStatus(UART_TypeDef* UARTx);

/**
  * @brief Return UART RX Interrupt Status.
  */
extern ITStatus UART_GetRxIRQStatus(UART_TypeDef* UARTx);

/**
  * @brief Clear UART TX Interrupt request.
  */
extern void UART_ClearTxIRQ(UART_TypeDef* UART);

/**
  * @brief Clear UART RX Interrupt request.
  */
extern void UART_ClearRxIRQ(UART_TypeDef* UART);

/**
  * @brief Return UART TX Overrun Interrupt Status.
  */
extern ITStatus UART_GetTxOverrunIRQStatus(UART_TypeDef* UARTx);

/**
  * @brief Return UART RX Overrun Interrupt Status.
  */
extern ITStatus UART_GetRxOverrunIRQStatus(UART_TypeDef* UARTx);

/**
  * @brief Clear UART TX Overrun Interrupt request.
  */
extern void UART_ClearTxOverrunIRQ(UART_TypeDef* UARTx);

/**
  * @brief Clear UART RX Overrun Interrupt request.
  */
extern void UART_ClearRxOverrunIRQ(UART_TypeDef* UARTx);

/**
  * @brief Sets Tx High Speed Test Mode
  */
extern void UART_SetHSTM(UART_TypeDef* UARTx);

/**
  * @brief Clears Tx High Speed Test Mode
  */
extern void UART_ClrHSTM(UART_TypeDef* UARTx);

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __GW1NS4C_UART_H */

/**
  * @}
  */ 

/**
  * @}
  */ 

/************************GowinSemiconductor******END OF FILE*******************/
