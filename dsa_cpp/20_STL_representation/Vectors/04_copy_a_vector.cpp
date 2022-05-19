// There is only one way to copy an array, i.e., by iterating over it.
// But a vector can be copied in 2 ways:
// 1. Iterative method
// 2. Assignment operator "="



// Method 1: Iterative method
// #include<bits/stdc++.h>
// using namespace std;

// void printVector(vector<int> v)
// {
// 	cout << "The vector elements are: ";
// 	for(int i = 0; i < v.size(); i++)
// 		cout << v[i] << " ";
// 	cout << endl;
// }

// int main()
// {
// 	vector<int> vect1{1,2,3,4};
// 	vector<int> vect2;

// 	// loop to copy elements of old vector into new vector
// 	for(int i = 0; i < vect1.size(); i++)
// 		vect2.push_back(vect1[i]);

// 	cout << "Old Vector: ";
// 	printVector(vect1);

// 	cout << "New Vector: ";
// 	printVector(vect2);
// }



// Method 2: Assignment operator "="
// #include<bits/stdc++.h>
// using namespace std;

// void printVector(vector<int> v)
// {
// 	cout << "The vector elements are: ";
// 	for(int i = 0; i < v.size(); i++)
// 		cout << v[i] << " ";
// 	cout << endl;
// }

// int main()
// {
// 	vector<int> vect1{1,2,3,4};
// 	vector<int> vect2;

// 	// using assignment operator to copy one vector to other
// 	vect2 = vect1;

// 	cout << "["="]Old Vector: ";
// 	printVector(vect1);

// 	cout << "New Vector: ";
// 	printVector(vect2);
// }



// Method 3: By passing vector as constructor.
// #include<bits/stdc++.h>
// using namespace std;

// void printVector(vector<int> v)
// {
// 	cout << "The vector elements are: ";
// 	for(int i = 0; i < v.size(); i++)
// 		cout << v[i] << " ";
// 	cout << endl;
// }

// int main()
// {
// 	vector<int> vect1{1,2,3,4};

// 	// declaring new vector and copying elems of old vector.
// 	// constructor method, Deep copy
// 	vector<int> vect2(vect1);

// 	cout << "[Constructor method: ]Old Vector: ";
// 	printVector(vect1);

// 	cout << "New Vector: ";
// 	printVector(vect2);
// }






// Method 4: By using inbuilt functions (copy() and assign() - deep copies)
// copy(<first_iterator_of_old_vector>, <last_iterator_of_old_vector>, <back_inserter() fn. to insert values from back>) - generated a deep copy
// assign(<first_iterator_of_old_vector>, <last_iterator_of_old_vector>) - generated a deep copy
// #include<bits/stdc++.h>
// // #include<vector>  
// // #include<algorithm>	// for copy() and assign()
// // #include<iterator>	// for back_inserter()
// using namespace std;

// void printVector(vector<int> v)
// {
// 	cout << "The vector elements are: ";
// 	for(int i = 0; i < v.size(); i++)
// 		cout << v[i] << " ";
// 	cout << endl;
// }

// int main()
// {
// 	vector<int> vect1{1,2,3,4};

// 	vector<int> vect2;

// 	copy(vect1.begin(), vect1.end(), back_inserter(vect2));

// 	cout << "[copy()]Old Vector: ";
// 	printVector(vect1);

// 	cout << "New Vector: ";
// 	printVector(vect2);
// }


// assign(<first_iterator_of_old_vector>, <last_iterator_of_old_vector>)
#include<bits/stdc++.h>
// #include<vector>  
// #include<algorithm>	// for copy() and assign()
// #include<iterator>	// for back_inserter()
using namespace std;

void printVector(vector<int> v)
{
	cout << "The vector elements are: ";
	for(int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}

int main()
{
	vector<int> vect1{1,2,3,4};

	vector<int> vect2;

	// copying vector by assign() fn.
	vect2.assign(vect1.begin(), vect1.end());

	cout << "[assign()]Old Vector: ";
	printVector(vect1);

	cout << "New Vector: ";
	printVector(vect2);
}
















