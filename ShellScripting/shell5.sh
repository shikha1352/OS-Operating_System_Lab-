#write a shell script which checks the total number of arguments passed.
#if the argument count is greater than 5 then display the message"Too many arguments"

#!/bin/bash
x=$#
if [ $x -gt 5 ]
then 
    echo "Too many arguments"
else
    echo "number of arguments are $x"

fi
