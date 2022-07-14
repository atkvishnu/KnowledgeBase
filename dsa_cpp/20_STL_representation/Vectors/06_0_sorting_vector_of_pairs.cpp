// vector of pairs

// A pair is a container which stores two values mapped to each other.
// A vector containing multiple number of such pair is called a vector of pairs.


/*
#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<pair<int,int>> vect;

	int arr[] = {10,20,5,40};
	int arr1[] = {30,60,20,50};
	int n = sizeof(arr)/sizeof(arr[0]);

	for(int i = 0; i < n; i++)
		vect.push_back(make_pair(arr[i], arr1[i]));

	for(int i = 0; i < n; i++)
	{
		cout << vect[i].first << " " << vect[i].second << endl;
	}

	return 0;
}
*/

// Case 1: Sorting the vector elems. on the basis of first element of pairs in ascending order.
// this can be done using the sort() fn.
/*
#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<pair<int,int>> vect;
	int arr[] = {10,20,5,40};
	int arr1[] = {30,60,20,50};
	int n = sizeof(arr)/sizeof(arr[0]);

	for(int i = 0; i < n; i++)
		vect.push_back(make_pair(arr[i], arr1[i]));

	cout << "The vector before sort operations: " << endl;
	for(int i = 0; i < n; i++)
		cout << vect[i].first << " " << vect[i].second << endl;

	sort(vect.begin(), vect.end());

	cout << "The vector after sort operations: " << endl;
	for(int i = 0; i < n; i++)
		cout << vect[i].first << " " << vect[i].second << endl;

	return 0;
}
*/

// Case 2: Sorting the vector elements on the basis of second element of pairs in ascending order
// we will have to use 3rd argument of sort() fn.
/*
#include <bits/stdc++.h>
using namespace std;

bool sortbysec(const pair<int,int> &a, const pair<int,int> &b)
{
	return (a.second < b.second);
}

int main()
{
	vector<pair<int,int>> vect;
	int arr[] = {10,20,5,40};
	int arr1[] = {30,60,20,50};
	int n = sizeof(arr)/sizeof(arr[0]);

	for(int i = 0; i < n; i++)
		vect.push_back(make_pair(arr[i], arr1[i]));

	cout << "The vector before sort operations: " << endl;
	for(int i = 0; i < n; i++)
		cout << vect[i].first << " " << vect[i].second << endl;

	sort(vect.begin(), vect.end(), sortbysec);

	cout << "The vector after sort operations: " << endl;
	for(int i = 0; i < n; i++)
		cout << vect[i].first << " " << vect[i].second << endl;

	return 0;

	return 0;
}
*/


// Case 3: Sorting the vector elements on the basis of first element of pairs in descending order.

// This is achieved by using “sort()” and passing iterators of 1D vector as its arguments.
/*
#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<pair<int,int>> vect;
	int arr[] = {5,20,10,40};
	int arr1[] = {30,60,20,50};
	int n = sizeof(arr)/sizeof(arr[0]);

	for(int i = 0; i < n; i++)
		vect.push_back(make_pair(arr[i], arr1[i]));

	cout << "The vector before sort operations: " << endl;
	for(int i = 0; i < n; i++)
		cout << vect[i].first << " " << vect[i].second << endl;

	sort(vect.rbegin(), vect.rend());

	cout << "The vector after sort operations: " << endl;
	for(int i = 0; i < n; i++)
		cout << vect[i].first << " " << vect[i].second << endl;

	return 0;
}
*/


// Case 4: Sorting the vector elems on the basis of 2nd elem of pairs in descending order.

#include <bits/stdc++.h>
using namespace std;

bool sortbysecdesc(const pair<int,int> &a, const pair<int,int> &b)
{
	return (a.second > b.second);
}

int main()
{
	vector<pair<int,int>> vect;
	int arr[] = {10,20,5,40};
	int arr1[] = {30,60,20,50};
	int n = sizeof(arr)/sizeof(arr[0]);

	for(int i = 0; i < n; i++)
		vect.push_back(make_pair(arr[i], arr1[i]));

	cout << "The vector before sort operations: " << endl;
	for(int i = 0; i < n; i++)
		cout << vect[i].first << " " << vect[i].second << endl;

	sort(vect.begin(), vect.end(), sortbysecdesc);

	cout << "The vector after sort operations: " << endl;
	for(int i = 0; i < n; i++)
		cout << vect[i].first << " " << vect[i].second << endl;

	return 0;
}