#include "valvecheck.h"
#include "sysdata.h"
void Valve_Check(void)
{
    if(sysdata.ZxqSelfCheck==1)
    {
        if(IO_HALL1)
        {
            sysdata.ZxqFlag1 = 1;
            sysdata.valve1  =close ;
        }
        else
        {
            if(sysdata.ZxqError1<2)
            {
                sysdata.ZxqFlag1 = 0;
                sysdata.ZxqError1 = 0;
            }

        }
        if(IO_HALL2)
        {
            sysdata.ZxqFlag2 = 1;
            sysdata.valve2  =close ;
        }
        else
        {
            if(sysdata.ZxqError2<2)
            {
                sysdata.ZxqFlag2 = 0;
                sysdata.ZxqError2 = 0;
            }

        }
        if(sysdata.ZxqFlag1==0&&sysdata.ZxqFlag2==0)
        {
            sysdata.ZxqSelfCheck=0;
        }
        else
        {
					  if(checkflag!=1)
						{
             sysdata.Open = close  ;
             IO_RLED(0) ;
						}
            sysdata.ZxqSelfCheck=2;
            sysdata.ZxqForwardCheckTime=1;
        }
    }
    else if(sysdata.ZxqSelfCheck==3)
    {
        if(sysdata.Alarm == 0)
        {
            sysdata.valve1  =open ;      //开机
            sysdata.valve2  =open ;
        }
    }
    else if(sysdata.ZxqSelfCheck==4)
    {
        if(sysdata.ZxqFlag1) sysdata.ZxqError1 = 1;
        else sysdata.ZxqError1 = 0;
        if(sysdata.ZxqFlag2) sysdata.ZxqError2 = 1;
        else sysdata.ZxqError2 = 0;
        if(sysdata.ZxqError1==0 &&sysdata.ZxqError2==0 && sysdata.Alarm == 0)
        {
					  if(checkflag!=1)
						{					
             IO_RLED(1) ;
             sysdata.Open =open ;
					   
						}
						checkflag=0;
            if(data_warning_timer == 12)
            {
                data_warning_timer =0; // 两声
                timer_countwarn =0;
                flag_count2_5Hz=0;
            }
        }
        sysdata.ZxqSelfCheck=0;
    }
}

void Valve_Alarm(void)
{
    if((sysdata.ZxqError1==1 || sysdata.ZxqError2==1) && sysdata.Alarm == 0)       //执行器故障报警
    {
        sysdata.Open=0;
        sysdata.SINError=0;
        data_warning_timer = 12; // 两声
        timer_countwarn =0;
        flag_count2_5Hz=0;
        if(sysdata.ZxqError1==1)
        {
            sysdata.ZxqError1=2;
        }
        if(sysdata.ZxqError2==1)
        {
            sysdata.ZxqError2=2;
        }
    }
//    else if((sysdata.ZxqError1==2 || sysdata.ZxqError2==2) && sysdata.Alarm == 0&&sysdata.ZxqKeyCheck==2)
//    {
//        sysdata.Open=1;
//        data_warning_timer =0;
//        timer_countwarn =0;
//        flag_count2_5Hz=0;
//        sysdata.ZxqError1=0;
//        sysdata.ZxqError2=0;
//        sysdata.ZxqKeyCheck=0;
//    }
}

void Valve_State(void)
{
    if(sysdata.valve1==open)
    {
        IO_POWER1(open);
    }
    else
    {
        IO_POWER1(close);
    }
    if(sysdata.valve2==open)
    {
        IO_POWER2(open);
    }
    else
    {
        IO_POWER2(close );
    }
}




