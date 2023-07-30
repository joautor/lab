#!/bin/bash

for f in ./*
do
    line=""
    if [ -f $f ]
    then
        line="-"
    elif [ -d $f ]
    then
        line="d"    else
        line="?"    fi

    if [ -r $f ]
    then
        line="${line}r"
    else
        line="${line}-"
    fi

    if [ -w $f ]
    then
        line="${line}w"
    else
        line="${line}-"
    fi

    if [ -x $f ]
    then
        line="${line}x"
    else
        line="${line}-"
    fi

    echo "$line $f"
done
