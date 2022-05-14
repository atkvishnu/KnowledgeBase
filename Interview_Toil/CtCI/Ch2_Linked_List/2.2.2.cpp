#include <bits/stdc++.h>
using namespace std;


int kth_to_last(forward_list<int> &l, int k) {
	int counter = 0;
	for(auto it = l.cbegin(); it != l.cend(); it++) {
		++counter;
	}
	counter -= k;
	auto answer = l.cbegin();
	for(int i = 0; i < counter; i++) {
		++answer;
	}
	return *answer;
}



int main() {
	forward_list<int> fll = {1,2,3,4};
	cout << kth_to_last(fll, 1) << endl;
	return 0;
}

// LL = {1,2,3,4}
// 1st to last = 4
// 2nd to last = 3
// 3rd to last = 2
// 4th to last = 1