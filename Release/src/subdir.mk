################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Person.cpp \
../src/XmlObject.cpp \
../src/XmlProject.cpp 

OBJS += \
./src/Person.o \
./src/XmlObject.o \
./src/XmlProject.o 

CPP_DEPS += \
./src/Person.d \
./src/XmlObject.d \
./src/XmlProject.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


