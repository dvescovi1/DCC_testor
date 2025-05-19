/**
  ******************************************************************************
  * @file           : SUSI_slave.h
  * @brief          : Header for SUSI_slave.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SUSI_SLAVE_H
#define __SUSI_SLAVE_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include "app_freertos.h"

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/

/* Exported functions prototypes ---------------------------------------------*/
void SUSI_slave(void);


/* Private defines -----------------------------------------------------------*/
#define PACKET_SIZE        3
#define PACKET_TIMEOUT_MS  8

/* SUSI commands */
//TODO: not complete
#define SUSI_FG1      (0x60)
#define SUSI_FG2      (0x61)
#define SUSI_FG3      (0x62)
#define SUSI_FG4      (0x63)

#define SUSI_VLOCO    (0x24)
#define SUSI_VCPU     (0x25)

/* SUSI packet timeout */
#define PACKET_TIMEOUT_MS  8
#define PACKET_TIMEOUT  pdMS_TO_TICKS(PACKET_TIMEOUT_MS)


#ifdef __cplusplus
}
#endif

#endif /* __SUSI_SLAVE_H */
