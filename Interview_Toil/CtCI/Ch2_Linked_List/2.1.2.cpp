// using STL


#include <bits/stdc++.h>
using namespace std;

void printLinkedList(forward_list<int> &FWL) {
	for(auto &x: FWL) {
    cout << x << " -> ";
  }
	cout << "nullptr" << endl;
}
/*
 * will return sorted linked list as answer.
 * uses an extra set.
 */
void solve1(forward_list<int> &li){
  set<int> o1;
  for(auto it = li.begin(); it!=li.end(); it++){
    o1.insert(*it);  
  }
  for(int x : o1) {
    cout << x << " -> ";
  }
  cout << "nullptr" << endl;
}


/**
 * @brief      Solution 2 using STL
 * @param      li    Forward List
 * 
 * Time Complexity: O(n), because we iterate through the forward list only once, performing constant work over each element.
 * Space Complexity: O(n), because in the worst case we store each element in the hashmap.
 */

void solve2(forward_list<int> &li) {
  
  map<int, bool> seen;
  
  auto first = li.begin();
  auto runner = ++(li.begin());
  
  while(runner!=li.end()){
    seen[*first] = true;
    if(seen[*runner]) {
      runner = first;
      li.erase_after(first);
    } else {
      ++first;
    }
    ++runner;
  }

}



int main() {
  cout << "Linked List before operation: \n";
	forward_list<int> the_list = {1,2,3,1,2,3,5,6,7,5,6,7};
	printLinkedList(the_list);
  cout << "Answer to Solution 1:\n";
  solve1(the_list);

  cout << "Answer to Solution 2:\n";
  solve2(the_list);
  printLinkedList(the_list);

}