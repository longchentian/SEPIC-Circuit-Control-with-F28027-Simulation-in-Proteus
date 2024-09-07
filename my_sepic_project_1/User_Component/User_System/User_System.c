// **************************************************************************
// the includes
#include "User_Component/User_System/User_System.h"


// **************************************************************************
// the defines


// **************************************************************************
// the globals


// **************************************************************************
// the functions

void User_System_init(void)
{
    // 0. system authorize
    System_authorize();
    // 1. disable watch DOG
    WDOG_disable(myWDog);
    // 2. disable interrupt
    CPU_disableGlobalInts(myCpu);
    // 3. Select the internal oscillator 1(10MHz) as the clock source
    CLK_setOscSrc(myClk, CLK_OscSrc_Internal);
    // 4. Configure the system clock output(SYSCLKOUT) SYSCLKOUT = 10Mhz * 12 / 2 = 60Mhz
    PLL_setup(myPll, PLL_Multiplier_12, PLL_DivideSelect_ClkIn_by_2);
    // 5. Configure the low speed peripheral clock(LSPCLK) LSPCLK = SYSCLKOUT/4 =15MHz
    CLK_setLowSpdPreScaler(myClk, CLK_LowSpdPreScaler_SysClkOut_by_4);
    // 6. Module's Clock configure
    CLK_enableGpioInputClock(myClk); //Gpio Input clock
    CLK_enableAdcClock(myClk);  //ADC colck
    CLK_enableCpuTimerClock(myClk, CLK_CpuTimerNumber_0);//Cpu Timer0 clock
//    CLK_enableCpuTimerClock(myClk, CLK_CpuTimerNumber_1);//Cpu Timer1 clock
//    CLK_enableCpuTimerClock(myClk, CLK_CpuTimerNumber_2);//Cpu Timer2 clock
    CLK_enablePwmClock(myClk, PWM_Number_1); //EPWM1 clock
    CLK_enablePwmClock(myClk, PWM_Number_2); //EPWM2 clock
//    CLK_enablePwmClock(myClk, PWM_Number_3); //EPWM3 clock
//    CLK_enablePwmClock(myClk, PWM_Number_4); //EPWM4 clock
    //CLK_enablePwmClock(myClk, PWM_Number_3); //EPWM3 clock
    //CLK_enablePwmClock(myClk, PWM_Number_4); //EPWM4 clock
    //CLK_enableHrPwmClock(myClk);  //HRPWM clock
//    CLK_enableEcap1Clock(myClk);  //ECAP clock
    //CLK_enableI2cClock(myClk);  //I2C clock
    CLK_enableSciaClock(myClk);  //SCIA clock
//    CLK_enableSpiaClock(myClk);  //SPIA clock
    //CLK_enableCompClock(myClk, CLK_CompNumber_1);//COMP1 clock
    //CLK_enableCompClock(myClk, CLK_CompNumber_2);//COMP2 clock
    //CLK_enableCompClock(myClk, CLK_CompNumber_3);//COMP3 clock

    // 6. PIE configure
    PIE_disable(myPie);                                      //��ֹPIE
    PIE_disableAllInts(myPie);                               //��ֹPIE�ж�
    CPU_disableGlobalInts(myCpu);                            //CPUȫ���жϽ�ֹ
    CPU_clearIntFlags(myCpu);                                //CPU�жϱ�־λ����
    PIE_setDefaultIntVectorTable(myPie);                     //�ж���ڵ�ַ����Ĭ��ֵ
    PIE_enable(myPie);                                       //ʹ��PIE

}



// end of file
