################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Startup/startup_stm32g0b1retxn.s 

OBJS += \
./Startup/startup_stm32g0b1retxn.o 

S_DEPS += \
./Startup/startup_stm32g0b1retxn.d 


# Each subdirectory must supply rules for building sources it contributes
Startup/%.o: ../Startup/%.s Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m0plus -g3 -DDEBUG -c -I"C:/Users/10820302/Desktop/STM/Target/Bit_Banging/Driver_new/Inc" -I"C:/Users/10820302/Desktop/STM/Target/Bit_Banging/Driver_new" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"

clean: clean-Startup

clean-Startup:
	-$(RM) ./Startup/startup_stm32g0b1retxn.d ./Startup/startup_stm32g0b1retxn.o

.PHONY: clean-Startup

