#ifndef _LED_
#define _LED_

#include <mega128.h>
#include <delay.h>

#define LED1 0x01
#define LED2 0x02
#define LED3 0x04

#define LED_PORT    PORTB   // LED ��Ʈ
#define LED_DDR     DDRB    // LED DDR

#if (1) //�ֳ�忡 High ��ȣ�� �ָ� ������ ȸ��
 #define LED_ALL_TURN_ON   0xFF
 #define LED_ALL_TURN_OFF  0x00
#else
 #define LED_ALL_TURN_ON   0x00
 #define LED_ALL_TURN_OFF  0xFF
#endif

void init_led();
void led_turn_on(unsigned char);

#endif
