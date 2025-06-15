#write a shell script to count the number of files having read permission in the current working directory
#!/bin/bash
count=0
for x in *
do
    if [ -f $x ] && [ -r $x ]
    then 
        count=$((count+1))

    fi
done
echo "Total files having read permission are $count"