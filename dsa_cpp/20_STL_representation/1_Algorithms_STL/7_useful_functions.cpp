#include<iostream>
#include<algorithm>

using namespace std;


int main() {

    int a = 10;
    int b = 20;
    
    //----------------------------------------------------------
    // swap
    cout << "Before swapping: a = " << a << ", b = " << b << endl;

    swap(a,b);      // swap(a,b) is same as a = a^b, b = a^b, a = a^b

    cout << "After swapping: a = " << a << " , b =  " << b << endl;
    
    //----------------------------------------------------------
    // max and min
    cout << max(a,b) << endl;
    cout << min(a,b) << endl;
    
    //----------------------------------------------------------
    // rotate
    int arr[] = {1,2,3,4,4,5};
    int n = sizeof(arr)/sizeof(int);
    // reverse(arr, arr+3);        // reverse(start, end)
    reverse(arr, arr+2);                // reverse() takes O(n) time
    // swap(arr[0], arr[1]);
    for(int i = 0; i<n; i++){
        cout << arr[i] << ", ";
    }
    cout << endl;
    // next_permutation(arr, arr+n);
    // for(int i = 0; i<n; i++){
    //     cout << arr[i] << ", ";
    // }
    //----------------------------------------------------------

}