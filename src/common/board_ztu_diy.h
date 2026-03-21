#ifndef SRC_COMMON_BOARD_ZTU_DIY_H_
#define SRC_COMMON_BOARD_ZTU_DIY_H_

/**************************** Configure UART ***************************************/
#if UART_PRINTF_MODE
#define DEBUG_INFO_TX_PIN       GPIO_PB5
#define PB5_DATA_OUT            ON
#define DEBUG_BAUDRATE          115200
#endif /* UART_PRINTF_MODE */

/********************* Configure External Battery GPIO ******************************/
#define VOLTAGE_DETECT_PIN      GPIO_PC5

/***************************** Configure LED  ***************************************/

#define LED_ON                  1
#define LED_OFF                 0
#define LED1                    GPIO_PD7
#define PD7_FUNC                AS_GPIO
#define PD7_OUTPUT_ENABLE       ON
#define PD7_INPUT_ENABLE        OFF
#define PD7_DATA_OUT            LED_OFF

/************************* Configure BUTTON GPIO ***************************************/
#define MAX_ROW_NUM             4
#define MAX_LINE_NUM            5
#define MAX_BUTTON_NUM          (MAX_ROW_NUM * MAX_LINE_NUM)

#define ROW1_GPIO               GPIO_PB4
#define PB4_INPUT_ENABLE        ON
#define PB4_OUTPUT_ENABLE       OFF
#define PB4_FUNC                AS_GPIO
#define PB4_DATA_OUT            0
#define PULL_WAKEUP_SRC_PB4     PM_PIN_PULLDOWN_100K

#define ROW2_GPIO               GPIO_PD2
#define PD2_INPUT_ENABLE        ON
#define PD2_OUTPUT_ENABLE       OFF
#define PD2_FUNC                AS_GPIO
#define PD2_DATA_OUT            0
#define PULL_WAKEUP_SRC_PD2     PM_PIN_PULLDOWN_100K

#define ROW3_GPIO               GPIO_PC3
#define PC3_INPUT_ENABLE        ON
#define PC3_OUTPUT_ENABLE       OFF
#define PC3_FUNC                AS_GPIO
#define PC3_DATA_OUT            0
#define PULL_WAKEUP_SRC_PC3     PM_PIN_PULLDOWN_100K

#define ROW4_GPIO               GPIO_PC2
#define PC2_INPUT_ENABLE        ON
#define PC2_OUTPUT_ENABLE       OFF
#define PC2_FUNC                AS_GPIO
#define PC2_DATA_OUT            0
#define PULL_WAKEUP_SRC_PC2     PM_PIN_PULLDOWN_100K

#define LINE1_GPIO              GPIO_PD4
#define PD4_INPUT_ENABLE        ON
#define PD4_OUTPUT_ENABLE       OFF
#define PD4_FUNC                AS_GPIO
#define PULL_WAKEUP_SRC_PD4     PM_PIN_PULLUP_10K

#define LINE2_GPIO              GPIO_PC1
#define PC1_INPUT_ENABLE        ON
#define PC1_OUTPUT_ENABLE       OFF
#define PC1_FUNC                AS_GPIO
#define PULL_WAKEUP_SRC_PC1     PM_PIN_PULLUP_10K

#define LINE3_GPIO              GPIO_PC4
#define PC4_INPUT_ENABLE        ON
#define PC4_OUTPUT_ENABLE       OFF
#define PC4_FUNC                AS_GPIO
#define PULL_WAKEUP_SRC_PC4     PM_PIN_PULLUP_10K

#define LINE4_GPIO              GPIO_PB7
#define PB7_INPUT_ENABLE        ON
#define PB7_OUTPUT_ENABLE       OFF
#define PB7_FUNC                AS_GPIO
#define PULL_WAKEUP_SRC_PB7     PM_PIN_PULLUP_10K

#define LINE5_GPIO              GPIO_PB1
#define PB1_INPUT_ENABLE        ON
#define PB1_OUTPUT_ENABLE       OFF
#define PB1_FUNC                AS_GPIO
#define PULL_WAKEUP_SRC_PB1     PM_PIN_PULLUP_10K


#endif /* SRC_COMMON_BOARD_ZTU_DIY_H_ */
