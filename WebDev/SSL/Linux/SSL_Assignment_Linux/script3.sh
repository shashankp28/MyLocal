#!/bin/bash
echo "Question a"
echo ""
awk -F'[| ]' '/Y/{if(length($2)==5)print$2}' data.txt
echo ""
echo "Question b"
echo ""
sed -n '6,+6p' data.txt
echo ""
echo "Question c"
echo ""
sed -i 's/Ankit/Ashish/g' data.txt
awk '{print}' data.txt