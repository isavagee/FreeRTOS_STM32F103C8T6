/**
  ******************************************************************************
  * �ļ�����: bsp_BasicTIM.c 
  * ��    ��: kian
  * ��    ��: V1.0
  * ��д����: 2017-07-19
  * ��    ��: ʵ��TIM�Ļص�����
  ******************************************************************************
  * ˵����
  ******************************************************************************
  */
/* ����ͷ�ļ� ----------------------------------------------------------------*/
#include "BasicTIM/bsp_BasicTIM.h" 

/* ˽�����Ͷ��� --------------------------------------------------------------*/
/* ˽�к궨�� ----------------------------------------------------------------*/
/* ˽�б��� ------------------------------------------------------------------*/

/*
 * �����Ӻ��� configureTimerForRunTimeStats() �� getRunTimeCounterValue() ���ã�
 * Ϊ���ڵ���ϵͳʱ������������������ʱ�䣬���ļ���Ƶ��Ҫ��ϵͳʱ��Ҫ��
 */
volatile uint32_t ulHighFrequencyTimerTicks; 

/* ��չ���� ------------------------------------------------------------------*/
/* ˽�к���ԭ�� --------------------------------------------------------------*/
/* ������ --------------------------------------------------------------------*/
extern TIM_HandleTypeDef htim3;


/**
  * ��������: ������ģʽ�¶�ʱ���Ļص�����
  * �������: htim����ʱ�����
  * �� �� ֵ: ��
  * ˵    ��: ��
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  if(__HAL_TIM_GET_IT_SOURCE(&htim3,TIM_IT_UPDATE)!=RESET)
  {
    ulHighFrequencyTimerTicks++;
    __HAL_TIM_CLEAR_IT(&htim3, TIM_IT_UPDATE);
  }
}


/* Functions needed when configGENERATE_RUN_TIME_STATS is on */
void configureTimerForRunTimeStats(void)
{
    ulHighFrequencyTimerTicks = 0ul;

}

unsigned long getRunTimeCounterValue(void)
{
    return ulHighFrequencyTimerTicks;
}

/******************* (C) COPYRIGHT 2015-2020 ӲʯǶ��ʽ�����Ŷ� *****END OF FILE****/
