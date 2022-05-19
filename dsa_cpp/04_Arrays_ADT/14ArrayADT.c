#include <stdio.h>
#include <stdlib.h>

struct Array
{
    //datamemberes of a structure Array
    int *A;
    int size;
    int length;
};

//Prototypes of the function
void Display(struct Array arr);
void Append(struct Array *arr, int x);
void Insert(struct Array *arr, int index, int x);
int Delete(struct Array *arr, int index);
void swap(int *x, int *y);
int LinearSearch(struct Array *arr, int key);
int BinarySearch(struct Array arr, int key);
int RBinSearch(int a[], int l, int h, int key);
int Get(struct Array arr, int index);
void Set(struct Array *arr, int index, int x);
int Max(struct Array arr);
int Min(struct Array arr);
int Sum(struct Array arr);
float Avg(struct Array arr);
void Reverse(struct Array *arr);
void Reverse2(struct Array *arr);
void InsertSort(struct Array *arr, int x);
int isSorted(struct Array arr);
void Rearrange(struct Array *arr);
void LeftShift(struct Array* arr, unsigned int n);
void LeftRotate(struct Array* arr, int n);
void RightShift(struct Array* arr, int n);
void RightRotate(struct Array* arr, int n);
struct Array* Merge(struct Array *arr1, struct Array *arr2);
struct Array* Union(struct Array *arr1, struct Array *arr2);
struct Array* Intersection(struct Array *arr1, struct Array *arr2);
struct Array* Difference(struct Array *arr1, struct Array *arr2);

void Display(struct Array arr)
{
    int i;
    printf("\nElements are: \n");
    for(i=0;i<arr.length;i++)
        printf("%d", arr.A[i]);
}

void Append(struct Array *arr, int x)
{
    if(arr->length<arr->size)
        arr->A[arr->length++] = x;
}

void Insert(struct Array *arr, int index, int x)
{
    int i;
    if(index>=0 && index<=arr->length)
    {
        for(i=arr->length;i>index;i--)
            arr->A[i] = arr->A[i-1];
        arr->A[index] = x;
        arr->length++;
    }
}

int Delete(struct Array *arr, int index)
{
    int x = 0;
    int i;

    if(index>=0 && index <arr->length)
    {
        x = arr->A[index];
        for(i=index;i<arr->length-1;i++)
            arr->A[i] = arr->A[i+1];
        arr->length--;
        return x;
    }
    return 0;
}

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int LinearSearch(struct Array *arr, int key)
{
    int i = 0;
    for(i; i< arr->length-1; i++)
    {
        if(key == arr->A[i])
            swap(&arr->A[i], &arr->A[0]);   // improvised Linear Search
            return i;
    }
    return -1;
}

int BinarySearch(struct Array arr, int key)
{
    int l,h,mid;
    l = 0;
    h = arr.length-1;
    
    while(l<=h)
    {
        mid = l+h/2;
        if(key == arr.A[mid])
            return mid;
        else if(key<arr.A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int RBinSearch(int a[], int l, int h, int key)      //Recursive Binary Search
{
    int mid;

    if(l<=h)
    {
        mid = l+h/2;
        if(key==a[mid])
            return mid;
        else if(key<a[mid])
            return RBinSearch(a,l,mid-1,key);
        else
            return RBinSearch(a,mid+1,h,key);
    }
    return -1;
}

int Get(struct Array arr, int index)
{
    if(index>=0 && index<arr.length)
        return arr.A[index];
    return -1;
}

void Set(struct Array *arr, int index, int x)
{
    if(index>=0 && index<arr->length)
        arr->A[index] = x;
    return -1;
}

int Max(struct Array arr)
{
    int max = arr.A[0];
    for(int i = 0; i<arr.length;i++)
    {
        if (arr.A[i]>max)
            max = arr.A[i];
    }
    return max;
}

int Min(struct Array arr)
{
    int min = arr.A[0];
    for(int i = 0; i<arr.length;i++)
    {
        if (arr.A[i]<min)
            min = arr.A[i];
    }
    return min;
}

int Sum(struct Array arr)
{
    int total = 0;
    for(int i=0;i<arr.length;i++)
    {
        total+=arr.A[i];
    }
    return total;
}


float Avg(struct Array arr)
{
    return (float)Sum(arr)/arr.length;
}

void Reverse(struct Array *arr)
{
    int *B;
    int i,j;
    B=(int *)malloc(arr->length*sizeof(int));
    // B = new int[arr->length];            //C++
    for(i=arr->length-1,j=0;i>=0;i--,j++)
        B[j] = arr->A[i];
    for(i=0;i<arr->length;i++)
        arr->A[i]=B[i];

}

void Reverse2(struct Array *arr)
{
    int i,j,temp;
    for(i=0,j=arr->length-1;i<j;i++,j--)
    {
        temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
        // OR
        // swap(&arr->A[i],&arr->A[j])
    }
}

void InsertSort(struct Array *arr, int x)
{
    int i = arr->length - 1;
    if(arr->length == arr->size)    //Checking if array has any free space or not for Inserting and sorting
        return;
    while(i>=0 && arr->A[i]>x)
    {
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = x;
    arr->length++;  /*as we have stored 1 element, the length should be incremented by 1*/
}

int isSorted(struct Array arr)
{
    for(int i=0;i<arr.length-1;i++)
    {
        if(arr.A[i]>arr.A[i+1])
            return 0;
    }
    return 1;
}

void Rearrange(struct Array *arr)
{
    int i = 0;
    int j = arr->length-1;
    while (i<j)
    {
        while (arr->A[i]<0)i++;
        while (arr->A[j]>=0)j--;
        if(i<j)swap(&arr->A[i],&arr->A[j]);     //because swap is call by address, we have to provide address to the pointer!
    }
    
}

// Left Shift-------------------------------------------------------------------------------------------------------

void LeftShift(struct Array* arr, unsigned int n)      //best      //SO-CodeReview
{
    int i;
    for (i = 0; i < arr->length; i++) {
        if (i + n < arr->length)
            arr->A[i] = arr->A[i + n];
        else
            arr->A[i] = 0;
    }
}

// Left Rotate------------------------------------------------------------------------------------------
void LeftRotate(struct Array *arr, int n)    //n is the number of shifts
{
    
    for(int i=0; i<n; i++)
    {
        int temp = arr->A[0];
        for(int j=0; j<arr->length-1; j++)
        {
            arr->A[j] = arr->A[j+1];
        }
        arr->A[arr->length-1] = temp;
    }
}

//Right Shift-------------------------------------------------------------------------------------------------------
void RightShift(struct Array *arr, int n)    //n is the number of shifts
{
    for(int i = 0; i<n; i++)
    {
        for(int j=arr->length-1; j>0; j--)
        {
            arr->A[j] = arr->A[j-1];
        }
        arr->A[0] = 0;
    }
    
}
// Right Rotate------------------------------------------------------------------------------------------
void RightRotate(struct Array *arr, int n)    //n is the number of shifts
{
    for(int i = 0; i<n; i++)
    {
        int temp = arr->A[arr->length-1]; 
        for(int j=arr->length-1; j>0; j--)
        {
            arr->A[j] = arr->A[j-1];
        }
        arr->A[0] = temp;
    }
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
    struct Array arr1;
    int ch;
    int x, index;

    do
    {
        printf("\n\nMenu\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Sum\n");
        printf("5. Display\n");
        printf("6.Exit\n");

        printf("enter you choice ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: printf("Enter an element and index");
            scanf("%d%d",&x,&index);
            Insert(&arr1,index,x);
            break;

            case 2: printf("Enter index ");
            scanf("%d",&index);
            x=Delete(&arr1,index);
            printf("Deleted Element is %d\n",x);
            break;

            case 3:printf("Enter element to search ");
            scanf("%d",&x);
            index=LinearSearch(&arr1,x);
            printf("Element index %d",index);
            break;

            case 4:printf("Sum is %d\n",Sum(arr1));
            break;
            
            case 5:Display(arr1);
        }
    }while(ch<6);

    return 0;
}
