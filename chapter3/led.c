#include "led.h"

void init_led()
{
    LED_PORT = LED_ALL_TURN_OFF;
    LED_DDR  = 0xFF; // LED PORT ������ ���� ���
}

void led_turn_on(unsigned char on)
{
    LED_PORT = on;
}