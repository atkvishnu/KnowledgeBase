// NOTE: The operator>> eats whitespace (space, tab, newline). Use yourstream.get() to read each character.
// https://stackoverflow.com/questions/6774825/reading-from-ifstream-wont-read-whitespace


#include <iostream>
#include <fstream>

using namespace std;

void read_the_file(int n){
	fstream my_file;
	my_file.open("my_file.txt", ios::in);
	if(!my_file)
		cout << "No such file!" << endl;
	else
	{
		char ch;
		int i;
		for (i=0;i<n;i++){
			//stream >> std::noskipws;
			//my_file >> ch;
			my_file.get(ch);
			if (my_file.eof())
				break;

			cout << ch;
		}
		cout << endl;
	}
	my_file.close();
}

int main(){
	int n;
	cout << "Enter the number of letters that you want to read from the file: ";
	cin >> n;
	read_the_file(n);
	return 0;
}
