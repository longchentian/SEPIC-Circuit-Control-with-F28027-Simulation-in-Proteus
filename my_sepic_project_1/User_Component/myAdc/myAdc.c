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
    //2. setup power  ADC�ϵ�

    ADC_powerUp(myAdc);
    ADC_enableBandGap(myAdc);
    ADC_enableRefBuffers(myAdc);
    //3. enable ADC  ADCʹ��

    ADC_enable(myAdc);
    //4. Volt ref     ���û�׼��ѹ��Դ
    ADC_setVoltRefSrc(myAdc, ADC_VoltageRefSrc_Int);
    //5. SOC          ����SOC

    ADC_setSocChanNumber(myAdc, ADC_SocNumber_0, ADC_SocChanNumber_A0);
    ADC_setSocSampleWindow(myAdc, ADC_SocNumber_0, ADC_SocSampleWindow_8_cycles);
    ADC_setSocTrigSrc(myAdc, ADC_SocNumber_0,  ADC_SocTrigSrc_Sw);
    //6. temp sensor   �ڲ��¶ȴ�����ʹ��

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
/***��λֵ�˲���***/
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
������
    Rֵ�̶���QֵԽ�󣬴���Խ���β���ֵ��Qֵ����󣬴���ֻ�ò���ֵ��
             QֵԽС������Խ����ģ��Ԥ��ֵ��QֵΪ0������ֻ��ģ��Ԥ��ֵ��
Q:����������Q���󣬶�̬��Ӧ��죬�����ȶ��Ա仵

R:����������R���󣬶�̬��Ӧ�����������ȶ��Ա��
*/
//����һ
float  KalmanFilter(float  inData)
//float  KalmanFilter(float  inData,float prevData)
{
    static float prevData = 0;                                 //��һ������
    static float p = 10, q = 0.009, r = 0.009, kGain = 0;      // q ������� r ������Ӧ�ٶ�
    p = p + q;
    kGain = p / ( p + r );                                      //���㿨��������
    inData = prevData + ( kGain * ( inData - prevData ) );      //���㱾���˲�����ֵ
    p = ( 1 - kGain ) * p;                                      //���²�������
    prevData = inData;
    return inData;                                             //���ع���ֵ
}
/*
    temp=get_ad();//�����ɼ�
    man=(float) temp;
    man=KalmanFilter(man);//�������˲�
*/
float Kalman2(void)
{
    float inData;
    unsigned int count, temp;

    float prevData = 0;                                 //��һ������
    float p = 10, q = 0.009, r = 0.009, kGain = 0;      // q ������� r ������Ӧ�ٶ�

    for( count = 0; count < M; count++ )
    {
        temp=get_ad();//�����ɼ�
        inData=(float) temp;
        p = p + q;
        kGain = p / ( p + r );                                      //���㿨��������
        inData = prevData + ( kGain * ( inData - prevData ) );      //���㱾���˲�����ֵ
        p = ( 1 - kGain ) * p;                                      //���²�������
        prevData = inData;
    }
    return inData;
}


// **************************************************************************
// the API functions

// end of file
