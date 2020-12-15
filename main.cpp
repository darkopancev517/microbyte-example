#include "mbed.h"

DigitalOut led(PA_3);

int main()
{
    while (1)
    {
        led = !led;
        wait(0.2);
    }

    return 0;
}
