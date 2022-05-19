/*
// random_shuffle

// It randomly rearrange elements in range [first, last).
// The function swaps the value of each element with some other randomly picked element. 
// When provided, the function gen determines which element is picked in every case. 
// Otherwise, the function uses some unspecified source of randomness.

#include <iostream>
#include <algorithm>	// random_shuffle()
#include <stdlib.h>		// rand(), srand()
#include <time.h>		// time()
using namespace std;


int randomFunc(int j) {
	return rand() % j;
}



int main()
{
	srand(unsigned(time(0)));
	vector<int> arr;

	for (int j = 0; j < 100; ++j)
	{
		arr.push_back(j);
	}

	// using built-in random generator
	random_shuffle(arr.begin(), arr.end());

	// using randomFunc
	random_shuffle(arr.begin(), arr.end(), randomFunc);

	cout << "arr contains: ";
	for(auto i = arr.begin(); i != arr.end(); ++i)
		cout << *i << " ";
	cout << endl;

	return 0;
}
*/


/*
// shuffle

// Rearranges the elements in the range [first, last) randomly, using g as uniform random number generator.
// The function swaps the value of each element with that of some other randomly picked element. 
// The function determines the element picked by calling g().


#include <bits/stdc++.h>
using namespace std;

int main()
{
	array<int, 5> s = {1,2,3,4,5};

	// to obtain time-based seed
	unsigned seed = 0;

	// use of shuffle
	shuffle(s.begin(), s.end(), default_random_engine(seed));

	cout << "shuffled elements are: ";
	for(int i : s){
		cout << i << " ";
	}
	cout << endl;

	return 0;
}
*/




//  difference between shuffle and random_shuffle c++?

// 1.The only difference is that random_shuffle uses rand() function to randomize the items, while the shuffle uses urng which is a better random generator, though with the particular overload of random_shuffle, we can get the same behavior (as with the shuffle).

// 2.shuffle is an improvement over random_shuffle, and we should prefer using the formerfor better results.

// 3.Example of Swapping Variables using both
// random shuffle:
// template (class RandomIt, class RandomFunc)
// void random_shuffle(RandomIt first, RandomIt last, RandomFunc&& r)
// {
//     typename iterator_traits::difference_type i, n;
//     n = last - first;
//     for (i = n-1; i > 0; --i) {
//         using std::swap;
//         swap(first[i], first[r(i+1)]);
//     }
// }
// Shuffle:

// template void shuffle(RandomIt first, RandomIt last, 
//              UniformRandomBitGenerator&& g)
// {
//     typedef typename iterator_traits::difference_type diff_t;
//     typedef uniform_int_distribution distr_t;
//     typedef typename distr_t::param_type param_t;
 
//     distr_t D;
//     diff_t n = last - first;
//     for (diff_t i = n-1; i > 0; --i) {
//         using swap;
//         swap(first[i], first[D(g, param_t(0, i))]);
//     }
// }
















