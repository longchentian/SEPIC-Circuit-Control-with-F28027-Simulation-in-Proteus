
//#############################################################################
//
//! \file   User_Component/User_Pie/User_Pie.h
//!
//! \brief  PIE
//!
//  Quthor:
//  Group:          C2000
//  Target Device:  TMS320F2802x
//
//  (C) Copyright 2015, Fuzhou University.
//#############################################################################
// $TI Release: f2802x Support Library v210 $
// $Release Date: Mon Sep 17 09:13:31 CDT 2012 $
//#############################################################################


#ifndef _USER_PIE_H_
#define _USER_PIE_H_


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


/*------- hardware description of the example module   -------------*/

TARGET_EXT void User_Pie_init(void);

TARGET_EXT void User_Pie_functionConfigure(void);

TARGET_EXT void User_Pie_eventConfigure(void);
//
/*******************************************/

/*------- API description of the example module   -------------*/


TARGET_EXT void inline User_Pie_start(void)
{
	//Enable Global Interrupts
	CPU_enableGlobalInts(myCpu);
}

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
TARGET_EXT interrupt void LED_EPWM1_isr(void);     //redefined in Isr.h

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

//! \brief      Interrupt Service Routine
//! \param[in]  None
//! \param[out] None
TARGET_EXT interrupt void mySCI_TXFIFOINT_isr(void);     //redefined in Isr.h

//! \brief      Interrupt Service Routine
//! \param[in]  None
//! \param[out] None
TARGET_EXT interrupt void mySCI_RXFIFOINT_isr(void);     //redefined in Isr.h

/*-------end of API description -------------*/




#ifdef __cplusplus
}
#endif // extern "C"


#endif  // end of _USER_PIE_H_ definition

