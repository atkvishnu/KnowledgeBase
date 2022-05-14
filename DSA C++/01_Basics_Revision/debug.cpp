#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std; 

int main()
{

    int sum = 0;

    int A[] = {2,4,6,7,9};

    for (int x : A)
    {
        sum = sum + x;
        cout << x << endl;
    }

    cout << "Sum is : " << sum <<  endl;
    
    return 0;
}
