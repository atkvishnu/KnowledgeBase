#include <iostream>
#include <stdlib.h>
#include <stdio.h> 

using namespace std; 

//nCr = n!/(r!*(n-r)!)
// We need 3 factorials: n!, r!, (n-r)!

int fact(int i)
{
    if (i==0)
        return 1;
    return i*fact(i-1);
}

//using 3 factorials
int C(int n, int r)
{
    int t1,t2,t3;
    t1 = fact(n);
    t2 = fact(r);
    t3 = fact(n-r);
    return t1/(t2*t3);
}


// using recursion
int Crecursion(int n,int r)
{
    if(r==0 || n==r)
        return 1;
    else
        return C(n-1,r-1)+C(n-1,r);
}

int main()
{
    cout << C(4,2) << " ";
    cout << Crecursion(4,2) << " ";
    return 0;
}