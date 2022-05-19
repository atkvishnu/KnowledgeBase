// C code for creating array in a heap

#include <iostream>
#include <stdlib.h>
#include <stdio.h> 

using namespace std; 

//structure of array having 3 components: A pointer, size, and length
struct Array
{
    int A[20];
    int size;
    int length;
};

//Display function - It takes Array structure(arr) as input and iterates through the array and prints the elements!
void Display(struct Array arr)
{
    int i;
    printf("\nElements are \n");
    for(i = 0;i<arr.length;i++)
        printf("%d ", arr.A[i]);
}


int main()
{
    struct Array arr={{2,4,6,8,10},20,5};   //struct Array arr = {{Elements of the array}, size of the array = 20, number of elements = 5}  -> declaration + initialization

    Display(arr);

    return 0;
}