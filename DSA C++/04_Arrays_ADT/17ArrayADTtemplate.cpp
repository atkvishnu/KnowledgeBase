#include <iostream>

using namespace std; 

template<class T>

class Array
{
private:
    T *A;
    int size;
    int length;
public:
    //Non-Parameterized constructor
    Array()
    {
        size = 10;
        A = new T[10];
        length = 0;
    }
    Array(int sz)
    {
        size = sz;
        length = 0;
        A = new T[sz];
    }
    ~Array()
    {
        delete []A;
    }
    void Display();             // In C, we were passing `struct Array *A` but here we don't have to pass anything because Display can access the private members of the Array class(because it's inside the Array class)
    void Insert(int index, T x);
    T Delete(int index);
    // We are only taking 3 fns here, we can write them all here!
};

template<class T>
void Array<T>::Display()
{
    for(int i = 0; i<length; i++)
        cout << A[i] << " ";
    cout << endl;
}

template<class T>
void Array<T>::Insert(int index, T x)
{
    if(index>=0 && index<=length)
    {
        for(int i = length-1; i>=index; i--)
            A[i+1] = A[i];
        A[index] = x;
        length++;
    }
}

template<class T>
T Array<T>::Delete(int index)
{
    if(index>=0 && index<length)
    {
        T x = A[index];
        for(int i = index; i<length-1;i++)
            A[i] = A[i+1];
        length--;
        return x;
    }
    return -1;
}

int main()
{
    Array<char> arr(10);

    arr.Insert(0,'A');
    arr.Insert(1,'B');
    arr.Insert(2,'C');

    arr.Display();
    cout << arr.Delete(0) << endl;
    arr.Display();

    return 0;
}

