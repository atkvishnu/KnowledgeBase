#include <iostream>

using namespace std; 

class Array
{
private:
    int *A;
    int size;
    int length;
public:
    //Non-Parameterized constructor
    Array()
    {
        size = 10;
        A = new int[10];
        length = 0;
    }
    Array(int sz)
    {
        size = sz;
        length = 0;
        A = new int[sz];
    }
    ~Array()
    {
        delete []A;
    }
    void Display();             // In C, we were passing `struct Array *A` but here we don't have to pass anything because Display can access the private members of the Array class(because it's inside the Array class)
    void Insert(int index, int x);
    int Delete(int index);
    // We are only taking 3 fns here, we can write them all here!
};

void Array::Display()
{
    for(int i = 0; i<length; i++)
        cout << A[i] << " ";
    cout << endl;
}

void Array::Insert(int index, int x)
{
    if(index>=0 && index<=length)
    {
        for(int i = length-1; i>=index; i--)
            A[i+1] = A[i];
        A[index] = x;
        length++;
    }
}

int Array::Delete(int index)
{
    if(index>=0 && index<length)
    {
        int x = A[index];
        for(int i = index; i<length-1;i++)
            A[i] = A[i+1];
        length--;
        return x;
    }
    return -1;
}

int main()
{
    Array arr(10);

    arr.Insert(0,5);
    arr.Insert(1,6);
    arr.Insert(2,9);

    arr.Display();
    cout << arr.Delete(0) << endl;
    arr.Display();

    return 0;
}


//This Array class which was created, only aides to the integer class.
//In place of creating a new separate class for strings, C++ provides us the benefit of templates!
//If we want to process a string class, it won't be possible because type of the class is set to integer. 
//For this we should Templatize the entire class.
//Done in next file!