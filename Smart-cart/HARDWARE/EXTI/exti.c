#include "exti.h"
/***********************************************
��˾����Ȥ�Ƽ�����ݸ�����޹�˾
Ʒ�ƣ�WHEELTEC
������wheeltec.net
�Ա����̣�shop114407458.taobao.com 
����ͨ: https://minibalance.aliexpress.com/store/4455017
�汾��V5.0
�޸�ʱ�䣺2021-11-05

Brand: WHEELTEC
Website: wheeltec.net
Taobao shop: shop114407458.taobao.com 
Aliexpress: https://minibalance.aliexpress.com/store/4455017
Version: V5.0
Update��2021-11-05

All rights reserved
***********************************************/
/**************************************************************************
�������ܣ��ⲿ�жϳ�ʼ��
��ڲ�������
����  ֵ���� 
**************************************************************************/
void Timer1_Init(u16 arr,u16 psc)  
{
	RCC->APB2ENR|=1<<11;//TIM1ʱ��ʹ��    
 	TIM1->ARR=arr;      //�趨�������Զ���װֵ   
	TIM1->PSC=psc;      //Ԥ��Ƶ��7200,�õ�10Khz�ļ���ʱ��
	TIM1->DIER|=1<<0;   //��������ж�				
	TIM1->DIER|=1<<6;   //�������ж�	   
	TIM1->CR1|=0x01;    //ʹ�ܶ�ʱ��
	MY_NVIC_Init(1,3,TIM1_UP_IRQn,2);
}
 

int TIM1_UP_IRQHandler(void)  
{    
	if(TIM1->SR&0X0001)//5ms��ʱ�ж�
	{   
		   	TIM1->SR&=~(1<<0);   
			  
		if(++count_temp>1)  
		{
		count_temp=0;	
		temp++;
		temp2=temp;
    if(temp>30) temp=0,flag=!flag;			
		}
		if(flag)temp3=0;else temp3=7;
		   
		    
				LED=0;
	}       	
	 return 0;	  
} 






