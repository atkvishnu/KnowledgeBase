#include <iostream>
#include <stdlib.h>
#include <stdio.h> 

using namespace std; 

//ERROR: funB was not declared in this scope

//defining a prototype of funB before funA, because funA is using funB

void funB(int n);


void funA(int n)
{
    if(n > 0)
    {
        cout << n << " ";
        funB(n-1);
    }
}

void funB(int n)
{
    if (n > 1)
    {
        cout << n << " ";
        funA(n/2);
    }
}


int main()
{
    funA(20);
    return 0;
}