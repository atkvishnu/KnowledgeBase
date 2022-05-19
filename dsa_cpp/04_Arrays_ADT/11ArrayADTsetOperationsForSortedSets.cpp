// union, intersection, difference, set membership upon set of elements stored in ARRAYS!
// We will use the same merge function for SORTED SETS and convert it into fns. for union, intersection, difference

// Take 2 examples, i.e, 1 of unsorted arrays and 1 of Sorted arrays, we can do this just by changing the elements stored in struct A and B

#include <iostream>
#include <stdlib.h>
#include <stdio.h> 
#include <cstring>

using namespace std; 

//structure of array having 3 components: A pointer, size, and length----------------------------------------------------------------------
struct Array
{
    int A[10];
    int size;
    int length;
};

//Display function - It takes Array structure(arr) as input and iterates through the array and prints the elements!------------------------
void Display(struct Array arr)
{
    printf("\nElements are : \n");
    for(int i = 0;i<arr.length;i++)
        printf("%d ", arr.A[i]);
}


//Merge operation--------------------------------------------------------------------------------------------------------------------------
struct Array* Merge(struct Array *arr1, struct Array *arr2)         // return type should be "struct Array*" beause we are returning arr3
{
    int i, j, k;
    i=j=k=0;                                                        // IT has to be i=j=k=0 not i,j,k=0
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    // This loop compares the elements of array 1 and 2
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


// UNION of sorted elements ------------------------------------------------------------------------------------------------------------------------
struct Array* Union(struct Array *arr1, struct Array *arr2)         // return type should be "struct Array*" beause we are returning arr3
{
    int i, j, k;
    i=j=k=0;                                                        // IT has to be i=j=k=0 not i,j,k=0
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    // logic is same as merge only difference is if elements are same we don't copy it
    while (i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])         // if array1 elements are smaller copy in arr3 element of arr1 and i++, k++
            arr3->A[k++] = arr1->A[i++];
        else if(arr2->A[j]<arr1->A[i])      // if array2 elements are smaller
            arr3->A[k++] = arr2->A[j++];
        else                                // if elements are equal, then copy any 1 element and increment both i and j
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    for(;i<arr1->length; i++)
            arr3->A[k++]= arr1->A[i];
    for(;j<arr2->length; j++)
            arr3->A[k++]= arr2->A[j];
    arr3->length = k;       //arr3 is made in heap and it's length was not set
    arr3->size = 10;                                //arr3's size was also not set

    return arr3;                                    //as arr3 is created in heap we can return arr3, we also have to change the return type to "struct Array*" because we are returning an struct
}

// Intersection
struct Array* Intersection(struct Array *arr1, struct Array *arr2)         // return type should be "struct Array*" beause we are returning arr3
{
    int i, j, k;
    i=j=k=0;                                                        // IT has to be i=j=k=0 not i,j,k=0
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    // logic is same as merge only difference is if elements are same we copy it (i.e., only duplicates are copied)
    while (i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])         // if array1 elements are smaller move the i and j pointers ahead
        {i++;}
        else if(arr2->A[j]<arr1->A[i])      // if array2 elements are smaller move the i and j pointers ahead
        {j++;}
        else                                // if elements are equal, then copy any 1 element and increment i, j and k
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    //removed the code for remaining elements because it's not needed here

    arr3->length = k;       //arr3 is made in heap and it's length was not set
    arr3->size = 10;                                //arr3's size was also not set

    return arr3;                                    //as arr3 is created in heap we can return arr3, we also have to change the return type to "struct Array*" because we are returning an struct
}

//DIFFERENCE ----(A-B)-----means we want all those elements of A which are not there in B-----------------------------------------------------------
struct Array* Difference(struct Array *arr1, struct Array *arr2)         // return type should be "struct Array*" beause we are returning arr3
{
    int i, j, k;
    i=j=k=0;                                                        // IT has to be i=j=k=0 not i,j,k=0
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    // logic is same as merge only difference is we want all elements of arr1 which are not there in arr2
    while (i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])         // if array1 elements are smaller copy in arr3 element of arr1 and i++, k++ and j++
            arr3->A[k++] = arr1->A[i++];
        else if(arr2->A[j]<arr1->A[i])      // if array2 elements are smaller we should only increment j
            j++;
        else                                // if elements are equal, then DO NOT copy and increment both i and j
        {
            i++;j++;
        }
    }
    for(;i<arr1->length; i++)
            arr3->A[k++]= arr1->A[i];
    //copy remaining elements only from array1 NOT from array2

    arr3->length = k;       //arr3 is made in heap and it's length was not set
    arr3->size = 10;                                //arr3's size was also not set

    return arr3;                                    //as arr3 is created in heap we can return arr3, we also have to change the return type to "struct Array*" because we are returning an struct
}


int main()
{
    struct Array arr1={{2,6,10,15,25},10,5};
    struct Array arr2={{3,6,7,15,20},10,5};
    struct Array *arr3;

    // arr3 = Union(&arr1, &arr2);
    // arr3 = Intersection(&arr1, &arr2);
    arr3 = Difference(&arr1, &arr2);

    //for set membership operation we can use the /search/ operation which we have written before!

    Display(*arr3);     // Display takes call by value that's why we need to take "*arr3"  

    return 0;
}