#include "mbed.h"
#include "MicroByteDevice.h"
#include "MicroByteThread.h"

char threadMainStack[0x400];
char threadIdleStack[0x400];

extern "C" void mbed_main(void);
extern int main(void);

void *threadIdleHandler(void *)
{
    while (1)
    {
        microbyte_sleep(0);
    }
    return nullptr;
}

void *threadMainHandler(void *)
{
    mbed_main();
    main();
    while (1)
    {
        // should not reach here
    }
    return nullptr;
}

extern "C"
void microbyte_rtos_init(void)
{
    (void) microbyte_disable_irq();
    (void) MicroByteScheduler::init();
    MicroByteThread::init(threadMainStack, sizeof(threadMainStack), threadMainHandler, "main");
    MicroByteThread::init(threadIdleStack, sizeof(threadIdleStack), threadIdleHandler, "idle", MICROBYTE_THREAD_PRIORITY_IDLE);
    microbyte_context_exit();
}
