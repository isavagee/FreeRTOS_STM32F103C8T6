#ifndef __BSP_LED_H__
#define __BSP_LED_H__

/* ����ͷ�ļ� ----------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* ���Ͷ��� ------------------------------------------------------------------*/
typedef enum
{
  LED_OFF = 0,
  LED_ON  = 1,
  LED_TOGGLE = 2,
}LEDState_TypeDef;
#define IS_LED_STATE(STATE)           (((STATE) == LED_OFF) || ((STATE) == LED_ON) || ((STATE) == LED_TOGGLE))

/* �궨�� --------------------------------------------------------------------*/
#define LED_RED                          (uint8_t)0x01
#define LED_GREEN                        (uint8_t)0x02
#define LED_BLUE                         (uint8_t)0x04
#define IS_LED_TYPEDEF(LED)           (((LED) == LED_RED) || ((LED) == LED_GREEN) || ((LED) == LED_BLUE))

/*
 * ���º궨�����ݸ�������Ӳ��ϢϢ��أ���Ҫ�鿴�������·ԭ��ͼ������ȷ��д��
 * ���磬��ԭ��ͼ����LED_RED�ƽ���stm32f103оƬ��PC15�����ϣ������й�LED_RED�ĺ궨��
 * ������GPIOC��GPIO_Pin_15��صģ�ר�Ű���Щ�뿪����Ӳ����ص����ݶ���Ϊ�꣬
 * ������޸Ļ�����ֲ����ǳ����㡣
 */
#define LED_RED_RCC_CLK_ENABLE()            __HAL_RCC_GPIOC_CLK_ENABLE()
#define LED_RED_GPIO_PIN                    GPIO_PIN_15
#define LED_RED_GPIO                        GPIOC


#define LED_GREEN_RCC_CLK_ENABLE()          __HAL_RCC_GPIOC_CLK_ENABLE()
#define LED_GREEN_GPIO_PIN                  GPIO_PIN_14
#define LED_GREEN_GPIO                      GPIOC


#define LED_BLUE_RCC_CLK_ENABLE()           __HAL_RCC_GPIOC_CLK_ENABLE()
#define LED_BLUE_GPIO_PIN                   GPIO_PIN_13
#define LED_BLUE_GPIO                       GPIOC

#define LED_RED_ON                          HAL_GPIO_WritePin(LED_RED_GPIO,LED_RED_GPIO_PIN,GPIO_PIN_SET)    // ����ߵ�ƽ
#define LED_RED_OFF                         HAL_GPIO_WritePin(LED_RED_GPIO,LED_RED_GPIO_PIN,GPIO_PIN_RESET)  // ����͵�ƽ
#define LED_RED_TOGGLE                      HAL_GPIO_TogglePin(LED_RED_GPIO,LED_RED_GPIO_PIN)                // �����ת

#define LED_GREEN_ON                        HAL_GPIO_WritePin(LED_GREEN_GPIO,LED_GREEN_GPIO_PIN,GPIO_PIN_SET)    // ����ߵ�ƽ
#define LED_GREEN_OFF                       HAL_GPIO_WritePin(LED_GREEN_GPIO,LED_GREEN_GPIO_PIN,GPIO_PIN_RESET)  // ����͵�ƽ
#define LED_GREEN_TOGGLE                    HAL_GPIO_TogglePin(LED_GREEN_GPIO,LED_GREEN_GPIO_PIN)                // �����ת

#define LED_BLUE_ON                         HAL_GPIO_WritePin(LED_BLUE_GPIO,LED_BLUE_GPIO_PIN,GPIO_PIN_SET)    // ����ߵ�ƽ
#define LED_BLUE_OFF                        HAL_GPIO_WritePin(LED_BLUE_GPIO,LED_BLUE_GPIO_PIN,GPIO_PIN_RESET)  // ����͵�ƽ
#define LED_BLUE_TOGGLE                     HAL_GPIO_TogglePin(LED_BLUE_GPIO,LED_BLUE_GPIO_PIN)                // �����ת


/* ��չ���� ------------------------------------------------------------------*/
/* �������� ------------------------------------------------------------------*/
void LED_GPIO_Init(void);
void LEDx_StateSet(uint8_t LEDx,LEDState_TypeDef state);

#endif  // __BSP_LED_H__

/******************* (C) COPYRIGHT 2015-2020 kian *****END OF FILE****/
