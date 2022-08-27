#include "IOcheck.h"
#include "sysdata.h"

void Key_Borad(void)
{

    /*--------------------------------- �����ʱ�����3.3V����������Ϊ0v----------------------------------------*/
    if(IO_LOES&&sysdata.Alarm==0&&sysdata.ZxqError1==0&&sysdata.ZxqError2==0)
    {
        if(sysdata.SINError==0)
        {
            sysdata.SINError=1;
            data_warning_timer = 4; // ����
            timer_countwarn =0;
            flag_count2_5Hz=0;
        }
        sysdata.Open=0;
    }
    else if(!IO_LOES)
    {
        if(sysdata.SINError)
        {
					  if(sysdata.ZxqSelfCheck==0)
						{
             sysdata.Open=1;
						}
            sysdata.SINError=0;
            data_warning_timer = 0; // ����
            timer_countwarn =0;
            flag_count2_5Hz=0;
        }
    }

    /*---------------------------------�������----------------------------------------*/
    if(!IO_KEY)
    {
        timer_keycount++;
    }
    else
    {

        if(timer_keycount >= 5 && timer_keycount <= 60) // �̰�
        {

            if(sysdata.Alarm==clearAlarm)
            {
                sysdata.Open=1;
                sysdata.Alarm=keyclearAlarm;
                sysdata.valve1=open  ;
                sysdata.valve2=open  ;
                data_warning_timer = 0; // 
                timer_countwarn =0;
                flag_count2_5Hz=0;
                if(sysdata.ZxqError1==2)
                {
                    sysdata.ZxqError1=1;
                }
                if(sysdata.ZxqError2==2)
                {
                    sysdata.ZxqError2=1;
                }
            }
            else if(sysdata.Alarm==0&&sysdata.ZxqSelfCheck==0)
            {
//                if(sysdata.valve1  ==open||sysdata.valve2 ==open )
//                {
                    sysdata.ZxqSelfCheck=1;
//                    sysdata.ZxqKeyCheck=1;
//							      data_warning_timer = 0; //
//                }
            }
//            else if(sysdata.Alarm==0&&sysdata.ZxqKeyCheck==1&&(sysdata.ZxqError1==2||sysdata.ZxqError2==2))&&sysdata.ZxqError1==0&&sysdata.ZxqError2==0&&sysdata.ZxqReversalCheckTime==0
//            {
//                sysdata.ZxqKeyCheck=2;
//            }
            timer_keycount = 0;
        }
        else
        {
            timer_keycount=0;
        }


    }

    /*---------------------------------ˮ���Ĵ��������3.3V���0V��0v�ᷢ��ˮ��----------------------------------------*/
    if(!IO_WATER)
    {
        if(sysdata.Alarm<clearAlarm)
        {
            sysdata.Alarm=warning;
            sysdata.SINError=0;
            sysdata.Open=0;
            data_warning_timer = 6; // 3��
            timer_countwarn =0;
            flag_count2_5Hz=0;
            sysdata.valve1=close ;
            sysdata.valve2=close ;
            sysdata.ZxqSelfCheck=0;
            sysdata.ZxqReversalCheckTime=0;
            sysdata.ZxqForwardCheckTime =0;
        }
        else
        {
            sysdata.Alarm=warning;
        }
    }
    else
    {
        if(sysdata.Alarm==warning)
            sysdata.Alarm=clearAlarm;
    }

}


void LED_State(void)
{
    if(sysdata.Open)
    {
        IO_GLED(0);
    }
    else
    {
        IO_GLED(1);
    }
}








