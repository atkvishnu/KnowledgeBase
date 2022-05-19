//USING AN ARRAY AS A PARAMETER

#include <iostream>
#include <stdlib.h>
#include <stdio.h> 

using namespace std; 

int * fun(int size)
{
    int *p;
#000000#000000#000000#000000#000000
    // p = (int *)malloc(size*sizeof(int));
    p = new int[size];

    for(int i=0;i<size;i++)
    p[i] = i+1;

    return p;

}


int main()
{
    
    int *ptr, sz = 6;

    ptr = fun(sz);

    for(int i=0;i<sz;i++)
    cout << ptr[i] << endl;

    system("pause>0");
}
