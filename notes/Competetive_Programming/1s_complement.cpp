/*
Inverting every bit of a number/1’s complement:
If we want to invert every bit of a number i.e change bit ‘0’ to ‘1’ and
bit ‘1’ to ‘0’.We can do this with the help of ‘~’ operator.
For example : if number is num=00101100 (binary representation)
so ‘~num’ will be ‘11010011’.
This is also the ‘1s complement of number’.
*/
#include <iostream>
using namespace std;
int main()
{
    int num = 4;

    // Inverting every bit of number num
    cout << (~num);
    return 0;
}
