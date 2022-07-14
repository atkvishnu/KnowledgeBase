#include <iostream>
#include <thread>
using namespace std;

void thread_function() {
    for(int i = 0; i < 10; i++) {
        cout << "thread function executing!" << endl;
    }
}

int main() {
    thread threadObj(thread_function);
    for(int i = 0; i < 10; i++) {
        cout << "Display from MainThread!" << endl;
    }
    threadObj.join();
    cout << "Exit of main function." << endl;
    return 0;
}
