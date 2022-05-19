/*
4. Checking if bit at nth position is set or unset:

It is quite easily doable using ‘AND’ operator.



Left shift ‘1’ to given position and then ‘AND'(‘&’).
*/
#include <iostream>
using namespace std;

bool at_position(int num,int pos)
{
    bool bit = num & (1<<pos);
    return bit;
}

int main()
{
    int num = 5;
    int pos = 0;
    bool bit = at_position(num, pos);
    cout << bit << endl;
    return 0;
}
/*
Observe that we have first left shifted ‘1’ and then used ‘AND’ operator
to get bit at that position. So if there is ‘1’ at
position ‘pos’ in ‘num’, then after ‘AND’ our variable ‘bit’ will store
‘1’ else if there is ‘0’ at position ‘pos’ in the number ‘num’ than
after ‘AND’ our variable bit will store ‘0’.
*/
