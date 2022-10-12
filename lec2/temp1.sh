#!/bin/bash

# Second task:
# finding in sys needed files and then read them
find /sys -name "temp*input" | xargs -n 1 cat $1
