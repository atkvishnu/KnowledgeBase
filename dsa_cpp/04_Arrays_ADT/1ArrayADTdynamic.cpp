// C code for creating array in a heap

#include <iostream>
#include <stdlib.h>
#include <stdio.h> 

using namespace std; 

//structure of array having 3 components: A pointer, size, and length
struct Array
{
    int *A;
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
    struct Array arr;   //name of struct - arr
    int n,i;
    printf("Enter size of an array ");
    scanf("%d", &arr.size);     
    arr.A=(int *)malloc(arr.size*sizeof(int));
    arr.length = 0;

    printf("Enter number of numbers ");
    scanf("%d",&n);
    

    printf("Enter all the Elements \n");
    for(i=0;i<n;i++)
        scanf("%d",&arr.A[i]);
    arr.length = n;

    Display(arr);

    return 0;
}