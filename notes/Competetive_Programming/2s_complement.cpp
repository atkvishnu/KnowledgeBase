/*
Two’s complement of the number: 2’s complement of a number is 1’s complement + 1.
So formally we can have 2’s complement by finding 1s complement and adding 1 to the
 result i.e (~num+1) or what else we can do is using ‘-‘ operator.
*/
#include <iostream>
using namespace std;
int main()
{
    int num = 4;
    int twos_complement = -num;
    cout << "This is two's complement " << twos_complement << endl;
    cout << "This is also two's complement " << (~num+1) << endl;
    return 0;
}
