#!/bin/bash
# Author: 你的名字
# Created Time : Tue 22 Dec 15:51:17 2020
# File Name: auto_test.sh
# Description:

./main -s 1 -E 1 -b 1 -t traces/yi2.trace 
./main -s 4 -E 2 -b 4 -t traces/yi.trace 
./main -s 2 -E 1 -b 4 -t traces/dave.trace 
./main -s 2 -E 1 -b 3 -t traces/trans.trace 
./main -s 2 -E 2 -b 3 -t traces/trans.trace
./main -s 2 -E 4 -b 3 -t traces/trans.trace 
./main -s 5 -E 1 -b 5 -t traces/trans.trace 
./main -s 5 -E 1 -b 5 -t traces/long.trace
