#ifndef _FND_
#define _FND_

#include <mega128.h>
#include <delay.h>

#define D1000            0
#define D100             1
#define D10              2
#define D1               3

#define MAX_FND_DIGIT    4
#define FND_DELAY        5

#define FND_DIGIT_PORT   PORTC
#define FND_DIGIT_DDR    DDRC

#define FND_NUMBER_PORT  PORTA
#define FND_NUMBER_DDR   DDRA

void init_fnd();
void display_fnd(const unsigned int);

#endif