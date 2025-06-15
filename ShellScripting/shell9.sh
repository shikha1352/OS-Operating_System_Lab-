#for loop
 #!/bin/bash


#create 3 files

for x in 12 qwe tyu
do
    touch $x
    echo "file is created"
done

#print date and time 10 times,once after each second
for((i=0;i<10;i++))
do
    date
    sleep 1
done
