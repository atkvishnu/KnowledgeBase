// Part of  (stdlib.h)
// atoi - Convert string to integer (stdlib.h)
// atof - Convert string to double (stdlib.h)
// atol - Convert string to long integer (stdlib.h)
// strtod - Convert string to double (stdlib.h)
// strtol - Convert string to long integer (stdlib.h)
// strtof - C++11 - Convert string to float (stdlib.h)
// atoll - C++11 - Convert string to long long integer (stdlib.h)
// strtold - C++11 - Convert string to long double (stdlib.h)
// strtoll - C++11 - Convert string to long long integer (stdlib.h)
// strtoull - C++11 - Convert string to unsigned long long integer (stdlib.h)



// Part of <string> - After C++11
// Available Classes: string, u16string, u32string, wstring
// Functions: 
// stoi - Convert string to integer
// stol - Convert string to long int
// stod - Convert string to double
// stoll - Convert string to long long
// stoull - Convert string to unsigned long long
// stof - Convert string to float
// stold - Convert string to long double
// stoul - Convert string to unsigned integer
// to_string - Convert numerical value to string
// to_wstring - Convert numerical value to wide string



/*
// 1. std::stoi()
// Introduced in C++11 

// Convert string to integer

// int stoi (const string&  str, size_t* idx = 0, int base = 10);
// int stoi (const wstring& str, size_t* idx = 0, int base = 10);

// Parses str interpreting its content as an integral number of the specified base, which is returned as an int value.
// If idx is not a null pointer, the function also sets the value of idx to the position of the first character in str after the number.
// The function uses strtol (or wcstol) to perform the conversion (see strtol for more details on the process).

#include <iostream>
#include <string>	// std::string, std::stoi
using namespace std;


int main()
{
	string str_dec = "2001, A Space Odyssey";
	string str_hex = "40c3";
	string str_bin = "-10101100011";
	string str_auto = "0x7f";

	string::size_type sz;	// alias of size_t

	int i_dec = stoi(str_dec, &sz);
	int i_hex = stoi(str_hex, nullptr, 16);
	int i_bin = stoi(str_bin, nullptr, 2);
	int i_auto = stoi(str_auto, nullptr, 0);

	cout << "Value of sz: " << sz << endl;

	cout << str_dec << ": " << i_dec << " and [" << str_dec.substr(sz+1) << " ]" << str_dec.substr(sz,7) << "]\n";
	cout << str_hex << ": " << i_hex << "\n";
	cout << str_bin << ": " << i_bin << "\n";
	cout << str_auto << ": " << i_auto << "\n";

	return 0;
}
*/



/*
// 2. std::stol (convert string to long int)
// Introduced in C++11

// long stol (const string&  str, size_t* idx = 0, int base = 10);
// long stol (const wstring& str, size_t* idx = 0, int base = 10);

// Parses str interpreting its content as an integral number of the specified base, which is returned as a value of type long int.
// If idx is not a null pointer, the function also sets the value of idx to the position of the first character in str after the number.
// The function uses strtol (or wcstol) to perform the conversion (see strtol for more details on the process).

#include <iostream>
#include <string>	// std::string, std::stol
using namespace std;

int main()
{
	string str_dec = "1987520";
	string str_hex = "2f04e009";
	string str_bin = "-11101001100100111010";
	string str_auto = "0x7fffff";

	string::size_type sz; 	// alias of size_t

	long li_dec = stol(str_dec, &sz);
	long li_hex = stol(str_hex, nullptr, 16);
	long li_bin = stol(str_bin, nullptr, 2);
	long li_auto = stol(str_auto, nullptr, 0);

	cout << str_dec << ": " << li_dec << "\n";
	cout << str_hex << ": " << li_hex << "\n";
	cout << str_bin << ": " << li_bin << "\n";
	cout << str_auto << ": " << li_auto << "\n";

	return 0;
}
*/

/*
// 3. std::stoll (convert string to long long)
// Introduced in C++11

// long long stoll (const string&  str, size_t* idx = 0, int base = 10);
// long long stoll (const wstring& str, size_t* idx = 0, int base = 10);

// Parses str interpreting its content as an integral number of the specified base, which is returned as a value of type long long.
// If idx is not a null pointer, the function also sets the value of idx to the position of the first character in str after the number.
// The function uses strtoll (or wcstoll) to perform the conversion.

// stoll example
#include <iostream>   // std::cout
#include <string>     // std::string, std::stoll

int main ()
{
	std::string str = "8246821 0xffff 020";

	std::string::size_type sz = 0;   // alias of size_t

	while (!str.empty()) {
		long long ll = std::stoll (str,&sz,0);
		std::cout << str.substr(0,sz) << " interpreted as " << ll << '\n';
		str = str.substr(sz);
	}

	return 0;
}
*/

/*
// 4. std::stoull (convert string to unsigned long long)
// Introduced in C++11

// Parses str interpreting its content as an integral number of the specified base, which is returned as a value of type unsigned long long.
// If idx is not a null pointer, the function also sets the value of idx to the position of the first character in str after the number.
// The function uses strtoull (or wcstoull) to perform the conversion (see strtol for more details on the process).

// stoull example
#include <iostream>   // std::cout
#include <string>     // std::string, std::stoull

int main ()
{
	std::string str = "8246821 0xffff 020 -1 +1";

	std::string::size_type sz = 0;   // alias of size_t

	while (!str.empty()) {
		unsigned long long ull = std::stoull (str,&sz,0);
		std::cout << str.substr(0,sz) << " interpreted as " << ull << '\n';
		str = str.substr(sz);
	}
  return 0;
}
*/

/*
// 5. std::strtoull (convert string to unsigned long long integer) - For C string equivalent
// C++11

// Syntax:
// unsigned long long int strtoull (const char* str, char** endptr, int base);

// Parses the C-string str interpreting its content as an integral number of the specified base, which is returned as a value of type unsigned long long int. If endptr is not a null pointer, the function also sets the value of endptr to point to the first character after the number.
// This function operates like strtol to interpret the string, but produces numbers of type unsigned long long int (see strtol for details on the interpretation process).


/* strtoull example 
#include <stdio.h>      /* printf, NULL 
#include <stdlib.h>     /* strtoull 

int main ()
{
	char szNumbers[] = "250068492 7b06af00 1100011011110101010001100000 0x6fffff";
	char * pEnd;
	unsigned long long int ulli1, ulli2, ulli3, ulli4;
	ulli1 = strtoull (szNumbers, &pEnd, 10);
	ulli2 = strtoull (pEnd, &pEnd, 16);
	ulli3 = strtoull (pEnd, &pEnd, 2);
	ulli4 = strtoull (pEnd, NULL, 0);
	printf ("The decimal equivalents are: %llu, %llu, %llu and %llu.\n", ulli1, ulli2, ulli3, ulli4);
	return 0;
}
*/


/*
// 6. std::strtod (convert string to double)

// Syntax: double strtod (const char* str, char** endptr);

// Parse C-string str interpreting its content as a floating point number (according to the current locale) and returns its value as a double.
// If endptr is not a null pointer, the function also sets the value of endptr to point to the first character after the number.

// strtod example
#include <stdio.h>      //printf, NULL
#include <stdlib.h>     //strtod

int main ()
{
  char szOrbits[] = "365.24 29.53";
  char* pEnd;
  double d1, d2;
  d1 = strtod (szOrbits, &pEnd);
  d2 = strtod (pEnd, NULL);
  printf ("The moon completes %.2f orbits per Earth year.\n", d1/d2);
  return 0;
}
*/



/*
// 7. std::atof (Convert string to double) - For C-string

// Syntax: double atof (const char* str);

// Parses the C string str, interpreting its content as a floating point number and returns its value as a double.

// atof example: sine calculator
#include <stdio.h>      // printf, fgets
#include <stdlib.h>     // atof
#include <math.h>       // sin

int main ()
{
	double n,m;
	double pi=3.1415926535;
	char buffer[256];
	printf ("Enter degrees: ");
	fgets (buffer,256,stdin);
	n = atof (buffer);
	m = sin (n*pi/180);
	printf ("The sine of %f degrees is %f\n" , n, m);
	return 0;
}
*/




// 