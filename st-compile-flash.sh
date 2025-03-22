#!/bin/bash

cd Debug && make -j16 all
/home/archingis/apps/stm32cubeProgrammer/ProgrammerInstall/bin/STM32_Programmer_CLI -c port=SWD -w h7a3zi_combine2.elf -v -rst

