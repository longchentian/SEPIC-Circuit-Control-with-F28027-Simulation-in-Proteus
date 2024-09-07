//includes
#include "F2802x_Device.h"

// function
void System_authorize(void)    //system authorize
{
	myCpu = CPU_init((void *)NULL, sizeof(CPU_Obj));
    myWDog = WDOG_init((void *)WDOG_BASE_ADDR, sizeof(WDOG_Obj));
    myPll = PLL_init((void *)PLL_BASE_ADDR, sizeof(PLL_Obj));
    myClk = CLK_init((void *)CLK_BASE_ADDR, sizeof(CLK_Obj));
	myGpio = GPIO_init((void *)GPIO_BASE_ADDR, sizeof(GPIO_Obj));
	myPie = PIE_init((void *)PIE_BASE_ADDR, sizeof(PIE_Obj));   // PIE
	myTimer0 = TIMER_init((void *)TIMER0_BASE_ADDR, sizeof(TIMER_Obj));//TIMER
    myTimer1 = TIMER_init((void *)TIMER1_BASE_ADDR, sizeof(TIMER_Obj));
    myTimer2 = TIMER_init((void *)TIMER2_BASE_ADDR, sizeof(TIMER_Obj));
	myPwm1 = PWM_init((void *)PWM_ePWM1_BASE_ADDR, sizeof(PWM_Obj)); // PWM1
	myPwm2 = PWM_init((void *)PWM_ePWM2_BASE_ADDR, sizeof(PWM_Obj)); // PWM2
    myPwm3 = PWM_init((void *)PWM_ePWM3_BASE_ADDR, sizeof(PWM_Obj)); // PWM1
    myPwm4 = PWM_init((void *)PWM_ePWM4_BASE_ADDR, sizeof(PWM_Obj)); // PWM2
	myCap = CAP_init((void *)CAPA_BASE_ADDR, sizeof(CAP_Obj));// CAP1
	myAdc = ADC_init((void *)ADC_BASE_ADDR, sizeof(ADC_Obj)); // ADC
	mySci = SCI_init((void *)SCIA_BASE_ADDR, sizeof(SCI_Obj)); // SCI
    mySpi = SPI_init((void *)SPIA_BASE_ADDR, sizeof(SPI_Obj)); // SCI
}

//===========================================================================
// End of file.
//===========================================================================



