
//#############################################################################
//
//! \file    Application\isr.h
//!
//! \brief   Interrupt Service Routine
//!
//  Quthor:
//  Group:          C2000
//  Target Device:  TMS320F2802x
//
//  (C) Copyright 2014, Fuzhou University.
//#############################################################################
// $TI Release: f2802x Support Library v210 $
// $Release Date: Mon Sep 17 09:13:31 CDT 2012 $
//#############################################################################


#ifndef _ISR_H_
#define _ISR_H_


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


// isr API
//! \brief     isr
//! \param[in] None
//! \param[out] None
//TARGET_EXT interrupt void isr(void);

//! \brief     Interrupt Service Routine
//! \param[in] None
//! \param[out] None
TARGET_EXT interrupt void KEY_XINT1_isr(void);     //redefined in Isr.h

//! \brief     Interrupt Service Routine
//! \param[in] None
//! \param[out] None
TARGET_EXT interrupt void myTimer_CpuTimer0_isr(void);     //redefined in Isr.h

//! \brief     Interrupt Service Routine
//! \param[in] None
//! \param[out] None
TARGET_EXT interrupt void myTimer_CpuTimer1_isr(void);     //redefined in Isr.h

//! \brief     Interrupt Service Routine
//! \param[in] None
//! \param[out] None
TARGET_EXT interrupt void myCap_CAPINT_isr(void);     //redefined in Isr.h

//! \brief     Interrupt Service Routine
//! \param[in] None
//! \param[out] None
TARGET_EXT interrupt void myAdc_ADCINT_isr(void);     //redefined in Isr.h

//! \brief      Interrupt Service Routine
//! \param[in]  None
//! \param[out] None
TARGET_EXT interrupt void mySCI_TXINT_isr(void);     //redefined in Isr.h

//! \brief      Interrupt Service Routine
//! \param[in]  None
//! \param[out] None
TARGET_EXT interrupt void mySCI_RXINT_isr(void);     //redefined in Isr.h


TARGET_EXT float VoltageRef1;
TARGET_EXT float VoltageRef2;
TARGET_EXT float Ts;
TARGET_EXT int target_val;
TARGET_EXT int real_val;
TARGET_EXT uint16_t Ref_scaler;
TARGET_EXT uint16_t Isr_count;




#ifdef __cplusplus
}
#endif // extern "C"


#endif  // end of _EXAMPLE_H_ definition

