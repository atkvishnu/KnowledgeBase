Daily Coding Problem: Problem #82 {Easy}

```
Good morning! Here's your coding interview problem for today.

This problem was asked Microsoft.

Using a read7() method that returns 7 characters from a file, implement readN(n) which reads n characters.

For example, given a file with the content “Hello world”, three read7() returns “Hello w”, “orld” and then “”.
```

ANSWER in `1readN.cpp`




# NOTES
## file handling in C++

Files store data permanently in a storage device. With file handling, the output from a program can be stored in a file. Various operations can be performed on the data while in the file.

A stream is an abstraction of a device where input/output operations are performed. You can represent a stream as either a destination or a source of characters of indefinite length. This will be determined by their usage. C++ provides you with a library that comes with methods for file handling.



## The fstream Library

The fstream library provides C++ programmers with three classes for working with files. These classes include:

-   **ofstream**– This class represents an output stream. It’s used for creating files and writing information to files.
-   **ifstream**– This class represents an input stream. It’s used for reading information from data files.
-   **fstream**– This class generally represents a file stream. It comes with ofstream/ifstream capabilities. This means it’s capable of creating files, writing to files, reading from data files.

!(fstream library)[https://www.guru99.com/images/2/100520_1107_CFileHandli1.png]

To use the above classes of the fstream library, you must include it in your program as a header file using the # include preprocessor directive.



## How to Open Files

Before performing any operation on a file, you must first open it. If you need to write to the file, open it using fstream or ofstream objects. If you only need to read from the file, open it using the ifstream object.

The three objects, that is, fstream, ofstream, and ifstream, have the open() function defined in them. The function takes this syntax:

open (file_name, mode);

-   The file_name parameter denotes the name of the file to open.
-   The mode parameter is optional. It can take any of the following values:

|   value    |                                      description                                      |
|:----------:|:-------------------------------------------------------------------------------------:|
| ios:: app  |            The Append mode. The output sent to the file is appended to it.            |
|  ios::ate  | It opens the file for the output then moves the read and write control to file’s end. |
|  ios::in   |                             It opens the file for a read.                             |
|  ios::out  |                            It opens the file for a write.                             |
| ios::trunc |     If a file exists, the file elements should be truncated prior to its opening.     |


It is possible to use two modes at the same time. You combine them using the | (OR) operator.


### Example 1:

```cpp
#include <iostream>
#include <fstream>
using namespace std;
int main() {
	fstream my_file;			// Creates an object of the fstream class and give it the name my_file.
	my_file.open("my_file", ios::out);		// Apply the open() function on the above object to create a new file. The out mode allows us to write into the file.
	// Use if statement to check whether file creation failed.
	if (!my_file) {
		cout << "File not created!";
	}
	else {
		cout << "File created successfully!";
		my_file.close(); 	// Apply the close() function on the object to close the file.
	}
	return 0;
}
```
**Output:**
File created successfully


## How to Close Files

Once a C++ program terminates, it automatically

-   flushes the streams
-   releases the allocated memory
-   closes opened files.

However, as a programmer, you should learn to close open files before the program terminates.

The fstream, ofstream, and ifstream objects have the close() function for closing files. The function takes this syntax:

```
void close();
```



## How to Write to Files

You can write to file right from your C++ program. You use stream insertion operator (<<) for this. The text to be written to the file should be enclosed within double-quotes.

Let us demonstrate this.

### Example 2:

```
#include <iostream>
#include <fstream>
using namespace std;
int main() {
	fstream my_file;	// Create an instance of the fstream class and give it the name my_file.
	my_file.open("my_file.txt", ios::out);	// Use the open() function to create a new file named my_file.txt. The file will be opened in the out mode for writing into it.
	// Use an if statement to check whether the file has not been opened.
	if (!my_file) {
		cout << "File not created!";
	}
	else {
		cout << "File created successfully!";
		my_file << "Hello, World";
		my_file.close();	// Use the close() function to close the file.
	}
	return 0;
}
```

**Output**:
File created successfully


## How to Read from Files

You can read information from files into your C++ program. This is possible using stream extraction operator (>>). You use the operator in the same way you use it to read user input from the keyboard. However, instead of using the cin object, you use the ifstream/ fstream object.

### Example 3:

```

#include <iostream>
#include <fstream>	// Include the fstream header file in the program to use its classes.
using namespace std;
int main() {
	fstream my_file;	// Create an instance of the fstream class and give it the name my_file
	my_file.open("my_file.txt", ios::in);
	if (!my_file) {
		cout << "No such file";
	}
	else {
		char ch;	// Create a char variable named ch.

		while (1) {		// while loop for iterating over the file contents
			my_file >> ch;	// Write/store contents of the file in the variable ch
			if (my_file.eof())	// Use an if condition and eof() function that is, end of the file, to ensure the compiler keeps on reading from the file if the end is not reached
				break;	// break statement to stop reading from the file once the end is reached

			cout << ch;
		}

	}
	my_file.close();
	return 0;
}

```

**Output:**
Hello World

### Summary:

-   With file handling, the output of a program can be sent and stored in a file.
-   A number of operations can then be applied to the data while in the file.
-   A stream is an abstraction that represents a device where input/output operations are performed.
-   A stream can be represented as either destination or source of characters of indefinite length.
-   The fstream library provides C++ programmers with methods for file handling.
-   To use the library, you must include it in your program using the # include preprocessor directive.