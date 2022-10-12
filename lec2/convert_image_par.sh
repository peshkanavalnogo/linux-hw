#!/bin/bash

# Third task:
# Adding "&" in the end of the command will make it
# run in the background. 

ls "$@"
while test -n "$1"
do
    convert $1 -resize 100% $1.png &
    shift
done

wait # Here we wait all tasks to be complited
