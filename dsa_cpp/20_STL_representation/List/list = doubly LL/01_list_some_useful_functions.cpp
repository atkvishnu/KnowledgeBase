// List - C++ - Some useful functions


// 1. emplace(position, value): inserts an elemnet at the "position" specified.

// 2. emplace_back(value): adds "value" @ end of list. It's faster than push_back() because it directly creates elements at position whereas push_back() first makes a temp. copy and copies from there. emplace_back() is faster in implementation than push_back()

// 3. emplace_front(value): adds "value" @ beginning of list. It's faster than push_front() by the fact that it directly creates elements at position whereas push_front() first makes a temporary copy and copies from there. emplace_front() is faster in implementation than push_front()


#include <iostream>
#include <list>
using namespace std;

void printList(list<int> LI){
	list<int>::iterator it;
	for(int &x: LI){
		cout << x << " ";
	}
	cout << endl;
}

/*
int main()
{
	// Declaring a list
	list<int> gqlist;

	// Initializing the iterator
	list<int>::iterator it = gqlist.begin();

	// 2
	for(int i = 1; i <= 5; i++)
		gqlist.emplace_back(i);

	cout << "List after emplace_back operation is: ";
	printList(gqlist);

	// 3
	for (int i = 10; i <= 50; ++i)
		gqlist.emplace_front(i);

	cout << "List after emplace_front operation is: ";
	printList(gqlist);

	// using advance() to advance iterator position
	advance(it, 2);

	// 1
	gqlist.emplace(it, 200);

	cout << "List after emplace operation: ";
	printList(gqlist);

	return 0;
}
*/


// 4. merge(list2) : merges list2 with list1. If both lists are in sorted order, then the resulting list is also sorted.

// 5. remove_if(condition) : removes the elements from the list on the basis of the condition given in the argument.
/*
int main()
{
	list<int> gqlist1 = {1,2,3};
	list<int> gqlist2 = {2,4,6};

	gqlist1.merge(gqlist2);		// as both the lists are sorted, the result also comes out to be sorted.
	
	cout << "List1 after merging: ";
	printList(gqlist1);

	gqlist1.remove_if([](int x) {return x % 2 != 0;});	// 1,3 removed

	cout << "List1 after remove_if operation: ";
	printList(gqlist1);

	return 0;
}
*/


// 6. unique(): used to delete the repeated occurences of the number. List has to be sorted.

// 7. splice(position, list2) : used to transfer elements from one list into another.
/*
int main()
{	
	list<int> gqlist1 = {1,1,1,2,2,3,3,4};
	list<int> gqlist2 = {2,4,6};

	list<int>::iterator it = gqlist1.begin();

	advance(it,3);

	cout << "list1 before unique operation is: ";
	printList(gqlist1);

	gqlist1.unique();

	cout << "list1 after unique operation: ";
	printList(gqlist1);				// 1 2 3 4

	// cout << *it << endl;			// 2
	// using splice() to splice list2 in list1 at position, it inserts list2 after 2nd position
	gqlist1.splice(it, gqlist2);	// 1 2 4 6 2 3 4

	cout << "list1 after splice operation: ";
	printList(gqlist1);

	return 0;
}
*/

// 8. swap(list2): swaps one list element with other.
int main()
{
	list<int> gqlist1 = {1,2,3,4};
	list<int> gqlist2 = {2,4,6};

	cout << "Contents of list1 before swap: ";
	printList(gqlist1);
	cout << "Contents of list2 before swap: ";
	printList(gqlist2);



	gqlist1.swap(gqlist2);



	cout << "Contents of list1 after swap: ";
	printList(gqlist1);

	cout << "Contents of list2 after swap: ";
	printList(gqlist2);


	return 0;
}

















