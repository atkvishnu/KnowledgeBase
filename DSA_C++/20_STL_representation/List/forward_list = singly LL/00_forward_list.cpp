#include <forward_list>
#include  <iostream>
using namespace std;

// NOTES: ---------------------
// Forward list in STL implements singly LL.
// They are more useful than other containers in insertion, removal, and moving operations (like sort).
// Allows contant time [O(1)] insertion and removal of elems.


// Difference b/w list and forward_list:
// * forward_list keeps track of the location of the location of only the next element, while, 
// * list keeps track of both next and previous elements (takes extra storage space).


// Drawback of a forward_list is that it canNOT be iterated backward, and, 
// it's individual elements cannot be accessed directly.


// forward_list is preferred over list when only forward traversal is required as we can save space (same as the singly LL is preferred over doubly LL).


// Some examples are:
// - Chaining in hashing.
// - Adjacency list representation of the graph, etc.
// -------------------------------

// ITERATORS: 
// begin(), end(),    cbegin(), cend()      , before_begin(), cbefore_begin()
// cbegin, cend, cbefore_begin -> gives us constant iterators

// --------------------------------------

// OPERATIONS: 

// 1. assign() : assigns values to the forward list. (it's other variant is used to assign repeated elements).

// 2. push_front() : insert the element at the first position on forward list. container_size++. The value from this function is copied to the space before first element in the container.

// 3. emplace_front() : similar to the previous function but in this no copying operation occurs, the element is created directly at the memory before the first element of the forward list.

// 4. pop_front() : deletes the first element of the list.

// 5. insert_after() :  gives us a choice to insert elements at any position in forward list. The arguments in this function are copied at the desired position.

// 6. emplace_after() : same operation as the above function but the elements are directly made without any copy operation.

// 7. erase_after() : erase elements from a particular position in the forward list.

// 8. remove() : removes the particular element from the forward list mentioned in its argument.

// 9. remove_if() : removes according to the condition in its argument.

// 10. splice_after() : transfers elements from one forward list to other.
// Syntax: forwardlist1_name.splice_after(position iterator, forwardlist2_name, first iterator, last iterator) 
// Parameters: The function accepts four parameters which are specified as below:
// position – Specifies the position in the forward_list after which the new elements are to be inserted.
// forwardlist2_name– Specifies the list from which elements are to be inserted.
// first– Specifies the iterator after which insertion is to be done.
// last– Specifies the iterator till which insertion is to be done.


// 11. front() : reference the first element in the forward list

// 12. empty() : checks if the forward list container is empty or not. Returns True/False

// 13. resize() : changes the size of forward list

// 14. unique() : Removes all consecutive duplicate elements from the forward_list. It uses a binary predicate for comparison.

// 15. reverse() : reverses thew order of the elements present in the forward list.

// ----------------------------------------------------


void printForwardList(forward_list<int> FORWARD_LIST){
	for(int &c: FORWARD_LIST) { 
		cout << c << " ";
	}
	cout << "\n";
}

int main()
{
	forward_list<int> f_list0;
	forward_list<int> f_list1;

	forward_list<int> f_list2 = {10,20,30,40,50,60,70};



	// 1. .assign()
	f_list0.assign({1,2,3});	
	f_list1.assign(5,10);	// assigns 5 - 10's

	cout << "The elements of the f_list0 are: ";
	printForwardList(f_list0);		// 1 2 3

	cout << "The elements of the f_list1 are: ";
	printForwardList(f_list1);		// 10 10 10 10 10


	// 2. .push_front()
	f_list2.push_front(10);
	// 3. .emplace_front()
	f_list2.emplace_front(100);
	f_list2.emplace_front(100);
	
	printForwardList(f_list2);

	// 4. .pop_front()
	f_list2.pop_front();

	printForwardList(f_list2);


	// 5. .insert_after()
	forward_list<int> f_list3 = {10,20,30};
	forward_list<int>::iterator ptr;
	ptr = f_list3.insert_after(f_list3.begin(), {1,2,3});
	printForwardList(f_list3);	// 10 1 2 3 20 30


	// 6. .emplace_after(<pos>, value)
	ptr = f_list3.emplace_after(ptr, 2);
	printForwardList(f_list3);	// 10 1 2 3 2 20 30 
	// cout << *ptr;

	// 7. .erase_after()
	ptr = f_list3.erase_after(ptr);
	printForwardList(f_list3);	// 10 1 2 3 2 30 


	// 8. .remove()
	cout << ".remove()";
	forward_list<int> f_list4 = {10,20,30,25,40,40};
	printForwardList(f_list4);
	f_list4.remove(40);
	cout << "The forward list after remove operation : ";
	printForwardList(f_list4);


	// 9. .remove_if()
	f_list4.remove_if([](int x) { return x > 20; });
    cout << "The forward list after remove_if operation : ";
	printForwardList(f_list4);


	// 10. .splice_after()
	forward_list<int> f_list5 = { 10, 20, 30 };
	forward_list<int> f_list6 = { 40, 50, 60 };
	f_list6.splice_after(f_list6.begin(), f_list5);	// f_list6.begin() = 40, elems added after 40
	cout << "The forward list after splice_after operation: ";
	printForwardList(f_list6);	// 40 10 20 30 50 60


    forward_list<int> list1 = { 10, 20, 30, 40 };
    forward_list<int> list2 = { 4, 9 };
    list2.splice_after(list2.begin(), list1, list1.begin(), list1.end());
    cout << "Elements are: " << endl;
    printForwardList(list2);	// 4 20 30 40 9


	// 11. .front()
	cout << "f_list6 1st item is: " << f_list6.front() << endl;


	// 12. .empty()
	if(f_list5.empty())
		cout << "True";
	else
		cout << "False";

	// 13. resize()
	f_list4.resize(10);
	printForwardList(f_list4);

	// 14. unique() : Removes all consecutive duplicate elements from the forward_list. It uses a binary predicate for comparison.
	forward_list<int> f_list7 = { 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 2, 4, 4 };
    cout << "List of elements before unique operation is: ";
    printForwardList(f_list7);
    f_list7.unique();
    cout << "\nList of elements after unique operation is: ";
    printForwardList(f_list7);

	// 15. reverse() : reverses thew order of the elements present in the forward list.
    f_list7.reverse();
    cout << "\nList elements after performing reverse operation: ";
	printForwardList(f_list7);    


	return 0;
}









