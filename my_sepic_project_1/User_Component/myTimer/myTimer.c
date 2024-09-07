#include "User_Component/myTimer/myTimer.h"

void myTimer0_init(uint16_t PERIOD)//灵活设置周期来使用
{
    // 1. stop
    TIMER_stop(myTimer0);
    // 2. set DecimationFactor  设置定时器分频系数
    TIMER_setDecimationFactor(myTimer0, 0);
    // 3. set Period        设置定时器周期
    TIMER_setPeriod(myTimer0, PERIOD);
    // 4. reload       定时器值重装载
    TIMER_reload(myTimer0);
    // 5. start     启动定时器
    TIMER_start(myTimer0);

    timer0base=0;

}

