#include <mega128.h>
#include <delay.h>

void main(void)
{
    unsigned char i;
    unsigned char flag = 0;
    DDRD = 0xff;
    
    while (1)
    {
        for (i=0; i<8; i++)
        {                 
            //0101 0101 LED ON
            if (flag == 0)
            {
                if (i%2 == 0)
                {
                    PORTD |= 1<<i;
                    delay_ms(500);
                }
            }
            //1010 1010 LED ON
            else                   
            {
                if (i%2 != 0)
                {
                    PORTD |= 1<<i;
                    delay_ms(500);
                }
            }
        }
        PORTD = 0x00;
        flag = ~flag;
    }
}