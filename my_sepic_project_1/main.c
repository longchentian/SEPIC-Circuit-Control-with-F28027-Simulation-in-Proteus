#define TARGET_GLOBAL 1
#include "Application\app.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"


float VoltageRef1 = 24;
float VoltageRef2 = 7.5;
float Ts = 0.001;
int target_val;
int real_val;
uint16_t Ref_scaler = 300;
uint16_t Isr_count=0;
uint16_t temp;
float man;
float val;
uint16_t duty_val =1000;

float control_uk;


void main(void)
{
    //1. System runtime environment
    User_System_init();
    //2. Module
    //2.1 motor
    myPwm1_init(6000);
    //2.2 timer0
    myTimer0_init(60000);
    //2.3
    myKey_init();
    //2.4
    PID_init();
    //2.10
    myAdc_init();
    //2.11
    LED_GPIO_initial();


    //3. PIE runtime environment(if use interrupt)
    User_Pie_init();
    //4. the global interrupt start (if use interrupt)
    User_Pie_start();
    //5. main LOOP

    for( ; ; )
    {




    }

}



