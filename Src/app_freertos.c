/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : app_freertos.c
  * Description        : Code for freertos applications
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
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "app_freertos.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "SUSI.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/** This define controls whether the example code uses a mutex to protect printf.
  * Set it to 0 to observe the behaviour without mutex.
  * Set it to 1 to protect access to printf. */
#define EXAMPLE_USES_MUTEX 1
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for Thread1 */
osThreadId_t Thread1Handle;
const osThreadAttr_t Thread1_attributes = {
  .name = "Thread1",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 256 * 4
};
/* Definitions for ThreadSUSI_SLAVE */
osThreadId_t ThreadSUSI_SLAVEHandle;
const osThreadAttr_t ThreadSUSI_SLAVE_attributes = {
  .name = "ThreadSUSI_SLAVE",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 256 * 4
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* USER CODE END RTOS_QUEUES */
  /* creation of Thread1 */
  Thread1Handle = osThreadNew(Thread1_Entry, NULL, &Thread1_attributes);

  /* creation of ThreadSUSI_SLAVE */
  ThreadSUSI_SLAVEHandle = osThreadNew(ThreadSUSI_SLAVE_Entry, NULL, &ThreadSUSI_SLAVE_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  if((Thread1Handle == NULL)||(ThreadSUSI_SLAVEHandle == NULL))
  {
    Error_Handler();
  }
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}
/* USER CODE BEGIN Header_Thread1_Entry */
/**
  * @brief Function implementing the Thread1 thread.
  * @param argument: Not used
  * @retval None
  */
/* USER CODE END Header_Thread1_Entry */
void Thread1_Entry(void *argument)
{
  /* USER CODE BEGIN Thread1 */
  while(1)
  {
    HAL_GPIO_TogglePin(LED1_GREEN_GPIO_Port, LED1_GREEN_Pin);
    osDelay(1000);
  }
  /* USER CODE END Thread1 */
}

/* USER CODE BEGIN Header_ThreadSUSI_SLAVE_Entry */
/**
* @brief Function implementing the ThreadSUSI_SLAVE thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_ThreadSUSI_SLAVE_Entry */
void ThreadSUSI_SLAVE_Entry(void *argument)
{
  /* USER CODE BEGIN ThreadSUSI_SLAVE */
  SUSI_slave();
  /* USER CODE END ThreadSUSI_SLAVE */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

