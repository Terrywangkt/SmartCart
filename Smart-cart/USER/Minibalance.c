#include "sys.h"
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
u8 Way_Angle=1;                             //��ȡ�Ƕȵ��㷨��1����Ԫ��  2��������  3�������˲� 
u8 Flag_Qian,Flag_Hou,Flag_Left,Flag_Right,Flag_Direction=0; //����ң����صı���
u8 Flag_Stop=1,Flag_Show=0;                 //ֹͣ��־λ�� ��ʾ��־λ Ĭ��ֹͣ ��ʾ��
int Encoder_A,Encoder_B,Encoder_C;             //���������������
int Encoder_A_EXTI;
int Motor_A,Motor_B,Motor_C;                   //���PWM����
int Target_A,Target_B,Target_C;                   //���Ŀ���ٶ�
int Temperature;                            //��ʾ�¶�
int Voltage;                                //��ص�ѹ������صı���
float Angle_Balance,Gyro_Balance,Gyro_Turn; //ƽ����� ƽ�������� ת��������
float Show_Data_Mb;                         //ȫ����ʾ������������ʾ��Ҫ�鿴������
u32 Distance;                               //���������
u8 delay_50,delay_flag;         //Ĭ������£����������Ϲ��ܣ������û�����2s���Ͽ��Խ������ģʽ
int Velocity=30;
u8 Usart3_Receive;
u8 rxbuf[8],Rxbuf[16];
u8 txbuf[8];
int AZ,GZ;
float Pitch,Roll,Yaw; 
u32 count,usart_count;
int temp,temp2,temp3,count_temp,flag; 
int CarSpin;
int main(void)
{ 
	Stm32_Clock_Init(9);            //=====ϵͳʱ������
	delay_init(72);                 //=====��ʱ��ʼ��
	LED_Init();
	KEY_Init();
  uart_init(72,115200);           //=====��ʼ������1
  uart2_init(36,115200);          //=====����2��ʼ��
	Timer1_Init(499,7199);
	CAN1_Mode_Init(1,2,3,6,0);  //CAN��ʼ��

	while(1)
	{    	
		//�ٶȵ�λmm/s
		PAout(4)=0;        //����LED
		usart2_send(0X7B); //֡ͷ
		usart2_send(0X00); //Ԥ��λ
		usart2_send(0X00); //Ԥ��λ
		usart2_send(0X01); //X���ٶȸ�8λ
		usart2_send(0X10); //X���ٶȵ�8λ
		usart2_send(0X00); //Y���ٶȸ�8λ
		usart2_send(0X00); //Y���ٶȵ�8λ
		usart2_send(0X00); //Z���ٶȸ�8λ
		usart2_send(0X00); //Z���ٶȵ�8λ
		usart2_send(0X6A); //BBCУ��λ
		usart2_send(0X7D); //֡β
	} 
}
