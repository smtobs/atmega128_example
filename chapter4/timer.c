#include "timer.h"

void init_timer()
{
     TCCR0 = 0x00;
     TCCR0 &= ~ ((1<<WGM00) | (1<<WGM01));       //TIMER Normal
     TCCR0 |= (1<<CS00) | (1<<CS01) | (1<<CS02); // Ŭ����  1024 ����
     TCNT0 = TCNT_OFF_SET;                       // 16MHz���� 1024���ָ� 10msec ����  ���ͷ�Ʈ  �߻�
     
     TIMSK = 0x00;
     TIMSK |= (1<<OCIE0) | (1<<TOIE0);           // OCIE0 ��� ��, TOIE0 �����÷� 
}