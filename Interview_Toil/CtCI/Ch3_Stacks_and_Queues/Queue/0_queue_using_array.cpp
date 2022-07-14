/**
 * @defgroup   Linear Queue using Array
 *
 * @brief      Linear Queue is a data structure used for holding a sequence of values, which can be added to the end line (enqueue), removed from head of line (dequeue) and displayed.
 * 
 * Values can be added by increasing the `rear` variable by 1 (which points to the end of the array), then assigning new value to `rear`'s element of the array.
 * Values can be removed by increasing the `front` variable by 1 (which points to the first of the array), so it cannot reached any more.
 * 
 */

#include <array>
#include <iostream>

using namespace std;

constexpr int max_size{10};		// max. size of queue

namespace data_structures {
	
	namespace queue_using_array {
		class Queue_Array {
		private:
			int front{-1};				// Index of head of the array
			int rear{-1};				// Index of tail of the array
			array<int, max_size> arr{};	// All stored data
		public:
			void enqueue(const int);	// Add element to the first of the queue
			int dequeue();				// Delete element to the back of the queue
			void display() const;		// show the data in queue
		};

		void Queue_Array::enqueue(const int element) {
			if (rear == arr.size() - 1) {
				cout << "Stack is full! \n";
			} else if(front == -1 && rear == -1) {
				cout << "Stack is full! \n";
			} else if(rear < arr.size()) {
				++rear;
				arr[rear] = element;
			}
		}


		int Queue_Array::dequeue() {
			int d{0};
			if(front == -1) {
				cout << "Stack is empty! \n";
				return 0;
			} else if(front == rear) {
				d = arr.at(front);
				front = rear = -1;
			} else {
				d = arr.at(front++);
			}

			return d;
		}


		void Queue_Array::display() const {
			if(front == -1) {
				cout << "Queue is full! \n";
			} else {
				for(auto r: arr) {
					cout << r << " ";
				}
				cout << endl;
			}
		}
 
	}		// namespace queue_using_array
}			// namespace data_structures



int main() {

	int op{0}, data{0};
	data_structures::queue_using_array::Queue_Array obj;

	cout << "1. enqueue(Insertion): \n";
	cout << "2. dequeue(Deletion): \n";
	cout << "3. Display: \n";
	cout << "4. Exit: \n";

	while(true) {

		cout << "Enter your choice: ";
		cin >> op;

		if(op == 1) {
			cout << "Enter data: ";
			cin >> data;
			obj.enqueue(data);
		} else if(op == 2) {
			data = obj.dequeue();
			cout << "Dequeued element is: " << data;
		} else if(op == 3) {
			obj.display();
		} else if(op == 4) {
			exit(0);
		} else {
			cout << "Wrong choice! \n";
		}
	}

	return 0;
}


