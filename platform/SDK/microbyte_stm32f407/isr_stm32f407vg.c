#include "mbed.h"

void dummy_handler()
{
    dummy_handler_default();
}

WEAK_DEFAULT void WWDG_IRQHandler();                /* Window WatchDog              */
WEAK_DEFAULT void PVD_IRQHandler();                 /* PVD through EXTI Line detection */
WEAK_DEFAULT void TAMP_STAMP_IRQHandler();          /* Tamper and TimeStamps through the EXTI line */
WEAK_DEFAULT void RTC_WKUP_IRQHandler();            /* RTC Wakeup through the EXTI line */
WEAK_DEFAULT void FLASH_IRQHandler();               /* FLASH                        */
WEAK_DEFAULT void RCC_IRQHandler();                 /* RCC                          */
WEAK_DEFAULT void EXTI0_IRQHandler();               /* EXTI Line0                   */
WEAK_DEFAULT void EXTI1_IRQHandler();               /* EXTI Line1                   */
WEAK_DEFAULT void EXTI2_IRQHandler();               /* EXTI Line2                   */
WEAK_DEFAULT void EXTI3_IRQHandler();               /* EXTI Line3                   */
WEAK_DEFAULT void EXTI4_IRQHandler();               /* EXTI Line4                   */
WEAK_DEFAULT void DMA1_Stream0_IRQHandler();        /* DMA1 Stream 0                */
WEAK_DEFAULT void DMA1_Stream1_IRQHandler();        /* DMA1 Stream 1                */
WEAK_DEFAULT void DMA1_Stream2_IRQHandler();        /* DMA1 Stream 2                */
WEAK_DEFAULT void DMA1_Stream3_IRQHandler();        /* DMA1 Stream 3                */
WEAK_DEFAULT void DMA1_Stream4_IRQHandler();        /* DMA1 Stream 4                */
WEAK_DEFAULT void DMA1_Stream5_IRQHandler();        /* DMA1 Stream 5                */
WEAK_DEFAULT void DMA1_Stream6_IRQHandler();        /* DMA1 Stream 6                */
WEAK_DEFAULT void ADC_IRQHandler();                 /* ADC1, ADC2 and ADC3s         */
WEAK_DEFAULT void CAN1_TX_IRQHandler();             /* CAN1 TX                      */
WEAK_DEFAULT void CAN1_RX0_IRQHandler();            /* CAN1 RX0                     */
WEAK_DEFAULT void CAN1_RX1_IRQHandler();            /* CAN1 RX1                     */
WEAK_DEFAULT void CAN1_SCE_IRQHandler();            /* CAN1 SCE                     */
WEAK_DEFAULT void EXTI9_5_IRQHandler();             /* External Line[9:5]s          */
WEAK_DEFAULT void TIM1_BRK_TIM9_IRQHandler();       /* TIM1 Break and TIM9          */
WEAK_DEFAULT void TIM1_UP_TIM10_IRQHandler();       /* TIM1 Update and TIM10        */
WEAK_DEFAULT void TIM1_TRG_COM_TIM11_IRQHandler();  /* TIM1 Trigger and Commutation and TIM11 */
WEAK_DEFAULT void TIM1_CC_IRQHandler();             /* TIM1 Capture Compare         */
WEAK_DEFAULT void TIM2_IRQHandler();                /* TIM2                         */
WEAK_DEFAULT void TIM3_IRQHandler();                /* TIM3                         */
WEAK_DEFAULT void TIM4_IRQHandler();                /* TIM4                         */
WEAK_DEFAULT void I2C1_EV_IRQHandler();             /* I2C1 Event                   */
WEAK_DEFAULT void I2C1_ER_IRQHandler();             /* I2C1 Error                   */
WEAK_DEFAULT void I2C2_EV_IRQHandler();             /* I2C2 Event                   */
WEAK_DEFAULT void I2C2_ER_IRQHandler();             /* I2C2 Error                   */
WEAK_DEFAULT void SPI1_IRQHandler();                /* SPI1                         */
WEAK_DEFAULT void SPI2_IRQHandler();                /* SPI2                         */
WEAK_DEFAULT void USART1_IRQHandler();              /* USART1                       */
WEAK_DEFAULT void USART2_IRQHandler();              /* USART2                       */
WEAK_DEFAULT void USART3_IRQHandler();              /* USART3                       */
WEAK_DEFAULT void EXTI15_10_IRQHandler();           /* External Line[15:10]s        */
WEAK_DEFAULT void RTC_Alarm_IRQHandler();           /* RTC Alarm (A and B) through EXTI Line */
WEAK_DEFAULT void OTG_FS_WKUP_IRQHandler();         /* USB OTG FS Wakeup through EXTI line */
WEAK_DEFAULT void TIM8_BRK_TIM12_IRQHandler();      /* TIM8 Break and TIM12         */
WEAK_DEFAULT void TIM8_UP_TIM13_IRQHandler();       /* TIM8 Update and TIM13        */
WEAK_DEFAULT void TIM8_TRG_COM_TIM14_IRQHandler();  /* TIM8 Trigger and Commutation and TIM14 */
WEAK_DEFAULT void TIM8_CC_IRQHandler();             /* TIM8 Capture Compare         */
WEAK_DEFAULT void DMA1_Stream7_IRQHandler();        /* DMA1 Stream7                 */
WEAK_DEFAULT void FSMC_IRQHandler();                /* FSMC                         */
WEAK_DEFAULT void SDIO_IRQHandler();                /* SDIO                         */
WEAK_DEFAULT void TIM5_IRQHandler();                /* TIM5                         */
WEAK_DEFAULT void SPI3_IRQHandler();                /* SPI3                         */
WEAK_DEFAULT void UART4_IRQHandler();               /* UART4                        */
WEAK_DEFAULT void UART5_IRQHandler();               /* UART5                        */
WEAK_DEFAULT void TIM6_DAC_IRQHandler();            /* TIM6 and DAC1&2 underrun errors */
WEAK_DEFAULT void TIM7_IRQHandler();                /* TIM7                         */
WEAK_DEFAULT void DMA2_Stream0_IRQHandler();        /* DMA2 Stream 0                */
WEAK_DEFAULT void DMA2_Stream1_IRQHandler();        /* DMA2 Stream 1                */
WEAK_DEFAULT void DMA2_Stream2_IRQHandler();        /* DMA2 Stream 2                */
WEAK_DEFAULT void DMA2_Stream3_IRQHandler();        /* DMA2 Stream 3                */
WEAK_DEFAULT void DMA2_Stream4_IRQHandler();        /* DMA2 Stream 4                */
WEAK_DEFAULT void ETH_IRQHandler();                 /* Ethernet                     */
WEAK_DEFAULT void ETH_WKUP_IRQHandler();            /* Ethernet Wakeup through EXTI line */
WEAK_DEFAULT void CAN2_TX_IRQHandler();             /* CAN2 TX                      */
WEAK_DEFAULT void CAN2_RX0_IRQHandler();            /* CAN2 RX0                     */
WEAK_DEFAULT void CAN2_RX1_IRQHandler();            /* CAN2 RX1                     */
WEAK_DEFAULT void CAN2_SCE_IRQHandler();            /* CAN2 SCE                     */
WEAK_DEFAULT void OTG_FS_IRQHandler();              /* USB OTG FS                   */
WEAK_DEFAULT void DMA2_Stream5_IRQHandler();        /* DMA2 Stream 5                */
WEAK_DEFAULT void DMA2_Stream6_IRQHandler();        /* DMA2 Stream 6                */
WEAK_DEFAULT void DMA2_Stream7_IRQHandler();        /* DMA2 Stream 7                */
WEAK_DEFAULT void USART6_IRQHandler();              /* USART6                       */
WEAK_DEFAULT void I2C3_EV_IRQHandler();             /* I2C3 event                   */
WEAK_DEFAULT void I2C3_ER_IRQHandler();             /* I2C3 error                   */
WEAK_DEFAULT void OTG_HS_EP1_OUT_IRQHandler();      /* USB OTG HS End Point 1 Out   */
WEAK_DEFAULT void OTG_HS_EP1_IN_IRQHandler();       /* USB OTG HS End Point 1 In    */
WEAK_DEFAULT void OTG_HS_WKUP_IRQHandler();         /* USB OTG HS Wakeup through EXTI */
WEAK_DEFAULT void OTG_HS_IRQHandler();              /* USB OTG HS                   */
WEAK_DEFAULT void DCMI_IRQHandler();                /* DCMI                         */
//WEAK_DEFAULT void 0                               /* CRYP crypto                  */
WEAK_DEFAULT void HASH_RNG_IRQHandler();            /* Hash and Rng                 */
WEAK_DEFAULT void FPU_IRQHandler();                 /* FPU                          */

ISR_VECTOR(1) const IsrTypeDef periph_vector[DEVICE_IRQ_NUMOF] = {
    [0] = WWDG_IRQHandler,
    [1] = PVD_IRQHandler,
    [2] = TAMP_STAMP_IRQHandler,
    [3] = RTC_WKUP_IRQHandler,
    [4] = FLASH_IRQHandler,
    [5] = RCC_IRQHandler,
    [6] = EXTI0_IRQHandler,
    [7] = EXTI1_IRQHandler,
    [8] = EXTI2_IRQHandler,
    [9] = EXTI3_IRQHandler,
    [10] = EXTI4_IRQHandler,
    [11] = DMA1_Stream0_IRQHandler,
    [12] = DMA1_Stream1_IRQHandler,
    [13] = DMA1_Stream2_IRQHandler,
    [14] = DMA1_Stream3_IRQHandler,
    [15] = DMA1_Stream4_IRQHandler,
    [16] = DMA1_Stream5_IRQHandler,
    [17] = DMA1_Stream6_IRQHandler,
    [18] = ADC_IRQHandler,
    [19] = CAN1_TX_IRQHandler,
    [20] = CAN1_RX0_IRQHandler,
    [21] = CAN1_RX1_IRQHandler,
    [22] = CAN1_SCE_IRQHandler,
    [23] = EXTI9_5_IRQHandler,
    [24] = TIM1_BRK_TIM9_IRQHandler,
    [25] = TIM1_UP_TIM10_IRQHandler,
    [26] = TIM1_TRG_COM_TIM11_IRQHandler,
    [27] = TIM1_CC_IRQHandler,
    [28] = TIM2_IRQHandler,
    [29] = TIM3_IRQHandler,
    [30] = TIM4_IRQHandler,
    [31] = I2C1_EV_IRQHandler,
    [32] = I2C1_ER_IRQHandler,
    [33] = I2C2_EV_IRQHandler,
    [34] = I2C2_ER_IRQHandler,
    [35] = SPI1_IRQHandler,
    [36] = SPI2_IRQHandler,
    [37] = USART1_IRQHandler,
    [38] = USART2_IRQHandler,
    [39] = USART3_IRQHandler,
    [40] = EXTI15_10_IRQHandler,
    [41] = RTC_Alarm_IRQHandler,
    [42] = OTG_FS_WKUP_IRQHandler,
    [43] = TIM8_BRK_TIM12_IRQHandler,
    [44] = TIM8_UP_TIM13_IRQHandler,
    [45] = TIM8_TRG_COM_TIM14_IRQHandler,
    [46] = TIM8_CC_IRQHandler,
    [47] = DMA1_Stream7_IRQHandler,
    [48] = FSMC_IRQHandler,
    [49] = SDIO_IRQHandler,
    [50] = TIM5_IRQHandler,
    [51] = SPI3_IRQHandler,
    [52] = UART4_IRQHandler,
    [53] = UART5_IRQHandler,
    [54] = TIM6_DAC_IRQHandler,
    [55] = TIM7_IRQHandler,
    [56] = DMA2_Stream0_IRQHandler,
    [57] = DMA2_Stream1_IRQHandler,
    [58] = DMA2_Stream2_IRQHandler,
    [59] = DMA2_Stream3_IRQHandler,
    [60] = DMA2_Stream4_IRQHandler,
    [61] = ETH_IRQHandler,
    [62] = ETH_WKUP_IRQHandler,
    [63] = CAN2_TX_IRQHandler,
    [64] = CAN2_RX0_IRQHandler,
    [65] = CAN2_RX1_IRQHandler,
    [66] = CAN2_SCE_IRQHandler,
    [67] = OTG_FS_IRQHandler,
    [68] = DMA2_Stream5_IRQHandler,
    [69] = DMA2_Stream6_IRQHandler,
    [70] = DMA2_Stream7_IRQHandler,
    [71] = USART6_IRQHandler,
    [72] = I2C3_EV_IRQHandler,
    [73] = I2C3_ER_IRQHandler,
    [74] = OTG_HS_EP1_OUT_IRQHandler,
    [75] = OTG_HS_EP1_IN_IRQHandler,
    [76] = OTG_HS_WKUP_IRQHandler,
    [77] = OTG_HS_IRQHandler,
    [78] = DCMI_IRQHandler,
    [80] = HASH_RNG_IRQHandler,
    [81] = FPU_IRQHandler
};
