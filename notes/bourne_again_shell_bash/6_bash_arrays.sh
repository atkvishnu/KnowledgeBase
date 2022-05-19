#!/bin/bash

# arrays can hold several values under the same name
# You can initialize an array by assigning values divided by space and enclosed in ()
# Example: my_array=("value1" "value2" "value3")

# You can access the values of an array by using the index number
# NOTE: We need to use CURLY BRACES to access the values of an array
# Example: echo ${my_array[0]}

my_array=("value1" "value2" "value3" "value 4")

echo "The first element using the 0 index: " ${my_array[0]}

echo "The second element of the array using 1 index: " ${my_array[1]}

echo "The last element of the array using -1 index: " ${my_array[-1]}    # -1 is the last index

echo "All the elements are: " ${my_array[@]}     # @ is the whole array

echo "The number of elements are: " ${#my_array[@]}    # prepending the array with a hash sign (#) will output the length of the array(total no. of elements)
