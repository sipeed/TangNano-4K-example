/*
 * *****************************************************************************************
 *
 * 		Copyright (C) 2014-2021 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file          gw1ns4c_flash.ld
 * @author        Embedded Development Team
 * @version       V1.x.x
 * @date          2021-01-01 09:00:00
 * @Target        GowinSemiconductor GW1NS-4C
 * @Environment   GOWIN MCU Designer
 * @Description   Linker script for GW1NS-4C Device with 32K-Byte FLASH, 16K-Byte RAM
 *                Set heap size, stack size and stack location according to application
 *                requirements.
 *                Set memory bank area and size if external memory is used.
 ******************************************************************************************
 */

GROUP(libgcc.a libc.a libm.a libnosys.a)

MEMORY
{
  FLASH (rx) : ORIGIN = 0x0,        LENGTH = 0x8000  /* 32KByte */
  RAM (rwx)  : ORIGIN = 0x20000000, LENGTH = 0x4000  /* 16KByte */
}

ENTRY(Reset_Handler)

SECTIONS
{
   .text :
   {
      KEEP(*(.isr_vector))
      *(.text*)

      *(.init)
      *(.fini)

      /* .ctors */
      *crtbegin.o(.ctors)
      *crtbegin?.o(.ctors)
      *(EXCLUDE_FILE(*crtend?.o *crtend.o) .ctors)
      *(SORT(.ctors.*))
      *(.ctors)

      /* .dtors */
       *crtbegin.o(.dtors)
       *crtbegin?.o(.dtors)
       *(EXCLUDE_FILE(*crtend?.o *crtend.o) .dtors)
       *(SORT(.dtors.*))
       *(.dtors)

      *(.rodata*)

      *(.eh_frame*)
   } > FLASH

   .ARM.extab :
   {
      *(.ARM.extab* .gnu.linkonce.armextab.*)
   } > FLASH

   __exidx_start = .;
   .ARM.exidx :
   {
      *(.ARM.exidx* .gnu.linkonce.armexidx.*)
   } > FLASH
   __exidx_end = .;

   __etext = .;

   .data : AT (__etext)
   {
      __data_start__ = .;
      *(vtable)
      *(.data*)

      . = ALIGN(4);
      /* preinit data */
      PROVIDE_HIDDEN (__preinit_array_start = .);
      *(.preinit_array)
      PROVIDE_HIDDEN (__preinit_array_end = .);

      . = ALIGN(4);
      /* init data */
      PROVIDE_HIDDEN (__init_array_start = .);
      *(SORT(.init_array.*))
      *(.init_array)
      PROVIDE_HIDDEN (__init_array_end = .);


      . = ALIGN(4);
      /* finit data */
      PROVIDE_HIDDEN (__fini_array_start = .);
      *(SORT(.fini_array.*))
      *(.fini_array)
      PROVIDE_HIDDEN (__fini_array_end = .);

      . = ALIGN(4);
      /* All data end */
      __data_end__ = .;

   } > RAM

   .bss :
   {
      . = ALIGN(4);
      __bss_start__ = .;
      *(.bss*)
      *(COMMON)
      . = ALIGN(4);
      __bss_end__ = .;
   } > RAM

   .heap (COPY):
   {
      __end__ = .;
      end = __end__;
      *(.heap*)
      __HeapLimit = .;
   } > RAM

   /* .stack_dummy section doesn't contains any symbols. It is only
    * used for linker to calculate size of stack sections, and assign
    * values to stack symbols later */
   .stack_dummy (COPY):
   {
      *(.stack*)
   } > RAM

   /* Set stack top to end of RAM, and stack limit move down by
    * size of stack_dummy section */
   __StackTop = ORIGIN(RAM) + LENGTH(RAM);
   __StackLimit = __StackTop - SIZEOF(.stack_dummy);
   PROVIDE(__stack = __StackTop);

   /* Check if data + heap + stack exceeds RAM limit */
   ASSERT(__StackLimit >= __HeapLimit, "region RAM overflowed with stack")
}


/*************************GowinSemiconductor*****END OF FILE*********************/
