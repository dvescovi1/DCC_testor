/**
  ******************************************************************************
  * File Name          : SUSI_slave.c
  * Description        : Code for SUSI slave applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "SUSI_slave.h"


/* Private includes ----------------------------------------------------------*/

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/


void SPI1_RxCpltCallback(SPI_HandleTypeDef *hspi) {
#if 0
  uint8_t rx_buffer[10];
  uint8_t i;

  /* Check if the SPI handle is the same as the one used for the transfer */
  if (hspi->Instance == SPI1) {
    /* Process received data */
    for (i = 0; i < sizeof(rx_buffer); i++) {
      tx_buffer[i] = rx_buffer[i] + 1; // Example processing: increment each byte
#endif
      }

/**
  * @brief  SUSI slave application
  * @param  None
  * @retval None
  */
void SUSI_slave(void) {

  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }

}
