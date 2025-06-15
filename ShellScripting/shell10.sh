#create file with passed argument value and print that this file is created

#!/bin/bash
for x in $*
do
    touch $x
    echo "$x file is created"
done
