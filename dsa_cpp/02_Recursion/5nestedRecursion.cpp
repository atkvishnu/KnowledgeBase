#include <iostream>
#include <stdlib.h>
#include <stdio.h> 

using namespace std; 

int fun(int n)
{
    if(n>100)
        return n-10;
    else
        return fun(fun(n+11));
}

int main()
{
    cout << fun(95) << endl;
    cout << fun(21) << endl;
    cout << fun(31) << endl;            //for any n < 100, it will give the same output as 91
    cout << fun(110) << endl;           //for any n > 100, it will give the same output as 100
    return 0;
}