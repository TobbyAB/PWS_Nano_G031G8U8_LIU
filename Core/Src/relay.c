#include "relay.h"
#include "sysdata.h"

u8 RelayState=0;//继电器开关标志；1开0关

void Relay_State(void)
{
    if(RelayState==close )
    {
        if(sysdata.Alarm==normal)
        {
            IO_RELAY2(GPIO_PIN_SET);
            HAL_Delay(10);
            IO_RELAY2(GPIO_PIN_RESET);
            HAL_Delay(100);
            IO_RELAY1(GPIO_PIN_SET);
            HAL_Delay(10);
            IO_RELAY1(GPIO_PIN_RESET);
            RelayState=open;
        }
        else if(sysdata.Alarm==keyclearAlarm)
        {
            IO_RELAY2(GPIO_PIN_SET);
            HAL_Delay(10);
            IO_RELAY2(GPIO_PIN_RESET);
            HAL_Delay(100);
            IO_RELAY1(GPIO_PIN_SET);
            HAL_Delay(10);
            IO_RELAY1(GPIO_PIN_RESET);
            sysdata.Alarm=normal;
            RelayState=open;
        }

    }
    else if(sysdata.Alarm==warning&&RelayState==open )
    {
        IO_RELAY1(GPIO_PIN_SET);
        HAL_Delay(10);
        IO_RELAY1(GPIO_PIN_RESET);
        HAL_Delay(100);
        IO_RELAY2(GPIO_PIN_SET);
        HAL_Delay(10);
        IO_RELAY2(GPIO_PIN_RESET);
        RelayState=close;
    }

}

void Relay_Init(void)
{
    IO_RELAY1(GPIO_PIN_SET);
    HAL_Delay(10);
    IO_RELAY1(GPIO_PIN_RESET);
    HAL_Delay(100);
    IO_RELAY2(GPIO_PIN_SET);
    HAL_Delay(10);
    IO_RELAY2(GPIO_PIN_RESET);
}





