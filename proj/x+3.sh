#!/bin/bash

func(){
    max=$1
    number=$1
    arr=()
    while (( number != 1 ))
    do	
    	arr+=($number)
	cond=$((number%2))
	if [[ $cond == 0 ]]; then
	    number=$((number/2))
	else
	    number=$((number*3 + 1))
	fi
	if [[ $number -gt $max ]]; then
	    max=$number
	fi
    done
    arr+=($number)
    echo "Array of numbers: "
    echo "${arr[@]}"
    echo "Max element in array: $max "
}

func $1
