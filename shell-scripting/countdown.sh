#!/bin/bash

INPUT_DATA=`cat test.txt`

for LINE in ${INPUT_DATA}
do
    echo $LINE
    sleep 1
done
