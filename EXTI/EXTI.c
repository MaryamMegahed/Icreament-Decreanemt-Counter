/*
 * EXTI.c
 *
 *  Created on: May 24, 2023
 *      Author: marya
 */


#include "EXTI.h"

#include "Bit_Operations.h"
#include "Rcc_Private.h"
#include "Rcc.h"
#include "Std_Types.h"
#include "Gpio.h"

void Exti_Init(uint8 PortName, uint8 PinNum,uint8 PinMode, uint8 DefaultState, uint8 TriggerType)
{
    // Enable GPIO port clock
    switch (PortName) {
        case GPIO_A:
            Rcc_Enable(RCC_GPIOA);
            break;
        case GPIO_B:
            Rcc_Enable(RCC_GPIOB);
            break;
        case GPIO_C:
            Rcc_Enable(RCC_GPIOC);
            break;
        case GPIO_D:
            Rcc_Enable(RCC_GPIOD);
            break;
    }

    // Configure the GPIO pin as input
    Gpio_ConfigPin(PortName, PinNum, PinMode, DefaultState);

    // Enable SYSCFG peripheral clock
    Rcc_Enable(RCC_SYSCFG);

    // Configure EXTI line
    uint32 extiPinSource = PinNum % 4;
    uint8 extiPortSource = PinNum / 4;
    uint8 port_num = PortName-GPIO_A;

    switch (extiPortSource) {
           case 0:
        	   SYSCFG_EXTICR1 &=~(0x0f<<(extiPinSource *4));
        	   SYSCFG_EXTICR1 |=(port_num<<(extiPinSource *4));
               break;
           case 1:
        	   SYSCFG_EXTICR2 &=~(0x0f<<(extiPinSource *4));
        	   SYSCFG_EXTICR2 |=(port_num<<(extiPinSource *4));
               break;
           case 2:
        	   SYSCFG_EXTICR3 &=~(0x0f<<(extiPinSource *4));
        	   SYSCFG_EXTICR3 |=(port_num<<(extiPinSource *4));

               break;
           case 3:
        	   SYSCFG_EXTICR4 &=~(0x0f<<(extiPinSource *4));
        	   SYSCFG_EXTICR4 |=(port_num<<(extiPinSource *4));
               break;
    }

    // Configure the EXTI trigger type
    CLEAR_BIT(EXTI->RTSR, PinNum);  // Clear the corresponding Rising Trigger Selection Register bit
    CLEAR_BIT(EXTI->FTSR, PinNum);  // Clear the corresponding Falling Trigger Selection Register bit

    switch (TriggerType) {
        case EXTI_RISING_EDGE:
            SET_BIT(EXTI->RTSR, PinNum);  // Set the corresponding Rising Trigger Selection Register bit
            break;
        case EXTI_FALLING_EDGE:
            SET_BIT(EXTI->FTSR, PinNum);  // Set the corresponding Falling Trigger Selection Register bit
            break;
        case EXTI_RISING_FALLING_EDGE:
            SET_BIT(EXTI->RTSR, PinNum);  // Set the corresponding Rising Trigger Selection Register bit
            SET_BIT(EXTI->FTSR, PinNum);  // Set the corresponding Falling Trigger Selection Register bit
            break;
    }

    // Enable NVIC interrupt for EXTI line which starts from pin 6
        uint8 NVIC_PIN = PinNum + 6;
        //in EXIT line case will alwase be <32 becase num of Exit lines is 16 and starts from pin 6
        if (PinNum < 32) {
            SET_BIT(NVIC_ISER0, NVIC_PIN);
        } else if (PinNum < 64) {
            SET_BIT(NVIC_ISER1, PinNum - 32);
        } else {
            SET_BIT(NVIC_ISER2, PinNum - 64);
        }

}
void Exti_Enable(uint8 PinNum)
{
    SET_BIT(EXTI->IMR, PinNum);  // Enable Interrupt Mask Register for the corresponding EXTI line
}

void Exti_Disable(uint8 PinNum)
{
    CLEAR_BIT(EXTI->IMR, PinNum);  // Disable Interrupt Mask Register for the corresponding EXTI line
}
