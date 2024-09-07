
// **************************************************************************
// the includes
#include "Application/app.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"

// **************************************************************************
// the defines

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



TARGET_EXT float control_uk;

#if defined(PID1)
    AW_PID pid = AW_PID_DEFAULTS;
#elif defined(PID2)
    SP_PID pid = SP_PID_DEFAULTS;
#elif defined(PID3)
    EH_PID pid = EH_PID_DEFAULTS;
#endif
// **************************************************************************
// the globals
void PID_init(void)
{



    ///*PID参数初始化*
 #if defined(PID1)
    /*抗饱和PID初始化*/
     pid.Kp = 10.4597502;
     pid.Ki = 5.0053997;
     pid.Kd = 8.59500027;
     pid.kw = 0;
     pid.Kc = 0;
     pid.Ts = Ts;
     pid.N = 20;
     pid.OutMax = 3750;
     pid.OutMin =  250;

     pid.SatErr = 0.005;
     pid.Ref=VoltageRef1;

 #elif defined(PID2)
     /*增量式PID初始化*/
     pid.Kp = 0.459750444;
     pid.Ki = 0.00539999164;
     pid.Kd = 0.595000153;

     pid.Kp = 5.4597502;
     pid.Ki = 1.053997;
     pid.Kd = 4.59500027;

     pid.Ts = Ts;
 //    pid.OutMax = 11;
 //    pid.OutMin =  1;

     pid.OutMax = 5750;
     pid.OutMin =  250;
     pid.Ref = VoltageRef2;


     pid.init(&pid);

 #elif defined(PID3)
     /*专家PID初始化*/
     pid.Kp = 0.0459750444;
     pid.Ki = 0.000539999164;
     pid.Kd = 0.00595000153;
     pid.Ts = Ts;

     pid.Kp = 15.4597502;
     pid.Ki = 5.053997;
     pid.Kd = 8.59500027;

     pid.OutMax = 5750;
     pid.OutMin =  250;
     pid.Ref = VoltageRef2;



 #endif

     int rule_base[][qf_default] = {
             //delta kp rule base
             {PB, PB, PM, PM, PS, ZO, ZO},
             {PB, PB, PM, PS, PS, ZO, NS},
             {PM, PM, PM, PS, ZO, NS, NS},
             {PM, PM, PS, ZO, NS, NM, NM},
             {PS, PS, ZO, NS, NS, NM, NM},
             {PS, ZO, NS, NM, NM, NM, NB},
             {ZO, ZO, NM, NM, NM, NB, NB},
             //delta ki rule base
             {NB, NB, NM, NM, NS, ZO, ZO},
             {NB, NB, NM, NS, NS, ZO, ZO},
             {NB, NM, NS, NS, ZO, PS, PS},
             {NM, NM, NS, ZO, PS, PM, PM},
             {NM, NS, ZO, PS, PS, PM, PB},
             {ZO, ZO, PS, PS, PM, PB, PB},
             {ZO, ZO, PS, PM, PM, PB, PB},
             //delta kd rule base
             {PS, NS, NB, NB, NB, NM, PS},
             {PS, NS, NB, NM, NM, NS, ZO},
             {ZO, NS, NM, NM, NS, NS, ZO},
             {ZO, NS, NS, NS, NS, NS, ZO},
             {ZO, ZO, ZO, ZO, ZO, ZO, ZO},
             {PB, PS, PS, PS, PS, PS, PB},
             {PB, PM, PM, PM, PS, PS, PB}};

     // Default parameters of membership function
     int mf_params[4 * qf_default] = {-3, -3, -2, 0,
                                      -3, -2, -1, 0,
                                      -2, -1,  0, 0,
                                      -1,  0,  1, 0,
                                       0,  1,  2, 0,
                                       1,  2,  3, 0,
                                       2,  3,  3, 0};

     float fuzzy_pid_params[1][pid_params_count] = {{10.4597502f,  5.0053997f,    8.59500027,    0, 0, 0, 1}};

     struct PID **subpid_vector = fuzzy_pid_vector_init(fuzzy_pid_params, 2.0f, 4, 1, 0, mf_params, rule_base, 1);

     pid_vector=subpid_vector;
}

interrupt void myTimer_CpuTimer0_isr(void)     //redefined in Isr.h
{

    timer0base++;

    Isr_count++;

//      temp=get_ad();//正常采集
//      man=(float) temp;
//      man=KalmanFilter(man);//卡尔曼滤波
//      man=man*3.3f/13107;

    temp=filter2();//中值滤波
//    man = temp*3.3f*17/4096;
    man = temp*3.3f*17/4096;

//    man = (1.786f-(float)temp/4096.0f*3.3f)*17;


    real_val = (int)(man*1000);


    #ifdef FUZZYPID
        control_uk = fuzzy_pid_motor_pwd_output(man, pid.Ref, true, pid_vector[0]);
        if(control_uk<250)
            control_uk=250;
        else if (control_uk>3750)
            control_uk=3750;

    #else
        pid.Fdb = man;
        pid.calc(&pid);
        control_uk = pid.Out;
    #endif

        duty_val = (int)control_uk;


        PWM_setCmpA(myPwm1, duty_val);


        if(Isr_count>=Ref_scaler)
       {
           Isr_count=0;
           GPIO_toggle(LED_Gpio_obj,LED4);

            if(pid.Ref==VoltageRef2)
            {

                pid.Ref=VoltageRef1;   // 电压给定 轮换
                #if defined(PID2)
                    pid.init(&pid);
                #endif


            }
            else
            {
                pid.Ref=VoltageRef2;
                #if defined(PID2)
                    pid.init(&pid);
                #endif
            }

       }
//    if( timer0base>=300)
//    {
//        timer0base=0;
//        PWM_setCmpA(myPwm1,duty_val);
//        duty_val+=500;
//        if(duty_val>5500)
//            duty_val = 1000;
//
//    }

    // Acknowledge this interrupt to get more from group 1
    PIE_clearInt(myPie, PIE_GroupNumber_1);

}
