#include <iostream>

using namespace std;

struct Array
{

private:                    //datamemberes are kept private
    int *A;
    int size;
    int length;
    void swap(int *x, int *y);      //swap fn. is written to be used inside another fn., so it's not available globally, It's made private, It's used by other fns.
    // swap is useful for internal usage of class. it is declared as private.
public:                     //functions are made public
    Array()                 //First fn. should be a constructor
    {
        size = 10;
        length = 0;
        A = new int[size];
    }
    Array(int sz)           //This is a "parameterized constructor"
    {
        size = sz;
        length = 0;
        A = new int[size];
    }
    //The task of non-parameterized constructor is to initialize data members to some
    //initial values, So as soon as an object is created we can begin using it's data members.(immediately use upon creation)

    //The task of parameterized constructor is to initialize data members to a user specified values.(use as per our needs)
    //NOTE: Constructors are not even necessary. 

    //Destructor (because we are using heap memory)
    ~Array()
    {
        delete []A;
    }

    //next we have to add all the prototype fns. into this class

    //Prototypes of the function
    void Display();                     //now because it's inside the class Array, we don't need to provide `` because it's directly accessible
    void Append(int x);                 //we don't have to pass ``, we can directly access it
    void Insert(int index, int x);
    int Delete(int index);

    int LinearSearch(int key);
    int BinarySearch(int key);
    int RBinSearch(int a[], int l, int h, int key);
    int Get(int index);
    int Set(int index, int x);
    int Max();
    int Min();
    int Sum();
    float Avg();
    void Reverse();
    void Reverse2();
    void InsertSort(int x);
    int isSorted();
    void Rearrange();
    void LeftShift(unsigned int n);
    void LeftRotate(int n);
    void RightShift(int n);
    void RightRotate(int n);
    Array* Merge(Array arr2);
    Array* Union(Array arr2);
    Array* Intersection(Array arr2);
    Array* Difference(Array arr2);

};

void Array::Display()       //className and scope resolution must be added before usage <className>::
{
    int i;
    cout <<("\nElements are: \n");
    for(i=0;i<length;i++)
        cout <<("%d", A[i]);
}

void Array::Append(int x)
{
    if(length<size)
        A[length++] = x;
}

void Array::Insert(int index, int x)
{
    int i;
    if(index>=0 && index<=length)
    {
        for(i=length;i>index;i--)
            A[i] = A[i-1];
        A[index] = x;
        length++;
    }
}

int Array::Delete( int index)
{
    int x = 0;
    int i;

    if(index>=0 && index<length)
    {
        x = A[index];
        for(i=index;i<length-1;i++)
            A[i] = A[i+1];
        length--;
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

int Array::LinearSearch(int key)
{
    int i = 0;
    for(i; i< length-1; i++)
    {
        if(key == A[i])
            swap(&A[i], &A[0]);   // improvised Linear Search
            return i;
    }
    return -1;
}

int Array::BinarySearch(int key)
{
    int l,h,mid;
    l = 0;
    h = length-1;
    
    while(l<=h)
    {
        mid = l+h/2;
        if(key == A[mid])
            return mid;
        else if(key<A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int Array::RBinSearch(int a[], int l, int h, int key)      //Recursive Binary Search
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

int Array::Get(int index)
{
    if(index>=0 && index<length)
        return A[index];
    return -1;
}

int Array::Set(int index, int x)
{
    if(index>=0 && index<length)
        A[index] = x;
    return -1;
}

int Array::Max()
{
    int max = A[0];
    for(int i = 0; i<length;i++)
    {
        if (A[i]>max)
            max = A[i];
    }
    return max;
}

int Array::Min()
{
    int min = A[0];
    for(int i = 0; i<length;i++)
    {
        if (A[i]<min)
            min = A[i];
    }
    return min;
}

int Array::Sum()
{
    int total = 0;
    for(int i=0;i<length;i++)
    {
        total+=A[i];
    }
    return total;
}


float Array::Avg()
{
    return (float)Sum()/length;
}

void Array::Reverse()
{
    int *B;
    int i,j;
    B = new int[length];
    for(i=length-1,j=0;i>=0;i--,j++)
        B[j] = A[i];
    for(i=0;i<length;i++)
        A[i]=B[i];

}

void Array::Reverse2()
{
    int i,j,temp;
    for(i=0,j=length-1;i<j;i++,j--)
    {
        // temp = A[i];
        // A[i] = A[j];
        // A[j] = temp;
        // OR
        swap(&A[i],&A[j]);
    }
}

void Array::InsertSort(int x)
{
    int i = length - 1;
    if(length == size)    //Checking if array has any free space or not for Inserting and sorting
        return;
    while(i>=0 && A[i]>x)
    {
        A[i+1] = A[i];
        i--;
    }
    A[i+1] = x;
    length++;  /*as we have stored 1 element, the length should be incremented by 1*/
}

int Array::isSorted()
{
    for(int i=0;i<length-1;i++)
    {
        if(A[i]>A[i+1])
            return 0;
    }
    return 1;
}

void Array::Rearrange()
{
    int i = 0;
    int j = length-1;
    while (i<j)
    {
        while (A[i]<0)i++;
        while (A[j]>=0)j--;
        if(i<j)swap(&A[i],&A[j]);     //because swap is call by address, we have to provide address to the pointer!
    }
    
}

// Left Shift-------------------------------------------------------------------------------------------------------

void Array::LeftShift(unsigned int n)      //best      //SO-CodeReview
{
    int i;
    for (i = 0; i < length; i++) {
        if (i + n < length)
            A[i] = A[i + n];
        else
            A[i] = 0;
    }
}

// Left Rotate------------------------------------------------------------------------------------------
void Array::LeftRotate(int n)    //n is the number of shifts
{
    
    for(int i=0; i<n; i++)
    {
        int temp = A[0];
        for(int j=0; j<length-1; j++)
        {
            A[j] = A[j+1];
        }
        A[length-1] = temp;
    }
}

//Right Shift-------------------------------------------------------------------------------------------------------
void Array::RightShift(int n)    //n is the number of shifts
{
    for(int i = 0; i<n; i++)
    {
        for(int j=length-1; j>0; j--)
        {
            A[j] = A[j-1];
        }
        A[0] = 0;
    }
    
}
// Right Rotate------------------------------------------------------------------------------------------
void Array::RightRotate(int n)    //n is the number of shifts
{
    for(int i = 0; i<n; i++)
    {
        int temp = A[length-1]; 
        for(int j=length-1; j>0; j--)
        {
            A[j] = A[j-1];
        }
        A[0] = temp;
    }
}




//Merge operation--------------------------------------------------------------------------------------------------------------------------
Array* Array::Merge(Array arr2)         // return type should be "Array*" beause we are returning arr3
// Merge fn. parameter is call by value now, arr1 is removed because it's available inside Array class
{
    int i, j, k;
    i=j=k=0;                                                        // IT has to be i=j=k=0 not i,j,k=0
    Array *arr3 = new Array(length + arr2.length);                  //length of the new array should be = length of 1st array + length of 2nd array

    // This loop compares the elements of array 1 and 2
    while (i<length && j<arr2.length)
    {
        if(A[i] < arr2.A[j])
            arr3->A[k++] = A[i++];          //arr3 is using -> because it's made in the heap and we are calling by address
        else
            arr3->A[k++] = arr2.A[j++];
    }
    for(;i<length; i++)
            arr3->A[k++]= A[i];
    for(;j<arr2.length; j++)
            arr3->A[k++]= arr2.A[j];
    arr3->length = length+arr2.length;       //arr3 is made in heap and it's length was not set
    arr3->size = 10;                                //arr3's size was also not set

    return arr3;                                    //as arr3 is created in heap we can return arr3, we also have to change the return type to "struct Array*" because we are returning an struct
}


// UNION of sorted elements ------------------------------------------------------------------------------------------------------------------------
Array* Array::Union(Array arr2)         // return type should be "struct Array*" beause we are returning arr3
{
    int i, j, k;
    i=j=k=0;                                                        // IT has to be i=j=k=0 not i,j,k=0
    Array *arr3 = new Array(length+arr2.length);

    // logic is same as merge only difference is if elements are same we don't copy it
    while (i<length && j<arr2.length)
    {
        if(A[i] < arr2.A[j])         // if array1 elements are smaller copy in arr3 element of arr1 and i++, k++
            arr3->A[k++] = A[i++];
        else if(arr2.A[j]<A[i])      // if array2 elements are smaller
            arr3->A[k++] = arr2.A[j++];
        else                                // if elements are equal, then copy any 1 element and increment both i and j
        {
            arr3->A[k++] = A[i++];
            j++;
        }
    }
    for(;i<length; i++)
            arr3->A[k++]= A[i];
    for(;j<arr2.length; j++)
            arr3->A[k++]= arr2.A[j];
    arr3->length = k;       //arr3 is made in heap and it's length was not set
    arr3->size = 10;                                //arr3's size was also not set

    return arr3;                                    //as arr3 is created in heap we can return arr3, we also have to change the return type to "struct Array*" because we are returning an struct
}

// Intersection
Array* Array::Intersection(Array arr2)         // return type should be "struct Array*" beause we are returning arr3
{
    int i, j, k;
    i=j=k=0;                                                        // IT has to be i=j=k=0 not i,j,k=0
    Array *arr3 = new Array(length+arr2.length);

    // logic is same as merge only difference is if elements are same we copy it (i.e., only duplicates are copied)
    while (i<length && j<arr2.length)
    {
        if(A[i] < arr2.A[j])         // if array1 elements are smaller move the i and j pointers ahead
        {i++;}
        else if(arr2.A[j]<A[i])      // if array2 elements are smaller move the i and j pointers ahead
        {j++;}
        else                                // if elements are equal, then copy any 1 element and increment i, j and k
        {
            arr3->A[k++] = A[i++];
            j++;
        }
    }
    //removed the code for remaining elements because it's not needed here

    arr3->length = k;       //arr3 is made in heap and it's length was not set
    arr3->size = 10;                                //arr3's size was also not set

    return arr3;                                    //as arr3 is created in heap we can return arr3, we also have to change the return type to "struct Array*" because we are returning an struct
}

//DIFFERENCE ----(A-B)-----means we want all those elements of A which are not there in B-----------------------------------------------------------
Array* Array::Difference(Array arr2)         // return type should be "struct Array*" beause we are returning arr3
{
    int i, j, k;
    i=j=k=0;                                                        // IT has to be i=j=k=0 not i,j,k=0
    Array *arr3 = new Array(length+arr2.length);

    // logic is same as merge only difference is we want all elements of arr1 which are not there in arr2
    while (i<length && j<arr2.length)
    {
        if(A[i] < arr2.A[j])         // if array1 elements are smaller copy in arr3 element of arr1 and i++, k++ and j++
            arr3->A[k++] = A[i++];
        else if(arr2.A[j]<A[i])      // if array2 elements are smaller we should only increment j
            j++;
        else                                // if elements are equal, then DO NOT copy and increment both i and j
        {
            i++;j++;
        }
    }
    for(;i<length; i++)
            arr3->A[k++]= A[i];
    //copy remaining elements only from array1 NOT from array2

    arr3->length = k;       //arr3 is made in heap and it's length was not set
    arr3->size = 10;                                //arr3's size was also not set

    return arr3;                                    //as arr3 is created in heap we can return arr3, we also have to change the return type to "struct Array*" because we are returning an struct
}


int main()
{
    Array *arr1;        //array object arr1 is a pointer
    int ch, sz;
    int x, index;

    cout << "Enter the size of the Array: ";
    cin >> sz;

    arr1 = new Array(sz); 


    do
    {
        cout <<("\n\nMenu\n");
        cout <<("1. Insert\n");
        cout <<("2. Delete\n");
        cout <<("3. Search\n");
        cout <<("4. Sum\n");
        cout <<("5. Display\n");
        cout <<("6.Exit\n");

        cout <<("enter you choice ");
        cin>>ch;

        switch(ch)
        {
            case 1: cout <<("Enter an element and index: ");
            cin >>x,index;
            arr1->Insert(index,x);
            cout << arr1;
            break;

            case 2: cout <<("Enter index ");
            cin>>index;
            x=arr1->Delete(index);
            cout <<("Deleted Element is \n",x);
            break;

            case 3:cout <<("Enter element to search ");
            cin>>x;
            index=arr1->LinearSearch(x);
            cout <<index;
            break;

            case 4:cout <<arr1->Sum();
            break;
            
            case 5:arr1->Display();
        }
    }while(ch<6);

    return 0;
}
