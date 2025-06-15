#check if the number entered by the user is greater than 10

#!/bin/bash
echo -n "Enter the number: "
read num
if [ $num -gt 10 ]
then
    echo "true"
else
    echo "number is small"
fi

#write a script if a file exists .if not then create it

echo -n "Enter the file name : "
read name
if [ -f $name ]
then 
    echo "file exists"
else   
    touch $name
    echo "new file created"
fi

