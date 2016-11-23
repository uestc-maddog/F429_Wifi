#include "common.h"
#include "stdlib.h"
#include "stdio.h"

// wifiģ�鷢������  TCP Client
// ����ֵ��0--ʧ��     1--�ɹ�
u8 atk_8266_wifisend_data(u8 *Wifi_Data)
{
	u8 i = 0;
	u8 res = 0;
	u8 constate = 0;	                  // ����״̬
	u8 *p = mymalloc(SRAMIN,32);			  // ����32�ֽ��ڴ�
	
	for(i = 0; i < 2; i++) constate = atk_8266_consta_check(); // �õ�����״̬
	if(constate=='+')  
	{
		printf("���ӳɹ� ");
		atk_8266_quit_trans();
		atk_8266_send_cmd("AT+CIPSEND","OK",20);  // ��ʼ͸��   
		
		sprintf((char*)p,"%s\r\n",Wifi_Data);         
		u3_printf("%s",p);                           // ��������
		printf("�ѷ��ͣ�%s\r\n", p); 
		res = 1;
	}
	else  
	{
		printf("����ʧ�� "); 
		res = 0;
	}
	atk_8266_at_response(1);
	myfree(SRAMIN,p);		//�ͷ��ڴ� 
	return res;		
} 



























