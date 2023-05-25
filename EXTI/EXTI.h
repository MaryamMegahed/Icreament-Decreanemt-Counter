/*
 * EXTI.h
 *
 *  Created on: May 24, 2023
 *      Author: marya
 */

#ifndef EXTI_H_
#define EXTI_H_

#include "Std_Types.h"

// SYSCFG base address
#define SYSCFG_BASE_ADDR 0x40013800

// SYSCFG register offsets
#define SYSCFG_EXTICR1 (*(uint32 *)(SYSCFG_BASE_ADDR + 0x08))
#define SYSCFG_EXTICR2 (*(uint32 *)(SYSCFG_BASE_ADDR + 0x0C))
#define SYSCFG_EXTICR3 (*(uint32 *)(SYSCFG_BASE_ADDR + 0x10))
#define SYSCFG_EXTICR4 (*(uint32 *)(SYSCFG_BASE_ADDR + 0x14))

// EXTI base address
#define EXTI_BASE_ADDR 0x40013C00

// EXTI register structure
typedef struct {
	uint32 IMR;
	uint32 EMR;
	uint32 RTSR;
	uint32 FTSR;
	uint32 SWIER;
	uint32 PR;
} ExtiType;

#define EXTI ((ExtiType *)EXTI_BASE_ADDR)


#define EXTI_RISING_EDGE 0x00
#define EXTI_FALLING_EDGE 0x01
#define EXTI_RISING_FALLING_EDGE 0x02

void Exti_Init(uint8 PortName, uint8 PinNum,uint8 PinMode, uint8 DefaultState, uint8 TriggerType);
void Exti_Enable(uint8 PinNum);
void Exti_Disable(uint8 PinNum);


// NVIC base address
#define NVIC_BASE_ADDR 0xE000E100

// NVIC register offsets
#define NVIC_ISER0 (*(uint32 *)(NVIC_BASE_ADDR + 0x000))
#define NVIC_ISER1 (*(uint32 *)(NVIC_BASE_ADDR + 0x004))
#define NVIC_ISER2 (*(uint32 *)(NVIC_BASE_ADDR + 0x008))

#endif /* EXTI_H_ */
