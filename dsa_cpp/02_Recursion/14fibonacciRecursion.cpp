#include <iostream>
#include <stdlib.h>
#include <stdio.h> 

using namespace std; 

int fib(int n)              //using recursion
{
    if(n<=1)
        return n;
    return fib(n-2)+fib(n-1);
}

int fibloop(int n)          //using loops/ iteration
{
    int t0 = 0,t1 = 1, s = 0, i;
    if(n<=1) return n;

    for(i=2;i<=n;i++)
    {
        s=t0+t1;
        t0=t1;
        t1=s;
    }
    return s;
}

// fibonnaci recursion + memoization
int F[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
int fibrecursion(int n)
{
    if(n<=1)
    {
        F[n] = n;
        return n;
    }
    else
    {
        if(F[n-2]==-1)
            F[n-2]=fib(n-2);
        if(F[n-1]==-1)
            F[n-1]=fib(n-1);
        return F[n-2]+F[n-1];
    }
}


int main()
{
    cout << fib(7) << " ";
    cout << fibloop(7) << " ";
    cout << fibrecursion(7) << " ";
    return 0;
}