#include <iostream>

#include <cstdlib>

using namespace std;
class Array {
    private:
        int * A;
    int size;
    int length;

    public:
        Array();
    Array(int size);
    void Create(int l);
    void display();
    Array * Merge(Array a2);
    Array * Union(Array a2);
    Array * Intersection(Array a2);
    Array * Difference(Array a2);
    int isSorted() {
        for (int i = 0; i < length - 1; i++) {
            if (A[i] > A[i + 1])
                return 0;
        }
        return 1;
    }~Array();
};
Array::Array() {
    size = 10;
    length = 0;
    A = new int[size];
}
Array::Array(int size) {
    this -> size = size;
    length = 0;
    A = new int[size];
}
void Array::Create(int l) {
    if (length <= size) {
        length = l;
        for (int i = 0; i < length; i++) {
            cout << "Enter element at index " << i << " : ";
            cin >> A[i];
        }
    }
}
void Array::display() {
    cout << "Elements are : \n";
    for (int i = 0; i < length; i++) {
        cout << A[i] << " ";
    }
    cout << "\n";
}
Array * Array::Merge(Array a2) {
    Array * a3;
    a3 = new Array(length + a2.length);
    int i = 0, j = 0, k = 0;
    while (i < length && j < a2.length) {
        if (A[i] > a2.A[j])
            a3 -> A[k++] = A[i++];
        else
            a3 -> A[k++] = a2.A[j++];
    }
    while (i < length)
        a3 -> A[k++] = A[i++];
    while (j < a2.length)
        a3 -> A[k++] = a2.A[j++];
    a3 -> length = length + a2.length;
    return a3;
}
Array * Array::Union(Array a2) {
    Array * a3;
    a3 = new Array(length + a2.length);
    int i = 0, j = 0, k = 0;
    if (isSorted() && a2.isSorted()) {
        while (i < length && j < a2.length) {
            if (A[i] < a2.A[j])
                a3 -> A[k++] = A[i++];
            else if (A[i] > a2.A[j])
                a3 -> A[k++] = a2.A[j++];
            else {
                a3 -> A[k++] = A[i++];
                j++;
            }
        }
        while (i < length) {
            a3 -> A[k++] = A[i++];
        }
        while (j < a2.length) {
            a3 -> A[k++] = a2.A[j++];
        }
    } else {
        for (i = 0; i < length; i++) {
            a3 -> A[k++] = A[i];
        }
        for (j = 0; j < a2.length; j++) {
            for (i = 0; i < length; i++) {
                if (a2.A[j] == A[i])
                    break;
            }
            if (i == length)
                a3 -> A[k++] = a2.A[j];
        }
    }
    a3 -> length = k;
    return a3;
}
Array * Array::Intersection(Array a2) {
    Array * a3;
    a3 = new Array(length + a2.length);
    int i = 0, j = 0, k = 0;
    if (isSorted() && a2.isSorted()) {
        while (i < length && j < a2.length) {
            if (A[i] < a2.A[j])
                i++;
            else if (a2.A[j] < A[i])
                j++;
            else if (A[i] == a2.A[j]) {
                a3 -> A[k++] = A[i++];
                j++;
            }
        }
    } else {
        for (i = 0; i < length; i++) {
            for (j = 0; j < a2.length; j++) {
                if (A[i] == a2.A[j]) {
                    a3 -> A[k++] = A[i];
                    break;
                }
            }
        }
    }
    a3 -> length = k;
    return a3;
}
Array * Array::Difference(Array a2) {
    Array * a3;
    a3 = new Array(length + a2.length);
    int i = 0, j = 0, k = 0;
    if (isSorted() && a2.isSorted()) {
        while (i < length && j < a2.length) {
            if (A[i] < a2.A[j])
                a3 -> A[k++] = A[i++];
            else if (A[i] > a2.A[j])
                j++;
            else if (A[i] == a2.A[j]) {
                i++;
                j++;
            }
        }
        while (i < length) {
            a3 -> A[k++] = A[i++];
        }
    } else {

        for (i = 0; i < length; i++) {
            for (j = 0; j < a2.length; j++) {
                if (A[i] == a2.A[j])
                    break;
            }
            if (j == a2.length)
                a3 -> A[k++] = A[i];
        }
    }
    a3 -> length = k;
    return a3;
}
Array::~Array() {
    // delete[] A;
}
int main() {

    Array * A1, * A2, * A3;
    int size, size2, length, length2, choice;
    cout << "Enter size of array 1st : ";
    cin >> size;
    cout << "Enter number of elements : ";
    cin >> length;
    A1 = new Array(size);
    A1 -> Create(length);
    cout << "Enter size of array 2nd : ";
    cin >> size2;
    cout << "Enter number of elements : ";
    cin >> length2;
    A2 = new Array(size2);
    A2 -> Create(length2);
    do {

        cout << "\n\n--------------------ARRAY ADT---------------------\n";
        cout << "1. Merge two sorted Array.\n";
        cout << "2. Union.\n";
        cout << "3. Intersection.\n";
        cout << "4. Difference.\n";
        cout << "5. Exit\n";
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice) {
        case 1:
            A3 = A1 -> Merge( * A2);
            A3 -> display();
            delete A3;
            break;
        case 2:
            A3 = A1 -> Union( * A2);
            A3 -> display();
            delete A3;
            break;
        case 3:
            A3 = A1 -> Intersection( * A2);
            A3 -> display();
            delete A3;
            break;
        case 4:
            A3 = A1 -> Difference( * A2);
            A3 -> display();
            delete A3;
            break;
        }
    } while (choice != 5);
    return 0;
}