#! /bin/bash
#!/bin/bash
echo "Enter directory: "
read dir
f_l=$(find $dir -type f -name "*.png" -size +100M)
echo "Total file size in KB: "
du -c $f_l | tail -1 | cut -f 1
