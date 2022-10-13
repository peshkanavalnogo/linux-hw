#!/bin/bash

ls > txt.txt

while read -r x;
do
    name=$(echo $x | tr [:lower:] [:upper:]);
    echo " mv $x $name" >> gg.sh;
done < txt.txt

bash -c "bash gg.sh"
bash -c "rm gg.sh"
bash -c "rm TXT.TXT"
