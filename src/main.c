#include "Bit_Operations.h"
#include "Gpio.h"
#include "Rcc.h"
#include "Std_Types.h"
#include "EXTI.h"
#include "seven_segment.h"


int counter=0;

int main() {
	Rcc_Init();
	config_seven_segment(GPIO_C, 2,8);
	Exti_Init(GPIO_A,0,GPIO_INPUT,GPIO_PULL_UP,EXTI_FALLING_EDGE);
	Exti_Enable(0);
	Exti_Init(GPIO_A,1,GPIO_INPUT,GPIO_PULL_UP,EXTI_FALLING_EDGE);
	Exti_Enable(1);
	while (1) {
	}

	return 0;
}



 void EXTI0_IRQHandler(void) {
	  Exti_Disable(1);
	  counter++;
	  if(counter>9)counter=0;
	  seven_segment_output(GPIO_C, 2,counter);
	  Exti_Enable(1);
	//clear pending flag
	SET_BIT(EXTI->PR, 0);
}
  void EXTI1_IRQHandler(void) {
	  Exti_Disable(0);
      counter--;
      if(counter<0)counter=9;
      seven_segment_output(GPIO_C, 2,counter);
      Exti_Enable(0);
    	//clear pending flag
      SET_BIT(EXTI->PR, 0);
 }






