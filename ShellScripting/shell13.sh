#write a shell script to check if the present month is October or not

#!/bin/bash
x=$(date +"%m")
if [ $x -eq 6 ]
then
    echo "Month is june"
else
    echo "Not"
fi