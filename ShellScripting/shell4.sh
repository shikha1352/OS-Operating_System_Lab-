# A script that takes two command line arguments.Check whether the name passed as first argument is of a directory or not.if not then create a new directory with the second name

#!/bin/bash
if [ -d $1 ]
then 
    echo "Directory exists"
else
    mkdir $2
    echo "Directory created"
fi