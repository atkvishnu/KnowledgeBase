#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

    int arr[] = {1,2,5,10,20,50,100,200,500,2000};

    int n = sizeof(arr)/sizeof(int);

    // -----------------------------------------------------------------------------------
    // 1. rotate the array from middle

    // we can rotate a vector also
    rotate(arr, arr+n/2, arr+n);        // rotate(start, index to rotate from, end)
    for(int i = 0; i<n; i++){
        cout << arr[i] << ", ";
    }
    cout << endl;
    
    // applying the same on vector
    vector<int> v{10,20,30,40,50};  // dynamic array
    // rotate(v.begin(), v.begin()+3, v.end());
    for(int i = 0; i<v.size(); i++){
        cout << v[i] << ", ";
    }
    cout << endl;
    // -----------------------------------------------------------------------------------
    // Next_permutation // next_permutation(start, end) 
    // This function is used to find the next permutation of the given array/vector/list.
    // This can help us find the next bigger number.    ex. if arr=1,2,3 ; then next permutation is 1,3,2 and next permutation will be 2,1,3
    // 1,2,3 => 1,3,2 => 2,1,3 => 2,3,1 => 3,1,2 => 3,2,1
    next_permutation(v.begin(), v.end());
    // next_permutation(v.begin(), v.end());    // we can call this function again to find the next permutation
    // next_permutation(v.begin(), v.end());
    // next_permutation(v.begin(), v.end());
    
    // for each loop
    for(int x:v){
        cout << x << endl;
    }



}