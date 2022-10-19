#!/bin/bash

# In "my_func" we execute command "$2" in file "$1".
# Also all the errors will be in file "$1".
# So the "2>&1" means that stderr and stdout will both be in file "$1".

set -x
my_func(){
   $2 > $1 2>&1
}
my_func $1 $2
