#include "mbed.h"
#include "MicroByteDevice.h"
#include "MicroByteThread.h"

extern "C" void mbed_main(void);
extern int main(void);

void *threadIdle(void *)
{
    while (1)
    {
        microbyte_sleep(0);
    }
    return nullptr;
}

void *threadMain(void *)
{
    mbed_main();
    main();
    while (1)
    {
        // should not reach here
    }
    return nullptr;
}

extern "C" void microbyte_rtos_init(void)
{
    (void) microbyte_disable_irq();
    (void) MicroByteScheduler::init();
    MicroByteThread::init(threadMain, "main");
    MicroByteThread::init(threadIdle, "idle", MICROBYTE_THREAD_PRIORITY_IDLE);
    microbyte_context_exit();
}
