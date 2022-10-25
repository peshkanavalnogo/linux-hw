#!/bin/bash

func(){
    max=0
    number=$1
    arr=()
    while (( number != 1 ))
    do
	cond=$((number%2))
	if [[ $cond == 0 ]]; then
	    number=$((number/2))
	else
	    number=$((number*3 + 1))
	fi
        arr+=($number)
	if [[ $number > $max ]]; then
	    max=$number
	fi
    done
    
    echo "Array of numbers: "
    echo ${arr[@]}
    echo "Max element in array: $max "
}

func $1
