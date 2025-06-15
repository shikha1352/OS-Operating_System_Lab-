#!/bin/bash
echo -n "Enter first number: "
read num1

echo -n "Enter second number: "
read num2

echo -n "Enter third number: "
read num3

sum=$(expr $num1 + $num2 + $num3)
echo "sum is $sum"