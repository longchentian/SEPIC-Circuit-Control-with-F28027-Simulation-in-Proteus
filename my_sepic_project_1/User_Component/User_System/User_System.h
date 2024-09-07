#ifndef _USER_SYSTEM_H_
#define _USER_SYSTEM_H_


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


TARGET_EXT void User_System_init(void);

#ifdef __cplusplus
}
#endif // extern "C"


#endif  // end of _USER_SYSTEM_H_ definition

