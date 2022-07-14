/*
ID: Kumar Vishnu [atkumar1]
TASK: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main()
{
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");

    string a, b;
    int sum1 = 1, sum2 = 1;
    int chars, chars1;

    fin >> a >> b;
    
    for(int i = 0; i < a.size(); i++) {
    	chars = (int)a[i]-64;
    	sum1 *= chars;
    }

    for(int i = 0; i < b.size(); i++) {
    	chars1 = (int)b[i]-64;
    	sum2 *= chars1;
    }

    if(sum1%47 == sum2%47) {
    	fout << "GO" << endl;
    } else {
    	fout << "STAY" << endl;
    }
    
    return 0;
}