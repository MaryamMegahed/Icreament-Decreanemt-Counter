################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../seven_segment/seven_segment.c 

OBJS += \
./seven_segment/seven_segment.o 

C_DEPS += \
./seven_segment/seven_segment.d 


# Each subdirectory must supply rules for building sources it contributes
seven_segment/%.o: ../seven_segment/%.c seven_segment/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -Wall -Wextra -g -DNDEBUG -DSTM32F401xE -DHSE_VALUE=8000000 -I"../include" -I"C:\Users\marya\Downloads\Project\Lab4_Startup_Project_TODO\KeyPad" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -I"C:\Users\marya\Downloads\Project\Lab4_Startup_Project_TODO\Lib" -I"C:\Users\marya\Downloads\Project\Lab4_Startup_Project_TODO\Rcc" -I"C:\Users\marya\Downloads\Project\Lab4_Startup_Project_TODO\Gpio" -I"C:\Users\marya\Downloads\Project\Lab4_Startup_Project_TODO\EXTI" -I"C:\Users\marya\Downloads\Project\Lab4_Startup_Project_TODO\seven_segment" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


