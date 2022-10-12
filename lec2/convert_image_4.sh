#!/bin/bash

# Fourt task:
# We convert all photos in dir using pipeline.
# "xargs -n 1" accepts one argument from pipeline.
# "bash -c '...' Here we running bash command with argument from xargs.

find pictures/ -name "*.jpg" | xargs -n 1 bash -c 'convert $0 "${0%.*}.png"'
