#include <cstdlib>
#include <iostream>
#include <forward_list>
#include <list>

#include "linked_list.h"
#include "linked_list.cpp"

void stdlib_forward_list_experiment();
void stdlib_doubly_linked_list_experiment();


int main(int argc, char *argv[]) {
    kv::LinkedList<int> ilist{};
    ilist.PushFront(5);
    ilist.PushFront(2);

    std::cout << "Size of int list is: " << ilist.Size() << std::endl;

    kv::LinkedList<std::string> strlist{};
    strlist.PushFront("Hello 1");
    strlist.PushFront("Hello 2");
    strlist.PushFront("Hello 3");

    std::cout << "Size of string list is: " << strlist.Size() << std::endl;

    std::cout << "STANDARD DIRECTORY LIBRARY FORWARD LIST EXPERIMENT" << std::endl;
    std::cout << "==================================================" << std::endl;

    stdlib_forward_list_experiment();
    
    std::cout << "STANDARD DIRECTORY LIBRARY DOUBLY LINKED LIST EXPERIMENT" << std::endl;
    std::cout << "========================================================" << std::endl;

    stdlib_doubly_linked_list_experiment();

    return EXIT_SUCCESS;
}


void stdlib_forward_list_experiment() {
    std::forward_list<int> f1 {100,200,300};

    std::cout << "Items: " << std::endl;
    for (int &item : f1) {
        std::cout << item << std::endl;
    }

    std::cout << "First item: " << f1.front() << std::endl;

    std::cout << "Getting items using iterators: ";
    for (auto it = f1.begin(); it != f1.end(); ++it) {
        std::cout << *it << "->";
    }
    std::cout << std::endl;


    std::cout << "Adding to front: " << std::endl;
    f1.push_front(8);
    for(auto it = f1.begin(); it != f1.end(); ++it) {
        std::cout << *it << "->";
    }
    std::cout << std::endl;

    std::cout << "Popping front 2x: " << std::endl;
    fl.pop_front();
    fl.pop_front();
    for (auto it = fl.begin(); it != fl.end(); ++it) {
        std::cout << *it << " -> ";
    }
    std::cout << std::endl;
}

void stdlib_doubly_linked_list_experiment() {

    std::cout << "----------------------------" << std::endl;
    std::cout << "Now messing with standard library's list (doubly-linked list)" << std::endl;

    std::list<int> dl {100, 200, 300};

    std::cout << "Items:" << std::endl;
    for (int &item : dl) {
        std::cout << item << std::endl;
    }

    std::cout << "First item: " << dl.front() << std::endl;

    std::cout << "Getting items using iterator: ";
    for (auto it = dl.begin(); it != dl.end(); ++it) {
        std::cout << *it << " -> ";
    }
    std::cout << std::endl;

    std::cout << "Adding to front and back: " << std::endl;
    dl.push_front(5);
    dl.push_back(400);
    for (auto it = dl.begin(); it != dl.end(); ++it) {
        std::cout << *it << " -> ";
    }
    std::cout << std::endl;

    std::cout << "Adding to back again: " << std::endl;
    dl.push_back(500);
    for (auto it = dl.begin(); it != dl.end(); ++it) {
        std::cout << *it << " -> ";
    }
    std::cout << std::endl;

    std::cout << "Popping front 2x: " << std::endl;
    dl.pop_front();
    dl.pop_front();
    for (auto it = dl.begin(); it != dl.end(); ++it) {
        std::cout << *it << " -> ";
    }
    std::cout << std::endl;

    std::cout << "Popping back 2x: " << std::endl;
    dl.pop_back();
    dl.pop_back();
    for (auto it = dl.begin(); it != dl.end(); ++it) {
        std::cout << *it << " -> ";
    }
    std::cout << std::endl;

    std::cout << "----------------------------" << std::endl;
    std::cout << "Now messing with standard library's list (doubly-linked list)" << std::endl;
}