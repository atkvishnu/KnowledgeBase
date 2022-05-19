#include <assert.h>
#include <iostream>
#include <vector>
#include "kvVector.h"
#include "kvVector.cpp"
#include "kvVector_test.h"
#include "kvVector_test.cpp"

void StandardExperiment();


int main(int argc, char *argv[]) {

    kv::kvVectorTest tester;
    // tester.RunTests();


    StandardLibraryExperiment();
    
    return EXIT_SUCCESS;
}

void StandardLibraryExperiment() {
    std::cout << "STL vector experiment" << std::endl;
    std::vector<int> myv{12,23,5,3};

    std::cout << "myv.size() = " << myv.size() << std::endl;
    std::cout << "myv.capacity() = " << myv.capacity() << std::endl;
    // std::cout << "myv.max_size() = " << myv.max_size() << std::endl;

    std::cout << "Adding a few items" << std::endl;

    myv.push_back(1);
    myv.push_back(2);
    myv.push_back(3);
    myv.push_back(4);
    myv.push_back(5);

    std::cout << "Size: " << myv.size() << std::endl;
    std::cout << "Capacity: " << myv.capacity() << std::endl;
    std::cout << "Popping 1 item" << std::endl;

    myv.pop_back();

    std::cout << "Size: " << myv.size() << std::endl;
    std::cout << "Capacity: " << myv.capacity() << std::endl;
    std::cout << "Items: " << std::endl;
    for(int value: myv) {
        std::cout << value << std::endl;
    }

    std::cout << "Adding a few more items" << std::endl;
    myv.insert(myv.begin() + 4, 99);

    std::cout << "Items: " << std::endl;
    for(int value: myv) {
        std::cout << value << std::endl;
    }

    myv.reserve(120);

    for(int i = 0; i<75; i++) {
        myv.push_back(i);
    }

    std::cout << "Size: " << myv.size() << std::endl;
    std::cout << "Capacity: " << myv.capacity() << std::endl;

    std::cout << "collapsing" << std::endl;
    myv.shrink_to_fit();    // this is the only way to shrink the vector
    std::cout << "Capacity: " << myv.capacity() << std::endl;

    std::cout << "Items: " << std::endl;
    for(unsigned long j=0; j<myv.size(); ++j) {
        std::cout << j << ": " << myv.at(j) << std::endl;
    }

    std::cout << "Erasing items from indices from 4-11: " << std::endl;
    myv.erase(myv.begin() + 4, myv.begin() + 12);

    std::cout << "Items: " << std::endl;
    for(unsigned long k = 0; k < myv.size(); ++k) {
        std::cout << k << ": " << myv.at(k) << std::endl;
    }


}