//#############################################################################
//
//! \file  Application\Isr.c
//!
//! \brief  Interrupt Service Routine
//
//  Author:
//  Group:          C2000
//  Target Device:  TMS320F2802x
//
//  (C) Copyright 2014, Texas Instruments, Inc.
//#############################################################################
// $TI Release: f2802x Support Library v210 $
// $Release Date: Mon Sep 17 09:13:31 CDT 2012 $
//#############################################################################

// **************************************************************************
// the includes
#include "Application/isr.h"

#include <stdint.h>
// **************************************************************************
// the defines


// **************************************************************************
// the globals


extern  float VoltageRef1;
extern float VoltageRef2;
extern float Ts;
extern int target_val;
extern int real_val;
extern uint16_t Ref_scaler;
extern uint16_t Isr_count;
extern uint16_t temp;
extern float man;
extern float val;
extern uint16_t duty_val;

extern float control_uk;

#if defined(PID1)
    extern  AW_PID pid;
#elif defined(PID2)
    extern  SP_PID pid ;
#elif defined(PID3)
    extern  EH_PID pid;

#endif

// **************************************************************************
// the functions


interrupt void KEY_XINT1_isr(void)     //redefined in Isr.h
{


    if(GPIO_getData(myGpio, GPIO_Number_12)==0)
        keycount++;

    if (keycount>=3)
    keycount=0;
    PIE_clearInt(myPie, PIE_GroupNumber_1);

}

//! \brief     Interrupt Service Routine
//! \param[in] None
//! \param[out] None

//! \brief     Interrupt Service Routine
//! \param[in] None
//! \param[out] None
interrupt void LED_EPWM1_isr(void)     //redefined in Isr.h
{
//
    PIE_clearInt(myPie, PIE_GroupNumber_3);
}


// end of file
