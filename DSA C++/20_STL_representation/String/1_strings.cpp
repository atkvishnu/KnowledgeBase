#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	string s, s1, s2;
	s = "HELLO";
	s1 = "HELLO";
	s2 = s1.c_str();

	if(s.compare(s1) == 0)
		cout << s << " is equal to " << s1 << endl;
	else
		cout << s << " is not equal to " << s1 << endl;

	s.append(" WORLD! ");
	cout << sizeof(s) << endl;

	printf("%s\n", s.c_str());
	cout << s.c_str() << endl;
	cout << sizeof(s.c_str()) << endl;

	if(s.compare(s1) == 0)
		cout << s << " is equal to " << s1 << endl;
	else
		cout << s << "is not equal to " << s1 << endl;

	for(int i = 0; s2[i] != '\0'; i++){
		cout << s[i] << "-";
	}

	return EXIT_SUCCESS;
	
}