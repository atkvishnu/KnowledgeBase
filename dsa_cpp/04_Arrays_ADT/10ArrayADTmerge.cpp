#include <iostream>
#include <stdlib.h>
#include <stdio.h> 
#include <cstring>

using namespace std; 

//structure of array having 3 components: A pointer, size, and length
struct Array
{
    int A[10];
    int size;
    int length;
};

//Display function - It takes Array structure(arr) as input and iterates through the array and prints the elements!----------
void Display(struct Array arr)
{
    printf("\nElements are : \n");
    for(int i = 0;i<arr.length;i++)
        printf("%d ", arr.A[i]);
}

struct Array* Merge(struct Array *arr1, struct Array *arr2)         // return type should be "struct Array*" beause we are returning arr3
{
    int i, j, k;
    i=j=k=0;                                                        // IT has to be i=j=k=0 not i,j,k=0
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }
    for(;i<arr1->length; i++)
            arr3->A[k++]= arr1->A[i];
    for(;j<arr2->length; j++)
            arr3->A[k++]= arr2->A[j];
    arr3->length = arr1->length+arr2->length;       //arr3 is made in heap and it's length was not set
    arr3->size = 10;                                //arr3's size was also not set

    return arr3;                                    //as arr3 is created in heap we can return arr3, we also have to change the return type to "struct Array*" because we are returning an struct
}


int main()
{
    struct Array arr1={{2,6,10,15,25},10,5};
    struct Array arr2={{3,4,7,18,20},10,5};
    struct Array *arr3;

    arr3 = Merge(&arr1, &arr2);

    Display(*arr3);     // Display takes call by value that's why we need to take "*arr3"  

    return 0;
}