#write a shell script to read a month name from the user.
#check if the name entered is August or October

#!/bin/bash
echo -n "Enter the name of the month: "
read month
if [ $month = "August" ]
then
    echo "the month is August"
elif [ $month = "October" ]
then 
    echo "the month is October"
else
    echo "neither the month is August nor October"
fi