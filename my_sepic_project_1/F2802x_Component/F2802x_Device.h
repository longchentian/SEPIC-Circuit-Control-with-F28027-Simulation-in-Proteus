#ifndef F2802X_DEVICE_H
#define F2802X_DEVICE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef TARGET_GLOBAL
   #define TARGET_EXT 	extern
#else
   #define TARGET_EXT
#endif


//includes
#include "F2802x_Component/common/include/cpu.h"
#include "F2802x_Component/common/include/adc.h"
#include "F2802x_Component/common/include/clk.h"
#include "F2802x_Component/common/include/flash.h"
#include "F2802x_Component/common/include/gpio.h"
#include "F2802x_Component/common/include/pie.h"
#include "F2802x_Component/common/include/pll.h"
#include "F2802x_Component/common/include/timer.h"
#include "F2802x_Component/common/include/wdog.h"
#include "F2802x_Component/common/include/pwm.h"
#include "F2802x_Component/common/include/cap.h"
#include "F2802x_Component/common/include/sci.h"
#include "F2802x_Component/common/include/IQmathLib.h"
#include "F2802x_Component/common/include/pwr.h"
#include "F2802x_Component/common/include/comp.h"
#include "F2802x_Component/common/include/pwmdac.h"
#include "F2802x_Component/common/include/sci_io.h"
#include "F2802x_Component/common/include/spi.h"
#include "F2802x_Component/common/include/osc.h"
// F2802x Device Define

TARGET_EXT CLK_Handle myClk;
TARGET_EXT CPU_Handle myCpu;
TARGET_EXT PLL_Handle myPll;
TARGET_EXT WDOG_Handle myWDog;
TARGET_EXT PIE_Handle myPie;
TARGET_EXT GPIO_Handle myGpio;
TARGET_EXT TIMER_Handle myTimer0;
TARGET_EXT TIMER_Handle myTimer1;
TARGET_EXT TIMER_Handle myTimer2;
TARGET_EXT ADC_Handle myAdc;
TARGET_EXT CAP_Handle myCap;
TARGET_EXT PWM_Handle myPwm1;
TARGET_EXT PWM_Handle myPwm2;
TARGET_EXT PWM_Handle myPwm3;
TARGET_EXT PWM_Handle myPwm4;
TARGET_EXT SCI_Handle mySci;
TARGET_EXT SPI_Handle mySpi;

TARGET_EXT void System_authorize(void);    //system authorize

#ifdef __cplusplus
}
#endif /* extern "C" */



#endif   // end of _F2802X_DEVICE_H_ definition



