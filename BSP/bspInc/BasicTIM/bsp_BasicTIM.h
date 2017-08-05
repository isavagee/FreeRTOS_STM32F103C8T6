#ifndef __BASIC_TIM_H__
#define __BASIC_TIM_H__

/* ����ͷ�ļ� ----------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* ���Ͷ��� ------------------------------------------------------------------*/
/* �궨�� --------------------------------------------------------------------*/
/**********************************************************************
 * ������ʱ��ֻ�д�������MCU��Ʒ��ӵ��
 * __________________________________________________________________________________
 * |        С����          |        �е�����          |             ������                   |
 * | 16Kflash | 32Kflash | 64Kflash | 128kflash | 256kflash | 384Kflash | 512Kflash |
 * | 6K RAM   | 10K RAM  | 20K RAM  | 20K RAM   | 48K RAM   | 64K RAM   | 64K RAM   |
 * |__________|__________|__________|___________|___________|___________|___________|
 **********************************************************************/
/********************������ʱ��TIM�������壬ֻ��TIM6 & TIM7************/
// ���ʹ��TIM7��ע�͵�����궨�弴��
#define USE_TIM6

#ifdef  USE_TIM6  // ʹ�û�����ʱ��TIM6
#define BASIC_TIMx                     TIM6
#define BASIC_TIM_RCC_CLK_ENABLE()     __HAL_RCC_TIM6_CLK_ENABLE()
#define BASIC_TIM_RCC_CLK_DISABLE()    __HAL_RCC_TIM6_CLK_DISABLE()
#define BASIC_TIM_IRQ                  TIM6_IRQn
#define BASIC_TIM_INT_FUN              TIM6_IRQHandler

#else  // ʹ�û�����ʱ��TIM7

#define BASIC_TIMx                     TIM7
#define BASIC_TIM_RCC_CLK_ENABLE()     __HAL_RCC_TIM7_CLK_ENABLE()
#define BASIC_TIM_RCC_CLK_DISABLE()    __HAL_RCC_TIM7_CLK_DISABLE()
#define BASIC_TIM_IRQ                  TIM7_IRQn
#define BASIC_TIM_INT_FUN              TIM7_IRQHandler

#endif

// ���嶨ʱ��Ԥ��Ƶ����ʱ��ʵ��ʱ��Ƶ��Ϊ��72MHz/��BASIC_TIMx_PRESCALER+1��
#define BASIC_TIMx_PRESCALER           0  // ʵ��ʱ��Ƶ��Ϊ��1MHz
// ���嶨ʱ�����ڣ�����ʱ����ʼ������BASIC_TIMx_PERIODֵ�Ǹ��¶�ʱ�������ɶ�Ӧ�¼����ж�
#define BASIC_TIMx_PERIOD              3600  // ��ʱ�������ж�Ƶ��Ϊ��1MHz/100=10KHz����100us��ʱ����

// ���ն�ʱ��Ƶ�ʼ���Ϊ�� 72MHz/��BASIC_TIMx_PRESCALER+1��/BASIC_TIMx_PERIOD
// ������Ҫ����20ms���ڶ�ʱ����������Ϊ�� 72MHz/��359+1��/4000=50Hz����20ms����
// �������� BASIC_TIMx_PRESCALER=359��BASIC_TIMx_PERIOD=4000��

/* ��չ���� ------------------------------------------------------------------*/
extern TIM_HandleTypeDef htimx;
/* �������� ------------------------------------------------------------------*/

void BASIC_TIMx_Init(void);

#endif	/* __BASIC_TIM_H__ */
/******************* (C) COPYRIGHT 2015-2020 ӲʯǶ��ʽ�����Ŷ� *****END OF FILE****/
