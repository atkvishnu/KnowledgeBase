// std::next_permutation and prev_permutation in C++

// std::next_permutation

// It is used to rearrange the elements in the range [first, last) into the next lexicographically greater permutation. 
// A permutation is each one of the N! possible arrangements the elements can take (where N is the number of elements in the range). 
// Different permutations can be ordered according to how they compare lexicographically to each other. 
// The complexity of the code is O(n*n!) which also includes printing all the permutations.

// Syntax: 
// template bool next_permutation (BidirectionalIterator first, BidirectionalIterator last);

// Parameters: 
// first, last : Bidirectional iterators to the initial and final positions of the sequence. 
// The range used is [first, last), which contains all the elements between first and last, including the element pointed 
// by first but not the element pointed by last.

// return value: 
// true : if the function could rearrange the object as a lexicographically greater permutation.
// Otherwise, the function returns false to indicate that the arrangement is not greater than the previous, but the lowest possible (sorted in ascending order).

// Question: use next_permutation to find next lexicographically greater value for given array of values. 
// Input : next permutation of 1 2 3 is 
// Output : 1 3 2

// Input : next permutation of 4 6 8 is 
// Output : 4 8 6

/*
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
	int arr[] = {1,2,3};
	sort(arr, arr+3);
	cout << "The 3! possible permutations with 3 elements: \n";
	do {
		cout << arr[0] << " " << arr[1] << " " << arr[2] << "\n";
	} while (next_permutation(arr, arr+3));

	cout << "After loop: " << arr[0] << " " << arr[1] << " " << arr[2] << "\n";

	return 0;
}
*/


// std::prev_permutation

// It is used to rearranges the elements in the range [first, last) into the previous lexicographically-ordered permutation. A permutation is each one of the N! possible arrangements the elements can take (where N is the number of elements in the range). Different permutations can be ordered according to how they compare lexicographically to each other.

// Syntax :  

// template bool prev_permutation (BidirectionalIterator first, BidirectionalIterator last );

// Parameters: 
// first, last : Bidirectional iterators to the initial and final positions of the sequence. The range 
// used is [first, last), which contains all the elements between first and last, including 
// the element pointed by first but not the element pointed by last.

// return value: 
// true : if the function could rearrange the object as a lexicographically smaller permutation.
// Otherwise, the function returns false to indicate that the arrangement is not less than the previous, 
// but the largest possible (sorted in descending order).


// Question: use prev_permutation to find previous lexicographically smaller value for given array of values. 
// Examples:  

// Input : prev permutation of 3 2 1 is 
// Output : 3 1 2 

// Input : prev permutation of 8 6 4 is 
// Output :8 4 6

#include <algorithm>
 
#include <iostream>
using namespace std;
int main()
{
    int arr[] = { 1, 2, 3 };
 
    sort(arr, arr + 3);
    reverse(arr, arr + 3);
 
    cout << "The 3! possible permutations with 3 elements:\n";
    do {
        cout << arr[0] << " " << arr[1] << " " << arr[2] << "\n";
    } while (prev_permutation(arr, arr + 3));
 
    cout << "After loop: " << arr[0] << ' ' << arr[1]
         << ' ' << arr[2] << '\n';
 
    return 0;
}
























