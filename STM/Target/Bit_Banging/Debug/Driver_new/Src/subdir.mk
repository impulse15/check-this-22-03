################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Driver_new/Src/GPIO_DRIVER.c \
../Driver_new/Src/SPI.c 

OBJS += \
./Driver_new/Src/GPIO_DRIVER.o \
./Driver_new/Src/SPI.o 

C_DEPS += \
./Driver_new/Src/GPIO_DRIVER.d \
./Driver_new/Src/SPI.d 


# Each subdirectory must supply rules for building sources it contributes
Driver_new/Src/%.o Driver_new/Src/%.su Driver_new/Src/%.cyclo: ../Driver_new/Src/%.c Driver_new/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32G0 -DSTM32G0B1RETxN -c -I../Inc -I"C:/Users/10820302/Desktop/STM/Target/Bit_Banging/Driver_new/Inc" -I"C:/Users/10820302/Desktop/STM/Target/Bit_Banging/Driver_new/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Driver_new-2f-Src

clean-Driver_new-2f-Src:
	-$(RM) ./Driver_new/Src/GPIO_DRIVER.cyclo ./Driver_new/Src/GPIO_DRIVER.d ./Driver_new/Src/GPIO_DRIVER.o ./Driver_new/Src/GPIO_DRIVER.su ./Driver_new/Src/SPI.cyclo ./Driver_new/Src/SPI.d ./Driver_new/Src/SPI.o ./Driver_new/Src/SPI.su

.PHONY: clean-Driver_new-2f-Src

