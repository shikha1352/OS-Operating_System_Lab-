#write a script that checks if the argument passed at command line is whether of a file or a directory

#!/bin/bash
if [ -f $1 ]
then
    echo "name is of a file"
elif [ -d $1 ]
then 
    echo "name is of a directory"
else
    echo "neither file nor directory"
fi