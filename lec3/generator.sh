#!/bin/bash

# Our idea is to create a var called "name" to echo it to our new_script
# called "gg.sh".
# Var name contains file name with lower case letters.
# In echo we rename file with this file but lower case.
# Then we execute created script.

ls > txt.txt

while read -r x;
do
    name=$(echo $x | tr [:lower:] [:upper:]);
    echo " mv $x $name" >> gg.sh;
done < txt.txt

bash -c "bash gg.sh"
bash -c "rm gg.sh" # Just remove useless junk
bash -c "rm TXT.TXT"
