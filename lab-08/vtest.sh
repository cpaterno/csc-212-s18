#!/bin/bash

g++ -g -std=c++11 darray.cc main.cc -o lab8

counter=1
while [ $counter -le 11 ]
do
    echo $counter
    ./lab8 $counter | grep .
    ((counter++))
done
