#include <mega128.h>
#include <delay.h>
#include "adc.h"
#include "led.h"
#include "fnd.h"
#include "timer.h"

#define VARIALBLE_PORT    PORTF
#define VARIALBLE_DDR     DDRF

unsigned char g_led=0x01;

unsigned int tcnt = 0;

#if (0)
interrupt [TIM0_OVF] void timer0_ovf_isr(void)
{
    TCNT0 = TCNT_OFF_SET;                     // couter reload
    static int tcnt = 0;                       // 인터럽트  발생  횟수  카운트  증가 
    
    tcnt++;
    if (tcnt >= 100)                          // 1000mSec? 
    { 
      led_turn_on(g_led);
              
      if (g_led == 0x80)
      {
         g_led = 0x01;
      }
      else
      {
        g_led <<= 1;
      }     
      tcnt = 0;
    }
}
#else
interrupt [TIM0_OVF] void timer0_ovf_isr(void)
{
    TCNT0 = TCNT_OFF_SET;
    //static unsigned int tcnt = 0;
    tcnt++;                        
    
    if (tcnt > 959)
    {
        tcnt = 0;
    }
    
}
#endif

void init_variable_sensor()
{
   VARIALBLE_PORT = 0x00;
   VARIALBLE_DDR  = 0x00;
}

void initial(void)
{
   SREG = 0x00;
    
   init_led();
   
   init_fnd();

   init_variable_sensor();
   
   init_adc();
   
   init_timer();
   
   SREG = 0x80;
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
    unsigned int adc_result=0;
    
    adc_result = (unsigned)get_adc();
    display_fnd(adc_result);
}

void example_fnd_1()
{ 
    volatile int show=0;
    //static unsigned int number = 0;
    
    for (show=0; show<9999; show++)
    {
        display_fnd(show);
    }  
}

void example_timer_2()
{
   while (1)
   {
   } 
}
void example_timer_3()
{
   while (1)
   {
    display_fnd(tcnt);
   } 
}

void main(void)
{  
    initial();
    
    while (1)
    {   
       example_timer_3();   
    }
}
