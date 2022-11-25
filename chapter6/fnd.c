#include "fnd.h"

                                        //0    //1    //2   //3   //4    //5   //6  //7   //8   //9   10A  11b  12c   13d    14E    15F    16N   17P   18L   19V   20Y
static const unsigned char arr_fnd[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79,  0x71,  0x54, 0x73, 0x38, 0x62, 0x66 };   
                                          
                                          //D1000  D100  D10   D1
static const unsigned char arr_digit[] = {0x0e, 0x0d, 0x0b, 0x07};

void display_fnd_number(unsigned char digit, unsigned int number)
{
    FND_DIGIT_PORT  = arr_digit[digit];        // FND 자리위치
    FND_NUMBER_PORT = arr_fnd[number];         //FND 숫자 표시
}

void init_fnd()
{
    FND_NUMBER_PORT = 0x00;  //FND TURN OFF
    FND_NUMBER_DDR  = 0xFF; //OUTPUT
                
    FND_DIGIT_PORT = 0xFF; //FND DIGIT ALL OFF
    FND_DIGIT_DDR  = 0xFF; //OUTPUT
}
    
void display_fnd(const unsigned int _data)
{
    int pos = 0;
    int i=0;
    //unsigned char data = (unsigned char)1234;  //_data;
    unsigned int data = _data;
     
    for (pos=0; pos<MAX_FND_DIGIT; pos++)
    {   
        switch (pos)
        {
           case D1000:
            display_fnd_number(D1000, data/1000);
            delay_ms(FND_DELAY);
            break;

           case D100:
            display_fnd_number(D100, data%1000/100);
            delay_ms(FND_DELAY);
            break;
     
           case D10:
            display_fnd_number(D10, data%100/10);
            delay_ms(FND_DELAY);
            break;
            
           case D1:
            display_fnd_number(D1, data%10/1);
            delay_ms(FND_DELAY);
            break;
                 
           default:
            break;
        }
    }
}