// Optimised space consumption of hash table.
// In this solution hash table is of size 26 (number of characters in english language)


#include <bits/stdc++.h>
using namespace std;


int getCharASCIIcode(char &c){
	char cl = tolower(c);			// convert each char into lowercase first
	int cNum = (int)cl;				// converting chars to integers	// can be merged in next line to save the space of a int variable!
	if(cNum>=97 && cNum<=122){		// 'a' = 97 && 'z' = 122
		return cNum;
	} else {
		return -1;
	}
}


vector<int> frequencyTable(string &str){
	vector<int> hash_table(26,0);
	for(char &c : str){
		int val = getCharASCIIcode(c);
		if(val!=-1){
			hash_table[val-97]++;		// (val-97) => a@0 && z@25
		}
	}
	return hash_table;
}


bool isPalindrome(string &str){

	vector<int> table = frequencyTable(str);
	// cout << table << endl;
	int countOdd = 0;	// cannot be more than 1 (middle element)
	for(int i: table) {
		if(i % 2 != 0){
			countOdd++;
		}
	}
	if (countOdd > 1) {
		return false;
	} else {
		return true;
	}
}




int main(){

	std::string str("Tact Coa");
	std::string str1("A big Cat");
	std::string str2("Aba cbc");

	cout << boolalpha << isPalindrome(str) << endl;
	cout << boolalpha << isPalindrome(str1) << endl;
	cout << boolalpha << isPalindrome(str2) << endl;

	exit(0);
}


