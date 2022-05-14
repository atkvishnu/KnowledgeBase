
# `const` keyword

Whenever `const` keyword is attached with any method(), variable, pointer variable, and with the object of a class - it prevents that specific object/method()/variable to modify its data items value.
    
### Rules for declaration and initialization of the const variables:

- The `const variable` cannot be left un-initialized at the time of the assignment.    
- It cannot be assigned value anywhere in the program.     
- Explicit value needed to be provided to the constant variable at the time of declaration of the constant variable.    

### Declarations:

- `int x = 5;`         // non-const value
- `const int x = 5;`      // const value

3 ways in which we can use const with pointers (syntax)
1. `const data_type* var_name;` // when the pointer variable points to a const value
- `const int *ptr_1 = &value;`      // ptr_1 points to a “const int” value, so this is a pointer to a const value.

2. `data_type* const var_name;` // when the const pointer variable point to the value
- `int *const ptr_2 = &value;`        // ptr_2 points to an “int”, so this is a const pointer to a non-const value.

3. `const data_type* const var_name;` // const pointer pointing to a const variable
- `const int *const ptr_3 = &value;`   // ptr_3 points to a “const int” value, so this is a const pointer to a const value.


>  Passing const-argument value to a non-const parameter of a function causes error: Passing const argument value to a non-const parameter of a function isn’t valid it gives you a compile-time error.

- **Constant Methods**

Objects of a class can also be declared as `const`.
An object declared as `const` cannot be modified and hence, can invoke only const member functions as these fns. ensure not to modify the object.

Syntax:
`const Class_Name Object_name;`
 
- When a function is declared as const, it can be called on any type of object, const object as well as non-const objects.
- Whenever an object is declared as const, it needs to be initialized at the time of declaration. However, the object initialization while declaring is possible only with the help of constructors.

There are 2 ways of a constant function declaration:

1. Ordinary const-function Declaration

```cpp
const void foo()
{
    // void foo() const not valid
}
int main() 
{
    foo(x);
}
```

2. A const member function of the class

```cpp
class
{
    void foo() const
    {
        // ....
    }
}
```

- **Constant function Parameter and Return Type**

A function() parameter and return type of function() can be declared as constant. Constant values cannot be changed as any such attempt will generate a compile-time error.

```cpp
// C++ program to demonstrate the above approach
#include <iostream>
using namespace std;
 
// Function foo() with variable
// const int
void foo(const int y)
{
    // y = 6; const value can't be change
    cout << y;
}
// Function foo() with variable int
void foo1(int y)
{
    // Non-const value can be change
    y = 5;
    cout << '\n' << y;
}

int main()
{
    int x = 9;
    const int z = 10;
    foo(z);
    foo1(x);
    return 0;
}
```

- **For const return type**:

The return type of the function() is const (i.e., it returns us a constant value.)

```cpp
// C++ program for the above approach
#include <iostream>
using namespace std;
 
const int foo(int y)
{
    y--;
    return y;
}
 
int main()
{
    int x = 9;
    const int z = 10;
    cout << foo(x) << '\n' << foo(z);
    return 0;
}
```
> Output :    
> 8   
> 9

- **For const return type and const parameter**

Here, both return type and parameter of the function are of const types.

```cpp
// C++ program for the above approach
#include <iostream>
using namespace std;
 
const int foo(const int y)
{
    // y = 9; it'll give CTE error as
    // y is const var its value can't
    // be change
    return y;
}
 
// Driver code
int main()
{
    int x = 9;
    const int z = 10;
    cout << foo(x) << '\n' << foo(z);
    return 0;
}
```

> Output:   
> 9   
> 10

> **Explanation :**
> Here, both const and non-const values can be passed as the const parameter to the function, but we are not allowed to then change the calue of a passed cariable because the parameter is const. Otherwise we will get a CTE.


---
---
---

# Const member function in C++

Like member functions and member function arguments, the objects of a class can also be declared as const. an object declared as const cannot be modified and hence, can invoke only const member functions as these functions ensure not to modify the object. 
A const object can be created by prefixing the const keyword to the object declaration. Any attempt to change the data member of const objects results in a compile-time error.   

A function becomes const when the `const` keyword is used in the function’s declaration. The idea of const functions is not to allow them to modify the object on which they are called. 

> **It is recommended the practice to make as many functions const as possible so that accidental changes to objects are avoided**.

```cpp
#include <iostream>
using namespace std;
 
class Test {
    int value;
 
public:
    Test(int v = 0) { value = v; }
 
    int getValue() const { return value; }
};
 
int main()
{
    Test t(20);
    cout << t.getValue();
    return 0;
}
```

> Output :   
> 20

- When a function is declared as const, it can be called on any type of object.
- Non-const functions can only be called by non-const objects.

Ex., following program has compiler errors

```cpp
#include<iostream>
using namespace std;
 
class Test {
    int value;
public:
    Test(int v = 0) {value = v;}
    int getValue() {return value;}
};
 
int main() {
    const Test t;
    cout << t.getValue();
    return 0;
}
```

another example

```cpp
// Demonstration of constant object,
// show that constant object can only
// call const member function
#include<iostream>
using namespace std;
class Demo
{
    int value;
    public:
    Demo(int v = 0) {value = v;}
    void showMessage()
    {
        cout<<"Hello World from showMessage() Function"<<endl;
    }
    void display()const
    {
        cout<<"from inside display() Function"<<endl;
    }
};
int main()
{
   //Constant object are initialised at the time of declaration using constructor
    const Demo d1;
    //d1.showMessage();Error occurred if uncomment.
    d1.display();
    return(0);
}
```

---
---
---


