/*
Stripping off the lowest set bit :
In many situations we want to strip off the lowest set bit for example in Binary Indexed tree data structure, counting number of set bit in a number.

We do something like this:

X = X & (X-1)
But how does it even work ?

Let us see this by taking an example, let X = 1100.

(X-1)  inverts all the bits till it encounter lowest set ‘1’ and it also invert that lowest set ‘1’.

X-1 becomes 1011. After ‘ANDing’ X with X-1 we get lowest set bit stripped.
*/


#include <iostream>
using namespace std;
void strip_last_set_bit(int &num)
{
    num = num & (num-1);
}
int main()
{
    int num = 7;
    strip_last_set_bit(num);
    cout << num << endl;
    return 0;
}
