// find(beginIterator, endIterator, value)
// Returns an iterator pointing to 1st element equal to val, if such element is found.
// Returns an iterator equal to "endIterator" if no such element is found.
// Time complexity is atmost O(DISTANCE(beginIterator, endIterator))


#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int arr[] = {1,10,11,9,100};
    int n = sizeof(arr)/sizeof(int);

    //Search --> find()
    int key;
    cin >> key;
    auto it = find(arr, arr+n, key);
    // cout << it;     // outputs the address
    int index = it - arr;
    // cout << it << endl << arr+n;    // outputs the address  // do this to check the when element is not present, we get the iterator equal to "endIterator".
    // cout << index;
    if(index==n)
        cout << key << " not present!" << endl;
    else
        cout << key << " is present at index " << index << endl;

    return 0;
}
