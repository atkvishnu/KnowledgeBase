#include <iostream> 

using namespace std; 

int main()
{
    int a = 10; //this will be ceated in the stack
    int &r = a;
    a = 25;

    int b = 30;
    r = b;  //this will make all r, b, a as 30


    cout << a << endl;
    r++;
    cout << a << ", " << r << endl;
    a++;
    r = r+1;
    cout << a << ", " << r << endl;
    return 0;
}