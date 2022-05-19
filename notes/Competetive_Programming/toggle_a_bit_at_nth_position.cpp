/*
3.  Toggling a bit at nth position :

Toggling means to turn bit ‘on'(1) if it was ‘off'(0) and to turn ‘off'(0) if it was ‘on'(1) previously.We will be using ‘XOR’ operator here which is this ‘^’. The reason behind ‘XOR’ operator is because of its properties.

Properties of ‘XOR’ operator.
1^1 = 0
0^0 = 0
1^0 = 1
0^1 = 1
If two bits are different then ‘XOR’ operator returns a set bit(1) else it returns an unset bit(0).
*/


#include <iostream>
using namespace std;
// First step is to shift 1,Second step is to XOR with given number
void toggle(int &num,int pos)
{
    num ^= (1 << pos);
}
int main()
{
    int num = 4;
    int pos = 1;
    toggle(num, pos);
    cout << num << endl;
    return 0;
}
