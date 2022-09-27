#!/bin/bash
isPrime() 
{
    local p=$1
    if [[ $p -eq 1 ]]
        then
            return 0
        fi
    if [[ $p -eq 2 ]]
        then
            return 1
    else
        s_r=$(echo "$p" | awk '{print sqrt($1)}')
        s_r=$(( `echo $s_r|cut -f1 -d"."` + 1 ))
        for(( i=2; i<=$s_r; i++ ))
        do
            if [[ $(($p % $i)) -eq 0 ]]
            then
                return 0
            fi
        done
    fi
    return 1
}
echo "Enter n: "
read n
sum=0
p=2
while [ $p -le $n ]
    do
        isPrime $p
        res=$?
        if [[ $res -eq 1 ]]
        then
            sum=$(( $sum +  $p*$p))
        fi
        if [[ $p -gt 2 ]]
        then
            p=$(( $p + 2 ))
        else
            p=$(( $p + 1 ))
        fi
    done
echo "Sum of squares of primes upto ($n) = $sum"