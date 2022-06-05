/*
 * *****************************************************************************************
 *
 * 		Copyright (C) 2014-2021 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file        gw1ns4c_uart.c
 * @author      Embedded Development Team
 * @version     V1.x.x
 * @date        2021-01-01 09:00:00
 * @brief       This file contains all the functions prototypes for the UART firmware library.
 ******************************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "gw1ns4c_uart.h"

/** @addtogroup GW1NS4C_StdPeriph_Driver
  * @{
  */

/** @defgroup UART 
  * @brief UART driver modules
  * @{
  */

/** @defgroup UART_Private_TypesDefinitions
  * @{
  */

/**
  * @}
  */

/** @defgroup UART_Private_Macros
  * @{
  */

/**
  * @}
  */

/** @defgroup UART_Private_Variables
  * @{
  */

/**
  * @}
  */

/** @defgroup UART_Private_FunctionPrototypes
  * @{
  */

/**
  * @}
  */

/** @defgroup UART_Private_Functions
  * @{
  */

/** 
  * @param UART_TypeDef Pointer
  * @param UART_InitTypeDef Pointer
  * @return ErrorStatus
  *         @arg ERROR
  *         @arg SUCCESS
  * @brief  Initializes the UART specifying the UART Baud rate divider value.
  *         And whether the send and receive functionality is enabled.
  *         It also specifies which of the various interrupts are enabled.
  */
ErrorStatus UART_Init(UART_TypeDef* UARTx, UART_InitTypeDef* UART_InitStruct)
{
  uint32_t new_ctrl = 0;

  /* Initial all register to zero */
  UARTx->DATA = 0;
  UARTx->STATE = 0;
  UARTx->CTRL = 0;
  UARTx->INTCLEAR = 0;
  UARTx->BAUDDIV = 0;

  /* Config CTRL register */
  /* Tx Enable */
  if(UART_InitStruct->UART_Mode.UARTMode_Tx == ENABLE)
  {
    new_ctrl |= UART_CTRL_TXEN;
  }

  /* Rx Enable */
  if(UART_InitStruct->UART_Mode.UARTMode_Rx == ENABLE)
  {
    new_ctrl |= UART_CTRL_RXEN;
  }

  /* Tx Interrupt Enable */
  if(UART_InitStruct->UART_Int.UARTInt_Tx == ENABLE)
  {
    new_ctrl |= UART_CTRL_TXIRQEN;
  }

  /* Rx Interrupt Enable */
  if(UART_InitStruct->UART_Int.UARTInt_Rx == ENABLE)
  {
    new_ctrl |= UART_CTRL_RXIRQEN;
  }

  /* Tx Overrun Enable */
  if(UART_InitStruct->UART_Ovr.UARTOvr_Tx == ENABLE)
  {
    new_ctrl |= UART_CTRL_TXORIRQEN;
  }

  /* Rx Overrun Enable */
  if(UART_InitStruct->UART_Ovr.UARTOvr_Rx == ENABLE)
  {
    new_ctrl |= UART_CTRL_RXORIRQEN;
  }

  /* High Speed Test Mode Enable */
  if(UART_InitStruct->UART_Hstm == ENABLE)
  {
    new_ctrl |= UART_CTRL_HSTM;
  }

  UARTx->CTRL = 0;         /* Disable UART when changing configuration */
  UARTx->CTRL = new_ctrl;  /* Update CTRL register to new value */

  /* Config baud divider */
  UARTx->BAUDDIV = PCLK1 / UART_InitStruct->UART_BaudRate;

  if((UARTx->STATE & (UART_STATE_RXOR | UART_STATE_TXOR)))
  {
    return ERROR;
  }
  else
  { 
    return SUCCESS;
  }
}

/**
  * @param  UART_TypeDef Pointer
  * @return RxBufferFull
  *         @arg SET
  *         @arg RESET
  * @brief  Returns whether the RX buffer is full.
  */
FlagStatus UART_GetRxBufferFull(UART_TypeDef* UARTx)
{
  return (FlagStatus)((UARTx->STATE & UART_STATE_RXBF) >> UART_STATE_RXBF_Pos);
}

/**
  * @param  UART_TypeDef Pointer
  * @return TxBufferFull 
  *         @arg SET
  *         @arg RESET
  * @brief  Returns whether the TX buffer is full.
  */
FlagStatus UART_GetTxBufferFull(UART_TypeDef* UARTx)
{
  return (FlagStatus)((UARTx->STATE & UART_STATE_TXBF) >> UART_STATE_TXBF_Pos);
}

/**
  * @param  UART_TypeDef Pointer
  * @return RxBufferOverrun
  *         @arg SET
  *         @arg RESET
  * @brief  Returns whether the RX buffer is overrun.
  */
FlagStatus UART_GetRxBufferOverrunStatus(UART_TypeDef* UARTx)
{
  return (FlagStatus)((UARTx->STATE & UART_STATE_RXOR) >> UART_STATE_RXOR_Pos);
}

/**
  * @param  UART_TypeDef Pointer
  * @return TxBufferOverrun
  *         @arg SET
  *         @arg RESET
  * @brief  Returns whether the TX buffer is overrun.
  */
FlagStatus UART_GetTxBufferOverrunStatus(UART_TypeDef* UARTx)
{
  return (FlagStatus)((UARTx->STATE & UART_STATE_TXOR) >> UART_STATE_TXOR_Pos);
}

/**
  * @param  UART_TypeDef Pointer
  * @return None
  * @brief Clears RxBuffer overrun status.
  */ 
void UART_ClearRxBufferOverrunStatus(UART_TypeDef* UARTx)
{
  UARTx->STATE = UART_STATE_RXOR;
}

/**
  * @param  UART_TypeDef Pointer
  * @return None
  * @brief Clears RxBuffer overrun status.
  */
void UART_ClearTxBufferOverrunStatus(UART_TypeDef* UARTx)
{
  UARTx->STATE = UART_STATE_TXOR;
}

/**
  * @param UART_TypeDef Pointer
  * @param txchar Character to be sent
  * @return none
  * @brief  Sends a character to the TX buffer for transmission.
  */
void UART_SendChar(UART_TypeDef* UARTx,char txchar)
{
  while(UARTx->STATE & UART_STATE_TXBF);
  UARTx->DATA = (uint32_t)txchar;
}

/**
  * @param UART_TypeDef Pointer
  * @param str string to be sent
  * @return none
  * @brief  Sends a string to the TX buffer for transmission.
  */
void UART_SendString(UART_TypeDef* pUARTx, char *str)
{
  unsigned int k = 0;
  
  do 
  {
      UART_SendChar( pUARTx, *(str + k) );
      k++;
  } while(*(str + k)!='\0');
}

/**
  * @param  UART_TypeDef Pointer
  * @return rxchar
  * @brief  returns the character from the RX buffer which has been received.
  */
char UART_ReceiveChar(UART_TypeDef* UARTx)
{
  while(!(UARTx->STATE & UART_STATE_RXBF));
  return (char)(UARTx->DATA);
}

/**
  * @param  UART_TypeDef Pointer
  * @return BaudDiv
  * @brief  Returns the current UART Baud rate divider.
  *         Note that the Baud rate divider is the difference between 
  *         the clock frequency and the Baud frequency.
  */
uint32_t UART_GetBaudDivider(UART_TypeDef* UARTx)
{
  return UARTx->BAUDDIV;
}

/**
  * @param  UART_TypeDef Pointer
  * @return TX IntStatus
  *         @arg SET
  *         @arg RESET
  * @brief  Returns the TX interrupt status.
  */
ITStatus UART_GetTxIRQStatus(UART_TypeDef* UARTx)
{
  return (ITStatus)((UARTx->INTSTATUS & UART_INTSTATUS_TXIRQ) >> UART_INTSTATUS_TXIRQ_Pos);
}

/**
  * @param  UART_TypeDef Pointer
  * @return RX IntStatus
  *         @arg SET
  *         @arg RESET
  * @brief  Returns the RX interrupt status.
  */
ITStatus UART_GetRxIRQStatus(UART_TypeDef* UARTx)
{
  return (ITStatus)((UARTx->INTSTATUS & UART_INTSTATUS_RXIRQ) >> UART_INTSTATUS_RXIRQ_Pos);
}

/**
  * @param  UART_TypeDef Pointer
  * @return none
  * @brief  Clears the TX buffer full interrupt status.
  */
void UART_ClearTxIRQ(UART_TypeDef* UARTx)
{
  UARTx->INTCLEAR = UART_INTCLEAR_TXIRQ;
}

/**
  * @param  UART_TypeDef Pointer
  * @return none
  * @brief  Clears the RX interrupt status.
  */
void UART_ClearRxIRQ(UART_TypeDef* UARTx)
{
  UARTx->INTCLEAR = UART_INTCLEAR_RXIRQ;
}

/**
  * @param  UART_TypeDef Pointer
  * @return Tx OverrunIRQ
  *         @arg SET
  *         @arg RESET
  * @brief Return UART TX Overrun Interrupt Status.
  */
ITStatus UART_GetTxOverrunIRQStatus(UART_TypeDef* UARTx)
{
  return (ITStatus)((UARTx->INTSTATUS & UART_INTSTATUS_TXORIRQ) >> UART_INTSTATUS_TXORIRQ_Pos);
}

/**
  * @param  UART_TypeDef Pointer
  * @return Rx OverrunIRQ
  *         @arg SET
  *         @arg RESET
  * @brief Return UART RX Overrun Interrupt Status.
  */
ITStatus UART_GetRxOverrunIRQStatus(UART_TypeDef* UARTx)
{
  return (ITStatus)((UARTx->INTSTATUS & UART_INTSTATUS_RXORIRQ) >> UART_INTSTATUS_RXORIRQ_Pos);
}

/**
  * @param  UART_TypeDef Pointer
  * @return none
  * @brief Clear UART TX Overrun Interrupt request.
  */
void UART_ClearTxOverrunIRQ(UART_TypeDef* UARTx)
{
  UARTx->INTCLEAR = UART_INTCLEAR_TXORIRQ;
}

/**
  * @param  UART_TypeDef Pointer
  * @return none
  * @brief Clear UART RX Overrun Interrupt request.
  */
void UART_ClearRxOverrunIRQ(UART_TypeDef* UARTx)
{
  UARTx->INTCLEAR = UART_INTCLEAR_RXORIRQ;
}

/**
  * @param none
  * @return none
  * @brief Sets Tx High Speed Test Mode
  */
void UART_SetHSTM(UART_TypeDef* UARTx)
{
  UARTx->CTRL |= UART_CTRL_HSTM;
}

/**
  * @param none
  * @return none
  * @brief Clears Tx High Speed Test Mode
  */
void UART_ClrHSTM(UART_TypeDef* UARTx)
{
  UARTx->CTRL &= ~UART_CTRL_HSTM;
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
