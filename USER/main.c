/*
Bվ����������?_?��Bվ���������MDK����ʾ��ȫ����Ҫ�˽⣬�ڴ��ļ���word�ĵ����������ҵ���		
֪������������							
CSDN�������������޿���				
���㣺����֮����

�´���QQȺ��822263013
����Ȥ��ͬѧ���Ⱥ������
*/

/*
����Ϊ ���Ƶ���Ĵ���PID���������汾��ƽ��С�����ơ�
����Ļ�е��ֵ��0�ȣ����Ƽ�ʹ��δ�Ƶ��Ĵ���PID������������ֱ�����������Ƕ�������ϻ�е��ֵ�����ɲ����ܻ�е��ֵΪ��0�ȵ�Ӱ�졣
��δ�Ƶ��Ĵ���PID���������ĳ�����Ҳ�����ű�����һ���ϴ���
*/

#include "stm32f10x.h"
#include "sys.h" 

float Pitch,Roll,Yaw;						//�Ƕ�
short gyrox,gyroy,gyroz;				//������--���ٶ�
short aacx,aacy,aacz;						//���ٶ�
int Encoder_Left,Encoder_Right;	//���������ݣ��ٶȣ�

int PWM_MAX=7200,PWM_MIN=-7200;	//PWM�޷�����
int MOTO1,MOTO2;								//���װ�ر���


int main(void)	
{
	delay_init();
	NVIC_Config();
	uart1_init(115200);
	
	OLED_Init();
	OLED_Clear();
	
	MPU_Init();
	mpu_dmp_init();
	MPU6050_EXTI_Init();
	
	Encoder_TIM2_Init();
	Encoder_TIM4_Init();
	Motor_Init();
	PWM_Init_TIM1(0,7199);
  while(1)	
	{
		OLED_Float(0,0,Pitch,3);
	} 	
}



