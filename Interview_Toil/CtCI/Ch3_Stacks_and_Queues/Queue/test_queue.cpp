#include <iostream>
#include <cassert>

#include "./queue.h"

using namespace std;

int main() {
	Queue<string> q;
	cout << "Test construct: \n";
	q.display();

	cout << "Test isEmptyQueue: \n";
	if(q.isEmptyQueue()) {
		cout << "PASS\n";
	} else {
		cout << "FAIL\n";
	}

	cout << "Test enQueue: \n";
	cout << "After Yayson, Jason, Baeson, Russel go into the queue: \n";
	q.enQueue("Yayson");
	q.enQueue("Jason");
	q.enQueue("Baeson");
	q.enQueue("Russell");
	q.display();

	cout << "Test front: \n";
	string val = q.front();
	if (val == "Yayson")
        cout << "PASS\n";
    else
        cout << "FAIL\n";


    cout << "Test deQueue: \n";
    q.display();
    q.deQueue();
    q.deQueue();
    q.deQueue();

    cout << "After Yayson, Jason, Baeson left the queue: \n";
    q.display();

    return 0;
}