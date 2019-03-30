#!/bin/bash

run=false
clf=false
while getopts ":rc" opt
do
    case ${opt} in
        r) run=true
        ;;
        c) clf=true
        ;;
    esac
done

echo "compiling..."
g++ src/main.cpp -o bin/main

if [ "$run" = true ]
then
    clear
    ./bin/main
    echo ""
    read -p "Press any key to exit"
    if [ "$clf" = true ]
    then
        clear
    fi
fi
