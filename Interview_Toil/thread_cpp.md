# Multithreading in C++


Multithreading support was introduced in C+11. Prior to C++11, we had to use `POSIX threads or p threads` library in C.
    

There was a `portability issue` because we `did not have standard library` which was provided by the CPP team.    

C++ 11 did away with all that and gave us `std::thread`.     

The thread classes and related functions are defined in the thread header file.    
`std::thread` is the thread class that represents a `single thread` in C++.


To start a thread we simply need to:
-  create a new thread object and pass the executing code to be called (i.e, a callable object) into the constructor of the object. 

- Once the object is created a new thread is launched which will execute the code specified in callable.




A callable can be either of the three

- A function pointer
- A function object
- A lambda expression

After defining callable, pass it to the constructor.




```cpp
#include <thread>
std::thread thread_object(callable);
```


### 1. Launching threads using function pointer


```cpp
void foo(param) {
	// DO SOMETHING
}

std::thread thread_obj(foo, params);
```














