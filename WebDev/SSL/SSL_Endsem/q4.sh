#!/bin/bash
echo "Enter string: "
read str1
t=0
l=${#str1}
for ((i = $l - 1; i >= 0; i--))
    do
    str2="$str2${str1:$i:1}" 
done
if [[ $str1 == $str2 ]]
    then
        echo "Given string is a palindrome"
    else
        echo "Given string is not a palindrome"
fi