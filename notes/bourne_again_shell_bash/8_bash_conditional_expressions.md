# Bash Conditional Expressions

In CS, conditional statements, conditional expressions, and conditional constructs perform different computations or actions depending on whether a programmer-specified boolean conditions evaluates to true or false.

In Bash,
Conditional expressions are used by `[[` `compound command`, and 
The `[` built-in commands to `test file attributes` and `perform string and arithmetic comparisions`!

## List of the most popular bash conditional expressions:

### File Expressions

- `true` if file exists.
> [[ -a ${file} ]]


- Returns `true` if the numbers are `equal`
> [[ ${arg1} -eq ${arg2} ]]

- Returns `true` if the numbers are `not equal`
> [[ ${arg1} -ne ${arg2} ]]

- Returns `true` if arg1 is `less than` arg2
> [[ ${arg1} -lt ${arg2} ]]

- Returns `true` if arg1 is `less than or equal` arg2
> [[ ${arg1} -le ${arg2} ]]

- Returns `true` if arg1 is `greater than` arg2
> [[ ${arg1} -gt ${arg2} ]]

- Returns `true` if arg1 is `greater than or equal` arg2
> [[ ${arg1} -ge ${arg2} ]]

- As a side note, **arg1 and arg2 may be positive or negative integers.**

- As with other programming languages We can use AND `&&` & OR `||` conditions:

> [[ test_case_1 ]] && [[ test_case_2 ]] # And
> [[ test_case_1 ]] || [[ test_case_2 ]] # Or


### Exit status operators

- Returns `true`if the command was successful without any errors
> [[ $? -eq 0 ]]

- Returns `false` if the command wasn't successful and had errors.
> [[ $? -gt 0 ]]    # exit status greater than 0


### Bash Conditionals

In the last section, we covered some of the most popular conditional expressions. We can now use them with standard conditional statements like `if`, `if-else` and `switch case` statements.




#### If statement
The format of an `if` statement in Bash is as follows:

**Syntax: **    
```bash
if [[ some_test ]]
then
 <commands>
fi
```

Quick example which will ask us to enter our name in case that we've left it empty:

```bash
#!bin/bash

read -p "What is Wer name?" name

if [[ -z ${name} ]]
then
    echo "Please enter Wer name: "
fi
```

#### If Else statement
With an `if-else` statement, we can specify an action in case that the condition in the if statement does not match. We can combine this with the conditional expressions from the previous section as follows:

```bash
#!/bin/bash
# Bash if statement example
read -p "What is Wer name? " name
if [[ -z ${name} ]]
then
 echo "Please enter Wer name!"
else
 echo "Hi there ${name}"
fi
```

We can use the above if statement with all of the conditional expressions which is mentioned earlier:

```bash
#!/bin/bash

admin="atkvishnu"

read -p "Enter your username: " username

# Check if the username provided is the admin

if [[ "${username}" eq "${admin}" ]]
    echo "You are the admin user!"
else
    echo "You are NOT the admin user!"
fi
```

Another example of an `if` statement which will check your current `user ID` and it will not allow you to run the script as the `root` user.

```bash
#!/bin/bash

if (( #EUID == 0 )); then
    echo "Please do not run as root!"
    exit
fi

```

If you put this on top of your script it would exit in case that the EUID is 0 and would not execute the rest of the script. This was discussed on the DigitalOcean community forum.
You can also test multiple conditions with an if statement. 

In this example we want to make sure that the user is neither the admin user or the root user to ensure the script is incapable of causing too much damage. We'll use the OR operator in this example, noted by ||. This means that either of the conditions needs to be true. If we used the and operator of && then both conditions would need to be true.

```bash
#!/bin/bash

admin="atkvishnu"

read -p "Enter your username: " username

# Check if the username provided is the admin
if [[ "${username}" != "${admin}" ]] || [[  $EUID != 0 ]];
then
    echo "You are not the admin or root user!"
else
    echo "You are the admin user! This could be very destructive!"
fi
```

#### Switch case statements

We can use `case` statements to simplify complex conditionals when there are multiple different choices.
So rather than using a few `if`, and `if-else` statements, we can use a single `case` statement!

**Syntax:**
```bash
case $some_variable in

    pattern_1)
        commands
        ;;
    
    pattern_2| pattern_3)
        commands
        ;;
    
    *)
        default commands
        ;;
esac
```

A quick rundown of the structure:    

- All `case` statements start with the `case` keyword.
- On the same line as the `case` keyword, we need to specify a variable or an expression followed 
- After that, we have the `case` patterns, where we need to use `)` to identify the end of the pattern.
- We can specify multiple patterns divided by a pipe: `|`.
- After the pattern, we specify the commands that we would like to be executed in case that the pattern matches the variable or the expression that we've specified!
- All clauses have to be terminated by adding `;;` at the end.
- We can have a default statement by adding a `*` as the pattern.
- To close the `case` statement, use the `esac` keyword (this is `case` typed backwards -> `esac`).


Let's check an example of case:

```bash
#!/bin/bash

echo -n "Enter the name of a car brand: "
read car

case $car in

    Tesla)
        echo -n "${car}'s factory is in the USA."
        ;;

    BMW | Mercedes | Audi | Porsche)
        echo -n "${car}'s factory is in Germany."
        ;;

    Toyota | Mazda | Mitsubishi | Subaru)
        echo -n "${car}'s factory is in Japan."
        ;;
    *)
        echo -n "${car} is an unknown car brand."
        ;;
esac
```

For more examples of Bash `case` statements, make sure to check [16_](). We build a interactive menu in Bash using cases to process the user input.














