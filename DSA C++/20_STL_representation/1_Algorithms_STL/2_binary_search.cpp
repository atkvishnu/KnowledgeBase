#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int arr[] = {20,30,40,40,40,50,100,1100};
    int n = sizeof(arr)/sizeof(int);

    //Search --> find()
    // int key;
    // cin >> key;
    
    // bool present = binary_search(arr, arr+n, key);
    // if(present){
    //     cout << "Present" << endl;
    // } else {
    //     cout << "Absent!" << endl;
    // }

    // 2 more things related to binary_search
    // Get the index of the element
    // lower_bound(start, end, key) & upper_bount(start, end, key)

    auto lb = lower_bound(arr, arr+n, 40);
    cout << "Lower bound of 40 is: " << lb << endl;
    cout << "Lower bound of 40 is: " << (lb-arr) << endl;

    // upper_bound
    auto ub = upper_bound(arr, arr+n, 40);
    cout << endl << "Upper bound of 40 is: " << ub << endl;
    cout << "Upper bound of 40 is: " <<  (ub-arr) << endl;

    // frequency of occurence can be found!
    cout << "Occurance frequency of 40 is: " << (ub-lb) << endl;

    return 0;
}
