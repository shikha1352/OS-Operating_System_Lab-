#logical comparison
#!/bin/bash
if [ -f $1 ] || [ -d $1 ]
then 
    echo "Entery exists"
else
    echo "No such Entry"
fi

# if the passed argument is a file and readable check

if [ -f $1 ] &&  [ -r $1 ]
then 
    echo "both are true"
else
    echo "partially true"
fi
