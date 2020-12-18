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
    return NULL;
}

void *threadMain(void *)
{
    mbed_main();
    main();
    while (1)
    {
        // should not reach here
    }
    return NULL;
}

char threadMainStack[0x400];
char threadIdleStack[0x400];

extern "C"
void microbyte_rtos_init(void)
{
    (void) microbyte_disable_irq();

    (void) MicroByteScheduler::init();

    MicroByteThread::init(threadMainStack, sizeof(threadMainStack),
            MICROBYTE_THREAD_PRIORITY_MAIN,
            MICROBYTE_THREAD_FLAGS_WOUT_YIELD | MICROBYTE_THREAD_FLAGS_STACKMARKER,
            threadMain, NULL, "main");

    MicroByteThread::init(threadIdleStack, sizeof(threadIdleStack),
            MICROBYTE_THREAD_PRIORITY_IDLE,
            MICROBYTE_THREAD_FLAGS_WOUT_YIELD | MICROBYTE_THREAD_FLAGS_STACKMARKER,
            threadIdle, NULL, "idle");

    microbyte_context_exit();
}
