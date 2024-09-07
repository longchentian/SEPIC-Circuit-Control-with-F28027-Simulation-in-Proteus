#ifndef _MYPWM_H_
#define _MYPWM_H_

// **************************************************************************
// the includes
#include <stdint.h>

// driver
#include "F2802x_Component/F2802x_Device.h"



#ifdef __cplusplus
extern "C" {
#endif

#ifndef TARGET_GLOBAL
   #define TARGET_EXT   extern
#else
   #define TARGET_EXT
#endif

// Defines the Variable
//宏定义使代码移植方便，引脚比较好换
#define PWM_pin1  GPIO_Number_0
#define PWM_pin2  GPIO_Number_1




#define pwm_handle1  myPwm1


//Defines the Function
TARGET_EXT void myPwm1_init(uint16_t PERIOD);


//**********************************************************************************//


#ifdef __cplusplus
}
#endif // extern "C"

#endif
