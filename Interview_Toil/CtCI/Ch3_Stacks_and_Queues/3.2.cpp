/**
 * @defgroup   3.2 Stack Min
 *
 * @brief      How would you design a stack which in addition to push and pop, 
 * 			   has a function min which returns the minimum element?
 * 			   Push, pop, and min should all operate in O(1) time.
 *
 * @author     Vishnu
 * @date       2022
 */

#include <iostream>
#include <stack>
#include<climits>

using namespace std;

	class StackMin {
	private:
		// s1 for push and pop and s2 for min.
		stack<int> s1, s2;
	public:

		void push(int data) {
			s1.push(data);
			if(min() >= data) {
				s2.push(data);
			}
		}
		void pop() {
			if(min() == s1.top()) {
				s2.pop();
			}
			s1.pop();
		}
		int min() {
			if(s2.empty()) {
				return INT_MAX;
			}
			return s2.top();
		}

		bool empty() {
			return s1.empty();
		}

		int top() {
			return s1.top();
		}

	};


int main() {

	StackMin stk;

	int stackTop;
	int arr[] = {6, 3, 5, 2, 2, 9, 2, 8, 1, 1};
	for(int i=0; i<10; i++){
		stk.push(arr[i]);
		cout<<"push in the element "<<arr[i]<<", the current min is "<<stk.min()<<'\n';


	}for(int i=0; i<10; i++){
        stackTop = stk.top();
		stk.pop();
		cout<<"pop out the element "<<stackTop<<" from the stack and the current min is "<<stk.min()<<'\n';
	}





}