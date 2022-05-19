// C code for creating array in a heap

#include <iostream>
#include <stdlib.h>
#include <stdio.h> 

using namespace std; 

//structure of array having 3 components: A pointer, size, and length
struct Array
{
    int A[10];
    int size;
    int length;
};

//Display function - It takes Array structure(arr) as input and iterates through the array and prints the elements!
void Display(struct Array arr)
{
    printf("\nElements are \n");
    for(int i = 0;i<arr.length;i++)
        printf("%d ", arr.A[i]);
}

// Add/Append function
void Append(struct Array *arr, int x)       // as the value is going to be modified in arr, therefore it has to be call by address i.e. *arr AND x is the value that we want to insert
{
    if(arr->length < arr->size)             // read "->" as "ka" i.e, "arr->size" means "arr ka size". All the elements in the structure arr needs to be called using ->
        arr->A[arr->length++] = x;
}


// Insert function
void Insert(struct Array *arr, int index, int x)    // call by address
{
    if(index >= 0 && index <= arr->length)
    {
        for(int i=arr->length; i>index; i--)
            arr->A[i] = arr->A[i-1];
        arr->A[index] = x;
        arr->length++;
    }
}

int main()
{
    struct Array arr={{1,2,3,4,5},10,5};   //struct Array arr = {{Elements of the array}, size of the array = 20, number of elements = 5}  -> declaration + initialization

    Append(&arr,10);
    Insert(&arr, 0,10);
    Display(arr);

    return 0;
}