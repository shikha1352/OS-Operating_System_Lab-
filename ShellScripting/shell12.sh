#write a shell script to count the number of file names passed at command line
#!/bin/bash
count=0
for x in $*
do
    if [ -f $x ]
    then
        count=$((count+1))
    fi
done
echo "total file names were : $count"
    