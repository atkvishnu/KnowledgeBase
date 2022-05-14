#include <iostream>
using namespace std;

template <class T>
class Array {

private:

	T *A;			// pointer in stack
	int size;
	int length;		// keeps track of no. of elements in the array.
	void swap(T *x, T *y);

public:

	Array(){			// copy constructor
		size = 10;
		length = 0;
		A = new T[size];	// array in heap
	}

	Array(int sz){		// copy assignment constructor
		size = sz;
		length = 0;
		A = new T[sz];
	}

	~Array() {
		delete[] A;
	}

	void Display();
	void Create(int l);
	void Append(T x);
	void Insert(int index, T x);
	T Delete(int index);

	T LinearSearch(T key);		// O(length)
	T BinarySearch(T key);		// O(log(length))

	T Get(int index);
	void Set(int index, T x);

	void Reverse();		// inplace using swap()
	void Reverse2();	// using extra space

	bool isSorted();
};


template<class T>
void Array<T>::swap(T *x, T *y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

template<class T>
void Array<T>::Display(){
	cout << "Elements are: " << endl;
	for(int i = 0; i < length; i++){
		cout << A[i] << " ";
	}
	cout << endl;
}

template<class T>
void Array<T>::Create(int l) {
	if(length <= size){
		length = l;
		// size = 2*size;		// some check for size considerations
		for (int i = 0; i < length; i++)
		{
			cout << "Enter element at index " << i << ": ";
			cin >> A[i];
			cout << endl;
		}
	}
}

template<class T>
void Array<T>::Append(T x) {
	if(length < size){
		A[length++] = x;
		// size = length;		// ??
	}
}

template<class T>
void Array<T>::Insert(int index, T x) {
	if (index >= 0 && index <= length) {
		for(int i = length-1; i >= index; i--){
			A[i+1] = A[i];
		}
		A[index] = x;	// A[i+1] = x;
		length++;
	}
}


template<class T>
T Array<T>::Delete(int index){
	if(index >=0 && index <= length) {
		int x = A[index];
		for(int i = index; i < length-1; i++) {
			A[i] = A[i+1];
		}
		length--;
		// return x;
		cout << "Deleted item is: " << x << endl;
	}
	return 0;
}


template<class T>
T Array<T>::LinearSearch(T key) {
	for(int i = 0; i > length; i++){
		if(A[i]==key){
			// swap(&A[i], &A[0]);		// optional optimization if subsequent search is predicted
			cout << "Found key at: " << i << endl;
			// return i;
		}
	}
	return 0;
}

template<class T>
T Array<T>::BinarySearch(T key) {		// works only on sorted arrays
	int l = 0;
	int h = length-1;
	int mid;
	while(l<=h){
		mid = (l+h)/2;
		if(key==A[mid]){
			// return mid;
			cout << "Key found at: " << mid << endl;
			break;
		} else if (key < A[mid]) {
			h = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	return 0;
}


template<class T>
T Array<T>::Get(int index){
	if(index >=0 && index < length) {
		return A[index];
	}
	return -1;
}


template<class T>
void Array<T>::Set(int index, T x){
	if(index >= 0 && index < length) {
		A[index] = x;
	}
}

template<class T>
void Array<T>::Reverse() {	// inplace (kindof, we are using a temp variable from swap fn.)
	int i,j;
	for(i = 0, j = length-1; i<j; i++, j--) {
		swap(&A[i], &A[j]);
	}
}

template<class T>
void Array<T>::Reverse2() {	// inplace (kindof, we are using a temp variable from swap fn.)
	T *B;
	B = new T[length];
	int i, j;
	for(i = length-1, j = 0; i >= 0; i--, j++){		// i for A[], j for B[]
		B[j] = A[i];
	}
	for(i = 0; i < length; i++){
		A[i] = B[i];
	}
}


template<class T>
bool Array<T>::isSorted() {
	for(int i = 0; i < length; i++) {
		if(A[i] < A[i+1]){
			return 0;
			// cout << "false" << endl;
		}
	}
	return 1;
	// cout << "true" << endl;
}



int main()
{
	Array<int> *arr1;
	int size, length;
	cout << "Enter the size of the array: ";
	cin >> size;
	cout << "Enter the number of elements that you want to store in the array: ";
	cin >> length;
	arr1 = new Array<int>(size);
	arr1->Create(length);

	arr1->Display();

	arr1->Append(14);
	arr1->Insert(7, 16);

	arr1->Delete(2);

	arr1->Display();

	arr1->LinearSearch(16);

	arr1->Get(8);
	arr1->Set(5,888);

	arr1->Reverse();
	arr1->Reverse2();


	arr1->isSorted();

	arr1->BinarySearch(14);


	return 0;
}