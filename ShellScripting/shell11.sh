#write a shell script to print long list of all the file names passed at command line

#!/bin/bash

for x in $*
do
    if [ -f $x ]
    then
        ls -l $x
    else
        echo "$x is not a file"
    fi
done
