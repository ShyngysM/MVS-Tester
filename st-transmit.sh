#!/bin/bash

stty 115200 -F /dev/ttyACM0 raw -echo && echo "data saved in tmp_data.txt" && cat /dev/ttyACM0 | tee tmp_data.txt
