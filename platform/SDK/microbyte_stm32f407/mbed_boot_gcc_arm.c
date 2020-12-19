#include "cmsis.h"

#ifndef STACK_CANARY_WORD
#define STACK_CANARY_WORD (0xE7FEE7FEu)
#endif

extern uint32_t __StackLimit;
extern uint32_t __StackTop;
extern uint32_t __end__;
extern uint32_t __HeapLimit;

unsigned char *mbed_heap_start;
uint32_t mbed_heap_size;

unsigned char *mbed_stack_isr_start;
uint32_t mbed_stack_isr_size;

extern void __libc_init_array(void);
extern void mbed_sdk_init(void);
extern void microbyte_rtos_init(void);

void software_init_hook(void)
{
    __libc_init_array();

    mbed_stack_isr_start = (unsigned char *) &__StackLimit;
    mbed_stack_isr_size = (uint32_t) &__StackTop - (uint32_t) &__StackLimit;
    mbed_heap_start = (unsigned char *) &__end__;
    mbed_heap_size = (uint32_t) &__HeapLimit - (uint32_t) &__end__;

    uint32_t *top;
    /* Fill stack space with canary values up until the current stack pointer */
    /* Read current stack pointer from CPU register */
    __asm__ volatile ("mov %[top], sp" : [top] "=r" (top) : : );
    uint32_t *dst = &__StackLimit;
    while (dst < top)
    {
        *(dst++) = STACK_CANARY_WORD;
    }

    mbed_sdk_init();
    microbyte_rtos_init();
}
