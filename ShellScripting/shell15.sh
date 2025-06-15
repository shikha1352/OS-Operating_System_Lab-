#Write a script to check whether current user is root user or not
#!/bin/bash
x=$(whoami)
if [ $x = "root" ]
then 
    echo "You are root user"
else

    echo "You are regular user"
fi
