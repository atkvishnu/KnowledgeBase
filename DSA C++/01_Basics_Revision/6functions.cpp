#include <iostream> 

using namespace std; 


int add(int a, int b)//a and b are formal parameters
{
    int c;
    c = a+b;
    return c;       
    //Since this function is an integer type that's why we need to return a integer. IF we don't want anything to be returned then use a void function!
}


int main()
{
    int num1 = 10, num2 = 15, sum;
    sum = add(num1,num2);   //num1,num2 here are actual parameters
    cout << sum << endl;

    return 0;
}