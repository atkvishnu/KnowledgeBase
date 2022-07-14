/*
ID: Kumar Vishnu [atkumar1]
TASK: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;

#define vi vector<int>

const long MOD = 1e9 + 7;

#define toUpper(x) std::transform(x.begin(), x.end(), x.begin(), std::toupper);
#define toLower(x) std::transform(x.begin(), x.end(), x.begin(), std::tolower);

#define sort_elements(a) sort(a.begin(), a.end())
#define fill_elements(a, n) fill(a.begin(), a.end(), n)
#define find_elements(a, n) find(a.begin(), a.end(), n)
#define reverse_elements(a) reverse(a.begin(), a.end())
#define replace_elements(a, n) replace(a.begin(), a.end(), n)
#define maximum_element(a) max_element(a.begin(), a.end())
#define minimum_element(a) min_element(a.begin(), a.end())
#define next_permutation_elements(a) next_permutation(a.begin(), a.end())

template <class T> T Ceils(T x, T y){ return x / y + ((x % y) != 0); }
template <class T> T gcd(T a, T b) { return (b ? __gcd(a, b) : a); }
template <class T> T lcm(T a, T b) { return (a / gcd(a, b)) * b; }
template <typename T> T nCr(T n, T r){ if (r > n - r)r = n - r;int ans = 1, i;for (i = 1; i <= r; i++){ans *= n - r + i;ans /= i;}return ans;}

int binary_to_decimal(long n) { int dec = 0, i = 0, rem; while (n!=0) {rem = n % 10;n /= 10;dec += rem * pow(2, i);++i;}return dec; }

long decimal_to_binary(int n) { long bin = 0;int rem, i = 1; while (n!=0) {rem = n % 2;n /= 2;bin += rem * i;i *= 10;}return bin; }

bool isPrime(int n){if (n < 2)return false;for (int i = 2; i * i <= n; i++)if (n % i == 0)return false;return true;}
bool isPowerTwo(int x) { return (x && !(x & (x - 1))); };
bool isSubstring(string s1, string s2){ if (s1.find(s2) != string::npos) return true; return false; }

int main()
{
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    int t = 0, amount = 0, friends = 0;
    string names[10];
    fin >> t;
    map<string, int> umap;
    for (int i = 0; i < t; ++i){
    	fin >> names[i];
    	umap[names[i]] = 0;
    }
    for(int i = 0; i < t; i++) {
		string name;
		fin >> name;
		fin >> amount >> friends;
		if (friends == 0) continue;
		
		int share = amount / friends;
		umap[name] -= share * friends;
		for(int x = 0; x < friends; x++) {
			fin >> name;
			umap[name] += share;
		}
	}
	for (int i = 0; i < t; i++) {
		fout << names[i] << " " << umap[names[i]] << endl;
	}

    return 0;
}

