#include <iostream>
#include <stdlib.h>
#include <stdio.h> 

using namespace std; 

int main()
{
    int *p, *q;
    int i;


    p = (int *)malloc(5*sizeof(int));
    p[0]=3;p[1]=5;p[2]=7;p[3]=9;p[4]=11;

    q = new int[10];

    for(i=0;i<5;i++)
        q[i] = p[i];


    for(i=0;i<5;i++)
        cout << p[i] << " ";
    cout << endl;

    for(i=0;i<5;i++)
        cout << q[i] << " ";
    cout << endl;
    
    free(p);
    p = q;
    q = NULL;

    for(i=0;i<5;i++)
        cout << p[i] << " ";        //after deallocating array q by doing q = NULL, we can only access the array using p (bcoz, p = q i.e., p is pointing to q and q is NULL) 
    cout << endl;


    return 0;
}