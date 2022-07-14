#include <iostream>
#include <cassert>
#include <queue>

using namespace std;



namespace data_structures {

	namespace stack_using_queue {

		struct Stack {
			queue<int> first;
			queue<int> second;
			int curr_size = 0;

			int top() {
				return first.front();
			}

			void push(int data) {
				second.push(data);
				while(!first.empty()) {
					second.push(first.front());
					first.pop();
				}
				swap(first, second);
				curr_size++;
			}

			void pop() {
				if(first.empty()) return;
				first.pop();
				curr_size--;
			}

			int size() { return curr_size; }

			void Display() {
				queue<int> copy1 = first;
				queue<int> copy2 = second;
				while (!copy1.empty()) {
				  cout << copy1.front() << " ";
				  copy1.pop();
				}
				cout << endl;
				while (!copy2.empty()) {
				  cout << copy2.front() << " ";
				  copy2.pop();
				}
				cout << endl;
			}
		};
	}
}


static void test() {
	data_structures::stack_using_queue::Stack s;
	s.push(1);
	s.push(2);
	s.push(3);

	s.Display();

	assert(s.size() == 3);

	assert(s.top() == 3);

	s.pop();
	s.Display();

	assert(s.top() == 2);

	s.pop();
	
	assert(s.top() == 1);

	s.push(5);
	assert(s.top() == 5);
	s.Display();
	
	s.pop();
	assert(s.top() == 1);

	assert(s.size() == 1);
}



int main() {
	test();
	return 0;
}