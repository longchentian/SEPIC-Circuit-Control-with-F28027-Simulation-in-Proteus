#ifndef _MYADC_H_
#define _MYADC_H_

// **************************************************************************
// the includes
#include <stdint.h>

// driver
#include "F2802x_Component/F2802x_Device.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef TARGET_GLOBAL
   #define TARGET_EXT 	extern
#else
   #define TARGET_EXT
#endif

TARGET_EXT void myAdc_init(void);



uint16_t get_ad(void);
float  KalmanFilter( float  inData );
unsigned int filter2( void );
//float  KalmanFilter(float  inData,float prevData);
float Kalman2(void);


#ifdef __cplusplus
}
#endif // extern "C"


#endif

