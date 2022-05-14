// C code for creating array in a heap

// NOTE:
// If we are modifying the array,then we need to call it by address
// If we are NOT modifying the array,then we need to call it by value

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
    printf("\nElements are : \n");
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

//Delete function
int Delete(struct Array *arr, int index)
{
    if(index >=0 && index <= arr->length)
    {
        int x = arr->A[index];
        for (int i = index; i < arr->length-1; i++)
            arr->A[i] = arr->A[i+1];
        arr->length--;
        return x;
    }
    return 0;
}


//Linear Search
int BasicLinearSearch(struct Array arr, int key) //"search/call by value" is enough because we only have to look for a key we don't need to change anything
{
    for(int i=0;i<arr.length;i++)
    {
        if(key==arr.A[i])
            return i;
    }
    return -1;
}

void swap(int *x,int *y)    //swap is call by address
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int LinearSearchTransposition(struct Array *arr, int key)   //here we have to modify the array itself, for which we need call by address
{
    for(int i=0;i<arr->length;i++)
    {
        if (key==arr->A[i])
        {
            //Transposition: Element at A[i] is changed with element at A[i-1]
            swap(&arr->A[i], &arr->A[i-1]); //& is used because swap is a "call by address" fn.
            return i;
        }
    }
    return -1;
}

int LinearSearchMoveToHead(struct Array *arr, int key)
{
    for(int i=0;i<arr->length;i++)
    {
        if (key==arr->A[i])
        {
            swap(&arr->A[i], &arr->A[0]);
            return i;
        }
    }
    return -1;
}


int BinarySearchIter(struct Array arr, int key)   //It's only going to access the elements, Therefore call by value is sufficient.
{
    int l, mid, h;
    l=0;
    h = arr.length - 1;

    while(l <= h)
    {
        mid=(l+h)/2;
        if(key == arr.A[mid])
            return mid;
        else if(key < arr.A[mid])
            h = mid-1;
        else
            l = mid+1;
    }
    return -1;
}

int BinarySearchRecursive(int a[], int l, int h, int key)
{
    int mid;

    if(l<=h)
    {
        mid=(l+h)/2;
        if(key == a[mid])
            return mid;
        else if(key<a[mid])
            return BinarySearchRecursive(a, l, mid-1, key);
        else
            return BinarySearchRecursive(a, mid+1, h, key);
    }
    return -1;
}

int Get(struct Array arr, int index)
{
    if(index >=0 && index < arr.length)
        return arr.A[index];
    return -1;
}

void Set(struct Array *arr, int index, int x)     //we have to change the array Therefore use call by address
{
    if(index >=0 && index < arr->length)
        arr->A[index] = x;
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

int RecursiveSum(int A[], int n)
{
    if(n<0)
        return 0;
    else
        return RecursiveSum(A,n-1)+A[n];
}

float Avg(struct Array arr)
{
    return (float)Sum(arr)/arr.length;
}



int main()
{
    struct Array arr={{1,2,3,4,5},10,5};   //struct Array arr = {{Elements of the array}, size of the array = 20, number of elements = 5}  -> declaration + initialization

    // Append(&arr,10);
    // Insert(&arr, 0,10);
    // cout << "Deleted element is : " << Delete(&arr, 4) << endl;
    // cout << BasicLinearSearch(arr, 4) << endl;
    // cout << LinearSearchTransposition(&arr, 2) << endl;
    // cout << LinearSearchMoveToHead(&arr, 5) << endl;
    // cout << BinarySearchIter(arr, 10) << endl;
    // cout << BinarySearchRecursive(arr.A, 0, arr.length, 9) << endl;

    // cout << Get(arr, 9) << endl;
    // Set(&arr, 2, 1);
    cout << Max(arr) << endl;
    cout << Min(arr) << endl;
    cout << Sum(arr) <<  endl;
    cout << Avg(arr) << endl;

    cout << RecursiveSum(arr.A, 5);


    Display(arr);

    return 0;
}