#!/bin/bash

# SLICING A STRING IN BASH

str=("a""b""c""d""e")        # This is a string
echo "String: " ${str[@]}


# First example
a=${str:0:2}     # starting from 0 index and ending at 2 index, where 2 is exclusive (i.e., not including 2)
echo "First Example (:0:2): ""${a}"

# Second example
b=${str::5}   # This will print from base index 0 to 5, where 5 is exclusive (i.e., not including 5) and starting index is set to 0 when it's not specified
echo "Second Example (::5): ""${b}"

# Third example
c=${str:3}     # This will print from starting index 3 to the end of the string inclusive
echo "Third Example (:3): ""${c}"


# b=${letters:2:10}
# echo "${b}"




# OUTPUT:
# String:  abcde
# Array (Think so?):  a b c d e f g h i j k l m n o p q r s t u v w x y z
# First Example (:0:2): ab
# Second Example (::5): abcde
# Third Example (:3): de



