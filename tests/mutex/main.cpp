#include "mbed.h"
#include "MicroByteThread.h"
#include "MicroByteMutex.h"

DigitalOut led1(PA_2);
DigitalOut led2(PA_3);

MicroByteMutex _mutex;

void *thread1(void *)
{
    while (1)
    {
        led2 = !led2;
        _mutex.lock();
    }
    return nullptr;
}

int main()
{
    _mutex = MicroByteMutex();

    MicroByteThread::init(thread1, "thread1", MICROBYTE_THREAD_PRIORITY_MAIN - 1);

    MicroByteScheduler::get().yield();

    while (1)
    {
        led1 = !led1;
        _mutex.unlock();
        wait(0.2);
    }
}
