#!/bin/bash
# Read number of elements
read -p "Enter how many numbers: " n

# Read array elements
echo "Enter the elements: "
nums=()
for (( i=0; i<n; i++ ))
do
    read nums[$i]
done

# Print array
echo "Array elements are:"
for (( i=0; i<n; i++ ))
do
    echo ${nums[$i]}
done

# Print length of the array
echo Length of the array: ${#nums[@]}

# Find largest number
largest=${nums[0]}  # initialize with first element

for (( i=1; i<n; i++ ))
do
    if [ ${nums[$i]} -gt $largest ]; then
        largest=${nums[$i]}
    fi
done

echo "Largest number is: $largest"
