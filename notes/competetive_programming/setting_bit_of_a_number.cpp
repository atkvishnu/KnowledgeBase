/*
1. How to set a bit in the number ‘num’ :

If we want to set a bit at nth position in number ‘num’ ,it can be done using ‘OR’ operator( | ).

First we left shift ‘1’ to n position via (1<<n)
Then, use ‘OR’ operator to set bit at that position.’OR’ operator is used because it will set the bit even if the bit is unset previously in binary representation of number ‘num’.

*/

#include <iostream>

using namespace std;

void set(int &num, int pos)
{
    cout<< &num << " and " << num << '\n';
    num |= (1<<pos);
    cout<< &num << " and " << num << '\n';
}

int main()
{
    int num = 4, pos = 1;
    set(num,pos);
    cout << "the value is: " << (int)(num) << endl;
    return 0;
}
