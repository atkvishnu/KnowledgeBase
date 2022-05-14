// Some of the operations other than insertions and deletions that can be used in forward lists are as follows :

// 1. merge() :- This function is used to merge one forward list with other. 
// 				If both the lists are sorted then the resulted list returned is also sorted.

// 2. operator “=” :- This operator copies one forward list into other. 
// 					The copy made in this case is deep copy.

// 3. sort() :- This function is used to sort the forward list.

// 4. unique() :- This function deletes the multiple occurrences of a number and returns a forward list with unique elements. 
// 				The forward list should be sorted for this function to execute successfully.

// 5. reverse() :- This function is used to reverse the forward list.

// 6. swap() :- This function swaps the content of one forward list with other.

// 7. clear() :- This function clears the contents of forward list. 
// 				After this function, the forward list becomes empty.

// 8. empty() :- This function returns true if the list is empty otherwise false.

#include<iostream>
#include<forward_list> 
using namespace std;

void printForwardList(forward_list<int> FORWARD_LIST){
	for(int &c: FORWARD_LIST) { 
		cout << c << " ";
	}
	cout << "\n";
}


int main()
{     
     // Initializing 1st forward list
     forward_list<int> flist1 = {1, 2, 3};
       
     // Declaring 2nd forward list
     forward_list<int> flist2; 
       
     // Creating deep copy using "="
     // 2. operator [=]
     flist2 = flist1;

    // Displaying flist2
     cout << "The contents of 2nd forward list after copy are : ";
     printForwardList(flist2);
       
     // Using merge() to merge both list in 1
     // 1. merge()
     flist1.merge(flist2);
       
     // Displaying merged forward list
     // Prints sorted list
     cout << "The contents of flist1 after merge are : ";
     printForwardList(flist1);


     forward_list<int> flist3 = {1, 2, 3, 2, 3, 3, 1};
     // 3. .sort()
     flist1.sort();
     // Displaying sorted forward list
     cout << "The contents of forward list after sorting are : ";
     printForwardList(flist3);


     // Use of unique() to remove repeated occurrences
     // 4. 
     flist3.unique();

     // Displaying forward list after using unique()
     cout << "The contents of forward list after unique operation are : \n";
     printForwardList(flist3);

     // 5.
     flist3.reverse();
     printForwardList(flist3);


     // Use of swap() to swap the list
     // 6. 
     forward_list<int> flist4 = {1, 2, 3};
     forward_list<int> flist5 = {4, 5, 6};
     printForwardList(flist4);
     printForwardList(flist5);
     flist4.swap(flist5);
     printForwardList(flist4);
     printForwardList(flist5);

     // 7. 
     flist4.clear();
     printForwardList(flist4);	// flist4 cleared

     // 8.
     flist4.empty() ? cout << "Forward list is empty" : 
                      cout << "Forward list is not empty";

       
     return 0;    
} 













