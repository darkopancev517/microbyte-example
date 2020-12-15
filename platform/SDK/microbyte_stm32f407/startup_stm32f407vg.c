#include "cmsis.h"
#include "device.h"

extern uint32_t _sfixed;
extern uint32_t _efixed;
extern uint32_t _etext;
extern uint32_t _srelocate;
extern uint32_t _erelocate;
extern uint32_t _szero;
extern uint32_t _ezero;
extern uint32_t _sstack;
extern uint32_t _estack;
extern uint8_t  _sram;
extern uint8_t  _eram;

__attribute__((used, section(".isr_stack"))) uint8_t isr_stack[DEVICE_ISR_STACK_SIZE];

__attribute__((weak)) void pre_startup(void)
{
}

__attribute__((weak)) void post_startup(void)
{
}

void dummy_handler_default()
{
    while (1);
}

void Reset_Handler()
{
    uint32_t *dst;
    uint32_t *src = &_etext;

    pre_startup();

    uint32_t *top;
    /* Fill stack space with canary values up until the current stack pointer */
    /* Read current stack pointer from CPU register */
    __asm__ volatile("mov %[top], sp" : [ top ] "=r"(top) : :);
    dst = &_sstack;
    while (dst < top)
    {
        *(dst++) = CORTEXM_STACK_CANARY_WORD;
    }

    /* load data section from flash to ram */
    for (dst = &_srelocate; dst < &_erelocate;)
    {
        *(dst++) = *(src++);
    }

    /* default bss section to zero */
    for (dst = &_szero; dst < &_ezero;)
    {
        *(dst++) = 0;
    }

    post_startup();

    SystemInit();

    NVIC_SetPriority(PendSV_IRQn, DEVICE_DEFAULT_IRQ_PRIO);
    NVIC_SetPriority(SVCall_IRQn, DEVICE_DEFAULT_IRQ_PRIO);

    for (unsigned i = 0; i < DEVICE_IRQ_NUMOF; i++)
    {
        NVIC_SetPriority((IRQn_Type)i, DEVICE_DEFAULT_IRQ_PRIO);
    }

    /* enable wake up on events for __WFE CPU sleep */
    SCB->SCR |= SCB_SCR_SEVONPEND_Msk;

    /* for Cortex-M3 r1p0 and up the STKALIGN option was added, but not automatically
     * enabled until revision r2p0. For 64bit function arguments to work properly this
     * needs to be enabled.
     */
#ifdef SCB_CCR_STKALIGN_Msk
    SCB->CCR |= SCB_CCR_STKALIGN_Msk;
#endif

    extern void __libc_init_array();
    __libc_init_array();

    extern int main();
    main();
}

__attribute__((weak, alias("dummy_handler_default"))) void NMI_Handler();
__attribute__((weak, alias("dummy_handler_default"))) void HardFault_Handler();
__attribute__((weak, alias("dummy_handler_default"))) void MemManage_Handler();
__attribute__((weak, alias("dummy_handler_default"))) void BusFault_Handler();
__attribute__((weak, alias("dummy_handler_default"))) void UsageFault_Handler();
__attribute__((weak, alias("dummy_handler_default"))) void SVC_Handler();
__attribute__((weak, alias("dummy_handler_default"))) void DebugMon_Handler();
__attribute__((weak, alias("dummy_handler_default"))) void PendSV_Handler();
__attribute__((weak, alias("dummy_handler_default"))) void SysTick_Handler();

ISR_VECTOR(0) const CortexMBaseTypeDef cortex_vector_base = {
    &_estack,
    {
    [0] = Reset_Handler,
    [1] = NMI_Handler,
    [2] = HardFault_Handler,
    [3] = MemManage_Handler,
    [4] = BusFault_Handler,
    [5] = UsageFault_Handler,
    [10] = SVC_Handler,
    [11] = DebugMon_Handler,
    [13] = PendSV_Handler,
    [14] = SysTick_Handler
    }
};
