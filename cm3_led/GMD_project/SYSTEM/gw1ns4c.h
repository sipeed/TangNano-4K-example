/*
 * *****************************************************************************************
 *
 * 		Copyright (C) 2014-2021 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file        gw1ns4c.h
 * @author      Embedded Development Team
 * @version     V1.x.x
 * @date        2021-01-01 09:00:00
 * @brief       CMSIS Cortex-M3 Core Peripheral Access Layer Header File for Device GW1NS-4C.
 *              This file contains all the peripheral register's definitions, bits 
 *              definitions and memory mapping for GW1NS-4C Connectivity line, 
 *              High density, High density value line, Medium density, 
 *              Medium density Value line, Low density, Low density Value line 
 *              and XL-density devices.
 *
 *              The file is the unique include file that the application programmer
 *              is using in the C source code, usually in main.c. This file contains:
 *                - Configuration section that allows to select:
 *                - The device used in the target application
 *                - To use or not the peripheral drivers in application code(i.e. 
 *                  code will be based on direct access to peripheral registers 
 *                  rather than drivers API)
 *                - To change few application-specific parameters such as 
 *                  crystal frequency
 *                - Data structures and the address mapping for all peripherals
 *                - Peripheral registers declarations and bits definition
 *                - Macros to access peripheral registers hardware
 *
 ******************************************************************************************
 */

/** @addtogroup CMSIS
  * @{
  */

/** @addtogroup GW1NS4C
  * @{
  */

#ifndef __GW1NS4C_H
#define __GW1NS4C_H

#ifdef __cplusplus
	extern "C" {
#endif

/**
  * @}
  */

/** @addtogroup Configuration_section_for_CMSIS
  * @{
  */

/* 
 * Configuration of the Cortex-M3 Processor and Core Peripherals
 */
#define __CM3_REV                 0x0201    /*!< Core Revision r2p1                             */
#define __NVIC_PRIO_BITS          3         /*!< Number of Bits used for Priority Levels        */
#define __Vendor_SysTickConfig    0         /*!< Set to 1 if different SysTick Config is used   */
#define __MPU_PRESENT             1         /*!< MPU present or not                             */


/*
 * ==========================================================================
 * ---------- Interrupt Number Definition -----------------------------------
 * ==========================================================================
 */
typedef enum IRQn
{
/******  Cortex-M3 Processor Exceptions Numbers ********************************/
  NonMaskableInt_IRQn           = -14,    /*!<  2 Cortex-M3 Non Maskable Interrupt                 */
  HardFault_IRQn                = -13,    /*!<  3 Cortex-M3 Hard Fault Interrupt                   */
  MemoryManagement_IRQn         = -12,    /*!<  4 Cortex-M3 Memory Management Interrupt            */
  BusFault_IRQn                 = -11,    /*!<  5 Cortex-M3 Bus Fault Interrupt                    */
  UsageFault_IRQn               = -10,    /*!<  6 Cortex-M3 Usage Fault Interrupt                  */
  SVCall_IRQn                   = -5,     /*!< 11 Cortex-M3 SV Call Interrupt                      */
  DebugMonitor_IRQn             = -4,     /*!< 12 Cortex-M3 Debug Monitor Interrupt                */
  PendSV_IRQn                   = -2,     /*!< 14 Cortex-M3 Pend SV Interrupt                      */
  SysTick_IRQn                  = -1,     /*!< 15 Cortex-M3 System Tick Interrupt                  */

/******  GW1NS-4C Specific Interrupt Numbers ************************************/
  UART0_IRQn                    = 0,       /* UART 0 RX and TX Combined Interrupt   */
  USER_INT0_IRQn                = 1,       /* Interrupt handler 0 to user extension */
  UART1_IRQn                    = 2,       /* UART 1 RX and TX Combined Interrupt   */
  USER_INT1_IRQn                = 3,       /* Interrupt handler 1 to user extension */
  USER_INT2_IRQn                = 4,       /* Interrupt handler 2 to user extension */
  RTC_IRQn                      = 5,       /* RTC Interrupt                         */
  PORT0_COMB_IRQn               = 6,       /* GPIO Port 0 combined Interrupt        */
  USER_INT3_IRQn                = 7,       /* Interrupt handler 3 to user extension */
  TIMER0_IRQn                   = 8,       /* TIMER 0 Interrupt                     */
  TIMER1_IRQn                   = 9,       /* TIMER 1 Interrupt                     */
  I2C_IRQn                      = 11,      /* I2C                                   */
  UARTOVF_IRQn                  = 12,      /* UART 0,1 Overflow Interrupt           */
  USER_INT4_IRQn                = 13,      /* Interrupt handler 4 to user extension */
  USER_INT5_IRQn                = 14,      /* Interrupt handler 5 to user extension */
  Spare15_IRQn                  = 15,      /* Undefined                             */
  PORT0_0_IRQn                  = 16,      /*!< All P0 I/O pins can be used as interrupt source. */
  PORT0_1_IRQn                  = 17,      /*!< There are 16 pins in total          */
  PORT0_2_IRQn                  = 18,      /*! PORT0_2 Interrupt                    */
  PORT0_3_IRQn                  = 19,      /*! PORT0_3 Interrupt                    */
  PORT0_4_IRQn                  = 20,      /*! PORT0_4 Interrupt                    */
  PORT0_5_IRQn                  = 21,      /*! PORT0_5 Interrupt                    */
  PORT0_6_IRQn                  = 22,      /*! PORT0_6 Interrupt                    */
  PORT0_7_IRQn                  = 23,      /*! PORT0_7 Interrupt                    */
  PORT0_8_IRQn                  = 24,      /*! PORT0_8 Interrupt                    */
  PORT0_9_IRQn                  = 25,      /*! PORT0_9 Interrupt                    */
  PORT0_10_IRQn                 = 26,      /*! PORT0_10 Interrupt                   */
  PORT0_11_IRQn                 = 27,      /*! PORT0_11 Interrupt                   */
  PORT0_12_IRQn                 = 28,      /*! PORT0_12 Interrupt                   */
  PORT0_13_IRQn                 = 29,      /*! PORT0_13 Interrupt                   */
  PORT0_14_IRQn                 = 30,      /*! PORT0_14 Interrupt                   */
  PORT0_15_IRQn                 = 31       /*! PORT0_15 Interrupt                   */
}IRQn_Type;

/**
  * @}
  */

#include "core_cm3.h"               /* Cortex-M3 processor and core peripherals         */
#include "system_gw1ns4c.h"         /* GW1NS-4C System include file                      */

/** @addtogroup Exported_types
  * @{
  */

typedef enum
{
  RESET = 0,
  SET = !RESET
}FlagStatus,ITStatus;

typedef enum
{
  DISABLE = 0,
  ENABLE = !DISABLE
}FunctionalState;

typedef enum
{
  ERROR = 0,
  SUCCESS = !ERROR
}ErrorStatus;

/**
  * @}
  */

/** @addtogroup Peripheral_registers_structures
  * @{
  */

/* --------------------  Begin of section using anonymous unions  ------------------- */
#if defined ( __CC_ARM   )
  #pragma push
  #pragma anon_unions
#elif defined(__ICCARM__)
  #pragma language=extended
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined(__TASKING__)
  #pragma warning 586
#else
  #warning Not supported compiler type
#endif

/******************************************************************************/
/*                         Peripheral Registers Definition                    */
/******************************************************************************/

/*--------- Universal Asynchronous Receiver Transmitter (UART) --------*/
typedef struct
{
  __IO   uint32_t  DATA;          /*!< Offset: 0x000 Data Register    (R/W)          */
  __IO   uint32_t  STATE;         /*!< Offset: 0x004 Status Register  (R/W)          */
  __IO   uint32_t  CTRL;          /*!< Offset: 0x008 Control Register (R/W)          */
  union
  {
    __I    uint32_t  INTSTATUS;   /*!< Offset: 0x00C Interrupt Status Register (R/ ) */
    __O    uint32_t  INTCLEAR;    /*!< Offset: 0x00C Interrupt Clear Register ( /W)  */
  };
  __IO   uint32_t  BAUDDIV;       /*!< Offset: 0x010 Baudrate Divider Register (R/W) */
}UART_TypeDef;

/*------------------------ Timer (TIMER) ------------------------*/
typedef struct
{
  __IO   uint32_t  CTRL;          /*!< Offset: 0x000 Control Register (R/W)          */
  __IO   uint32_t  VALUE;         /*!< Offset: 0x004 Current Value Register (R/W)    */
  __IO   uint32_t  RELOAD;        /*!< Offset: 0x008 Reload Value Register  (R/W)    */
  union
  {
    __I    uint32_t  INTSTATUS;   /*!< Offset: 0x00C Interrupt Status Register (R/ ) */
    __O    uint32_t  INTCLEAR;    /*!< Offset: 0x00C Interrupt Clear Register ( /W)  */
  };
}TIMER_TypeDef;

/*--------------------- General Purpose Input Output (GPIO) ----------*/
typedef struct
{
  __IO   uint32_t  DATA;          /* Offset: 0x000 (R/W) DATA Register                     */
  __IO   uint32_t  DATAOUT;       /* Offset: 0x004 (R/W) Data Output Latch Register        */
         uint32_t  RESERVED0[2];  /* Offset: 0x010-0x004                                   */
  __IO   uint32_t  OUTENSET;      /* Offset: 0x010 (R/W) Output Enable Set Register        */
  __IO   uint32_t  OUTENCLR;      /* Offset: 0x014 (R/W) Output Enable Clear Register      */
  __IO   uint32_t  ALTFUNCSET;    /* Offset: 0x018 (R/W) Alternate Function Set Register   */
  __IO   uint32_t  ALTFUNCCLR;    /* Offset: 0x01C (R/W) Alternate Function Clear Register */
  __IO   uint32_t  INTENSET;      /* Offset: 0x020 (R/W) Interrupt Enable Set Register     */
  __IO   uint32_t  INTENCLR;      /* Offset: 0x024 (R/W) Interrupt Enable Clear Register   */
  __IO   uint32_t  INTTYPESET;    /* Offset: 0x028 (R/W) Interrupt Type Set Register       */
  __IO   uint32_t  INTTYPECLR;    /* Offset: 0x02C (R/W) Interrupt Type Clear Register     */
  __IO   uint32_t  INTPOLSET;     /* Offset: 0x030 (R/W) Interrupt Polarity Set Register   */
  __IO   uint32_t  INTPOLCLR;     /* Offset: 0x034 (R/W) Interrupt Polarity Clear Register */
  union
  {
    __I    uint32_t  INTSTATUS;    /* Offset: 0x038 (R/ ) Interrupt Status Register        */
    __O    uint32_t  INTCLEAR;     /* Offset: 0x038 ( /W) Interrupt Clear Register         */
  };
         uint32_t RESERVED1[241];    /* Offset : 0x400-0x0038                              */
  __IO   uint32_t MASKLOWBYTE[256];  /* Offset: 0x400 - 0x7FC Lower byte Masked Access Register (R/W) */
  __IO   uint32_t MASKHIGHBYTE[256]; /* Offset: 0x800 - 0xBFC Upper byte Masked Access Register (R/W) */
}GPIO_TypeDef;

/*----------------------------- WatchDog ------------------------*/
typedef struct
{
  __IO    uint32_t  LOAD;           /* Offset: 0x000 (R/W) Watchdog Load Register                         */
  __I     uint32_t  VALUE;          /* Offset: 0x004 (R/ ) Watchdog Value Register                        */
  __IO    uint32_t  CTRL;           /* Offset: 0x008 (R/W) Watchdog Control Register                      */
  __O     uint32_t  INTCLR;         /* Offset: 0x00C ( /W) Watchdog Clear Interrupt Register              */
  __I     uint32_t  RIS;            /* Offset: 0x010 (R/ ) Watchdog Raw Interrupt Status Register         */
  __I     uint32_t  MIS;            /* Offset: 0x014 (R/ ) Watchdog Interrupt Status Register             */
          uint32_t  RESERVED0[762]; /* Offset: 0xC00-0x014                                                */
  __IO    uint32_t  LOCK;           /* Offset: 0xC00 (R/W) Watchdog Lock Register                         */
          uint32_t  RESERVED1[191]; /* Offset: 0xF00-0xC00                                                */
  __IO    uint32_t  ITCR;           /* Offset: 0xF00 (R/W) Watchdog Integration Test Control Register     */
  __O     uint32_t  ITOP;           /* Offset: 0xF04 ( /W) Watchdog Integration Test Output Set Register  */
}WDOG_TypeDef;

/*---------------------------------- I2C ------------------------------*/
typedef struct
{
	__IO uint32_t PRER;            /* Offset: 0x00 (R/W) I2C Prescale Register                            */
	__IO uint32_t CTR;			   /* Offset: 0x04 (R/W) I2C Control Register                             */
	union
	{
		__I uint32_t RXR;          /* Offset: 0x0C (R/ ) I2C Data Receive Register                        */
		__O uint32_t TXR;          /* Offset: 0x08 ( /W) I2C Data Transmit Register                       */
	};
	union
	{
		__I uint32_t SR;           /* Offset: 0x14 (R/ ) I2C Status Register                              */
		__O uint32_t CR;           /* Offset: 0x10 ( /W) I2C Command Register                             */
	};
}I2C_TypeDef;

/*------------------ System Control (SYSCON) -----------------------*/
typedef struct
{
  __IO   uint32_t  REMAP;        /* Offset: 0x000 (R/W) Remap Control Register     */
  __IO   uint32_t  PMUCTRL;      /* Offset: 0x004 (R/W) PMU Control Register       */
  __IO   uint32_t  RESETOP;      /* Offset: 0x008 (R/W) Reset Option Register      */
  __IO   uint32_t  RESERVED0;    /* Offset: 0x00C Reserved                         */
  __IO   uint32_t  RSTINFO;      /* Offset: 0x010 (R/W) Reset Information Register */
}SYSCON_TypeDef;

/*----------------Serial Peripheral Interface (SPI)-----------------*/
typedef struct
{
  __I     uint32_t RDATA;        /* Offset: 0x00 (R/ ) Data Read Register          */
  __O     uint32_t WDATA;        /* Offset: 0x04 (/W ) Data Write Register         */
  __IO    uint32_t STATUS;       /* Offset: 0x08 (R/W) Status Register             */
  __IO    uint32_t SSMASK;       /* Offset: 0x0C (R/W) Unused Select slave address */
  __IO    uint32_t CTRL;         /* Offset: 0x10 (R/W) Control Register            */
}SPI_TypeDef;

/*--------------------Real Timer Clock (RTC)-----------------------*/
typedef struct
{
	__I  uint32_t RTC_CURRENT_DATA;       /* Offset: 0x000 (R/ ) Data Register                          */
	__IO uint32_t RTC_MATCH_VALUE;        /* Offset: 0x004 (R/W) Match Register                         */
	__IO uint32_t RTC_LOAD_VALUE;         /* Offset: 0x008 (R/W) Load Register                          */
	__IO uint32_t RTC_CTROLLER_REG;       /* Offset: 0x00C (R/W) Control Register                       */
	__IO uint32_t RTC_IMSC;               /* Offset: 0x010 (R/W) Interrupt Mask Set and Clear Register  */
	__I  uint32_t RTC_RIS;                /* Offset: 0x014 (R/ ) Raw Interrupt Status Register          */
	__I  uint32_t RTC_MIS;                /* Offset: 0x018 (R/ ) Masked Interrupt Status Register       */
	__O  uint32_t RTC_INTR_CLEAR;         /* Offset: 0x01C ( /W) Interrupt Clear Register               */
}RTC_TypeDef;


/* --------------------  End of section using anonymous unions  ------------------- */
#if defined ( __CC_ARM   )
  #pragma pop
#elif defined(__ICCARM__)
  /* leave anonymous unions enabled */
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined(__TASKING__)
  #pragma warning restore
#else
  #warning Not supported compiler type
#endif

/**
  * @}
  */

/** @addtogroup Peripheral_memory_map
  * @{
  */

/* Peripheral and SRAM base address */
#define FLASH_BASE        ((uint32_t)0x00000000)   /*!< (FLASH     ) Base Address */
#define SRAM_BASE         ((uint32_t)0x20000000)   /*!< (SRAM      ) Base Address */
#define PERIPH_BASE       ((uint32_t)0x40000000)   /*!< (Peripheral) Base Address */

#define APB1PERIPH_BASE   PERIPH_BASE              /* !< APB1_Peripheral Base Address */
#define APB2PERIPH_BASE   (PERIPH_BASE + 0x02000)  /* !< APB2_Peripheral Base Address */
#define AHB1PERIPH_BASE   (PERIPH_BASE + 0x10000)  /* !< AHB1 Peripheral Base Address */
#define AHB2PERIPH_BASE   ((uint32_t)0xA0000000)   /* !< AHB2 Peripheral Base Address */

/* APB1 Peripheral base address */
#define TIMER0_BASE       (APB1PERIPH_BASE + 0x0000)    /* !< TIMER0 Base Address     */
#define TIMER1_BASE       (APB1PERIPH_BASE + 0x1000)    /* !< TIMER1 Base Address     */
#define UART0_BASE        (APB1PERIPH_BASE + 0x4000)    /* !< UART0  Base Address     */
#define UART1_BASE        (APB1PERIPH_BASE + 0x5000)    /* !< UART1  Base Address     */
#define RTC_BASE          (APB1PERIPH_BASE + 0x6000)    /* !< RTC Base Address        */
#define WDOG_BASE         (APB1PERIPH_BASE + 0x8000)    /* !< WATCHDOG  Base Address  */

/* APB2 Peripheral base address */
#define I2C_BASE          (APB2PERIPH_BASE + 0x0000)    /* !< I2C Base Address         */
#define SPI_BASE          (APB2PERIPH_BASE + 0x0200)    /* !< SPI Base Address         */

/* AHB Peripheral base address */
#define GPIO0_BASE        (AHB1PERIPH_BASE + 0x0000)    /* !< GPIO0 Base Address     */
#define SYSCTRL_BASE      (AHB1PERIPH_BASE + 0xF000)    /* !< SYSCON Base Address    */

/* APB2 Extension Peripherals base address to user */
#define APB2MASTER1_BASE   (APB2PERIPH_BASE + 0x400)	/* !< APB2 Master 1 Base Address  */
#define APB2MASTER2_BASE   (APB2PERIPH_BASE + 0x500)	/* !< APB2 Master 2 Base Address  */
#define APB2MASTER3_BASE   (APB2PERIPH_BASE + 0x600)	/* !< APB2 Master 3 Base Address  */
#define APB2MASTER4_BASE   (APB2PERIPH_BASE + 0x700)	/* !< APB2 Master 4 Base Address  */
#define APB2MASTER5_BASE   (APB2PERIPH_BASE + 0x800)	/* !< APB2 Master 5 Base Address  */
#define APB2MASTER6_BASE   (APB2PERIPH_BASE + 0x900)	/* !< APB2 Master 6 Base Address  */
#define APB2MASTER7_BASE   (APB2PERIPH_BASE + 0xA00)	/* !< APB2 Master 7 Base Address  */
#define APB2MASTER8_BASE   (APB2PERIPH_BASE + 0xB00)	/* !< APB2 Master 8 Base Address  */
#define APB2MASTER9_BASE   (APB2PERIPH_BASE + 0xC00)	/* !< APB2 Master 9 Base Address  */
#define APB2MASTER10_BASE  (APB2PERIPH_BASE + 0xD00)	/* !< APB2 Master 10 Base Address */
#define APB2MASTER11_BASE  (APB2PERIPH_BASE + 0xE00)	/* !< APB2 Master 11 Base Address */
#define APB2MASTER12_BASE  (APB2PERIPH_BASE + 0xF00)	/* !< APB2 Master 12 Base Address */

/**
  * @}
  */
  
/** @addtogroup Peripheral_declaration
  * @{
  */

/******************************************************************************/
/*                         Peripheral declaration                             */
/******************************************************************************/
#define UART0             ((UART_TypeDef   *) UART0_BASE)
#define UART1             ((UART_TypeDef   *) UART1_BASE)
#define TIMER0            ((TIMER_TypeDef  *) TIMER0_BASE)
#define TIMER1            ((TIMER_TypeDef  *) TIMER1_BASE)
#define WDOG              ((WDOG_TypeDef   *) WDOG_BASE)
#define RTC               ((RTC_TypeDef    *) RTC_BASE)

#define GPIO0             ((GPIO_TypeDef   *) GPIO0_BASE)
#define SYSCON            ((SYSCON_TypeDef *) SYSCTRL_BASE)

#define I2C               ((I2C_TypeDef    *) I2C_BASE)           //Soft-Core Extended           
#define SPI               ((SPI_TypeDef    *) SPI_BASE)           //Soft-Core Extended

/**
  * @}
  */

/** @addtogroup Peripheral_Registers_Bits_Definition
  * @{
  */
 
/******************************************************************************/
/*                         Peripheral Registers_Bits_Definition               */
/******************************************************************************/

/******************************************************************************/
/*           Universal Asynchronous Receiver Transmitter (UART)               */
/******************************************************************************/
/* bit definitions for DATA register */
#define UART_DATA              ((uint32_t) 0x000000FF) /* UART DATA: Data value */

/* bit definitions for STATE register */
#define UART_STATE_TXBF        ((uint32_t) 0x00000001) /* UART STATE: Tx buffer full    */
#define UART_STATE_RXBF        ((uint32_t) 0x00000002) /* UART STATE: Rx buffer full    */
#define UART_STATE_TXOR        ((uint32_t) 0x00000004) /* UART STATE: Tx buffer overrun */
#define UART_STATE_RXOR        ((uint32_t) 0x00000008) /* UART STATE: Rx buffer overrun */

/* bit definitions for CTRL register */
#define UART_CTRL_TXEN         ((uint32_t) 0x00000001) /* UART CTRL: TX enable                           */
#define UART_CTRL_RXEN         ((uint32_t) 0x00000002) /* UART CTRL: RX enable           
            */
#define UART_CTRL_TXIRQEN      ((uint32_t) 0x00000004) /* UART CTRL: TX interrupt enable 
            */
#define UART_CTRL_RXIRQEN      ((uint32_t) 0x00000008) /* UART CTRL: RX interrupt enable 
            */
#define UART_CTRL_TXORIRQEN    ((uint32_t) 0x00000010) /* UART CTRL: TX overrun interrupt enable         */
#define UART_CTRL_RXORIRQEN    ((uint32_t) 0x00000020) /* UART CTRL: RX overrun interrupt enable         */
#define UART_CTRL_HSTM         ((uint32_t) 0x00000040) /* UART CTRL: High-speed test mode for TX enable  */

/* bit definitions for INTSTATUS register */
#define UART_INTSTATUS_TXIRQ    ((uint32_t) 0x00000001) /* UART INTCLEAR: Get TX interrupt status         */
#define UART_INTSTATUS_RXIRQ    ((uint32_t) 0x00000002) /* UART INTCLEAR: Get RX interrupt status         */
#define UART_INTSTATUS_TXORIRQ  ((uint32_t) 0x00000004) /* UART INTCLEAR: Get TX overrun interrupt status */
#define UART_INTSTATUS_RXORIRQ  ((uint32_t) 0x00000008) /* UART INTCLEAR: Get RX overrun interrupt status */

/* bit definitions for INTCLEAR register */
#define UART_INTCLEAR_TXIRQ    ((uint32_t) 0x00000001) /* UART INTCLEAR: Clear TX interrupt         */
#define UART_INTCLEAR_RXIRQ    ((uint32_t) 0x00000002) /* UART INTCLEAR: Clear RX interrupt         */
#define UART_INTCLEAR_TXORIRQ  ((uint32_t) 0x00000004) /* UART INTCLEAR: Clear TX overrun interrupt */
#define UART_INTCLEAR_RXORIRQ  ((uint32_t) 0x00000008) /* UART INTCLEAR: Clear RX overrun interrupt */

/* bit definitions for BAUDDIV register */
#define UART_BAUDDIV           ((uint32_t) 0x000FFFFF) /* UART BAUDDIV: Baud rate divider*/


/******************************************************************************/
/*                                Timer (TIMER)                               */
/******************************************************************************/
/* bit definitions for CTRL register */
#define TIMER_CTRL_EN          ((uint32_t) 0x00000001) /* TIMER CTRL: Enable                          */
#define TIMER_CTRL_SELEXTEN    ((uint32_t) 0x00000002) /* TIMER CTRL: Select external input as enable */
#define TIMER_CTRL_SELEXTCLK   ((uint32_t) 0x00000004) /* TIMER CTRL: Select external input as clock  */
#define TIMER_CTRL_IRQEN       ((uint32_t) 0x00000008) /* TIMER CTRL: Timer interrupt enable */

/* bit definitions for VALUE register */
#define TIMER_VALUE            ((uint32_t) 0xFFFFFFFF) /* TIMER VALUE: Current value */

/* bit definitions for RELOAD register */
#define TIMER_RELOAD           ((uint32_t) 0xFFFFFFFF) /* TIMER RELOAD: Reload value */

/* bit definitions for INTSTATUS register */
#define TIMER_INTSTATUS        ((uint32_t) 0x00000001) /* TIMER INTSTATUS: Get Timer interrupt status */

/* bit definitions for INTCLEAR register */
#define TIMER_INTCLEAR         ((uint32_t) 0x00000001) /* TIMER INTCLEAR: Clear Timer interrupt */

/******************************************************************************/
/*                   General Purpose Input Output (GPIO)                      */
/******************************************************************************/
/* bit definitions for  DATA register */
#define GPIO_DATA           ((uint32_t) 0x0000FFFF)  /* GPIO DATA: Data value */

/* bit definitions for DATAOUT register */
#define GPIO_DATAOUT        ((uint32_t) 0x0000FFFF)  /* GPIO DATAOUT: Data output value */

/* bit definitions for OUTENSET register */
#define GPIO_OUTENSET       ((uint32_t) 0x0000FFFF)  /* GPIO OUTENSET: Output enable set */

/* bit definitions for OUTENCLR register */
#define GPIO_OUTENCLR       ((uint32_t) 0x0000FFFF)  /* GPIO OUTENCLR: Output enable clear */

/* bit definitions for ALTFUNCSET register */
#define GPIO_ALTFUNSET      ((uint32_t) 0x0000FFFF)  /* GPIO ALTFUNCSET: Alternative function set */

/* bit definitions for ALTFUNCCLR register */
#define GPIO_ALTFUNCCLR     ((uint32_t) 0x0000FFFF)  /* GPIO ALTFUNCCLR: Alternative function clear */

/* bit definitions for INTENSET register */
#define GPIO_INTENSET       ((uint32_t) 0x0000FFFF)  /* GPIO INTENSET: Interrupt enable set */

/* bit definitions for INTENCLR register */
#define GPIO_INTENCLR       ((uint32_t) 0x0000FFFF)  /* GPIO INTENCLR: Interrupt enable clear */

/* bit definitions for INTTYPESET register */
#define GPIO_INTTYPESET     ((uint32_t) 0x0000FFFF)  /* GPIO INTTYPESET: Interrupt type set */

/* bit definitions for INTTYPECLR register */
#define GPIO_INTTYPECLR     ((uint32_t) 0x0000FFFF)  /* GPIO INTTYPECLR: Interrupt type clear */

/* bit definitions for INTPOLSET register */
#define GPIO_INTPOLSET      ((uint32_t) 0x0000FFFF)  /* GPIO INTPOLSET: Interrupt polarity set */

/* bit definitions for INTPOLCLR register */
#define GPIO_INTPOLCLR      ((uint32_t) 0x0000FFFF)  /* GPIO INTPOLCLR: Interrupt polarity clear */

/*  bit definitions for INTSTATUS register */
#define GPIO_INTSTATUS      ((uint32_t) 0x0000FFFF)  /* GPIO INTSTATUS: Get Interrupt status */

/*  bit definitions for INTCLEAR register */
#define GPIO_INTCLEAR       ((uint32_t) 0x0000FFFF)  /* GPIO INTCLEAR: Interrupt request clear*/

/*  bit definitions for MASKLOWBYTE register */
#define GPIO_MASKLOWBYTE    ((uint32_t) 0x000000FF)  /* GPIO MASKLOWBYTE: Data for lower byte access */

/*  bit definitions for MASKHIGHBYTE register */
#define GPIO_MASKHIGHBYTE   ((uint32_t) 0x0000FF00)  /* GPIO MASKHIGHBYTE: Data for high byte access */

/******************************************************************************/
/*                             WatchDog (WDOG)                                */
/******************************************************************************/
/*  bit definitions for LOAD register */
#define WDOG_LOAD              ((uint32_t) 0xFFFFFFFF)  /* the value from which the counter is to decrement */

/*  bit definitions for VALUE register */
#define WDOG_VALUE             ((uint32_t) 0xFFFFFFFF) /* the current value of the decrementing counter     */

/*  bit definitions for CTRL register */
#define WDOG_CTRL_INTEN        ((uint32_t) 0x00000001)  /* Enable the interrupt         */
#define WDOG_CTRL_RESEN        ((uint32_t) 0x00000002)  /* Enable watchdog reset output */

/*  bit definitions for INTCLR register */
#define WDOG_INTCLR            ((uint32_t) 0x00000001)  /* clear the watchdog interrupt and reloads the counter */

/*  bit definitions for RAWINTSTAT register */
#define WDOG_RAWINTSTAT        ((uint32_t) 0x00000001)  /* Raw interrupt status from the counter */

/*  bit definitions for MASKINTSTAT register */
#define WDOG_MASKINTSTAT       ((uint32_t) 0x00000001)  /* Enable interrupt status from the counter */

/*  bit definitions for LOCK register */
#define WDOG_LOCK_ENSTAT       ((uint32_t) 0x00000001)  /* Register write enable status */
#define WDOG_LOCK_EN           ((uint32_t) 0xFFFFFFFE)  /* Enable register writes */

/*  bit definitions for ITCR register */
#define WDOG_ITCR_INTEGTESTEN  ((uint32_t) 0x00000001)  /* Integration test mode enable */

/*  bit definitions for ITOP register */
#define WDOG_ITOP_WDOGRES      ((uint32_t) 0x00000001)  /* Integration test WDOGINT value */
#define WDOG_ITOP_WDOGINT      ((uint32_t) 0x00000002)  /* Integration test WDOGRES value */

/******************************************************************************/
/*                       System Control (SYSCON)                              */
/******************************************************************************/
/* bit definitions for REMAP register */
#define SYSCON_REMAP                  ((uint32_t) 0x00000001)  /* SYSCON MEME_CTRL       */

/* bit definitions for PMUCTRL register */
#define SYSCON_PMUCTRL_EN             ((uint32_t) 0x00000001)  /* PMUCTRL ENABLE         */

/* bit definitions for RESETOP register */
#define SYSCON_RESETOP_LOCKUPRST      ((uint32_t) 0x00000001)  /* LOCKUP RESET ENABLE    */

/* bit definitions for RSTINFO register */
#define SYSCON_RSTINFO_SYSRESETREQ    ((uint32_t) 0x00000001)  /* System Reset Request   */
#define SYSCON_RSTINFO_WDOGRESETREQ   ((uint32_t) 0x00000002)  /* WatchDog Reset Request */
#define SYSCON_RSTINFO_LOCKUPRESET    ((uint32_t) 0x00000004)  /* Lockup Reset           */

/******************************************************************************/
/*                  Serial Peripheral Interface (SPI)                         */
/******************************************************************************/
/* bit definitions for CTRL register */
#define SPI_CR_DIRECTION           ((uint32_t) 0x00000001)    /* DIRECTION              */
#define SPI_CR_PHASE               ((uint32_t) 0x00000002)    /* PHASE                  */
#define SPI_CR_POLARITY            ((uint32_t) 0x00000004)    /* POLARITY               */
#define SPI_CR_CLKSEL              ((uint32_t) 0x00000018)    /* CLKSEL                 */

/* bit definitions for STATUS register */
#define SPI_STATUS_ROE             ((uint32_t) 0x00000004)    /* Receive Overrun Error  */
#define SPI_STATUS_TOE             ((uint32_t) 0x00000008)    /* Transmit Overrun Error */
#define SPI_STATUS_TMT             ((uint32_t) 0x00000010)    /* Transmitting           */
#define SPI_STATUS_TRDY            ((uint32_t) 0x00000020)    /* Transmit Ready         */
#define SPI_STATUS_RRDY            ((uint32_t) 0x00000040)    /* Receive Ready          */
#define SPI_STATUS_ERR             ((uint32_t) 0x00000080)    /* Error                  */

/**
  * @}
  */

/*-------------------------------Include peripherals---------------------------------*/
#include "gw1ns4c_conf.h"

#ifdef __cplusplus
}
#endif

#endif /* __GW1NS4C_H */

/**
  * @}
  */

  /**
  * @}
  */

/************************GowinSemiconductor******END OF FILE*******************/
