#!/bin/bash

# KIM: $0 is a `special variable` that `holds the name of the script itself`. It's used to reference the script itself.
# This is an excellent way to create and self destruct the file if you need to or just get the name of the script.
# Let's create a script that prints out the name of a file and deletes the file after that.

echo "The name of the file is: $0 and it's going to be self deleted!"
rm -f $0