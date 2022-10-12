#!/bin/bash

# First task:

ls "$@" # Reading all arguments
while test -n "$1" # checking if arg is empty, if not do the following
do
    convert $1 -resize 100% $1.png
    shift # another argument
done
