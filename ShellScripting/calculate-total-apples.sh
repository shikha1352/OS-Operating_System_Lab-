#!/bin/bash
echo -n "Enter basket number: "
read baskets
echo -n "Enter apples per basket: "
read apples_per_basket

total_apples=$(($baskets * $apples_per_basket))
echo "Total Apples = $total_apples"