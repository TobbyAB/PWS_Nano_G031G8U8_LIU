#ifndef __SYSDATA_H__
#define __SYSDATA_H__
#include "main.h"

#ifdef __cpluplus
extern "C" {
#endif
  
typedef struct
{
  u32 ObjID;            //ѧϰ����ʱid
  
  u16 WaitSendTime;      //����ͻ��ʱ
  u32 SendHeartTime;     //�������
  u8  ReciveTime;        //���յȴ�ʱ�䣬���ճ�ʱ
  
  
  u8 Learn;          //ѧϰ״̬ + ʱ��(S)
  u8 Alarm;          //ϵͳ�ܱ���״̬
  u8 AlarmFlag;      //����������������־
  u16 AlarmSound;        //����������־
  u8 HeartAlarm;        //����������־
  
  
  u8 SendTest;          //��Ҫ���Ͳ���
  u8 SendLearn;         //��Ҫ����ѧϰ
  u8 SendNoLearn;       //��Ҫ���ͽ��
  u8 SendAlarm;         //��Ҫ���ͱ���
  u8 SendHeart;         //��Ҫ��������
//  u8 SendChildlock;     //��Ҫ����ͯ��
//  u8 SendDelayoff;      //��Ҫ������ʱ�ػ�
  

  
  u8 Open;  //�̵ƿ��أ�   
  u8 valve1;//����1��0���� 1����
	u8 valve2;//����2��0���� 1����
	
  u8 ZxqFlag1;  //ִ��������
  u8 ZxqFlag2;  //ִ��������
  
  u8 ZxqError1;  //ִ��������
  u8 ZxqError2;  //ִ��������
  
  u8 SINError;   //������������
	
  u8 ZxqSelfCheck;//ִ�����Լ��־
	u8 ZxqKeyCheck;//ִ������������־
	
	u32 ZxqForwardCheckTime;//ִ��������ʱ
	
	u32 ZxqReversalCheckTime;//ִ������ת��ʱ
	u32 TimeInterval;//ʱ����
  u32 ZxqTime;  //ִ������ʱ
  
}SYSDATA_STRUCT;




extern SYSDATA_STRUCT sysdata;

#ifdef __cplusplus
}
#endif
#endif /* __SYSDATA_H__ */

/** @} */
/** @} */
