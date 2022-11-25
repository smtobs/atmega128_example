#include "adc.h"
#include "led.h"

void init_adc()
{
    ADCSRA = 0x85;        // ADC enable, 32분주
    ADMUX = 0b01000001;  // 기준전압 = AVCC(+5V), select 채널 ADC1 
    delay_us(150);
}

int get_adc()
{
    int i, result = 0;  
    for (i = 1; i <= 4; i++)
     {
        ADCSRA = 0xD5;
        while( (ADCSRA & 0x10) == 0 );
        
       result += (int)ADCL + ((int) ADCH << 8);
       delay_ms(1);
     }
     result = result / 4; //평균 계산
     return result;
}