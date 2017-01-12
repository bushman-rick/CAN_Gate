#!/bin/bash

y=1

for run in {1..1000}
do
    echo $y > /dev/udp/192.168.1.136/8583
    y=$((y+1))
    sleep 0.003
    
done