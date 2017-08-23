/**
  ******************************************************************************
  * �ļ�����: bsp_led.c 
  * ��    ��: kian
  * ��    ��: V1.0
  * ��д����: 2017-07-19
  * ��    ��: ����HAL��İ���LED�Ƶײ�����ʵ��
  ******************************************************************************
  * ˵����
  * 
  * 
  ******************************************************************************
  */

/* ����ͷ�ļ� ----------------------------------------------------------------*/
#include "led/bsp_led.h"

/* ˽�����Ͷ��� --------------------------------------------------------------*/
/* ˽�к궨�� ----------------------------------------------------------------*/
/* ˽�б��� ------------------------------------------------------------------*/
/* ��չ���� ------------------------------------------------------------------*/
/* ˽�к���ԭ�� --------------------------------------------------------------*/
/* ������ --------------------------------------------------------------------*/

/**
  * ��������: ����LED��IO���ų�ʼ��.
  * �������: ��
  * �� �� ֵ: ��
  * ˵    ����ʹ�ú궨�巽������������źţ����������ֲ��ֻҪ���޸�bsp_led.h
  *           �ļ���غ궨��Ϳ��Է����޸����š�
  */
void LED_GPIO_Init(void)
{
    /* ����IOӲ����ʼ���ṹ����� */
  GPIO_InitTypeDef GPIO_InitStruct;
	
    /* ʹ��(����)LED���Ŷ�ӦIO�˿�ʱ�� */  
  LED_RED_RCC_CLK_ENABLE();
  LED_GREEN_RCC_CLK_ENABLE();
  LED_BLUE_RCC_CLK_ENABLE();
  
  /* ����LED_RED���������ѹ */
  HAL_GPIO_WritePin(LED_RED_GPIO, LED_RED_GPIO_PIN, GPIO_PIN_RESET);

  /* ����LED_GREEN���������ѹ */
  HAL_GPIO_WritePin(LED_GREEN_GPIO, LED_GREEN_GPIO_PIN, GPIO_PIN_RESET);

  /* ����LED_BLUE���������ѹ */
  HAL_GPIO_WritePin(LED_BLUE_GPIO, LED_BLUE_GPIO_PIN, GPIO_PIN_RESET);
  
  /* �趨LED_RED��Ӧ����IO��� */
  GPIO_InitStruct.Pin = LED_RED_GPIO_PIN;
  /* �趨LED_RED��Ӧ����IOΪ���ģʽ */
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  /* �趨LED_RED��Ӧ����IO�����ٶ� */
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  /* ��ʼ��LED_RED��Ӧ����IO */
  HAL_GPIO_Init(LED_RED_GPIO, &GPIO_InitStruct);
  
  /* �趨LED_GREEN��Ӧ����IO��� */
  GPIO_InitStruct.Pin = LED_GREEN_GPIO_PIN;
  /* �趨LED_GREEN��Ӧ����IOΪ���ģʽ */
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  /* �趨LED_GREEN��Ӧ����IO�����ٶ� */
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  /* ��ʼ��LED2��Ӧ����IO */
  HAL_GPIO_Init(LED_GREEN_GPIO, &GPIO_InitStruct);
  
  /* �趨LED_BLUE��Ӧ����IO��� */
  GPIO_InitStruct.Pin = LED_BLUE_GPIO_PIN;
  /* �趨LED_BLUE��Ӧ����IOΪ���ģʽ */
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  /* �趨LED_BLUE��Ӧ����IO�����ٶ� */
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  /* ��ʼ��LED_BLUE��Ӧ����IO */
  HAL_GPIO_Init(LED_BLUE_GPIO, &GPIO_InitStruct);
  
}

/**
  * ��������: ���ð���LED�Ƶ�״̬
  * �������: LEDx:����x������Ϊ(1,2,3)����ѡ���Ӧ��LED��
  * ���������state:����LED�Ƶ����״̬��
  *             ��ѡֵ��LED_OFF��LED����
  *                     LED_ON�� LED������
  *                     LED_TOGGLE����תLED
  * �� �� ֵ: ��
  * ˵    �����ú���ʹ�����Ʊ�׼�⺯���ı�̷�������������׼�⺯�����˼�롣
  */
void LEDx_StateSet(uint8_t LEDx,LEDState_TypeDef state)
{
  /* �����������Ƿ�Ϸ� */
  assert_param(IS_LED_TYPEDEF(LEDx));
  assert_param(IS_LED_STATE(state));
  
  /* �ж����õ�LED��״̬���������ΪLED���� */
  if(state==LED_OFF)
  {
    if(LEDx & LED_RED)            
      LED_RED_OFF;/* LED_RED�� */
    
    if(LEDx & LED_GREEN)
      LED_GREEN_OFF;/* LED_GREEN�� */
    
    if(LEDx & LED_BLUE)
      LED_BLUE_OFF;/* LED_BLUE�� */    
  }
  else if(state==LED_ON) /* ����LED��Ϊ�� */
  {
    if(LEDx & LED_RED)
      LED_RED_ON;/* LED_RED�� */
    
    if(LEDx & LED_GREEN)
      LED_GREEN_ON;/* LED_GREEN�� */
    
    if(LEDx & LED_BLUE)
      LED_BLUE_ON;/* LED_BLUE�� */ 
  }
  else
  {
    if(LEDx & LED_RED)
      LED_RED_TOGGLE;/* �������������ת */
    
    if(LEDx & LED_GREEN)
      LED_GREEN_TOGGLE;/* �������������ת */
    
    if(LEDx & LED_BLUE)
      LED_BLUE_TOGGLE;/* �������������ת */ 
  }
}

/******************* (C) COPYRIGHT 2015-2020 ӲʯǶ��ʽ�����Ŷ� *****END OF FILE****/
