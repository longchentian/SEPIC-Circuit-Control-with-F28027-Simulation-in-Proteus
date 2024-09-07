/*
 * AW_PID.h
 *
 *  Created on: 2021年9月29日
 *      Author: longchentian
 */

#ifndef INCLUDE_AW_PID_H_
#define INCLUDE_AW_PID_H_
#include "F2802x_Component/F2802x_Device.h"

typedef  struct
{
    float  Ref;           // 输入：参考输入  Input: Reference input
    float  Fdb;           // 输入：反馈输入  Input: Feedback input
    float  Err;           // 变量：误差信号e(k)
    float  Err_1;          // 变量：误差信号e(k-1)   Variable: Error
    float  umax;          // 参数：控制量的饱和限幅值
    float  Ts;            // 控制周期

    float  kw;            // 参数：抗饱和方案：0 （无）；1（条件积分）；2（反馈抑制）
    float  Kp;            // 参数：比例增益  Parameter: Proportional gain
    float  Ki;            // 参数：积分增益 Parameter: Integral gain
    float  Kc;            // 参数：积分修正增益 Parameter: Integral correction gain
    float  Kd;            // 参数：微分增益Parameter: Derivative gain

    float  Up;            // 变量：比例输出  Variable: Proportional output
    float  Ui;            // 变量：积分输出  Variable: Integral output
    float  Ud;            // 变量：微分输出  Variable: Derivative output
    float  Ud1;           // 变量：微分输出(k-1)  Variable: Derivative output
    float  N;             // 变量：低通滤波参数

    float  OutPreSat;     // 变量：饱和输出  Variable: Pre-saturated output
    float  OutMax;        // 参数：最大输出  Parameter: Maximum output
    float  OutMin;        // 参数：最小输出  Parameter: Minimum output
    float  Out;           // 输出：AW_PID输出  Output: AW_PID output
    float  SatErr;        // 变量：饱和差值 Variable: Saturated difference
    void (*calc)();         // 计算函数指针  Pointer to calculation function
} AW_PID;
typedef   AW_PID  *AW_PID_handle;
/*-----------------------------------------------------------------------------
  默认初始化   Default initalizer for the AW_PID object.
-----------------------------------------------------------------------------*/
#define  AW_PID_DEFAULTS { 0, 0, 0, 0, 0, 0, \
                           0, 0, 0, 0, 0, \
                           0, 0, 0, 0, 10, \
                           0, 0, 0, 0, 0, \
                    (void (*)(unsigned long)) aw_pid_calc }
/*------------------------------------------------------------------------------
  函数原型   Prototypes for the functions in  <AW_PID.c>
------------------------------------------------------------------------------*/
void aw_pid_calc(AW_PID_handle);


#endif /* INCLUDE_AW_PID_H_ */
