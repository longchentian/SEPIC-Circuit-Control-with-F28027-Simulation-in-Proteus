


#include "User_Component/myPID/eh_pid.h"

// include the header for PID data structure definition


void eh_pid_calc(EH_PID *v)
{

    float Delta_Err;                  //e(k)-e(k-1)
    float Last_Delta_Err;             //e(k-1)-e(k-2)
    float uk;                         //本次调节输出值

    v->Err = v->Ref - v->Fdb;
    Delta_Err = v->Err - v->Err_1;
    Last_Delta_Err = v->Err_1 - v->Err_2;

    uk = v->Out + v->Kp * Delta_Err + v->Ki * v->Err + v->Kd * (Delta_Err - Last_Delta_Err);

    v->OutPreSat = uk;
    // Saturate the output
    if (v->OutPreSat > v->OutMax)
        v->Out =  v->OutMax;
    else if (v->OutPreSat < v->OutMin)
        v->Out =  v->OutMin;
    else
        v->Out = v->OutPreSat;

    v->Err_2 = v->Err_1;
    v->Err_1 = v->Err ;

}


