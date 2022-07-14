# Definitions and ODR (One Definition Rule)

Definitions are declarations that fully define the entity introduced by the declaration.

DECLARATION -> then -> DEFINITION
DECLARE -> then -> DEFINE


---

Declaration - A declaration means that you are telling the compiler about type and sizes. 
In case of function declaration, type and size of its parameters of any variable, or user-defined type or function in your program.

- No space is reserved in memory for any variable in case of declaration!


Definition - means all the things declaration does + space is additionally reserved in memory.

Therefore, 
    `DEFINITION = DECLARATION + SPACE RESERVED`

Example of Declaration:

```cpp
extern int a;                           // Declaring a variable a without defining it
struct _tagExample { int a; int b; };   // Declaring a struct
int myFunc (int a, int b);              // Declaring a function
```

Example of Definition:

```cpp
int a;
int b = 0;
int myFunc (int a, int b) { return a + b; }
struct _tagExample example;
```

---



