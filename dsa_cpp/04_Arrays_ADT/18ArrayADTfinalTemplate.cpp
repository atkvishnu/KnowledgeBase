#include <iostream>
using namespace std;

template <class T>
class Array 
{
private:
    T *A;
    int size;
    int length;
    void swap(int * x, int * y);

public:
    Array() 
    {
        size = 10;
        length = 0;
        A = new T[size];
    }
    Array(int sz) 
    {
        size = sz;
        length = 0;
        A = new T[size];
    }
    ~Array() 
    {
        delete[] A;
    }
    void Display();
    void Create(int l);
    void Append(T x);
    void Insert(int index, T x);
    T Delete(int index);
    T LinearSearch(T key);
    T BinarySearch(T key);
    T Get(int index);
    void Set(int index, T x);
    T Max();
    T Min();
    T Sum();
    T Avg();
    void Reverse();
    void Reverse2();
    void InsertSort(int x);
    T isSorted();
    void Rearrange();
    void LeftShift(int n);
    void LeftRotate(int n);
    void RightShift(int n);
    void RightRotate(int n);
    Array * Merge(Array arr2);
    Array * Union(Array arr2);
    Array * Difference(Array arr2);
    Array * Intersection(Array arr2);
};


template <class T>
void Array<T>::Display()
{
    int i;
    cout << "Elements are: ";
    for (i = 0; i < length; i++)
        cout << A[i] << " ";
}

template <class T>
void Array<T>::Create(int l){
    if(length<=size){
        length = l;
        for(int i=0;i<length;i++){
            cout << "Enter element at index " << i << " : ";
            cin >> A[i];
        }
    }
}

template <class T>
void Array<T>::Append(T x) {
    if (length < size)
        A[length++] = x;
}

template <class T>
void Array<T>::Insert(int index, T x) {
    int i;
    if (index >= 0 && index <= length) {
        for (i = length; i > index; i--)
            A[i] = A[i - 1];
        A[index] = x;
        length++;

    }
}

template <class T>
T Array<T>::Delete(int index) {
    int x = 0;
    int i;

    if (index >= 0 && index < length) {
        x = A[index];
        for (i = index; i < length - 1; i++)
            A[i] = A[i + 1];
        length--;
        return x;
    }

    return 0;
}

template <class T>
void Array<T>::swap(T * x, T * y) {
    int temp;
    temp = * x;
    * x = * y;
    * y = temp;
}

template <class T>
T Array<T>::LinearSearch(T key) {
    int i;
    for (i = 0; i < length; i++) {
        if (key == A[i]) {
            // swap( &A[i], &A[0]);
            return i;
        }
    }
    return -1;
}

template <class T>
T Array<T>::BinarySearch(T key) {
    int l, mid, h;
    l = 0;
    h = length - 1;

    while (l <= h) {
        mid = (l + h) / 2;
        if (key == A[mid])
            return mid;
        else if (key < A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

template <class T>
T Array<T>::Get(int index) {
    if (index >= 0 && index < length)
        return A[index];
    return -1;
}

template <class T>
void Array<T>::Set(int index, T x) {
    if (index >= 0 && index < length)
        A[index] = x;
}

template <class T>
T Array<T>::Max() {
    int max = A[0];
    int i;
    for (i = 1; i < length; i++) {
        if (A[i] > max)
            max = A[i];
    }
    return max;
}

template <class T>
T Array<T>::Min() {
    int min = A[0];
    int i;
    for (i = 1; i < length; i++) {
        if (A[i] < min)
            min = A[i];
    }
    return min;
}

template <class T>
T Array<T>::Sum() {
    int s = 0;
    int i;
    for (i = 0; i < length; i++)
        s += A[i];

    return s;
}

template <class T>
T Array<T>::Avg() {
    return (float) Sum() / length;
}

template <class T>
void Array<T>::Reverse() {
    T * B;
    int i, j;

    B = (int * ) malloc(length * sizeof(int));
    for (i = length - 1, j = 0; i >= 0; i--, j++)
        B[j] = A[i];
    for (i = 0; i < length; i++)
        A[i] = B[i];

}

template <class T>
void Array<T>::Reverse2() {
    int i, j;
    for (i = 0, j = length - 1; i < j; i++, j--) {
        swap( & A[i], & A[j]);
    }
}

template <class T>
void Array<T>::InsertSort(int x) {
    int i = length - 1;
    if (length == size)
        return;
    while (i >= 0 && A[i] > x) {
        A[i + 1] = A[i];
        i--;
    }
    A[i + 1] = x;
    length++;
}

template <class T>
T Array<T>::isSorted() {
    int i;
    for (i = 0; i < length - 1; i++) {
        if (A[i] > A[i + 1])
            return 0;
    }
    return 1;
}

template <class T>
void Array<T>::Rearrange() {
    int i, j;
    i = 0;
    j = length - 1;

    while (i < j) {
        while (A[i] < 0) i++;
        while (A[j] >= 0) j--;
        if (i < j) swap( & A[i], & A[j]);
    }
}

template <class T>
void Array<T>::LeftShift(int n)
{
    for (int i = 0; i < length; i++)
    {
        if(i+n < length)
            A[i] = A[i+n];
        else
            A[i] = 0;
    }
}

template <class T>
void Array<T>::LeftRotate(int n)
{
    for(int i = 0; i<n;i++)
    {
        int temp = A[0];
        for(int j = 0;j<length-1;j++)
            A[j] = A[j+1];
        A[length-1] = temp;
    }
}

template <class T>
void Array<T>::RightShift(int n)    //O(n^2
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

//Right shift optimization (O(n))-------------------------------------------------------------------------------------------------------
template <class T>
void Array<T>::RightShift2(int n)    //n is the number of shifts
{
    for(int i = length-1; i>=0; i--)
    {
        if(i-n>=0)
            A[i] = A[i-n];
        else
            A[i] = 0;
    }
}


template <class T>
void Array<T>::RightRotate(int n)
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

template <class T>
Array<T> * Array<T>::Merge(Array<T> arr2) {
    int i, j, k;
    i = j = k = 0;

    Array<T> *arr3 = new Array<T>(length + arr2.length);

    while (i < length && j < arr2.length) {
        if (A[i] = arr2.A[j]) {
            arr3 -> A[k++] = A[i++];
            arr3 -> A[k++] = arr2.A[j++];
        }
        else if (A[i] < arr2.A[j])
            arr3 -> A[k++] = A[i++];
        else
            arr3 -> A[k++] = arr2.A[j++];
    }
    for (; i < length; i++)
        arr3 -> A[k++] = A[i];
    for (; j < arr2.length; j++)
        arr3 -> A[k++] = arr2.A[j];
    arr3 -> length = length + arr2.length;

    return arr3;
}

template <class T>
Array<T> * Array<T>::Union(Array<T> arr2) {
    int i, j, k;
    i = j = k = 0;

    Array<T> *arr3 = new Array<T>(length + arr2.length);

    while (i < length && j < arr2.length) {
        if (A[i] < arr2.A[j])
            arr3 -> A[k++] = A[i++];
        else if (arr2.A[j] < A[i])
            arr3 -> A[k++] = arr2.A[j++];
        else {
            arr3 -> A[k++] = A[i++];
            j++;
        }
    }
    for (; i < length; i++)
        arr3 -> A[k++] = A[i];
    for (; j < arr2.length; j++)
        arr3 -> A[k++] = arr2.A[j];

    arr3 -> length = k;
    return arr3;
}

template <class T>
Array<T>* Array<T>::Intersection(Array<T> arr2) {
    int i, j, k;
    i = j = k = 0;

    Array<T> *arr3 = new Array<T>(length + arr2.length);

    while (i < length && j < arr2.length) {
        if (A[i] < arr2.A[j])
            i++;
        else if (arr2.A[j] < A[i])
            j++;
        else if (A[i] == arr2.A[j]) {
            arr3 -> A[k++] = A[i++];
            j++;
        }
    }

    arr3 -> length = k;
    return arr3;
}

template <class T>
Array<T>* Array<T>::Difference(Array<T> arr2) {
    int i, j, k;
    i = j = k = 0;

    Array<T> *arr3 = new Array<T>(length + arr2.length);

    while (i < length && j < arr2.length) {
        if (A[i] < arr2.A[j])
            arr3 -> A[k++] = A[i++];
        else if (arr2.A[j] < A[i])
            j++;
        else {
            i++;
            j++;
        }
    }
    for (; i < length; i++)
        arr3 -> A[k++] = A[i];

    arr3 -> length = k;
    return arr3;
}

int main() {

    Array<int> *arr1;
    Array<int> *arr2;
    Array<int> *arr3;       //for set operations

    int n;
    int ch, size, size2, alength, blength;
    int x, index;

    cout << "Enter Size of the first array: ";
    cin >> size;
    cout << "Enter number of elements for first array: ";
    cin >> alength;
    arr1 = new Array<int>(size);
    arr1->Create(alength);

    cout << "Enter Size of the second array: ";
    cin >> size2;
    cout << "Enter number of elements for second array: ";
    cin >> blength;
    arr2 = new Array<int>(size2);
    arr2->Create(blength);


    do {
        cout << "\n================Menu================\n";
        cout << "1.  Insert \n";
        cout << "2.  Append \n";
        cout << "3.  Delete \n";
        cout << "4.  Linear Search \n";
        cout << "5.  Binary Search \n";
        cout << "6.  Get \n";
        cout << "7.  Set \n";
        cout << "8.  Max \n";
        cout << "9.  Min \n";
        cout << "10. Sum \n";
        cout << "11. Avg \n";
        cout << "12. Reverse \n";
        cout << "13. Reverse 2 \n";
        cout << "14. InsertSort (BUGGY)\n";
        cout << "15. isSorted \n";
        cout << "16. Rearrange \n";
        cout << "17. Left Shift \n";
        cout << "18. Left Rotate \n";
        cout << "19. Right Shift \n";
        cout << "20. Right Rotate \n";
        cout << "21. Merge \n";
        cout << "22. Union of 2 sets \n";
        cout << "23. Difference of 2 sets \n";
        cout << "24. Intersection of 2 sets \n";
        cout << "25. Display \n";
        cout << "26. Exit \n";
        cout << "====================================\n\n";

        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {

        case 1:
            cout << "Enter the index and element: ";
            cin >> index >> x;
            arr1 -> Insert(index, x);
            arr1->Display();
            break;

        case 2:
            cout <<"NOTE: Append() can only be used if declared size of array is large enough to fit new elements!\n";
            cout << "Enter the element to be appended at the end of the array: ";
            cin >> x;
            arr1->Append(x);
            arr1->Display();
            break;

        case 3:
            cout << "Enter index of element to be deleted: ";
            cin >> index;
            x = arr1 -> Delete(index);
            cout << "Deleted Element is: " << x << endl;
            cout << "After deletion remaining ";
            arr1->Display();
            break;

        case 4:
            cout << "Enter element to search: ";
            cin >> x;
            index = arr1 -> LinearSearch(x);
            arr1->Display();
            cout << "\nElement index is: " << index;
            break;

        case 5:
            cout << "Enter element to search: ";
            cin >> x;
            index = arr1 -> BinarySearch(x);
            arr1->Display();
            cout << "\nElement index is: " << index;
            break;

        case 6:
            cout << "Enter index of element which has to be returned: ";
            cin >> index;
            cout << arr1->Get(index);
            break;

        case 7:
            cout << "Enter the element and index: ";
            cin >> x >> index;
            arr1->Set(index,x);
            cout << "\n";
            arr1->Display();
            break;

        case 8:
            cout << "The maximum element in array is: ";
            cout << arr1->Max() << endl;
            arr1->Display();
            break;

        case 9:
            cout << "The minimum element in array is: ";
            cout << arr1->Min() << endl;
            arr1->Display();
            break;

        case 10:
            cout << "Sum = " << arr1 -> Sum();
            break;

        case 11:
            cout << "Average = " << arr1 -> Avg();
            break;

        case 12:
            arr1->Reverse();
            cout << "Reversed ";
            arr1->Display();
            break;

        case 13:
            arr1->Reverse2();
            cout << "Reversed ";
            arr1->Display();
            break;

        case 14:
            cout << "NOTE: This operation will sort the array after insertion!\n";
            cout << "Enter the element to be inserted: ";
            cin >> x;
            arr1->InsertSort(x);
            arr1->Display();
            break;

        case 15:
            cout << "\nThis operation will tell us if an array is sorted or not!\nSORTED -> 1\nNOT SORTED -> 0\n\n";
            cout << "Answer: " << arr1->isSorted() << endl;
            break;

        case 16:
            cout << "This function will rearrange negative numbers on the LHS and positive numbers on the RHS";
            arr1->Rearrange();
            arr1->Display();
            break;

        case 17:
            cout << "How many elements to shift to the left? \n";
            cin >> x;
            arr1->LeftShift(x);
            arr1->Display();
            break;

        case 18:
            cout << "How many elements to rotate to the left? \n";
            cin >> x;
            arr1->LeftRotate(x);
            arr1->Display();
            break;

        case 19:
            cout << "How many elements to shift to the right? \n";
            cin >> x;
            arr1->RightShift(x);
            arr1->Display();
            break;

        case 20:
            cout << "How many elements to rotate to the right? \n";
            cin >> x;
            arr1->RightRotate(x);
            arr1->Display();
            break;

        case 21:
            arr3 = arr1->Merge(*arr2);
            arr3->Display();
            delete arr3;
            break;

        case 22:
            arr3 = arr1->Union(*arr2);
            arr3->Display();
            delete arr3;
            break;

        case 23:
            arr3 = arr1->Difference(*arr2);
            arr3 -> Display();
            delete arr3;
            break;

        case 24:
            arr3 = arr1->Intersection(*arr2);
            arr3->Display();
            delete arr3;
            break;

        case 25:
            arr1 -> Display();
            break;
        }
    } while (ch < 26);
    return 0;
}