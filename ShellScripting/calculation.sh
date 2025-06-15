#!/bin/bash

echo -n "Enter first number: "
read A
echo -n "Enter second number: "
read B

echo "Sum is $(( A + B))"
echo "Difference is $(( A - B))"
echo "Product is $(( A * B))"
echo "Quotient is $(( A / B))"