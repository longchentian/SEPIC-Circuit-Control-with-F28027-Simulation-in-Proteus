#include "myKey.h"


void myKey_init(void)
{
    /******************************************pinConfigure******************************************/
    // 1. set mode

    GPIO_setMode(myGpio, key_pin, key_pin_mode);
    // 2. set pullup

    GPIO_setPullUp(myGpio, key_pin, GPIO_PullUp_Disable);
    //3. set direction

    GPIO_setDirection(myGpio, key_pin, GPIO_Direction_Input);
    //4. set Qualification

    GPIO_setQualification(myGpio, key_pin, GPIO_Qual_ASync);
    /*********************************************-----end------***************************************/
    /******************************************eventConfigure******************************************/
    // 1. set Int Polarity
    PIE_setExtIntPolarity(myPie, CPU_ExtIntNumber_1, PIE_ExtIntPolarity_FallingEdge);
    // 2. set Ext Int
    GPIO_setExtInt(myGpio, key_pin, CPU_ExtIntNumber_1);

    keycount=0;


}


