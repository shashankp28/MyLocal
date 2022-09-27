#!/bin/bash
echo "Enter a: "
read a
echo "Enter b :"
read b
echo "Enter Operation (+, -, *, /): "
read o
if [[ $o == '+' ]]
then
    c=$(($a + $b))
    echo "a + b = $c"
elif [[ $o == '-' ]]
then
    c=$(($a - $b))
    echo "a + b = $c"
elif [[ $o == '*' ]]
then
    c=$(($a * $b))
    echo "a + b = $c"
elif [[ $o == '/' ]]
then
    if [[ $b -eq 0 ]]
    then
        echo "Cannot Divide By 0"
    else
        echo "a / b = $(echo "scale=2; $a / $b" | bc)"
    fi
else
    echo "Invalid Operation"
fi