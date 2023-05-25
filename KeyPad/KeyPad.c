/*
 * main.c
 *
 *      Created on: May 6, 2023
 *      Author:Maryam Megahed
 *      BN:32
 */
#include "KeyPad.h"
#include "Gpio.h"
#include "Std_Types.h"

uint8 key=0,flag=0;
//indices of keypad
uint8 keyVal[4][3]={
		{1,2,3},
		{4,5,6},
		{7,8,9},
		{0,0,0}
};
void Keypad_Init(void)
{
	uint8 i=0;
	//columns pins configration
	for(i=COL_START_INDEX; i<=COL_END_INDEX; i++)
	{
		Gpio_ConfigPin(GPIO_B,i,GPIO_INPUT,GPIO_PULL_UP);
	}
	//rows pins configration
	for(i=ROW_START_INDEX; i<=ROW_END_INDEX; i++)
	{
		Gpio_ConfigPin(GPIO_B,i,GPIO_OUTPUT,GPIO_PUSH_PULL);
		Gpio_WritePin(GPIO_B,i,BUTTON_RELEASED);
	}
}
void Keypad_Manage(void)
{
	uint8 i,j;
	for(i=ROW_START_INDEX; i<=ROW_END_INDEX; i++)
	{
		//pressed each row then check pins in this columns with this row
		Gpio_WritePin(GPIO_B,i,BUTTON_PRESSED);
		for(j=COL_START_INDEX; j<=COL_END_INDEX; j++)
		{
            //check if the button is clicked and flag is false which mean that the button was released
			if(Gpio_ReadPin(GPIO_B,j)==BUTTON_PRESSED && !flag)
			{
                flag=1;
				key=keyVal[i-ROW_START_INDEX][j-COL_START_INDEX];
				KeypadCallout_KeyPressNotification();
			}
			//check if the button is released return flag to 0
            if(Gpio_ReadPin(GPIO_B,j)==BUTTON_RELEASED)
			{
				flag=0;
			}

		}
		Gpio_WritePin(GPIO_B,i,BUTTON_RELEASED);
	}
}
//return the value of key
uint8 Keypad_Getkey()
{
	return key;
}
