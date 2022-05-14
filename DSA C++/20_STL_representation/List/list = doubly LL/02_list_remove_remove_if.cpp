// Lists are containers used to store data in a 
// non-contiguous fashion.

// Normally, Arrays and Vectors are contiguous in nature,
// Therefore, the insertion and deletion ops. are costlier
// as compared to the insertion and deletion ops in lists.





// list::remove() : removes all the values from the list that correspond to the "value" given as parameter to the fn.

// Syntax: listname.remove(value) 

// Input  : list list{1, 2, 3, 4, 5};
//          list.remove(4);
// Output : 1, 2, 3, 5

// Input  : list list{1, 2, 2, 2, 5, 6, 7};
//          list.remove(2);
// Output : 1, 5, 6, 7


#include <iostream>
#include <list>
#include<math.h>
using namespace std;

void printList(list<int> LIST){
	for(auto it = LIST.begin(); it != LIST.end(); it++)
			cout << *it << " ";

	cout << endl;
}

/*
int main()
{
	list<int> myList = {1,2,2,2,5,6,7};
	
	myList.remove(2);	// 2's removed

	printList(myList);
	return 0;
}
*/



// list::remove_if() : removes all the values from the list that correspond true to the predicate/condition given as parameter to the function.
// The fn. iterates through every member of the list container and removes all the elements that return true for the predicate.

// Syntax: listname.remove_if(predicate)

// The predicate in the form of a function pointer or function object is passed as the parameter.

// Input  : list list{1, 2, 3, 4, 5};
//          list.remove_if(odd);
// Output : 2, 4

// Input  : list list{1, 2, 2, 2, 5, 6, 7};
//          list.remove_if(even);
// Output : 1, 5, 7



// bool even(const int &value) {return (value % 2) == 0;}

// bool odd(const int &value) {return (value % 2) != 0;}

/*
int main()
{
	list<int> myList = {1,2,2,2,5,6,7};
	myList.remove_if(even);

	printList(myList);

	return 0;
}
*/




// Question: Given a list of integers, remove all the prime numbers from the list and print the list.

bool isPrime(const int& value)
{
	if(value<=1){ return false;}

    for (int i = 2; i < value; i++) 
    {
        if (value % i == 0)
            return false;
	}
	return true;
}


int main()
{
	list<int> myList = {2,4,6,7,9,11,13};
	myList.remove_if(isPrime);

	printList(myList);

	return 0;
}











