// Maps are containers which store elements by mapping their value against a particular key. It stores the combination of key value and mapped value following a specific order. Here key value are used to uniquely identify the elements mapped to it. The data type of key value and mapped value can be different. Elements in map are always in sorted order by their corresponding key and can be accessed directly by their key using bracket operator ([ ]).

// In map, key and mapped value have a pair type combination,i.e both key and mapped value can be accessed using pair type functionalities with the help of iterators.

// declaration. Here key values are of char type and mapped values(value of element) is of int type.

// map <char ,int > mp;
// mp[‘b’]  = 1;

// It will map value 1 with key ‘b’. We can directly access 1 by using mp[ ‘b’ ].
// mp[‘a’] = 2;
// It will map value 2 with key ‘a’.

// In map mp , the values be will be in sorted order according to the key.

// Note: N is the number of elements in map.

// Some Member Functions of map:

// at( ): Returns a reference to the mapped value of the element identified with key.Its time complexity is O(logN).
// count( ): searches the map for the elements mapped by the given key and returns the number of matches.As map stores each element with unique key, then it will return 1 if match if found otherwise return 0.Its time complexity is O(logN).
// clear( ): clears the map, by removing all the elements from the map and leaving it with its size 0.Its time complexity is O(N).
// begin( ): returns an iterator(explained above) referring to the first element of map.Its time complexity is O(1).
// end( ): returns an iterator referring to the theoretical element(doesn’t point to an element) which follows the last element.Its time complexity is O(1).
// empty( ): checks whether the map is empty or not. It doesn’t modify the map.It returns 1 if the map is empty otherwise returns 0.Its time complexity is O(1).
// erase( ): removes a single element or the range of element from the map.
// find( ): Searches the map for the element with the given key, and returns an iterator to it, if it is present in the map otherwise it returns an iterator to the theoretical element which follows the last element of map.Its time complexity is O(logN).
// insert( ): insert a single element or the range of element in the map.Its time complexity is O(logN), when only element is inserted and O(1) when position is also given.

#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<char,int> mp;
	map<char,int> mymap,mymap1;

	// insert element individually in map with the combination of key-value of element
	mp.insert(pair<char,int>('a',2));
	mp.insert(pair<char,int>('b',1));
	mp.insert(pair<char,int>('c',43));	// key is 'c' and 43 is the value
	// mp = {'a': 2, 'b': 1, 'c': 43}

	// inserts elements in range using insert() function in map 'mymap'
	mymap.insert(mp.begin(),mp.end());
	// mymap = {'a': 2, 'b': 1, 'c': 43}


	// declaring iterator for map
	map<char,int>::iterator it;

	// using find() fn. to return reference of element mapped by key 'b'.
	it = mp.find('b');

	cout << "Key and element's value of map are: ";
	cout << it->first << " and " << it->second << endl;

	// alternative way to insert elements by mapping with their keys
	mymap1['x'] = 23;
	mymap1['y'] = 21;	// mymap = {'x': 23, 'y': 21}

	cout << "Printing element mapped by key 'b' using at() function: " << mp.at('b') << endl;
	cout << "Printing element mapped by key 'x' using at() function: " << mymap1.at('x') << endl;

	// cout << mymap.at('c') << endl;

	// swap contents of 2 maps namely mymap and mymap1
	mymap.swap(mymap1);

	// prints swapped elements of mymap and mymap1 by iterating all the elements through using iterator
	cout<<"Swapped elements and their keys of mymap are: "<<endl;
    for(it=mymap.begin();it!=mymap.end();it++)
    	cout<<it->first<<" "<<it->second<<endl;
    cout<<"Swapped elements and their keys of mymap1 are: "<<endl;
    for(it=mymap1.begin();it!=mymap1.end();it++)
    	cout<<it->first<<" "<<it->second<<endl;

    // erases element mapped at 'c'
    mymap1.erase('c');

    //prints all elements of mymap after erasing element at 'c'.
    cout<<"Elements of mymap1 after erasing element at key 'c' : "<<endl;
    for(it=mymap1.begin();it!=mymap1.end();it++)
    	cout<<it->first<<" "<<it->second<<endl;


    // erases element in range from mymap1
    mymap1.erase(mymap1.begin(), mymap1.end());

    cout << "As mymap1 is empty so empty() function will return 1: " << mymap1.empty() << endl;

    // number of elements with key = 'a' in map mp.
    cout << "Number of elements with key='a' in map mp are: " << mp.count('a') << endl;


    // if mp is empty then return 1 else 0
    if(mp.empty())
    	cout << "Map is empty." << endl;
    else
    	cout << "Map is not empty." << endl; 

    return 0;
}














