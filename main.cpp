#include "mbed.h"

DigitalOut led(PA_3);

int main()
{
    led.write(1);

    while (1)
    {
    }

    return 0;
}
