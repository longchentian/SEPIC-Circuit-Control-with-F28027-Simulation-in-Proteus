// **************************************************************************
// the includes
#include <User_Component/myAdc/myAdc.h>


// **************************************************************************
// the defines


// **************************************************************************
// the globals


// **************************************************************************
void myAdc_init(void)
{


	/**********************************functionConfigure*************************************/
    //2. setup power  ADC上电

    ADC_powerUp(myAdc);
    ADC_enableBandGap(myAdc);
    ADC_enableRefBuffers(myAdc);
    //3. enable ADC  ADC使能

    ADC_enable(myAdc);
    //4. Volt ref     设置基准电压来源
    ADC_setVoltRefSrc(myAdc, ADC_VoltageRefSrc_Int);
    //5. SOC          设置SOC

    ADC_setSocChanNumber(myAdc, ADC_SocNumber_0, ADC_SocChanNumber_A0);
    ADC_setSocSampleWindow(myAdc, ADC_SocNumber_0, ADC_SocSampleWindow_8_cycles);
    ADC_setSocTrigSrc(myAdc, ADC_SocNumber_0,  ADC_SocTrigSrc_Sw);
    //6. temp sensor   内部温度传感器使能

    //ADC_enableTempSensor(myAdc);




    /*********************************************end*********************************************/
    /****************************************eventConfigure***************************************/
    //1. int Configure
//    ADC_setIntMode(myAdc, ADC_IntNumber_1, ADC_IntMode_EOC);
//    ADC_setIntPulseGenMode(myAdc, ADC_IntPulseGenMode_Prior);
//    ADC_setIntSrc(myAdc, ADC_IntNumber_1, ADC_IntSrc_EOC0);

}

uint16_t get_ad(void)
{
    uint16_t temp;
    ADC_forceConversion(myAdc, ADC_SocNumber_0);
    temp = ADC_readResult(myAdc, ADC_ResultNumber_0);
    return temp;
}

#define M  7
/***中位值滤波法***/
unsigned int filter2( void )
{
    unsigned int value_buf[M];
    unsigned int count, i, j, temp;
    for( count = 0; count < M; count++ )
    {
        value_buf[count] = get_ad();
    }
    for( j = 0; j < M - 1; j++ )
    {
        for( i = 0; i < M - j - 1; i++ )
        {
            if( value_buf[i] > value_buf[i + 1] )
            {
                temp = value_buf[i];
                value_buf[i] = value_buf[i + 1];
                value_buf[i + 1] = temp;
            }
        }
    }
    return value_buf[( M - 1 ) / 2];
}


/*
卡尔曼
    R值固定，Q值越大，代表越信任测量值，Q值无穷大，代表只用测量值。
             Q值越小，代表越信任模型预测值，Q值为0，代表只用模型预测值。
Q:过程噪声，Q增大，动态响应变快，收敛稳定性变坏

R:测量噪声，R增大，动态响应变慢，收敛稳定性变好
*/
//参数一
float  KalmanFilter(float  inData)
//float  KalmanFilter(float  inData,float prevData)
{
    static float prevData = 0;                                 //上一个数据
    static float p = 10, q = 0.009, r = 0.009, kGain = 0;      // q 控制误差 r 控制响应速度
    p = p + q;
    kGain = p / ( p + r );                                      //计算卡尔曼增益
    inData = prevData + ( kGain * ( inData - prevData ) );      //计算本次滤波估计值
    p = ( 1 - kGain ) * p;                                      //更新测量方差
    prevData = inData;
    return inData;                                             //返回估计值
}
/*
    temp=get_ad();//正常采集
    man=(float) temp;
    man=KalmanFilter(man);//卡尔曼滤波
*/
float Kalman2(void)
{
    float inData;
    unsigned int count, temp;

    float prevData = 0;                                 //上一个数据
    float p = 10, q = 0.009, r = 0.009, kGain = 0;      // q 控制误差 r 控制响应速度

    for( count = 0; count < M; count++ )
    {
        temp=get_ad();//正常采集
        inData=(float) temp;
        p = p + q;
        kGain = p / ( p + r );                                      //计算卡尔曼增益
        inData = prevData + ( kGain * ( inData - prevData ) );      //计算本次滤波估计值
        p = ( 1 - kGain ) * p;                                      //更新测量方差
        prevData = inData;
    }
    return inData;
}


// **************************************************************************
// the API functions

// end of file
