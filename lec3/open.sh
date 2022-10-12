#!/bin/bash

# First task:
# "name" is equal to MIME file format.
# Then we compare "name" to other MIMO's.
# If it's "True" we are opening this file with a certain program.

name="$(file -i -b $1)"
if [ "$name" = "image/png; charset=binary" ]; then
   gimp $1
elif [ "$name" = "application/vnd.openxmlformats-officedocument.wordprocessingml.document; charset=binary" ]; then
   libreoffice $1 
else
   mpv $1
fi
