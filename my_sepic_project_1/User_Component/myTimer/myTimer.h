#ifndef _MYTIMER_H_
#define _MYTIMER_H_

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

TARGET_EXT uint16_t  timer0base;
TARGET_EXT void myTimer0_init(uint16_t PERIOD);




#ifdef __cplusplus
}
#endif // extern "C"


#endif /* USER_COMPONENT_INCLUDE_MYTIMER_H_ */
