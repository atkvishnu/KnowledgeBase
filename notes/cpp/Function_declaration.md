# Function declaration

























# Deleted functions

If, instead of a function body, the special syntax `= delete ;` is used, the function is defined as deleted. Any use of a deleted function is ill-formed (the program will not compile).

This includes calls, both explicit (with a function call operator) and implicit (a call to deleted overloaded operator, special member function, allocation function etc), constructing a pointer or pointer-to-member to a deleted function, and even the use of a deleted function in an unevaluated expression.

However, implicit ODR-use of a non-pure virtual member function that happens to be deleted is allowed.

If the function is overloaded, overload resolution takes place first, and the program is only ill-formed if the deleted function was selected:
```cpp
struct sometype
{
    void* operator new(std::size_t) = delete;
    void* operator new[](std::size_t) = delete;
};
sometype* p = new sometype; // error: attempts to call deleted sometype::operator new
```












