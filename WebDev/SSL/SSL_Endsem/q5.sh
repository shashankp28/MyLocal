#!/bin/bash
echo "Enter year: "
read n
if [[ $n%4 -eq 0 ]]
then
    if [[ $n%100 -eq 0 && $n%400 -ne 0 ]]
    then
        echo "$n is a not leap year"
    else
        echo "$n is a leap year"
    fi
else
    echo "$n is not a leap year"
fi