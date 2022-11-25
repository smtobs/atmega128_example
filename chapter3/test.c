#include <mega128.h>
#include <delay.h>
#include "adc.h"
#include "led.h"
#include "fnd.h"

#define VARIALBLE_PORT    PORTF
#define VARIALBLE_DDR     DDRF

void init_variable_sensor()
{
   VARIALBLE_PORT = 0x00;
   VARIALBLE_DDR  = 0x00;
}

void initial(void)
{
   init_led();
   
   init_fnd();

   init_variable_sensor();
   
   init_adc();
}


// 실습1 ADC 값에 따라 LED를 TURN ON하는 예제
void example_adc_1()
{
    unsigned int adc_result=0;

    adc_result = (unsigned)get_adc();
    
    if ((adc_result > 400 ) && (adc_result < 800))
    {
       led_turn_on(LED2);
    }
    else if (adc_result <= 400)
    {
        led_turn_on(LED1);
    }
    else if (adc_result >= 800)
    {
        led_turn_on(LED3);
    }
}


void example_adc_2()
{
}


void example_fnd_1()
{ 
    volatile int show=0;
    static unsigned int number = 0;
    
    for (show=0; show<9999; show++)
    {
        display_fnd(show);
    }  
    
}

void  main(void)
{  
    initial();
    
    while (1)
    {   
        example_fnd_1();   
    }
}
