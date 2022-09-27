#!/bin/bash
echo "Enter n: "
read n
ap=0
an=1
e=1
o=0
if [[ $n -lt 1 ]]
    then
        echo "Please enter number greater than 0"
        exit 1
    fi
while [ $an -le $n ]
    do
        if [[ $an%2 -eq 0 ]]
        then
            e=$(( $e + 1 ))
        else
            o=$(( $o + 1 ))
        fi
        temp=$an 
        an=$(( $an + $ap))
        ap=$temp
    done
echo "Upto $n :"
echo "Even Numbers = $e"
echo "Odd Numbers = $o"