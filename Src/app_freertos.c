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
/* Definitions for ThreadSUSI */
osThreadId_t ThreadSUSIHandle;
const osThreadAttr_t ThreadSUSI_attributes = {
  .name = "ThreadSUSI",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 256 * 4
};
/* Definitions for Mutex */
osMutexId_t MutexHandle;
const osMutexAttr_t Mutex_attributes = {
  .name = "Mutex"
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
  /* creation of Mutex */
  MutexHandle = osMutexNew(&Mutex_attributes);

  /* USER CODE BEGIN RTOS_MUTEX */
  if(MutexHandle == NULL)
  {
    Error_Handler();
  }
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */
  /* creation of Thread1 */
  Thread1Handle = osThreadNew(Thread1_Entry, NULL, &Thread1_attributes);

  /* creation of ThreadSUSI */
  ThreadSUSIHandle = osThreadNew(ThreadSUSI_Entry, NULL, &ThreadSUSI_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  if((ThreadSUSIHandle == NULL)||(ThreadSUSIHandle == NULL))
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
  /* Prevent unused argument warning */
  (void)argument;

  /* USER CODE BEGIN Thread1 */
  uint16_t i;
  /* Infinite loop */
  for(i = 0; i < 10; ++i)
  {
    #if EXAMPLE_USES_MUTEX
      osMutexAcquire(MutexHandle, osWaitForever);
      printf ("Thread1: Mutex Acquired!\n");
    #endif

    printf("Thread1 : This is message number %u\n", i+1);

    #if EXAMPLE_USES_MUTEX
      printf ("Thread1: Mutex Released!\n");
      osMutexRelease(MutexHandle);
    #endif

    HAL_GPIO_TogglePin(LED1_GREEN_GPIO_Port, LED1_GREEN_Pin);
    osDelay(200);
  }

  while(1)
  {
    HAL_GPIO_TogglePin(LED1_GREEN_GPIO_Port, LED1_GREEN_Pin);
    osDelay(1000);
  }
  /* USER CODE END Thread1 */
}

/* USER CODE BEGIN Header_ThreadSUSI_Entry */
/**
* @brief Function implementing the ThreadSUSI thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_ThreadSUSI_Entry */
void ThreadSUSI_Entry(void *argument)
{
  /* Prevent unused argument warning */
  (void)argument;

  /* USER CODE BEGIN ThreadSUSI */

  HAL_StatusTypeDef HAL_Status;
  /* Buffer used for reception */
  uint8_t aRxBuffer[5];

  /* Infinite loop */
  for(;;)
  {
    HAL_Status = HAL_SPI_Receive(&hspi1, (uint8_t *)aRxBuffer, 2, 100);
    switch (HAL_Status)
    {
      case HAL_OK:
        /* Turn LED1 on: Transfer in reception process is complete */
        HAL_GPIO_TogglePin(LED2_YELLOW_GPIO_Port, LED2_YELLOW_Pin);
        printf("Hex byte: %02X%02X   Decimal: %u\n", aRxBuffer[0], aRxBuffer[1], aRxBuffer[0]);
        break;
      case HAL_TIMEOUT:
        break;
      case HAL_ERROR:
        /* Turn LED3 on: Transfer error in reception process */
        //BSP_LED_On(LED3);
        Error_Handler();
        break;
      default:
        break;
    }
    osDelay(1);
  }
  /* USER CODE END ThreadSUSI */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

