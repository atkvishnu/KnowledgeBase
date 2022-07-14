// inbuilt sort() function in algorithm lib. of STL
// The C++ inbuilt sort function only uses the : Merge Sort

#include <iostream>
#include <algorithm>

using namespace std;

// comparator function
bool compare(int A, int B){
    cout << "Comparing " << A << " and " << B << endl;
    // return A < B;    // increasing order
    return A > B;       // decreasing order
}

int main() {
    int n, key;
    cin >> n;
    int a[1000];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a, a+n, compare);
    for(int i =0; i<n; i++){
        cout << a[i] << ", ";
    }
    return 0;
}