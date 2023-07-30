#!/bin/bash

case "$1" in
    1) echo "The value is 1"
        exit
        ;;
    2) echo "The value is 2"
        exit
        ;;
    3) echo "The vlaue is 3"
        exit
        ;;
    *) echo "Value empty or not recognized"
        echo "Accepted values: 1, 2, 3"
        echo "Received input is [$1]"
        exit
        ;;
esac

