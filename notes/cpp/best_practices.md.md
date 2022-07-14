# **Motivation:**

I can see on leetcode most C++ solutions (even the most upvoted) are not following C++ good practices, such as (but not limited to):

-   lack of const correctness
-   lack of memory management (ie. code leaking memory)
-   ignorance of memory locality and not taking advantage of cache memory of modern computer hardware
-   abuse of pass by copy semantic (vs pass by reference semantic)
-   use of deprecated style (ie, not using modern C++ idioms such as rangefor loops, auto variables...)
-   lack of use of the Standard library (ie: computing a sum manually instead of using accumulate (AKA reinventing the wheel + adding potential bugs)
-   use of C functions instead of their C++ equivalent (eg initializing a vector with memset)

---

# **Who would get benefit from reading this article?**

-   You are a complete beginner in C++
-   Practiced C++ for less than 5 years and / or have no experience with modern C++ (post C++11)
-   You come from a different language and you think the job is done when the program compile:
    -   You are a C programmer that wants to get a job as a C++ developper (spoiler alert: you have strong basis, you just need to think differently)
    -   You are a Python programmer that wants to get a job as a C++ developper (spoiler alert: modern C++ is very pythonic!)
    -   You are a Java programmer that wants to get a job as a C++ developper (spoiler alert: Forget about your Java habits!)

---

# **How do I know I really need to improve my C++ skills?**

To keep things simple, anybody that ticks **AT LEAST ONE** of the following points:

-   Never read a **GOOD** book on C++
-   Never visited [https://isocpp.org/](https://isocpp.org/) website
-   Dont visit [https://en.cppreference.com/w/](https://en.cppreference.com/w/) on a daily / very regular basis
-   Dont visit [https://stackoverflow.com/](https://stackoverflow.com/) on a daily / very regular basis
-   Never heard of CPP Con (or other C++ conference)
-   Do not know **AT LEAST ONE** of the following term:
    -   RAII
    -   static initialization order fiasco
    -   Move Semantics
    -   Undefined Behavior
-   Have not practiced professionnally Modern C++ (>= C++11)

**NOTE:** There are obviously exception, please dont get offended if you tick one of those boxes and you feel I'm terribly wrong (you have already my sincere apologies :-)

**NOTE 2:** If you feel I'm very wrong about that list, I encourage you to test your C++ skills by answering some quiz questions on this site : [http://cppquiz.org/](http://cppquiz.org/) (warning: this can be a violent reality check! :-) )

---

# **Why does this matter?**

After all, why should you care about all of these things written by some random user?

-   For Job interviews:
    -   LeetCode helps you to prepare for problem solving questions, it doesnt necessarily help you to improve your c++ skills
    -   Any Company / Interviewer that is serious about C++ will ask you some question that will uncover approximative knowledge about the language
-   When you have your job:
    -   on a daily basis, you will have to face code review evaluation, you dont want people to reject your code regularly (and make you feel insecure for your next evaluation)
    -   you will have to read others code, you might feel lost if you encounter real modern c++ and have to modify it
    -   others will read your code and they will not appreciate to spend time decyphering your old code style and/or having to refactor your yet compiling but bad/deprecated style code
    -   for all these reasons, you better have be familiar with modern C++ and good practices in general
-   For other LeetCode users:  
    You will help to improve the quality of C++ solution on LeetCode and beginners will learn good habits from you!

---

# **Ok Ok, but so far, you are not helping anybody here!**

True, but actually the most important here for you is to realize where you are in your journey to learning C++.  
I dont pretend to give you all the keys for writting proper C++ (as I dont know them all myself).  
However, I can give you:

-   a list of **TRUSTED references** for improving your knowledge of C++
-   a selection of basic points on which you can focus

## **What can I do to improve the quality of my C++ solutions on leetcode?**

NOTE: I might provide concrete example later if therer is any demand for it.

-   Important things that any decent C++ programer should do:
    -   Pay attention to const correctness
    -   Be careful of copy semantics
    -   Dont Leak Memory!!!
    -   USE THE STL!!!
    -   Use modern C++ features
    -   Use iterators instead of indices (when you can)
    -   Pay for what you need, and only for that

### 1 - Pay attention to const correctness:

That's very simple: if you pass by reference (or pointer) some variable to a function that does not modify the variable, just pass a a const ref or a pointer to const

### 2 - Be careful of copy semantics

That's a classic mistake from beginners, for example, if you pass a vector to a function and you dont modify it, make sure you pass it by const ref, and not by copy

### 3 - Dont Leak Memory!!!

When Leetcode asks you to remove some elements (from a linked list generally) dont forget to delete the pointer!  
An interviewer will not miss that and you would definetly fail in the context of an interview if you miss that.

### 4 - _**USE THE STL!!!**_

When ever you can, always try to use functions from std::algorithms and the standard library in general  
Dont compute a sum manually! just use std::accumulate instead!  
The STL offers you a fantastic toolbox for crafting your algorithms, using it will have many benefits:

-   your code will look familiar other c++ users
-   your code will be more concise and more readable
-   you will not spend time reinventing the weel for simple things
    -   that will enable you to focus on solving the problem rather than sub problems
    -   that reduces the risks of bugs you might introduce when doing it yourself
-   Dont use functions from the C library, favor their C++ counterpart

### 5 - Use modern C++ features

-   Really, you should use this:
    -   Almost Always use auto
    -   use rangefor loops
    -   use std::array instead of plain C arrays
    -   use initializer lists / uniform intialisation {}
-   Some nice features from C++17 you might <3 :
    -   string_view
    -   If Statements with Initializer
    -   structured binding

### 6 - Use iterators (when you can):

Iterators are everywhere in the STL, C++ programmers are used to reason about them, so get familiar to using iterators instead of indices (C style programming)  
But be pragmatic, sometimes iterators can obfuscate a bit the code and would make your solution unnecessarily complex.  
Also, generally, pass iterators by copy, not by reference (while it might be useful sometimes to pass an iterator by reference)

**NOTE:** This advice might be deprecated / less important with the arrival of ranges library in C++20  
**NOTE2:** Iterators are not hashable so dont use them **if you want to put them into an unordered_set/map** (constant time vs set/map n log n complexity )

### 7 - Pay for what you need, and only for that

This is the whole phylosophy of C++ and that should drive your coding style most of the time (being pramatic as well).  
This means: **Use the right tool for the job**

For example:

-   dont use `std::sort` when you actually only need `std::partial_sort`
-   dont use `std::partial_sort` when what you actually need is `std::nth_element`
-   you get the idea...

Some do and donts :

-   prefer preincrement `++variable` to post increment `variable++`, post-increment requires to store the actual value in a temp, increment the variable then return the temp.

```
/* dont do this (if you dont really need to) */
for(int i = 0; i != end; i++){...}

/* prefer this form instead when possible */
for(int i = 0; i != end; ++i){...}
```

-   Dont use `size()` function to check for emptyness, use `empty()` instead :

```
/* dont do this */
if(cont.size() == 0) {...}
/* or this */
if(!cont.size()){...}

/*use empty() member function instead */
if(cont.empty()){...}
```

-   Dont call container.size() multiple times in a loop when you actually only need it once:

```
/* dont do this : */
for(int i = 0; i != container.size(); ++i){...}

/* use a loop variable */
for(int i = 0, size = container.size(); i != size; ++i){...}
```

Provided you are NOT changing the size of the container within the loop!

## **Where can I find reliable sources of information for learning C++?**

DISCLAIMER: this is a **SHORT SELECTION**, many other sites, books, conferences and videos are great ressources as well.

-   Some Great Websites:
    
    -   [https://isocpp.org/](https://isocpp.org/) : it all starts here!
    -   [https://isocpp.org/faq](https://isocpp.org/faq) : if you have questions about C++, have a look here first
    -   [C++ Core Guidelines](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#c-core-guidelines)
    -   [https://en.cppreference.com](https://en.cppreference.com/) : your bible
    -   [https://stackoverflow.com/](https://stackoverflow.com/) : your second bible
    -   [https://godbolt.org/](https://godbolt.org/) : to understand what the compiler is doing (not a source of information site though)
    -   [http://cppquiz.org](http://cppquiz.org/) : a fun way to test your C++ knowledge or feel depressed on how hard is c++ :-)
    -   [https://www.reddit.com/r/cpp/](https://www.reddit.com/r/cpp/) : reddit provide generally good information about C++
    -   in general, **avoid** job interview based & multi-languages coding sites **C++ information there are generally inacurate**
-   Some Great C++ Books
    
    -   A Tour Of C++ (Bjarne Stroustrup) : A great introduction for beginners
    -   The C++ Programming Language 4Th Edition (Bjarne Stroustrup) : A reference book from the author of C++
    -   Effective C++ (Scott Meyers) : A bit old but still a reference, a collection of idioms / items to avoid some C++ traps
    -   Effective Modern C++ (Scott Meyers) : A collection of items/idions to avoid some traps of C++
    -   C++ Concurrency in Action: Practical Multithreading (Anthony Williams) : A book focussing on the threading library
    -   [C++ 17 - The Complete Guide](https://www.cppstd17.com/) (Nicolai M. Josuttis): A book about the additions of C++17
-   Video ressources
    
    -   **Avoid youtubers** / c++ boot camps videos / job interview c++ videos, **they often dont know c++ enough to teach it**
    -   [cppcon Youtube channel](https://www.youtube.com/user/CppCon)
    -   [Meeting C++ Youtube channel](https://www.youtube.com/c/MeetingCPP)
    -   [Cpp Now / BoostCon Youtube channel](https://www.youtube.com/user/BoostCon)
    -   A micro selection of talk any C++ programmer should have seen
        -   [Back to the basics](https://www.youtube.com/watch?v=xnqTKD8uD64) by Herb Sutter
        -   [C++ Seasoning](https://www.youtube.com/watch?v=W2tWOdzgXHA) by Sean Parent
        -   [Writing Good C++14](https://www.youtube.com/watch?v=1OEu9C51K2A) by God



<https://www.youtube.com/watch?v=xnqTKD8uD64>
<https://www.youtube.com/watch?v=W2tWOdzgXHA>
<https://www.youtube.com/watch?v=1OEu9C51K2A>