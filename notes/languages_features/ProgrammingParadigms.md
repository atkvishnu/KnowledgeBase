#to-sort 
## Programming Paradigms

**Programming paradigms** refer to the style of writing the program depending on the programmer’s choice on how he chooses to place the different elements of programming in a sensible code. Most programming languages fall under only one programming paradigm but there are a few languages that can have multiple paradigms like C which is both _procedural_ and _functional programming language_.


Few common programming paradigms:

-   _**Procedural Programming**_: It is based on procedures and allows stepwise sequential execution(explained in detail below). 
	 Eg: C, Go, Fortran, Pascal, Ada, and BASIC

-   _**Functional Programming**_: It is mostly used for mathematical functions where it takes an argument and returns a value. 
	Eg: Common Lisp, Scheme, Clojure, Wolfram **Language,** F#, etc.

-   _**Object Oriented Programming**_: It is a programming language that makes use of objects which is a bundle of both data and methods. 
	 Eg: JAVA, C#, C++, VB.NET, etc.

-   _**Logical programming**_ : As the name suggests logical programming is based on logic, problem domains, relations and facts. 
	 Eg: Prolog, Datalog, ASP.


## Procedural Programming

**Procedural programming** stems from _Structured programming_ and is based on the concept of the _Procedure call_. It is a **programming paradigm** that makes use of _procedures_(also called _routines_, _subroutines,_ or _functions_). Most of the programming languages in the early days were Procedural. Procedural Programming is also known as Imperative Programming. It has well-structured computational steps which make use of features like **modularity** and **scoping** to enhance its readability and decrease its complexity.

**Modularity** refers to the systematic division of a complex code into small modules. It reduces the complexity of a program and makes it easier to find and edit any part of the code if required.

**Scoping** refers to enclosing the variables, constants, and other statements and functions in a module. Scoping and modularity are closely related as _scoping_ are used to implement _modularity_.

A program gets divided into small modules for which the variables have a scope and cannot/can be accessed by other functions according to the programmer’s choice.

Let’s have a look at a simple procedure of finding the maximum number from two user input numbers (flow chart).

![[https://www.codingeek.com/wp-content/uploads/2016/11/max-flowchart.png]]

Flow chart to find maximum of two numbers

Here we see a simple program in the form of a flow chart. Although this process can be done using other programming paradigms here we focus on the Procedural paradigm.

In the flow chart, we see sequential steps which show the actual flow of execution(based on decisions) that will be followed to execute the program. It goes sequentially by taking two numbers as input in the first step, comparing them in the second, and resulting in the output in the third step. Thus, we get a picture of how Procedural programming works.



## Procedural vs Object-Oriented Programming
-   In procedural programming the data and function are treated as different elements of a program whereas, in [OOP](https://www.codingeek.com/oops/object-oriented-programming-best-explanation/), both are wrapped into the same bundle known as an **object**.
-   In Procedural programming most of the data and variable have a global access because there are no access specifiers in Procedural Programming. On the other hand, OOP offers access specifiers which can restrict the usage of the data and variables to a particular method(Eg: public, private, protected,etc).
-   Procedural programming has a **Top-down** approach to programming whereas, OOP has the **Bottom-up** approach to programming.




## Procedural vs Functional Programming
-   Procedural programming follows a series of steps for the execution of the code, whereas, functional programming can randomly go to a step depending on the function it needs to perform.
-   Functional programming makes use of sub-routine calls or _tail calls_ and _higher order_ functions instead of _imperative loops_ used by procedural programming.
-   In Functional programming, programming is done by expressions and declarations rather than statements as used by procedural programming.

