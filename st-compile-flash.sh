#!/bin/bash

cd Debug && make -j16 all

/home/archingis/Apps/stm32/installation/bin/STM32_Programmer_CLI -c port=SWD -w h7a3zi_combine2.elf -v -rst
#/home/sm/STMicroelectronics/STM32Cube/STM32CubeProgrammer/bin/STM32_Programmer_CLI -c port=SWD -w h7a3zi_combine2.elf -v -rst
