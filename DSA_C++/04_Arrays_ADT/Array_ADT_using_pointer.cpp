/**
 * @file Array_ADT_using_pointer.cpp
 * @author Kumar Vishnu (rwxvishnu@gmail.com)
 * @brief [Array ADT using pointer](https://en.wikipedia.org/wiki/Array_data_type)
 * @version 0.1
 * @date 2022-01-13
 * 
 * @copyright Copyright (c) 2022-2032
 */

#include <iostream>
using namespace std;


/**
 * @brief class Array declaration using rule of three and different types of operations
 */
template <class T>
class Array {
private:
    T *A; // pointer to array
    int size;   // size of array
    int length; // number of elements in array

public:
    // Array() {
    //     size = 10;  // default size
    //     length = 0; // default length
    //     A = new T[size];  // allocate memory
    // }

    // Array(int sz) {
    //     size = sz;  // set size
    //     length = 0; // default length
    //     A = new T[size];  // allocate memory
    // }

    // rule of three
    Array(): size(10), length(0), A(new T[size]) {  // default constructor
        // A = new T[size];
    }
    Array(int sz): size(sz), length(0), A(new T[size]) {    // constructor
        // A = new T[size];
    }
    ~Array() {  // destructor
        delete[] A;
    }

    // operations
    void swap(T *x, T *y);
    void Display();
    void Create(int l);
    void Append(T x);
    
    void Insert(int index, T x);
    T Delete(int index);

    // search ops
    T LinearSearch(T key);
    T BinarySearch(T key);
    
    // access ops
    T Get(int index);
    void Set(int index, T x);
    T Max();
    T Min();
    
    // math ops
    int Sum();
    float Avg();

    // reverse and sort ops
    void Reverse();
    void Reverse2();
    void InsertSort(T x);
    bool isSorted();
    void Rearrange();

    // Shift and Rotate ops
    void LeftShift(int n);
    void RightShift(int n);
    void LeftRotate(int n);
    void RightRotate(int n);

    // Set operations
    Array * Merge(Array arr2);
    Array * Union(Array arr2);
    Array * Difference(Array arr2);
    Array * Intersection(Array arr2);

};



/**
 * @brief Swap two elements
 * 
 * @param x First element
 * @param y Second element
 */
template <class T>
void Array<T>::swap(T *x, T *y) {
    auto temp;
    temp = *x;
    *x = *y;
    *y = temp;
}



/**
 * @brief Display the array
 */
template <class T>
void Array<T>::Display() {
    cout << "Elements are: ";
    for(int i = 0; i < length; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}



/**
 * @brief Create the array with given length and fill with user input
 * 
 * @param l length of array (number of elements currently present in the array) 
 */
template <class T>
void Array<T>::Create(int l) {
    if(length<=size){
        length = l;
        for(int i = 0; i < length; i++){
            cout << "Enter element at index " << i << " : ";
            cin >> A[i];
        }
    }
}




/**
 * @brief Append an element to the end of the array
 * 
 * @param x Element to be appended
 */
template <class T>
void Array<T>::Append(T x) {
    if (length < size) {
        A[length++] = x;    // append the element
    }
    else {
        cout << "Array is full!" << endl;
        cout << "Doubling the size of array..." << endl;
        length = 2*length;          // double the length
        size = 2*size;              // double the size
        T *A1 = new T[size];        // allocate memory
        for(int i = 0; i < length; i++) {   // copy the elements
            A1[i] = A[i];
        }
        for(int i = length/2; i < size; i++) {  // fill the rest of the elements as 0s
            A1[i] = 0;
        }
        delete[] A;
        A = A1;
        A[(length/2)] = x;           // append the element
    }
}


/**
 * @brief Insert element `x` at `index`
 * 
 * @param index 
 * @param x 
 */
template <class T>
void Array<T>::Insert(int index, T x) {
    if (index >= 0 && index <= length) {
        // shift all the elements before insertion
        for (int i = length; i > index; i--)
            A[i] = A[i-1];
        A[index] = x;
        length++;
    }
}


/**
 * @brief Delete element at `index`
 * 
 * @param index index of element to be deleted
 */
template <class T>
T Array<T>::Delete(int index) {
       int x = 0;
    if (index >= 0 && index < length) {
        x = A[index];
        for (int i = index; i < length-1; i++)
            A[i] = A[i+1];
        length--;
    }
    return x;
}


/**
 * @brief Linear Search operation
 * 
 * @tparam T : template type
 * @param key : key to be searched
 * @return T : template type key
 */
template <class T>
T Array<T>::LinearSearch(T key){
    for(int i = 0; i < length; i++) {
        if(A[i] == key) {
            cout << "Element found at index: " << endl;
            return i;
        }
    }
    cout << "Key not found!" << endl;
}


/**
 * @brief Binary Search operation
 * 
 * @tparam T Template type
 * @param key Element to be searched
 * @return T type of key (templatized)
 */
template <class T>
T Array<T>::BinarySearch(T key){
    int l = 0;
    int h = length-1;

    while(l<=h){
        int mid = (l+h)/2;
        if(key == A[mid]) {
            cout << "Element found at index: " << endl;
            return mid;
        }
        else if(key<A[mid]){
            h = mid-1;
        }
        else {
            l = mid + 1;
        }
    }
}



/**
 * @brief Get element at index
 * 
 * @tparam T Template class type
 * @param index 
 * @return T 
 */
template <class T>
T Array<T>::Get(int index){
    if(index >=0 && index < length) {
        return A[index];
    } else {
        cout << "Invalid index!" << endl;
    }
}

template <class T>
void Array<T>::Set(int index, T x) {
    if (index >= 0 && index < length) {
        A[index] = x;
    } else {
        cout << "Invalid index!" << endl;
    }
}

template <class T>
T Array<T>::Max() {
    int x = A[0];
    for(int i = 1; i < length; i++) {
        if (A[i] > x) {
            x = A[i];
        }
    }
    return x;
}




template <class T>
T Array<T>::Min(){
    int x = A[0];
    for(int i = 1; i < length; i++) {
        if (A[i] < x) {
            x = A[i];
        }
    }
    return x;
}


template <class T>
int Array<T>::Sum(){
    int sum = 0;
    for(int i = 0; i < length; i++) {
        sum += A[i];
    }
    return sum;
}


template <class T>
float Array<T>::Avg() {
    return (float)Sum()/length;
}

template <class T>
void Array<T>::LeftShift(int n) {
    n = n % length;
    for(int i = 0; i < length - n; i++) {
        A[i] = A[i+n];
    }

}

    // Shift and Rotate ops
    // void RightShift(int n);
    // void LeftRotate(int n);
    // void RightRotate(int n);
















int main()
{
    int asize, len;
    Array<int> *arr1;

    cout << "Enter size of array: ";
    cin >> asize;
    cout << "Enter length of array (The number of elements that will be present in the array): ";
    cin >> len;

    arr1 = new Array<int>(asize);

    cout << "Creating array..." << endl;
    arr1->Create(len);

    // arr1->Display();
    // arr1->Insert(6,7);
    arr1->Display();

    cout << "Enter element to be appended: ";
    int elementToAppend;
    cin >> elementToAppend;
    arr1->Append(elementToAppend);
    arr1->Display();

    cout << "Enter element to be deleted: ";
    int elementToDelete;
    cin >> elementToDelete;
    arr1->Delete(elementToDelete);
    arr1->Display();

}