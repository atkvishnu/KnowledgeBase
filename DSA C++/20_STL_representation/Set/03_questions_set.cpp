// Count number of unique Triangles using STL | Set 1 (Using set)

// We are given n triangles along with length of their three sides as a,b,c. Now we need to count number of unique triangles out of these n given triangles. Two triangles are different from one another if they have at least one of the sides different.

// Example:
// Input: arr[] = {{1, 2, 2},{4, 5, 6},{4, 5, 6}}   
// Output: 2

// Input: arr[] = {{4, 5, 6}, {6, 5, 4}, {1, 2, 2}, {8, 9, 12}}
// Output: 3


// Since we are asked to find number of “unique” triangles, we can use either set or unordered_set.

// How to store three sides as an element in the container? We use STL pair to store all the three sides together as

// pair <int, pair<int, int> >
// We one by one insert all triangles into the set. But the problem with this approach is that a triangle with sides as {4, 5, 6} is different from a triangle with sides {5, 4, 6} although they refer to a same triangle.

// In order to handle such cases, we store sides in sorted order (on the basis of length of sides), here sorting won’t be an issue since we have only 3 sides and we can sort them in constant time. For example {5, 4, 6} is inserted into set as {4, 5, 6}

// Note : We can make pair either by make_pair(a,b) or we can simply use {a, b}.


#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> iPair;

struct Triangle{
	int a,b,c;
};

void sort3(int &a, int &b, int &c) {
	vector<int> arr({a,b,c});
	sort(arr.begin(), arr.end());
	a = arr[0];
	b = arr[1];
	c = arr[2];
}


int countUniqueTriangles(struct Triangle arr[], int n) {

	set<pair<int, iPair>> s;

	for (int i = 0; i < n; ++i)
	{
		int a = arr[i].a, b = arr[i].b, c=arr[i].c;
		sort3(a,b,c);
		s.insert({a,{b,c}});
	}
	return s.size();
}


int main()
{
	struct Triangle arr[] = {{3,2,2}, {3,4,5}, {1,2,2}, {2,2,3}, {5,4,3}, {6,4,5}};
	int n = sizeof(arr)/sizeof(Triangle);

	cout << "Number of unique triangles are: " << countUniqueTriangles(arr, n);

	return 0;
}













