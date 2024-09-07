/*
 * myKey.h
 *
 *  Created on: 2020Äê10ÔÂ23ÈÕ
 *      Author: Administrator
 */

#ifndef _MYKEY_H_
#define _MYKEY_H_

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

#define key_pin GPIO_Number_12
#define key_pin_mode GPIO_12_Mode_GeneralPurpose


TARGET_EXT void myKey_init(void);
TARGET_EXT uint16_t keycount;

#ifdef __cplusplus
}
#endif // extern "C"


#endif /* _MYKEY_H_ */
