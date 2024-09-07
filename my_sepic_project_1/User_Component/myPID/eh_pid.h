/*
 * eh_pid.h
 *
 *  Created on: 2021年10月10日
 *      Author: longchentian
 */

#ifndef EH_PID_H_
#define EH_PID_H_

#include "F2802x_Component/F2802x_Device.h"

typedef  struct
{
    float  Ref;           // 输入：参考输入  Input: Reference input
    float  Fdb;           // 输入：反馈输入  Input: Feedback input、
    float  Err;            //变量：误差信号e(k)
    float  Err_1;          // 变量：误差信号e(k-1)   Variable: Error
    float  Err_2;          // 变量：误差信号e(k-2)   Variable: Error
    float  umax;          // 参数：控制量的饱和限幅值
    float  Ts;            // 控制周期

    float  Kp;            // 参数：比例增益  Parameter: Proportional gain
    float  Ki;            // 参数：积分增益 Parameter: Integral gain
    float  Kd;            // 参数：微分增益Parameter: Derivative gain


    float  OutPreSat;     // 变量：饱和输出  Variable: Pre-saturated output
    float  OutMax;        // 参数：最大输出  Parameter: Maximum output
    float  OutMin;        // 参数：最小输出  Parameter: Minimum output
    float  Out;           // 输出：SP_PID输出  Output: SP_PID output


    void (*calc)();         // 计算函数指针  Pointer to calculation function
} EH_PID;
typedef   EH_PID  *EH_PID_handle;


/*-----------------------------------------------------------------------------
  默认初始化   Default initalizer for the AW_PID object.
-----------------------------------------------------------------------------*/
#define  EH_PID_DEFAULTS { 0, 0, 0, 0, 0, 0, 0,\
                           0, 0, 0, \
                           0, 0, 0, 0, \
                    (void (*)(unsigned long)) eh_pid_calc }

void eh_pid_calc(EH_PID_handle);

#endif /* EH_PID_H_ */
