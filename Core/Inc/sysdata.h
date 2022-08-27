#ifndef __SYSDATA_H__
#define __SYSDATA_H__
#include "main.h"

#ifdef __cpluplus
extern "C" {
#endif
  
typedef struct
{
  u32 ObjID;            //学习用临时id
  
  u16 WaitSendTime;      //防冲突延时
  u32 SendHeartTime;     //心跳间隔
  u8  ReciveTime;        //接收等待时间，接收超时
  
  
  u8 Learn;          //学习状态 + 时间(S)
  u8 Alarm;          //系统总报警状态
  u8 AlarmFlag;      //主机传感器报警标志
  u16 AlarmSound;        //报警声音标志
  u8 HeartAlarm;        //心跳报警标志
  
  
  u8 SendTest;          //需要发送测试
  u8 SendLearn;         //需要发送学习
  u8 SendNoLearn;       //需要发送解绑
  u8 SendAlarm;         //需要发送报警
  u8 SendHeart;         //需要发送心跳
//  u8 SendChildlock;     //需要发送童锁
//  u8 SendDelayoff;      //需要发送延时关机
  

  
  u8 Open;  //绿灯开关；   
  u8 valve1;//阀门1；0：关 1：开
	u8 valve2;//阀门2；0：关 1：开
	
  u8 ZxqFlag1;  //执行器故障
  u8 ZxqFlag2;  //执行器故障
  
  u8 ZxqError1;  //执行器故障
  u8 ZxqError2;  //执行器故障
  
  u8 SINError;   //传感器掉落检测
	
  u8 ZxqSelfCheck;//执行器自检标志
	u8 ZxqKeyCheck;//执行器按键检测标志
	
	u32 ZxqForwardCheckTime;//执行器检测计时
	
	u32 ZxqReversalCheckTime;//执行器反转计时
	u32 TimeInterval;//时间间隔
  u32 ZxqTime;  //执行器计时
  
}SYSDATA_STRUCT;




extern SYSDATA_STRUCT sysdata;

#ifdef __cplusplus
}
#endif
#endif /* __SYSDATA_H__ */

/** @} */
/** @} */
