#include "adc.h"
#include "led.h"

void init_adc()
{
    ADCSRA = 0x85;        // ADC enable, 32����
    ADMUX = 0b01000001;  // �������� = AVCC(+5V), select ä�� ADC1 
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
     result = result / 4; //��� ���
     return result;
}