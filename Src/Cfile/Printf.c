/*
 * Printf.h
 *
 *  Created on: 2019年8月3日
 *      Author: wyz
 */

#ifndef CFILE_PRINTF_C_
#define CFILE_PRINTF_C_
#include "main.h"
/***************************重定向printf************************************/
extern UART_HandleTypeDef huart2;

#ifdef __GNUC__
/* With GCC, small printf (option LD Linker->Libraries->Small printf
   set to 'Yes') calls __io_putchar() */
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

PUTCHAR_PROTOTYPE
{
  /* Place your implementation of fputc here */
  /* e.g. write a character to the USART1 and Loop until the end of transmission */
  // 注意下面第一个参数是&huart1，因为cubemx配置了串口1自动生成的
  HAL_UART_Transmit(&huart2, (uint8_t *)&ch, 1, 0xFFFF);

  return ch;
}



#endif /* CFILE_PRINTF_C_ */
