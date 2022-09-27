#!/bin/bash
function arrSum() 
{
    sum=0
    arr=("$@")
    for i in "${arr[@]}"
        do
            sum=$(($sum + $i))
        done
    echo "Sum of elements in (${arr[@]}) = $sum"
}
arr1=(1 2 3 5 6)
arr2=(4 5 6 10 0)
arrSum "${arr1[@]}"
arrSum "${arr2[@]}"