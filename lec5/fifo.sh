#!/bin/bash

# In pipeline we line by line print this line and after that we print bash command "date".

cat $1 | while read y; do echo "$y"; bash -c "date"; echo ; done;

# To test this code you need to open 2 terminal windows.
# In one window you create fifo by command "mkfifo @yourname".
# That you need to give this fifo some text or whatever ( you can use just ls > @yourname.)
# So in other window you need to open this scripts by this command "bash fifo.sh @yourname".
