#!/bin/bash

# In "my_func" we execute command "$1" in file "$2".
# Also all the errors will be in file "$2".
# So the "2>&1" means that stderr and stdout will both be in file "$2".

set -x
my_func(){
   $2 > $1 2>&1
}
my_func $1 $2
