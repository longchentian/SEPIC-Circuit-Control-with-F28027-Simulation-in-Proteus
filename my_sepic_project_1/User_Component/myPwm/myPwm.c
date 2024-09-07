#include "User_Component/myPwm/myPwm.h"


void myPwm1_init(uint16_t PERIOD)
{
    /***************************************pinConfigure********************************************/
    // 1. set mode

    GPIO_setMode(myGpio, PWM_pin1, GPIO_0_Mode_EPWM1A);
    GPIO_setMode(myGpio, PWM_pin2, GPIO_1_Mode_EPWM1B);
    // 2. set pullup   PWM����Ĭ����������������

    GPIO_setPullUp(myGpio, PWM_pin1, GPIO_PullUp_Enable);
    GPIO_setPullUp(myGpio, PWM_pin2, GPIO_PullUp_Disable);
    //3. set direction

    GPIO_setDirection(myGpio, PWM_pin1, GPIO_Direction_Output);
    GPIO_setDirection(myGpio, PWM_pin2, GPIO_Direction_Output);
    /*************************************--------end--------*****************************************/

    /**************************************functionConfigure******************************************/
    ///*1. TBCLKSYNC = 0*/  �ر�ʱ��ͬ��

    CLK_disableTbClockSync(myClk);
    ///*2. TBCLK*/    ����PWMģ��ʱ�ӷ�Ƶ

    PWM_setHighSpeedClkDiv(myPwm1, PWM_HspClkDiv_by_1);
    PWM_setClkDiv(myPwm1, PWM_ClkDiv_by_1);
    //3. TBCTR         ����PWMģ�����ģʽ

    PWM_setCounterMode(myPwm1, PWM_CounterMode_Up);
    ///*4. TBPRD*/     ����PWMģ�����ڡ����ڸ��£�װ�أ�ģʽ����Ӱ�ӡ�����

    PWM_setPeriod(myPwm1, PERIOD);

    PWM_setPeriodLoad(myPwm1, PWM_PeriodLoad_Shadow);
    ///*5. CMPA*/     ���ñȽϵ�CMPA  �Ƚϵ�װ��ģʽ������ʱ��

    PWM_setCmpA(myPwm1,0);

    PWM_setShadowMode_CmpA(myPwm1, PWM_ShadowMode_Shadow);

    PWM_setLoadMode_CmpA(myPwm1, PWM_LoadMode_Zero);
    ///*6. CMPB*/    ���ñȽϵ�CMPB  �Ƚϵ�װ��ģʽ������ʱ��

    PWM_setCmpB(myPwm1, 0);

    PWM_setShadowMode_CmpB(myPwm1, PWM_ShadowMode_Shadow);

    PWM_setLoadMode_CmpB(myPwm1, PWM_LoadMode_Zero);
    ///*7. action*/   AQ��������

//    PWM_setActionQual_Zero_PwmA(myPwm1, PWM_ActionQual_Set);

//    PWM_setActionQual_CntUp_CmpA_PwmA(myPwm1, PWM_ActionQual_Clear);

    PWM_setActionQual_CntUp_CmpA_PwmA(myPwm1, PWM_ActionQual_Clear);

    PWM_setActionQual_Period_PwmA(myPwm1, PWM_ActionQual_Set);

    PWM_setActionQual_Zero_PwmB(myPwm1, PWM_ActionQual_Set);

    PWM_setActionQual_CntUp_CmpB_PwmB(myPwm1, PWM_ActionQual_Clear);

    /*************************************--------end--------*****************************************/
    /****************************************eventConfigure*******************************************/
    // 1.1 EPWMxINT    PWM�ж�����
    PWM_setIntMode(myPwm1, PWM_IntMode_CounterEqualZero);
    PWM_setIntPeriod(myPwm1, PWM_IntPeriod_FirstEvent);
    //1.2 ADC EPWMxSOCA/EPWMxSOCA    PWM����ADCת������
//    PWM_setSocAPulseSrc(myPwm1, PWM_SocPulseSrc_CounterEqualPeriod);
//    PWM_setSocAPeriod(myPwm1, PWM_SocPeriod_FirstEvent);
//    PWM_enableSocAPulse(myPwm1);
    /*************************************------end---------******************************************/

    CLK_enableTbClockSync(myClk);
}

