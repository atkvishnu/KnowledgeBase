// C++ provides a powerful alternative for the char*. 
// String class provides different string manipulation functions 
// like concatenation, find, replace etc.

#include <string>

// Member functions
// 		String constructor -> default(Class_name()), Parameterized(Class_name(parameters)), Copy(Class_name(const Class_name old_object))
//		String destructor -> ~constructor-name() [new->delete][malloc->free]
//		String operators -> assignment(=)
// 		* constructor of string class will set it to C-style string, which ends at '\0'


// Iterators (#include <iterator>)
//		begin() -> iterator to "beginning" pos of container. Its time complexity is O(1).
//		end() -> Returns an iterator pointing to a position which is next to the last character. Its time complexity is O(1).
//		advance(ptr, x) -> increment iterator pos till specified number(x)
//		next(ptr, x) -> new iterator which would point after advancing the positions mentioned in args
//		prev(ptr, x) -> new iterator which would point after decrementing the positions mentioned in args
//		inserter() -> insert element at any position in the container
//		rbegin() -> returns reverse iterator to reverse beginning
//		rend() -> returns reverse iterator to reverse end
//		cbegin() -> Return const_iterator to beginning
//		cend() -> Return const_iterator to end
//		crbegin() -> Return const_reverse_iterator to reverse beginning
//		crend() -> Return const_reverse_iterator to reverse end


// Capacity (std::string str;)
//		size() -> returns length of string (vector, map, etc.). Its time complexity is O(1).
//		length() -> -do- (word, sentence, paragraph). Its time complexity is O(1).
//		str.max_size() -> returns max size of string (max. size depends on the compiler and system)
//		str.resize(x, <optional: element>) -> resize string. Resize the string to the new length which can be less than or greater than the current length. Its time complexity is O(N) where N is the size of the new string.
//		capacity() -> returns size of allocated storage
//		reserve() -> request a change in capacity
//		clear() -> Erases all the contents of the string and assign an empty string (“”) of length zero. Its time complexity is O(1).
//		empty() -> Returns a boolean value, true if the string is empty and false if the string is not empty. Its time complexity is O(1).
//		shrink_to_fit() -> decreases the capacity of the string and makes it equal to minm. capacity of the string. useful to save additional memory if we are sure that no further addition of characters has to be made.
//		strlen() -> C library fn., computes length of string
//		using `while` loop.	[while(str(i)){i++;}cout << i;]
//		using `for` loop. [for(int i = 0; str[i]; i++){;}cout << i << endl;]


// Element Access
//		at() -> Returns the character at a particular position (can also be done using ‘[ ]’ operator). Its time complexity is O(1).
//		back() -> access last character
//		front() -> access first char


// Modifiers
//		Operator [+=] -> Append to string
//		append(str2)/str1.append(str2, 0, 5) -> appends 5 chars. from 0th index of str2 to str1. Inserts additional characters at the end of the string (can also be done using ‘+’ or ‘+=’ operator). Its time complexity is O(N) where N is the size of the new string.
//		push_back() -> adds chars @ end of string
//		assign() -> used for assignment. asssigns new value to the string, replacing the current contents.(can also be done using ‘=’ operator).
//		insert(pos, "chars to insert") -> insert @pos into string.  Its time complexity is O(N) where N is the size of the new string.
//		erase() -> Deletes a substring of the string. Its time complexity is O(N) where N is the size of the new string.
//		str1.replace(0, 7, str2) -> replace portion of string. Its time complexity is O(N) where N is size of the new string.
//		replace_if(str1.begin(), str1.end(), f, <new-char>) -> f is a fn.
//		swap() -> swap string values
//		pop_back() -> delete last chars.

// String Operations
//		Operator -> [] -> Gets character of string
//		c_str() -> Convert the string into C-style string (null terminated string) and returns the pointer to the C-style string. Its time complexity is O(1).
//		data -> Get string data
//		get_allocator -> get allocator
//		copy() -> Copies the substring of the string in the string passed as parameter and returns the number of characters copied. Its time complexity is O(N) where N is the size of the copied string.
//		find() -> find content in string. Searches the string and returns the first occurrence of the parameter in the string. Its time complexity is O(N) where N is the size of the string.
//		rfind() -> find last occurance of content in string
//		find_first_of() -> find character in string
//		find_last_of() -> find char in string from end
//		find_first_not_of() -> find absence of chars in string
//		find_last_not_of() -> find non-matching chars in the string from the end 
//		substr() -> Returns a string which is the copy of the substring. Its time complexity is O(N) where N is the size of the substring.
//		compare() -> Compares the value of the string with the string passed in the parameter and returns an integer accordingly. Its time complexity is O(N + M) where N is the size of the first string and M is the size of the second string.


// Member constants and Non-member function overloads
//		Operator -> [+] -> concatenates strings
//		Operator -> [<<] -> Insert string into stream
//		Operator -> [>>] -> Extract string from stream
//		npos -> maxm. value of size_t
//		Relational Operators -> >,<,==,!=,>=,<=
//		swap() -> exchanges values of two strings
//		getline(cin, str) -> get line from stream into string

#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	string s, s1;

	return 0;
}

