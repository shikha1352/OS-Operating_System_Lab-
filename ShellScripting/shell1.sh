#Environmental variables
#Environmental variables are HOME,SHELL,PATH etc
echo "the home directory of the user is: $HOME"
echo " the default shell :$SHELL"


#assign the value to the variables

echo -n "Enter the name of a file: "
read filename
touch $filename
echo "file is created"

#write a shell script to create two directories.The name of the directories will be passed by the users
echo -n "Enter the two directory names: "
read dir1 dir2
mkdir $dir1 $dir2
echo "directory created"

#write script to change the name of a file.Ask from the user ,the old file name and the new file name

echo "write name of file ypu want to rename "
read old
read new
mv $old $new
echo "file is renamed"
