//1. CALL BY VALUE (Available in C and C++)

#include <iostream>
#include <stdlib.h>
#include <stdio.h> 

using namespace std; 

int add(int a, int b)       //This is "call by value" mechanism, because these "formal parameters" are simple variables NOT pointers and they are not changing the "actual parameters" i.e. num1, num2!
{
    int c;
    c = a+b;

    return c;
}


int main()
{
    int num1 = 10, num2 = 15, sum;
    sum = add(num1,num2);           //These are "actual parameters"!
    cout << "Sum is: " << sum << endl;
}

//Values of num1 and num2 will be passed to a and b. The formal parameters will not change the actual parameters!
//Therefore this is an Call by Value!

//When to use Call by value?
//Call by value is used when we want a function to process something and return the result. It should take the values and return the results!
//Adding 2 numbers, Finding the maximum of numbers, Finding greatest of any numbers, Checking a number is a palindrome or not!

//When to use Call by value?
//-> When a function has to just process i.e., do the computation get some results and return those results!