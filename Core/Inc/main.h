/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
typedef int  s32;
typedef short int s16;
typedef char  s8;

typedef int  i32;
typedef short int i16;
typedef char  i8;

typedef unsigned          char uint8_t;
typedef unsigned short     int uint16_t;
typedef unsigned           int uint32_t;
typedef unsigned       __int64 uint64_t;

typedef unsigned          char u8;
typedef unsigned short     int u16;
typedef unsigned           int u32;
typedef unsigned       __int64 u64;

typedef unsigned          char uchar;
typedef unsigned short     int usint;
typedef unsigned           int uint;
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
#define IO_KEY                  HAL_GPIO_ReadPin(SW_GPIO_Port,SW_Pin)
#define IO_WATER                HAL_GPIO_ReadPin(WATER_SINGAL_GPIO_Port,WATER_SINGAL_Pin)
#define IO_LOES                 HAL_GPIO_ReadPin(WATER_LOS_GPIO_Port,WATER_LOS_Pin)
#define IO_HALL1                HAL_GPIO_ReadPin(HALL_1_GPIO_Port,HALL_1_Pin)
#define IO_HALL2                HAL_GPIO_ReadPin(HALL_2_GPIO_Port,HALL_2_Pin)


#define IO_RLED(STATUS)         HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, (GPIO_PinState)STATUS)
#define IO_GLED(STATUS)         HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, (GPIO_PinState)STATUS)//绿色LED1
#define IO_BUZZER(STATUS)       HAL_GPIO_WritePin(BEEP_GPIO_Port, BEEP_Pin, (GPIO_PinState)STATUS)
#define IO_RELAY1(STATUS)       HAL_GPIO_WritePin(J_220V_ON_GPIO_Port, J_220V_ON_Pin, (GPIO_PinState)STATUS)
#define IO_RELAY2(STATUS)       HAL_GPIO_WritePin(J_220V_OFF_GPIO_Port, J_220V_OFF_Pin, (GPIO_PinState)STATUS)
#define IO_POWER1(STATUS)       HAL_GPIO_WritePin(POWER12_1_GPIO_Port, POWER12_1_Pin, (GPIO_PinState)STATUS)
#define IO_POWER2(STATUS)       HAL_GPIO_WritePin(POWER12_2_GPIO_Port, POWER12_2_Pin, (GPIO_PinState)STATUS)


#define ZXQTIMETOALT 43200000//6000

#define ON 1
#define OFF 0

#define open 1
#define close 0

#define red 1
#define green 0

#define normal 0
#define keyclearAlarm 1
#define clearAlarm 2
#define warning 3


/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

extern unsigned int timer_count500ms;
extern unsigned char flag_count2_5Hz;
extern unsigned int timer_count2_5Hz;//定时器200ms计时和标志位
extern unsigned int timer_keycount;//按键被按下的时间计时
extern unsigned char timer_countwarn;//  报警次数
extern unsigned char data_warning_timer;// 报警延迟
extern u8 BuzzerState;
extern u8 checkflag;
/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define POWER12_1_Pin GPIO_PIN_1
#define POWER12_1_GPIO_Port GPIOA
#define J_220V_OFF_Pin GPIO_PIN_2
#define J_220V_OFF_GPIO_Port GPIOA
#define POWER12_2_Pin GPIO_PIN_3
#define POWER12_2_GPIO_Port GPIOA
#define J_220V_ON_Pin GPIO_PIN_6
#define J_220V_ON_GPIO_Port GPIOC
#define LED_1_Pin GPIO_PIN_11
#define LED_1_GPIO_Port GPIOA
#define LED_2_Pin GPIO_PIN_12
#define LED_2_GPIO_Port GPIOA
#define SW_Pin GPIO_PIN_15
#define SW_GPIO_Port GPIOA
#define HALL_2_Pin GPIO_PIN_4
#define HALL_2_GPIO_Port GPIOB
#define HALL_1_Pin GPIO_PIN_5
#define HALL_1_GPIO_Port GPIOB
#define WATER_LOS_Pin GPIO_PIN_6
#define WATER_LOS_GPIO_Port GPIOB
#define WATER_SINGAL_Pin GPIO_PIN_7
#define WATER_SINGAL_GPIO_Port GPIOB
#define BEEP_Pin GPIO_PIN_8
#define BEEP_GPIO_Port GPIOB



/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
