#check whether a number odd or even

#!/bin/bash

echo -n "Enter a number:"
read num

rem=$(expr $num % 2)

if [ $rem -eq 0 ]
then
    echo "$num is even"
else
    echo "$num is odd"
fi