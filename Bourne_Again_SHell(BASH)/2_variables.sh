#!/bin/bash

# Assign values to variables using = (WITHOUT ANY SPACES around =)
# Double quote is used to prevent globbing and word splitting.
name="Vishnu"

# We can use $ sign to access the variables
echo "1 " $name

# Good Practice: wrapping the variable name between curly brackets
echo "2" ${name}

echo "3 Hi there ${name}"

greeting="Hello"
echo "4 $greeting $name"
