#positional parameters,commandline arguments

#!/bin/bash
# $0 ->name of the script
# $1 ->first arguments
# $2 ->second arguments and so on

# $# -> total number of arguments
# $* -> value of all the arguments

# pass to arguments at the command line and create two files

# touch $1 $2             # this will create two files 

# echo "files created"

# using of $#
echo "total arguments passed are : $#"

echo "Each arguments value is : $*"

#write a script  to rename a file.the old and new name must be passed at command line
mv $1 $2
echo name updated
