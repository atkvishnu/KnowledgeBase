#!/bin/bash

# input can be taken using the read command, it prompts the user for input
echo "What is your name?"
read name

echo "Hello, $name"


# To reduce the code we can change the first `echo` statement with the `read -p` command
# The `read` command used with `-p` flag will print a message before prompting the user for their input.
echo "Second example: "

read -p "What is your name? " name
echo "Hi there, $name"
echo "Welcome to the bash shell"