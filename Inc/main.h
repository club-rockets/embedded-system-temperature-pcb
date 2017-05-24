/**
  ******************************************************************************
  * File Name          : main.h
  * Description        : This file contains the common defines of the application
  ******************************************************************************
  *
  * COPYRIGHT(c) 2017 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H
  /* Includes ------------------------------------------------------------------*/

/* USER CODE BEGIN Includes */
/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/

#define SPI1_SCLK_Pin GPIO_PIN_5
#define SPI1_SCLK_GPIO_Port GPIOA
#define SPI1_FM1_SELECT_Pin GPIO_PIN_4
#define SPI1_FM1_SELECT_GPIO_Port GPIOC
#define SP1_FM2_SELECT_Pin GPIO_PIN_5
#define SP1_FM2_SELECT_GPIO_Port GPIOC
#define FM_PROTECT_Pin GPIO_PIN_0
#define FM_PROTECT_GPIO_Port GPIOB
#define FM_HOLD_Pin GPIO_PIN_1
#define FM_HOLD_GPIO_Port GPIOB
#define SPI2_ADC_SELECT_Pin GPIO_PIN_7
#define SPI2_ADC_SELECT_GPIO_Port GPIOE
#define SPI2_TEMP1_SELECT_Pin GPIO_PIN_8
#define SPI2_TEMP1_SELECT_GPIO_Port GPIOE
#define SPI2_TEMP2_SELECT_Pin GPIO_PIN_9
#define SPI2_TEMP2_SELECT_GPIO_Port GPIOE
#define SPI2_TEMP3_SELECT_Pin GPIO_PIN_10
#define SPI2_TEMP3_SELECT_GPIO_Port GPIOE
#define SPI2_TEMP4_SELECT_Pin GPIO_PIN_11
#define SPI2_TEMP4_SELECT_GPIO_Port GPIOE
#define SPI2_TEMP5_SELECT_Pin GPIO_PIN_12
#define SPI2_TEMP5_SELECT_GPIO_Port GPIOE
#define SPI2_TEMP6_SELECT_Pin GPIO_PIN_13
#define SPI2_TEMP6_SELECT_GPIO_Port GPIOE
#define SPI2_TEMP7_SELECT_Pin GPIO_PIN_14
#define SPI2_TEMP7_SELECT_GPIO_Port GPIOE
#define SPI2_TEMP8_SELECT_Pin GPIO_PIN_15
#define SPI2_TEMP8_SELECT_GPIO_Port GPIOE
#define SPI2_SCLK_Pin GPIO_PIN_10
#define SPI2_SCLK_GPIO_Port GPIOB
#define CAN2_STANDBY_Pin GPIO_PIN_11
#define CAN2_STANDBY_GPIO_Port GPIOB
#define CAN2_RX_Pin GPIO_PIN_12
#define CAN2_RX_GPIO_Port GPIOB
#define CAN2_TX_Pin GPIO_PIN_13
#define CAN2_TX_GPIO_Port GPIOB
#define SPI2_MISO_Pin GPIO_PIN_14
#define SPI2_MISO_GPIO_Port GPIOB
#define SPI2_MOSI_Pin GPIO_PIN_15
#define SPI2_MOSI_GPIO_Port GPIOB
#define SPI2_TC1_SELECT_Pin GPIO_PIN_10
#define SPI2_TC1_SELECT_GPIO_Port GPIOD
#define SPI2_TC2_SELECT_Pin GPIO_PIN_11
#define SPI2_TC2_SELECT_GPIO_Port GPIOD
#define LED1_Pin GPIO_PIN_12
#define LED1_GPIO_Port GPIOD
#define LED2_Pin GPIO_PIN_13
#define LED2_GPIO_Port GPIOD
#define LED3_Pin GPIO_PIN_14
#define LED3_GPIO_Port GPIOD
#define LED4_Pin GPIO_PIN_15
#define LED4_GPIO_Port GPIOD

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

/**
  * @}
  */ 

/**
  * @}
*/ 

#endif /* __MAIN_H */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
