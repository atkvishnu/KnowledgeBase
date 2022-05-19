#include <iostream>
#include <stdlib.h>
#include <stdio.h> 

using namespace std; 

int fact(int i)
{
    if (i==1)
        return 1;
    return i*fact(i-1);
}

float power(float x, int i)
{
    if(i==1)
        return x;
    return x*power(x,i-1);
}

float compute(float x, int i, int sign)
{
    if(i==0)
        return 1;
    else
        return (sign*power(x,i)/fact(i)+compute(x,i-2,-1*sign));
}

int main()
{
    float x,Q,S;
    int N,sign;
    cin >> x >> N;
    Q = x;
    x = x*3.14/180;

    if((N%2)==0)
        sign = -1;
    sign = 1;

    S = compute(x,2*N-1,sign);
    cout << "cos(" << Q << ") = " << S;
    return 0;
}