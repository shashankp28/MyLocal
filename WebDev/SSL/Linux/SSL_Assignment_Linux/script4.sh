#!/bin/bash
array=("Apple" "Mango" "Jackfruit" "Grapes" "Lichi" "Stawberry" "Guava")
echo "Number of elements: ${#array[@]}"
echo ""
echo "All elements: ${array[@]}"
echo ""
echo "5th element: ${array[4]}"
echo ""
echo "3 elements starting from 2: ${array[@]:2:3}"
echo ""
array[2]="Debian"
echo "All elements: ${array[@]}"
echo ""
array+=("Blueberry")
echo "All elements: ${array[@]}"
echo ""