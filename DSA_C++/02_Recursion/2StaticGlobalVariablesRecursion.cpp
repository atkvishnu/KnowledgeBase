#include <iostream>
#include <stdlib.h>
#include <stdio.h> 

using namespace std; 

// int x = 0;   //global variable will also have the same effect.
int fun(int n)
{
    static int x = 0;       //static variables (They are declared in the code section)
    if(n > 0)
    {
        x++;
        return fun(n-1)+x;
    }
    return 0;
}

int main()
{
    int a = 5;
    int r = fun(a);
    printf("%d", r);
    return 0;
}