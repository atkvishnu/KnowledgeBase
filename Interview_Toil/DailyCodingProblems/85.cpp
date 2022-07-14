// ```question
// 85
// Facebook
// Given three 32-bit integers x, y and b, return x if b is 1 and y if b is 0, using only mathematical or bit operations. You can assume b can only be 1 or 0.
// ```


#include<iostream>
using namespace std;

class Solution {
public:
	int returnXorY(int x, int y, int b) {
        return (x * (b&1) + y * (!(b&1)));      // if b is 1/odd then x else y
	}
};


int main()
{
	// int x,y,b;
	
	// cout << "Enter the values of x, y and b: " << endl;
	// cin >> x >> y >> b;
	
	//if(b==1)
	//	return x
	//else if(b==0)
	//	return y    
    
    Solution t;
    cout << t.returnXorY(2, 3, 0) << endl;
    
    return 0;
}