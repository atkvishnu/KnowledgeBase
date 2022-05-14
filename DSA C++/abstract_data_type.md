# Abstract Data Type (ADT)

- In CS, an ADT is a mathemetical model for various data types.
- An ADT is defined by its behaviour from the POV of a user, of the data, specifically in terms of possible value, possible operations on data of this type, and the behavious of these operations.
- This mathematical model contrasts with data structures, which are concrete representations of data, and are the POV of an implementer, not the user!

> ADT -> POV of the user  
> Data Structures -> POV of the implementer

- In practice, many common data types are not ADTs, as the abstractions is not perfect, and users must be aware of issues like *arithmetic overflow*. that are due to the representation. Ex. integers are often stored as fixed-width values(32-bit or 64-bit binary numbers), and thus experience integer overflow if the maximum value is exceeded.

- ADTs are a theoretical concept, in computer science, used in design and analysis of algorithms, data structures, and software systems.

- ADT's are often implemented as **modules**: the module's interface declares procedures that correspond to the ADT opeartions. *This **information hiding** strategy allows the implementation of the module to be changed without disturbing the client programs.*

> The concept of ADTs is related to the concept of **data abstraction** (which is important in **OOP** and **design by contract** methedologies for software development.)

## ADT's

- It is a type (or class) of objects whose behaviour is defined by a set of values and a set of operations. 
- The user interacts with the interface, using the operations that have been specified by the abstract data type. 
- It offers a high level use of a concept independent of it’s implementation. 
- They  package data structure and operations on them hiding internal details.

![](https://media.geeksforgeeks.org/wp-content/uploads/20210614194148/Screenshot20210614194018.jpg)

- Examples – Use a class with private data and public functions to represent the record.

```cpp
public class date
{
 private int day;
 private string  month;
 private int year;
};
public  void increment ()
{
 return day;
}
```

- Ex. Integers are an ADT, defined as the values ....,-2,-1,0,1,2,...., and by the operations of +, -, *, /, >, <, etc. which behave according to familiar mathematics.
- Explicitily, "behavious" includes obeying various axioms (associativity and commutativity of addition, etc.), and preconditions on operations (cannot divide by 0).
- Typically integers are represented in a data structures as binary number, mmost often as *2's complement*, but might be binary-coded decimal or in *1's complement*, but the user is abstracted feom the concrete choice of representation, and can simply use the data as data types.

    
        
- Ex. an abstract **stack** (LIFO), could be defined by 3 operations:
    + **push** (inserts a data item onto the stack)
    + **pop** (removes a data item from it)
    + **peek/top** (accesses a data item on top of the stack without removal.)

- Ex. an abstract **queue** (FIFO), would also have 3 operations:
    + **enqueue** (inserts a data item into the queue).
    + **dequeue** (removes the first data item from it)
    + **front** (accesses and serves the first data item in the queue)

> - There will be no way to differentiating between these two data types unless a mathematical constraint is introduced that for a stack specifies that each pop always returns the most recently pushed item that has not been popped yet.
> - When analyzing the efficiency of algorithms that use stacks, one may also specify that all operations take the same time no matter how many data items have been pushed into the stack, and that the stack uses a constant amount of storage for each element.

# Defining an ADT

An ADT is defined as mathematical model of the data objects that make up a data type as well as the functions that operate on these objects. There are no standard conventions for defining them.

- A broad devision may be drawn between "imperative" and "functional" definitions styles.

## Imperative-style definition
In the philosophy of imperative programming languages, an abstract data structure is conceived as an entity that is **mutable** - meaning that it may be in different states at different times.  
Some operations may change the state of the ADT; therefore, the order in which operations are evaluated is important, and the same operation on the same entities may have different effects if executed at different times - just like the instructions of a computer, or the commands and procedures of an imperative language.   
To underscore this view, it is customary to say that the operations are executed or applied, rather than evaluated. The imperative style is often used when describing abstract algorithms.

### Abstract variable
Imperative-style definitions of ADT often depend on the concept of an abstract variable, which may be regarded as the simplest non-trivial ADT. An abstract variable V is a mutable entity that admits two operations:

- `store(V, x)` where x is a value of unspecified nature;
- `fetch(V)`, that yields a value,
with the constraint that

`fetch(V)` always returns the value x used in the most recent `store(V, x)` operation on the same variable V.
As in so many programming languages, the operation `store(V, x)` is often written V ← x (or some similar notation), and `fetch(V)` is implied whenever a variable V is used in a context where a value is required. Thus, for example, V ← V + 1 is commonly understood to be a shorthand for `store(V,fetch(V) + 1)`.

In this definition, it is implicitly assumed that storing a value into a variable U has no effect on the state of a distinct variable V. To make this assumption explicit, one could add the constraint that

- if U and V are distinct variables, the sequence { store(U, x); store(V, y) } is equivalent to { store(V, y); store(U, x) }.

### Instance creation   

Some algorithms need to create new instances of some ADT (such as new variables, or new stacks). To describe such algorithms, one usually includes in the ADT definition a create() operation that yields an instance of the ADT, usually with axioms equivalent to
- the result of create() is distinct from any instance in use by the algorithm.
This axiom may be strengthened to exclude also partial aliasing with other instances. On the other hand, this axiom still allows implementations of create() to yield a previously created instance that has become inaccessible to the program.

#### Example: abstract stack (imperative)

As another example, an imperative-style definition of an **abstract stack** could specify that the state of a stack `S` can be modified only by the operations

- `push(S, x)`, where x is some value of unspecified nature;
- `pop(S)`, that yields a value as a result,
with the constraint that

- For any value x and any abstract variable V, the sequence of operations { push(S, x); V ← pop(S) } is equivalent to V ← x.
    
Since the assignment V ← x, by definition, cannot change the state of S, this condition implies that `V ← pop(S)` restores `S` to the state it had before the `push(S, x)`. From this condition and from the properties of abstract variables, it follows, for example, that the sequence

`{ push(S, x); push(S, y); U ← pop(S); push(S, z); V ← pop(S); W ← pop(S) }`
where x, y, and z are any values, and U, V, W are pairwise distinct variables, is equivalent to

`{ U ← y; V ← z; W ← x }`
Here it is implicitly assumed that operations on a stack instance do not modify the state of any other ADT instance, including other stacks; that is,

For any values x, y, and any distinct stacks S and T, the sequence `{ push(S, x); push(T, y) }` is equivalent to `{ push(T, y); push(S, x) }`.
An abstract stack definition usually includes also a Boolean-valued function empty(S) and a create() operation that returns a stack instance, with axioms equivalent to

- `create()` ≠ S for any prior stack S (a newly created stack is distinct from all previous stacks);
- empty(`create()`) (a newly created stack is empty);
- not empty(`push(S, x)`) (pushing something into a stack makes it non-empty).


#### Single-instance style
Sometimes an ADT is defined as if only one instance of it existed during the execution of the algorithm, and all operations were applied to that instance, which is not explicitly notated. For example, the abstract stack above could have been defined with operations push(x) and pop(), that operate on the only existing stack. ADT definitions in this style can be easily rewritten to admit multiple coexisting instances of the ADT, by adding an explicit instance parameter (like S in the previous example) to every operation that uses or modifies the implicit instance.

On the other hand, some ADTs cannot be meaningfully defined without assuming multiple instances. This is the case when a single operation takes two distinct instances of the ADT as parameters. For an example, consider augmenting the definition of the abstract stack with an operation compare(S, T) that checks whether the stacks S and T contain the same items in the same order.


Advantages of abstract data typing

Encapsulation - Abstraction provides a promise that any implementation of the ADT has certain properties and abilities; knowing these is all that is required to make use of an ADT object.


Localization of change
Code that uses an ADT object will not need to be edited if the implementation of the ADT is changed. Since any changes to the implementation must still comply with the interface, and since code using an ADT object may only refer to properties and abilities specified in the interface, changes may be made to the implementation without requiring any changes in code where the ADT is used.

Flexibility
Different implementations of the ADT, having all the same properties and abilities, are equivalent and may be used somewhat interchangeably in code that uses the ADT. This gives a great deal of flexibility when using ADT objects in different situations. For example, different implementations of the ADT may be more efficient in different situations; it is possible to use each in the situation where they are preferable, thus increasing overall efficiency.



# Typical operations

Some operations that are often specified for ADTs (possibly under other names) are

- `compare(s, t)`, that tests whether two instances' states are equivalent in some sense;
- `hash(s)`, that computes some standard hash function from the instance's state;
- `print(s)` or `show(s)`, that produces a human-readable representation of the instance's state.

In imperative-style ADT definitions, one often finds also

- `create()`, that yields a new instance of the ADT;
- `initialize(s)`, that prepares a newly created instance s for further operations, or resets it to some "initial state";
- `copy(s, t)`, that puts instance s in a state equivalent to that of t;
- `clone(t)`, that performs s ← create(), copy(s, t), and returns s;
- `free(s)` or `destroy(s)`, that reclaims the memory and other resources used by s.

The free operation is not normally relevant or meaningful, since ADTs are theoretical entities that do not "use memory". 
However, it may be necessary when one needs to analyze the storage used by an algorithm that uses the ADT. In that case, one needs additional axioms that specify how much memory each ADT instance uses, as a function of its state, and how much of it is returned to the pool by free.


# Examples

Some common ADTs, which have proved useful in a great variety of applications, are

- Collection
- Container
- List
- Set
- Multiset
- Map
- Multimap
- Graph
- Tree
- Stack
- Queue
- Priority queue
- Double-ended queue
- Double-ended priority queue

Each of these ADTs may be defined in many ways and variants, not necessarily equivalent. 

For example, an abstract stack may or may not have a count operation that tells how many items have been pushed and not yet popped. This choice makes a difference not only for its clients but also for the implementation.


# Abstract graphical data type

An extension of ADT for computer graphics was proposed in 1979: an abstract graphical data type (AGDT). 
It was introduced by `Nadia Magnenat Thalmann`, and `Daniel Thalmann`.

`AGDTs` provide the `advantages of ADTs` with `facilities to build graphical objects in a structured way`.



# Implementation

Implementing an ADT means providing one procedure or function for each abstract operation. 
The ADT instances are represented by some concrete/physical data structure that is manipulated by those procedures, according to the ADT's specifications.

Usually, there are many ways to implement the same ADT, using several different concrete data structures. 
Thus, for example, an abstract stack can be implemented by a linked list or by an array.


In order to prevent clients from depending on the implementation, an ADT is often packaged as an opaque data type in one or more modules, whose interface contains only the signature (number and types of the parameters and results) of the operations. The implementation of the module—namely, the bodies of the procedures and the concrete data structure used—can then be hidden from most clients of the module. This makes it possible to change the implementation without affecting the clients. If the implementation is exposed, it is known instead as a transparent data type.

When implementing an ADT, each instance (in imperative-style definitions) or each state (in functional-style definitions) is usually represented by a handle of some sort.

Modern object-oriented languages, such as C++ and Java, support a form of abstract data types. When a class is used as a type, it is an abstract type that refers to a hidden representation. In this model, an ADT is typically implemented as a class, and each instance of the ADT is usually an object of that class. The module's interface typically declares the constructors as ordinary procedures, and most of the other ADT operations as methods of that class. However, such an approach does not easily encapsulate multiple representational variants found in an ADT. It also can undermine the extensibility of object-oriented programs. In a pure object-oriented program that uses interfaces as types, types refer to behaviours, not representations.


Example: implementation of the abstract stack
As an example, here is an implementation of the abstract stack above in the C programming language.

Imperative-style interface
An imperative-style interface might be:

```c
typedef struct stack_Rep stack_Rep;       // type: stack instance representation (opaque record)
typedef stack_Rep* stack_T;               // type: handle to a stack instance (opaque pointer)
typedef void* stack_Item;                 // type: value stored in stack instance (arbitrary address)

stack_T stack_create(void);               // creates a new empty stack instance
void stack_push(stack_T s, stack_Item x); // adds an item at the top of the stack
stack_Item stack_pop(stack_T s);          // removes the top item from the stack and returns it
bool stack_empty(stack_T s);              // checks whether stack is empty
```

This interface could be used in the following manner:

```c
#include <stack.h>          // includes the stack interface

stack_T s = stack_create(); // creates a new empty stack instance
int x = 17;
stack_push(s, &x);          // adds the address of x at the top of the stack
void* y = stack_pop(s);     // removes the address of x from the stack and returns it
if (stack_empty(s)) { }     // does something if stack is empty
```

This interface can be implemented in many ways. The implementation may be arbitrarily inefficient, since the formal definition of the ADT, above, does not specify how much space the stack may use, nor how long each operation should take. It also does not specify whether the stack state s continues to exist after a call x ← pop(s).

In practice the formal definition should specify that the space is proportional to the number of items pushed and not yet popped; and that every one of the operations above must finish in a constant amount of time, independently of that number. To comply with these additional specifications, the implementation could use a linked list, or an array (with dynamic resizing) together with two integers (an item count and the array size).

Functional-style interface
Functional-style ADT definitions are more appropriate for functional programming languages, and vice versa. However, one can provide a functional-style interface even in an imperative language like C. For example:

```c
typedef struct stack_Rep stack_Rep;          // type: stack state representation (opaque record)
typedef stack_Rep* stack_T;                  // type: handle to a stack state (opaque pointer)
typedef void* stack_Item;                    // type: value of a stack state (arbitrary address)

stack_T stack_empty(void);                   // returns the empty stack state
stack_T stack_push(stack_T s, stack_Item x); // adds an item at the top of the stack state and returns the resulting stack state
stack_T stack_pop(stack_T s);                // removes the top item from the stack state and returns the resulting stack state
stack_Item stack_top(stack_T s);             // returns the top item of the stack state
```

ADT libraries
Many modern programming languages, such as C++ and Java, come with standard libraries that implement several common ADTs, such as those listed above.

Built-in abstract data types
The specification of some programming languages is intentionally vague about the representation of certain built-in data types, defining only the operations that can be done on them. Therefore, those types can be viewed as "built-in ADTs". Examples are the arrays in many scripting languages, such as Awk, Lua, and Perl, which can be regarded as an implementation of the abstract list.












# Concrete Data Structure/Types (CDT)

A concrete data type is the opposite of an abstract data type. 
It is a specialized solution-oriented data type that represents a well-defined single solution domain concept. 
A concrete data type is rarely reusable beyond its original use, but can be embedded or composed with other data types to form larger data types. 
They are direct implementations of a relatively simple concept. It does not hide anything. 

Examples – 
Use a struct with public data and no functions to represent the record 

```cpp
struct  date
{
 int day;
 string month;
 int year;
};
```

|Abstract Data Types or structure (ADT)|Concrete Data Types or structure (CDT)|
|:--:|:--:|
|Abstract Data Types or structures describe the data and the operations to manipulate and change it.|Concrete data types or structures provide  how these operations are actually implemented.| 
|Most of the program becomes independent of the abstract data types representation, so it can be improved without breaking the program.|Which is not possible in Concrete Data Types or structure (CDT)|
|It’s easier for each part of a program to use an implementation of its data types and that will be more efficient.|It is not so efficient compared to ADT.|
|Implementation of a high level concept|Implementation of a simple concept|
|It is usable beyond its original use.|	It is rarely reusable beyond its original use.|
|It hides the internal details.	|It doesn’t hide anything.|
|It uses class.	|It uses structure.|
|Examples- graphs, lists, sets, stacks, queues, priority queue, dictionary.|Examples-Arrays, linked lists, trees,heaps, hash table, boolean, integer, floating point, text, etc.|
| They are just ideas, i.e. "black boxes" with a defined behavior. To implement them, you have to choose a suitable concrete datatype.;
Abstract Data types can be constructed from known - or unknown data. |A concrete data type is absolutely defined. only certain inputs and outputs can exist in this.|


- **The abstract data type (ADT) is essentially an API, and a concrete data structure provides an implementation of that API. For a given ADT, there are often several different choices of concrete data structures which support the query and update operations described by the ADT.**

- Every concrete data structure for a given ADT must support all the operations described by the ADT (possibly with some probability of success in the case of randomized structures), but each concrete structure may make different guarantees of the running times of each operation. The choice of which concrete data structure to implement for a given ADT usually depends on the priorities of efficiency of each operation (including initializing the structure) and the complexity of implementing and maintaining the various data types.

- what is the difference between ADT and data structure? Simply put, an ADT (Abstract Data Type) is more of a logical description, while a Data Structure is concrete. Think of an ADT as a picture of the data and the operations to manipulate and change it. A Data Structure is the the real, concrete thing. It can be implemented and used within an algorithm.
- A concrete data type is a data type whose representation is known and relied upon by the programmers who use the data type.

- If you know the representation of a data type and are allowed to rely upon that knowledge, then the data type is concrete.

- If you `do not know` the representation of a data type and are not allowed to rely upon its representation, then the data type is abstract.

Examples of Concrete and Abstract Data Types:

- The MouseEvent data type defined by Racket is a concrete data type.
You know its values are strings, and you know the possible values of those strings (such as "button-down"). You are allowed to rely upon that representation when you write functions that process a MouseEvent.

- The structure types you designed and defined near the beginning of the semester were concrete types.
You knew the field names of each structure, and you relied upon that knowledge in your observer templates and in functions that used those observer templates.

- The char[] type of Java is concrete.
You know the values of that type are represented as 0-origin arrays of fixed length, and you know every element of those arrays is represented by a 16-bit integer.

- The List type of Java is abstract.
You do not know how values of that type are represented. A value of the List type might be a LinkedList, an ArrayList, a CopyOnWriteArrayList, or an object of some class defined by the course staff whose representation will never be revealed to you. Methods that are passed a List argument can observe properties of that argument by calling the methods listed by the List interface, but they cannot rely on the representation of the argument.
    
Note also that, in general, you do not even know whether a value of the List type is mutable. All of the methods listed by the List interface that are capable of modifying a list's state are optional. You cannot use optional methods unless a precondition or some other invariant tells you the methods are available for you to use.






![](https://www.thecshandbook.com/public_html/img/uploads/adt.png)


![Interfacing to a Abstract Data Type](https://www.tutorialscan.com/wp-content/uploads/2019/11/Abstract-data-types.jpg)


[***********PLEASE COMPLETE THIS***********](https://ece.uwaterloo.ca/~dwharder/aads/Projects/List/)





[complete list - NIST](https://xlinux.nist.gov/dads/)