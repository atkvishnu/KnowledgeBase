/*
2. How to unset/clear a bit at n’th position in the number ‘num’ :

Suppose we want to unset a bit at nth position in number ‘num’ then we have to do this with the help of ‘AND’ (&) operator.

First we left shift ‘1’ to n position via (1<<n) than we use bitwise NOT operator ‘~’ to unset this shifted ‘1’.
Now after clearing this left shifted ‘1’ i.e making it to ‘0’ we will ‘AND'(&) with the number ‘num’ that will unset bit at nth position position.
*/

#include <iostream>
using namespace std;
// First step is to get a number that  has all 1's except the given position.
void unset(int &num,int pos)
{
    //Second step is to bitwise and this  number with given number
    cout<< &num << " and " << num << '\n';
    num &= (~(1 << pos));
    cout<< &num << " and " << num << '\n';
}
int main()
{
    int num = 7;
    int  pos = 1;
    unset(num, pos);
    cout << num << endl;
    return 0;
}
