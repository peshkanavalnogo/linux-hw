#!/bin/bash

# Second task:
# Function getopts accepts two arguments.
# In cycle we making two new variables and assign them
# with values that we gave in getopts.
# The last step is to open wttr.in in console.

while getopts x:y: option
do
   case "$option" in
     x) coorx=$OPTARG ;;
     y) coory=$OPTARG ;; 
   esac
done
curl wttr.in/$coorx,$coory 

# To test this program you can enter in console "bash weather.sh -x 59.57 -y 30.19"
