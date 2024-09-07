#ifndef _APP_H_
#define _APP_H_

// **************************************************************************
// the includes
#include <stdint.h>

// driver
#include "User_Component/User_Device.h"


#ifdef __cplusplus
extern "C" {
#endif


#ifndef TARGET_GLOBAL
   #define TARGET_EXT 	extern
#else
   #define TARGET_EXT
#endif

#define  PID3 1

#if defined(PID1)
    extern  AW_PID pid;
#elif defined(PID2)
    extern  SP_PID pid ;
#elif defined(PID3)
    extern  EH_PID pid;

#endif




TARGET_EXT float control_uk;


TARGET_EXT int rule_base[21][qf_default];
TARGET_EXT int mf_params[4 * qf_default];
TARGET_EXT float fuzzy_pid_params[1][pid_params_count] ;
TARGET_EXT struct PID **pid_vector;


TARGET_EXT void PID_init(void);


TARGET_EXT float VoltageRef1;
TARGET_EXT float VoltageRef2;
TARGET_EXT float Ts;
TARGET_EXT int target_val;
TARGET_EXT int real_val;
TARGET_EXT uint16_t Ref_scaler;
TARGET_EXT uint16_t Isr_count;


TARGET_EXT interrupt void myTimer_CpuTimer0_isr(void);     //redefined in Isr.h

#ifdef __cplusplus
}
#endif // extern "C"

#endif  // end of _APP_H_ definition

