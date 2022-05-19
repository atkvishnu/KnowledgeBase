#include <iostream>
#include <stdlib.h>
#include <stdio.h> 

using namespace std; 

int fact(int n)
{
    if (n==0){
        return 1;
    }
    else{
        return fact(n-1) * n;
    }
}


int Ifact(int n)
{
    int f = 1;
    for (int i = 1; i<=n;i++)
    {
        f *= i;
    }
    return f;
}

int main()
{
    cout << fact(5) << " ";
    cout << Ifact(5) << " ";
    return 0;
}