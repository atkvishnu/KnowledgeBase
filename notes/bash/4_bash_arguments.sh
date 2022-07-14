#!/bin/bash

# We can pass arguments to our shell script when we execute the script.
# To pass an argument to a script, we just need to write it right after the name of our script.
# ./<file-name> <argument1> <argument2> <argument3> ....

echo "First example"

echo "Argument one is $1"
echo "Argument two is $2"
echo "Argument three is $3"


# To reference all the arguments, we can use $@

echo "Second example"
echo "All arguments are: $@"

# KIM: $@ is a special variable that holds all the arguments that were passed to a script.

# KIM: $# is a special variable that holds the number of arguments that were passed to a script.



# KIM: $0 is a special variable that holds the name of the script itself. It's used to reference the script itself.
# This is an excellent way to create and self destruct the file if you need to or just get the name of the script.
# Let's create a script that prints out the name of a file and deletes the file after that.

# echo "The name of the file is: $0 and it's going to be self deleted!"
# rm -f $0


