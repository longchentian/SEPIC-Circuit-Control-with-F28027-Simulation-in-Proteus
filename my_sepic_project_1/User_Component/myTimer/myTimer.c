#include "User_Component/myTimer/myTimer.h"

void myTimer0_init(uint16_t PERIOD)//�������������ʹ��
{
    // 1. stop
    TIMER_stop(myTimer0);
    // 2. set DecimationFactor  ���ö�ʱ����Ƶϵ��
    TIMER_setDecimationFactor(myTimer0, 0);
    // 3. set Period        ���ö�ʱ������
    TIMER_setPeriod(myTimer0, PERIOD);
    // 4. reload       ��ʱ��ֵ��װ��
    TIMER_reload(myTimer0);
    // 5. start     ������ʱ��
    TIMER_start(myTimer0);

    timer0base=0;

}

