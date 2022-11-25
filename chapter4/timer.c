#include "timer.h"

void init_timer()
{
     TCCR0 = 0x00;
     TCCR0 &= ~ ((1<<WGM00) | (1<<WGM01));       //TIMER Normal
     TCCR0 |= (1<<CS00) | (1<<CS01) | (1<<CS02); // 클럭을  1024 분주
     TCNT0 = TCNT_OFF_SET;                       // 16MHz에서 1024분주면 10msec 마다  인터럽트  발생
     
     TIMSK = 0x00;
     TIMSK |= (1<<OCIE0) | (1<<TOIE0);           // OCIE0 출력 비교, TOIE0 오버플로 
}