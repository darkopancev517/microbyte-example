#include "mbed.h"
#include "MicroByteThread.h"
#include "MicroByteMutex.h"

DigitalOut led1(PA_2);
DigitalOut led2(PA_3);

char thread1Stack[0x400];
MicroByteMutex _mutex;

void *thread1(void *)
{
    while (1)
    {
        led2 = !led2;
        _mutex.lock();
    }
    return NULL;
}

int main()
{
    _mutex = MicroByteMutex(MICROBYTE_MUTEX_LOCKED);

    MicroByteThread::init(thread1Stack, sizeof(thread1Stack),
            MICROBYTE_THREAD_PRIORITY_MAIN - 1,
            MICROBYTE_THREAD_FLAGS_WOUT_YIELD | MICROBYTE_THREAD_FLAGS_STACKMARKER,
            thread1, NULL, "thread1");

    MicroByteScheduler::get().yield();

    while (1)
    {
        led1 = !led1;
        _mutex.unlock();
        wait(0.2);
    }
}
