#!/bin/bash

stty 115200 -F /dev/ttyACM0 raw -echo && echo "data saved in uart_tmp.csv" && cat /dev/ttyACM0 | tee uart_tmp.csv
