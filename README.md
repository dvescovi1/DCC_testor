## <b>Application Description</b>

This application runs the DCC decoder test suite.

The program uses the FreeRTOS middleware component.

The application has several threads:

    -Thread1 : Prints messages counting from 1 to 10 ("Thread1 : This is message number x")
               Blinks the green LED every second

    -Thread2 : Prints messages counting from 1 to 10 ("Thread2 : This is message number x")
               Blinks the yellow LED every second

#### <b>Expected success behavior</b>

The yellow LED and green LEDs are used as application feedback.

#### <b>Error behaviors</b>

On failure, the red LED is ON.

#### <b>Assumptions if any</b>

None

#### <b>Known limitations</b>

None

### <b>Notes</b>

None

#### <b>FreeRTOS usage hints</b>

The FreeRTOS heap size configTOTAL_HEAP_SIZE defined in FreeRTOSConfig.h is set accordingly to the
OS resources memory requirements of the application with +10% margin and rounded to the upper Kbyte boundary.

For more details about FreeRTOS implementation on STM32Cube, please refer to UM1722 "Developing Applications
on STM32Cube with RTOS".

### <b>Keywords</b>

NMRA, DCC

### <b>Hardware and Software environment</b>

  - This application runs on STM32H563xx devices.
  - This application has been tested with STMicroelectronics NUCLEO-H563ZI board
    and can be easily tailored to any other supported device and development board.

  - This application uses USART3 to display output, the hyperterminal configuration is as follows:

    - BaudRate = 115200 baud
    - Word Length = 8 Bits
    - Stop Bit = 1
    - Parity = None
    - Flow control = None

### <b>How to use it ?</b>

In order to make the program work, you must do the following :

 - Open the project in your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the application
