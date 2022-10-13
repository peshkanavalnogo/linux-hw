#!/bin/bash

cat $1 | while read y; do echo "$y"; bash -c "date"; echo ; done;
