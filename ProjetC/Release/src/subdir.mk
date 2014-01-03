################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/FileManip.c \
../src/IHM.c \
../src/Main.c \
../src/ParseRequest.c \
../src/Util.c 

OBJS += \
./src/FileManip.o \
./src/IHM.o \
./src/Main.o \
./src/ParseRequest.o \
./src/Util.o 

C_DEPS += \
./src/FileManip.d \
./src/IHM.d \
./src/Main.d \
./src/ParseRequest.d \
./src/Util.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I/home/dev/git/ProjetC/ProjetC/headers -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


