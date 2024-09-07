/*============================================================
    <<aw_pid.c  >>     Anti-windup PID controller
------------------------------------------------------------------------------------------------------*/

#include "User_Component/myPID/aw_pid.h"

// include the header for PID data structure definition

void aw_pid_calc(AW_PID *v)
{
    float uk;
    v->Err = v->Ref - v->Fdb;
    v->Up = v->Kp * v->Err;  // Compute the proportional output
    // Compute the integral output
    if (v->kw == 0)
        v->Ui = v->Ui + v->Ki * v->Err;
    else if (v->kw == 1)
    {
        if ((v->SatErr == 0) || (v->Err * v->SatErr > 0))
            v->Ui = v->Ui + v->Ki * v->Err;
    }
    else
        v->Ui = v->Ui + v->Ki * v->Err + v->Kc * v->SatErr;
    // Compute the derivative output
    // v->Ud = v->Ud1/(v->N+1)+v->Kd*(v->Err - v->Err_1)*v->N/(v->N+1);
    v->Ud = v->Kd * (v->Err - v->Err_1);

    // Compute the pre-saturated output
    uk = v->Up + v->Ui + v->Ud;
    v->OutPreSat = uk;

    // Saturate the output
    if (v->OutPreSat > v->OutMax)
        v->Out =  v->OutMax;
    else if (v->OutPreSat < v->OutMin)
        v->Out =  v->OutMin;
    else
        v->Out = v->OutPreSat;

    // Compute the saturate difference
    v->SatErr = v->Out - v->OutPreSat;

    // Update the relevant variables
    v->Err_1 = v->Err;
    v->Ud1 =  v->Ud;
}


