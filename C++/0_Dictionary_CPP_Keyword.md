# The Dictionary of C++ Keywords

C++ is a superset of C, therefore C++ is backward compatible to C!

There are some exceptions and additions!

### Token: 
When the compiler is processing the source code of the C++ program, each group of characters seperated by white space is called a token.
Tokens are the smallest individual units in a program.
A C++ program is written using Tokens.
It has the following Tokens:
- Keywords
- Identifiers
- Constants
- Strings
- Operators

![](https://media.geeksforgeeks.org/wp-content/uploads/20210507151607/token2.png)

## C Keywords 

|||||
|:--:|:--:|:--:|:--:|
|int|double|float|char|
|auto|const|void|goto|
|if|else|for|while|
|typedef|return|union|enum|
|signed|unsigned|short|long|
|break|continue|default|case|
|switch|sizeof|static|volatile|
|do|extern|struct|register|


1. `int` - Fundamental data type used to define integer objects.
1. `double` - Fundamental data type used to define a floating-point number.
1. `float` - Fundamental data type used to define a floating-point number.
1. `char` - Fundamental data type that defines character objects.
1. `auto` - The auto keyword declares automatic variables. Since automatic variables are local to a function, they are also called local variables.
1. `const` - To define objects whose value will not alter throughout the lifetime of program execution.
1. `void` - Absent of a type or function parameter list.
1. `if` - Indicate the start of an if statement to achieve selective control.
1. `else` - Used specifically in an if-else statement. if and else are used to make decisions.
1. `for` - Indicates the start of a statement to achieve repetitive control.
1. `while` - Start of a while statement and end of a do-while statement.
1. `typedef` - Synonym for another integral or user-defined type. It's is used to explicitly associate a type with an identifier.
    ```cpp
    typedef float kg;
    kg bear, tiger;
    ```
1. `return` - Returns an object to a function’s caller.
1. `union` - Similar to a structure, struct, in that it can hold different types of data, but a union can hold only one of its members at a given time. It's is used for grouping different types of variables under a single name.
    ```cpp
    union student {
        char name[80];
        float marks;
        int age;
    }
    ```
1. `enum` - To declare a user-defined enumeration data type. 
    ```cpp
    enum suit
    {
        hearts;
        spades;
        clubs;
        diamonds;
    };  // heart = 0, spades = 1, clubs = 2, diamond = 3  
    ```
1. `goto` - Transfer control to a specified label.
    ```cpp
    for(i=1; i<5; ++i)
    {
        if (i==10)
        goto error;
    }
    printf("i is not 10");
    error:
        printf("Error, count cannot be 10.");
    ```
1. `signed` - A data type modifier that indicates an object’s sign is to be stored in the high-order bit.    
`signed int : -32768 to 32767`
1. `unsigned` - A data type modifier that indicates the high-order bit is to be used for an object.    
`unsigned int : 0 to 65535`
1. `short` - A data type modifier that defines a 16-bit int number.
`short int : -32768 to 32767`
1. `long` - A data type modifier that defines a 32-bit int or an extended double.
`long int : -2147483648 to 214743648`
1. `break` - It terminates the innermost loop immediately when it's encountered. It's also used to terminate the switch statement.
    ```cpp
    for (i=1;i<=10;++i){
        if (i==3)
            continue;
        if (i==7)
            break;
        printf("%d ",i);
    } 
    ```
1. `continue` - It skips the statements after it's inside the loop for the iteration. (Transfers control to the start of a loop.)
1. `default` - Handles expression values in a switch statement that are not handled by case.
1. `case`- Used specifically within a switch statement to specify a match for the statement’s expression.
1. `switch` - The switch and case statement is used when a block of statements has to be executed among many blocks.
    ```cpp
    switch(expression)
    {
        case '1':
        //some statements to execute when 1
        break;
        case '5':
        //some statements to execute when 5
        break;
        default:
        //some statements to execute when default;
    }
    ```
1. `sizeof` - Returns the size of an object in bytes.
    ```cpp
    #include <stdio.h>
    int main()
    {
        printf("%u bytes.",sizeof(char));
    }
    ```
1. `static` - The lifetime of an object-defined static exists throughout the lifetime of program execution. (The static keyword creates a static variable. The value of the static variables persists until the end of the program.)
1. `volatile` - The volatile keyword is used for creating volatile objects. A volatile object can be modified in an unspecified way by the hardware.
    ```cpp
    const volatile number; // Here, number is a `volatile object`. 
    // Since number is a `constant`, the program cannot change it. However, hardware can change it since it is a volatile object.
    ```
1. `do` - indicate the start of a do-while statement in which the sub-statement is executed repeatedly until the value of the expression is logical-false.
    ```cpp
    int i;
    do 
    {
    printf("%d ",i);
    i++;
    }
    while (i<10)
    ```
1. `extern` - An identifier specified as extern has external linkage to the block.
1. `struct` - It's used for declaring a structure. A structure can hold variables of different types under a single name.
    ```cpp
    struct student{
        char name[80];
        float marks;
        int age;
    }s1, s2;
    ```
1. `register` - The register keyword creates register variables which are much faster than normal variables. (A storage class specifier that is an auto specifier, but which also indicates to the compiler that an object will be frequently used and should therefore be kept in a register.)
    ```cpp
    register int var1;
    ```


## C++ Keywords = C Keywords+⬇     
|||||
|:--:|:--:|:--:|:--:|
|asm|new|operator|template|
|private|this|protected|throw|
|public|try|catch|friend|
|virtual|inline|delete|class|

33. `asm` - To declare that a block of code is to be passed to the assembler.
33. `new` - Memory allocation operator.
33. `operator` - Overloads a c++ operator with a new declaration.
33. `template` - parameterized or generic type.
33. `private` - Declares class members which are not visible outside the class.
33. `this` - A class pointer points to an object or instance of the class.
33. `protected` - Declares class members which are private except to derived classes
33. `throw` - Generate an exception.
33. `public` - Declares class members who are visible outside the class.
33. `try` - Indicates the start of a block of exception handlers.
33. `catch` - Specifies actions taken when an exception occurs.
33. `friend` - A class or operation whose implementation can access the private data members of a class.
33. `virtual` - A function specifier that declares a member function of a class that will be redefined by a derived class.
33. `inline` - A function specifier that indicates to the compiler that inline substitution of the function body is to be preferred to the usual function call implementation.
33. `delete` - Memory deallocation operator.
33. `class` - To declare a user-defined type that encapsulates data members and operations or member functions.


## As of C++17
|||||
|:--:|:--:|:--:|:--:|
|alignas|decltype|namespace|alignof|
|typename|bool|noexcept|and_eq|
|not_eq|thread_local|dynamic_cast|nullptr|
|bitand|bitor|or|and|
|not|or_eq|explicit|export|
|true|false|char16_t|char32_t|
|reinterpret_cast|using|typeid|compl|
|wchar_t|constexpr|const_cast|static_assert|
|xor|mutable|static_cast|xor_eq|


49. `explicit` - is used to mark constructors to not implicitly convert types. It is optional for constructors that take exactly one argument and works on constructors(with single argument) since those are the only constructors that can be used in type casting.


















## C++ Identifiers

Identifiers are the unique names given to variables, classes, functions, or other entities by the programmer. For example,
```cpp
int money;
double accountBalance;
```
Here, money and accountBalance are identifiers.

### Rules for naming identifiers
- Identifiers can be composed of letters, digits, and the underscore character.
- It has no limit on name length.
- It must begin with either a letter or an underscore.
- It is case-sensitive.
- We cannot use keywords as identifiers.


>Examples of good and bad identifiers.

>|Invalid Identifier|	Bad Identifier|	Good Identifier|
>|:--:|:--:|:--:|
>|Total points|	T_points|	totalPoint|
>|1list|	list_1|	list1|
>|float|	n_float|	floatNumber|