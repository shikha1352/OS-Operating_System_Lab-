#write a script to check the total number of arguments passed at command line.
#if the arguments are more than three then list the arguments else print "type more next"
#!/bin/bash
if [ $# -gt 3 ]
then    
    echo "the arguments were: $*"
else
    echo "Type more next"
fi
