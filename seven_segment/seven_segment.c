/*
 * seven_segment.c
 *
 *  Created on: May 24, 2023
 *      Author: marya
 */
#include "seven_segment.h"
#include "Rcc_Private.h"
#include "Rcc.h"
#include "Std_Types.h"
#include "Gpio.h"


 void config_seven_segment(uint8 PortName, uint8 first_PinNum, uint8 last_PinNum)
  {
	  // Enable GPIO port clock  for seven_segment
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
	  	uint32 i;
	  	  for(i=first_PinNum; i<=last_PinNum; i++)
	  	  {
	  		  Gpio_ConfigPin(GPIO_C,i,GPIO_OUTPUT,GPIO_PUSH_PULL);
	  	  }
  }
  void seven_segment_output(uint8 PortName, uint8 first_PinNum,uint8 counter)
  {
	  switch(counter)
	  	{
	  	case 0:
	  		Gpio_WritePin(PortName,first_PinNum+0,HIGH);
	  		Gpio_WritePin(PortName,first_PinNum+1,HIGH);
	  		Gpio_WritePin(PortName,first_PinNum+2,HIGH);
	  		Gpio_WritePin(PortName,first_PinNum+3,HIGH);
	  		Gpio_WritePin(PortName,first_PinNum+4,HIGH);
	  		Gpio_WritePin(PortName,first_PinNum+5,HIGH);
	  		Gpio_WritePin(PortName,first_PinNum+6,LOW);
	  	    break;
	  	case 1:
	  		Gpio_WritePin(PortName,first_PinNum+0,LOW);
	  		Gpio_WritePin(PortName,first_PinNum+1,HIGH);
	  		Gpio_WritePin(PortName,first_PinNum+2,HIGH);
	  		Gpio_WritePin(PortName,first_PinNum+3,LOW);
	  		Gpio_WritePin(PortName,first_PinNum+4,LOW);
	  		Gpio_WritePin(PortName,first_PinNum+5,LOW);
	  		Gpio_WritePin(PortName,first_PinNum+6,LOW);
	  		break;
	  	case 2:
	  			Gpio_WritePin(PortName,first_PinNum+0,HIGH);
	  			Gpio_WritePin(PortName,first_PinNum+1,HIGH);
	  			Gpio_WritePin(PortName,first_PinNum+2,LOW);
	  			Gpio_WritePin(PortName,first_PinNum+3,HIGH);
	  			Gpio_WritePin(PortName,first_PinNum+4,HIGH);
	  			Gpio_WritePin(PortName,first_PinNum+5,LOW);
	  			Gpio_WritePin(PortName,first_PinNum+6,HIGH);
	  			break;
	  	case 3:
	  			Gpio_WritePin(PortName,first_PinNum+0,HIGH);
	  			Gpio_WritePin(PortName,first_PinNum+1,HIGH);
	  			Gpio_WritePin(PortName,first_PinNum+2,HIGH);
	  			Gpio_WritePin(PortName,first_PinNum+3,HIGH);
	  			Gpio_WritePin(PortName,first_PinNum+4,LOW);
	  			Gpio_WritePin(PortName,first_PinNum+5,LOW);
	  			Gpio_WritePin(PortName,first_PinNum+6,HIGH);
	  			break;
	  	case 4:
	  			Gpio_WritePin(PortName,first_PinNum+0,LOW);
	  			Gpio_WritePin(PortName,first_PinNum+1,HIGH);
	  			Gpio_WritePin(PortName,first_PinNum+2,HIGH);
	  			Gpio_WritePin(PortName,first_PinNum+3,LOW);
	  			Gpio_WritePin(PortName,first_PinNum+4,LOW);
	  			Gpio_WritePin(PortName,first_PinNum+5,HIGH);
	  			Gpio_WritePin(PortName,first_PinNum+6,HIGH);
	  			break;
	  	case 5:
	  			Gpio_WritePin(PortName,first_PinNum+0,HIGH);
	  			Gpio_WritePin(PortName,first_PinNum+1,LOW);
	  			Gpio_WritePin(PortName,first_PinNum+2,HIGH);
	  			Gpio_WritePin(PortName,first_PinNum+3,HIGH);
	  			Gpio_WritePin(PortName,first_PinNum+4,LOW);
	  			Gpio_WritePin(PortName,first_PinNum+5,HIGH);
	  			Gpio_WritePin(PortName,first_PinNum+6,HIGH);
	  			break;
	  	case 6:
	  			Gpio_WritePin(PortName,first_PinNum+0,HIGH);
	  			Gpio_WritePin(PortName,first_PinNum+1,LOW);
	  			Gpio_WritePin(PortName,first_PinNum+2,HIGH);
	  			Gpio_WritePin(PortName,first_PinNum+3,HIGH);
	  			Gpio_WritePin(PortName,first_PinNum+4,HIGH);
	  			Gpio_WritePin(PortName,first_PinNum+5,HIGH);
	  			Gpio_WritePin(PortName,first_PinNum+6,HIGH);
	  			break;
	  	case 7:
	  			Gpio_WritePin(PortName,first_PinNum+0,HIGH);
	  			Gpio_WritePin(PortName,first_PinNum+1,HIGH);
	  			Gpio_WritePin(PortName,first_PinNum+2,HIGH);
	  			Gpio_WritePin(PortName,first_PinNum+3,LOW);
	  			Gpio_WritePin(PortName,first_PinNum+4,LOW);
	  			Gpio_WritePin(PortName,first_PinNum+5,LOW);
	  			Gpio_WritePin(PortName,first_PinNum+6,LOW);
	  			break;
	  	case 8:
	  			Gpio_WritePin(PortName,first_PinNum+0,HIGH);
	  			Gpio_WritePin(PortName,first_PinNum+1,HIGH);
	  			Gpio_WritePin(PortName,first_PinNum+2,HIGH);
	  			Gpio_WritePin(PortName,first_PinNum+3,HIGH);
	  			Gpio_WritePin(PortName,first_PinNum+4,HIGH);
	  			Gpio_WritePin(PortName,first_PinNum+5,HIGH);
	  			Gpio_WritePin(PortName,first_PinNum+6,HIGH);
	  			break;
	  	case 9:
	  			Gpio_WritePin(PortName,first_PinNum+0,HIGH);
	  			Gpio_WritePin(PortName,first_PinNum+1,HIGH);
	  			Gpio_WritePin(PortName,first_PinNum+2,HIGH);
	  			Gpio_WritePin(PortName,first_PinNum+3,HIGH);
	  			Gpio_WritePin(PortName,first_PinNum+4,LOW);
	  			Gpio_WritePin(PortName,first_PinNum+5,HIGH);
	  			Gpio_WritePin(PortName,first_PinNum+6,HIGH);
	  			break;
	  	 default:
	  			Gpio_WritePin(PortName,first_PinNum+0,HIGH);
	  			Gpio_WritePin(PortName,first_PinNum+1,HIGH);
	  			Gpio_WritePin(PortName,first_PinNum+2,HIGH);
	  			Gpio_WritePin(PortName,first_PinNum+3,HIGH);
	  			Gpio_WritePin(PortName,first_PinNum+4,HIGH);
	  			Gpio_WritePin(PortName,first_PinNum+5,HIGH);
	  			Gpio_WritePin(PortName,first_PinNum+6,LOW);
	  		    break;
	  	}
  }
