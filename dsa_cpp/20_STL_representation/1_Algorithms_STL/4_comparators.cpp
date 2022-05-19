// passing a function as a parameter

#include<iostream>
#include<algorithm>

using namespace std;

// comparator function for bubble_sort 
bool compare(int A, int B){
    cout << "Comparing " << A << " and " << B << endl;
    return A < B;    // increasing order
    // return A > B;       // decreasing order
}

// Bubble sort
// void bubble_sort(int a[], int n){

//     // N-1 large elements to the end
//     for(int itr = 1; itr<=n-1; itr++){

//         // Pairwise Swapping in the unsorted of the array
//         for(int j = 0; j<=(n-itr-1); j++){    
//             if(a[j]>a[j+1]) {
//                 swap(a[j], a[j+1]);
//             }
//         }
//     }
// }

// we will make our own sort() function which will accept another function (passing function as a parameter to another fn.)
// It's related to pointers. We can create function pointers in c++
void bubble_sort(int a[], int n, bool (&cmp)(int a, int b)){    \
// this parameter (bool (&cmp)(int a, int b)) will accept a function which returns a boolean and takes 2 input integers as parameters!

    // N-1 large elements to the end
    for(int itr = 1; itr<=n-1; itr++){

        // Pairwise Swapping in the unsorted of the array
        for(int j = 0; j<=(n-itr-1); j++){    
            if(cmp(a[j], a[j+1])) {
                swap(a[j], a[j+1]);
            }
        }
    }
}

int main() {
    int n, key;
    cin >> n;
    int a[1000];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    bubble_sort(a, n, compare);

    for(int i =0; i<n; i++){
        cout << a[i] << ", ";
    }
    return 0;
}