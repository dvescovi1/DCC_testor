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
#include "app_freertos.h"
#include <stdbool.h>

/* Private includes ----------------------------------------------------------*/
#include "SUSI.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
uint8_t packet[PACKET_SIZE];

/* Private function prototypes -----------------------------------------------*/


/**
  * @brief  SUSI slave application
  * @param  None
  * @retval None
  */
void SUSI_slave(void) {
bool bytePacket3 = false;

while (1)
  {
    // Receive data using HAL_SPI_Receive
    if (HAL_TIMEOUT == HAL_SPI_Receive(&hspi1, packet, 2, PACKET_TIMEOUT))
    {
      vTaskDelay(1);
    }
    else {
      // Process the received data
      // test three byte packet
      if (0x70 == (packet[0] & 0xf0))
      {
        if (HAL_TIMEOUT == HAL_SPI_Receive(&hspi1, &packet[2], 1, PACKET_TIMEOUT))
        {
          vTaskDelay(1);
        }
        else
        {
          bytePacket3 = true;
        }
      }
      
      printf("RX %02x: %02x ", packet[0], packet[1]);
      if (bytePacket3)
        printf("%02x", packet[2]);
      printf("\r\n");

      switch (packet[0])
      {
        case SUSI_FG1:
          printf("FG1 %02x\r\n", packet[1]);
          // Handle SUSI_FG1 command
          break;
        case SUSI_FG2:
          printf("FG2 %02x\r\n", packet[1]);
          // Handle SUSI_FG2 command
          break;
        case SUSI_FG3:
          printf("FG3 %02x\r\n", packet[1]);
          // Handle SUSI_FG3 command
          break;
        case SUSI_FG4:
          printf("FG4 %02x\r\n", packet[1]);
          // Handle SUSI_FG4 command
          break;
        case SUSI_VLOCO:
          printf("VLOCO %02x\r\n", packet[1]);
          break;
        case SUSI_VCPU:
          printf("VCPU %02x\r\n", packet[1]);
          break;
        default:
          // Unknown command
          printf("Unknown command!\r\n");
          break;
      }
      // Reset the bytePacket3 flag
      bytePacket3 = false;

    }
  }
}
  
