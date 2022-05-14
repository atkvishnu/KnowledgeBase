#include "list_element.h"
#include <stdlib.h>
#include <iostream>

#ifndef PROJECT_LINKEDLIST_H
#define PROJECT_LINKEDLIST_H

namespace kv {

    template <class T>
    class LinkedList {
        private:
            ListElement<T> *head_;                          // head of the list
        public:
            explicit LinkedList() : head_(nullptr) {}       // constructor
            ~LinkedList();                                  // destructor
            LinkedList(const LinkedList &) = delete;        // copy constructor
            LinkedList &operator=(const LinkedList &) = default;    // assignment operator

            int Size() const;   // returns the number of elements in the list

            void PushFront(T value);  // adds a new element to the front of the list

            bool Empty() const;    // returns true if the list is empty

            const T &ValueAt(int index) const;    // returns the value of the element at the given index

            void PrintDebug() const;    // Prints the list to the console

            const T PopFront();    // Removes the first element of the list and returns its value

            void PushBack(T value);    // Adds a new element to the end of the list

            const T PopBack();    // Removes the last element of the list and returns its value

            const T Front();    // Returns the value of the first element of the list

            const T Back();    // Returns the value of the last element of the list

            void Insert(int index, T value);    // Inserts value at index, so current item at that index is pointed to by new item at index

            void Erase(int index);    // Erases node at given index
            
            const T ValueNFromEnd(int n);    // Returns the value of the node at nth element from the end of the list

            void Reverse();    // Reverses the list

            void RemoveValue(T value);    // Removes first element in the list with the given value

            void RemoveAll(T value);    // Removes all elements in the list with the given value

            void RemoveAll();    // Removes all elements in the list
    };
}       // namespace kv

# endif //PROJECT_LINKEDLIST_H