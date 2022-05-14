// Template - freedom from underlying data type
// Iterator - freedom from containers (list, vector, etc. (sequential containers))
// Comparator - freedom from different type of operations operating on the data.

#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

class Book{
public:
    string name;
    int price;
    Book(){}
    Book(string name, int price){
        this->name = name;
        this->price = price;
    }
};

class BookCompare{
    public:
        bool operator()(Book A, Book B){
            if(A.name==B.name){
                return true;
            }
            return false;
        }
};



// Templates - free from data types
template<typename T>
int search(T arr[], int n, T key){
    for(int p=0;p<n;p++)
    {
        if(arr[p]==key){
            return p;
        }
    }
    return n;   // return n if element is not found
}


// Templates + Iterators
template<class ForwardIterator, class T>
ForwardIterator search2(ForwardIterator start, ForwardIterator end, T key){
    while(start != end){
        if(*start==key){
            return start;
        }
        start++;
    }
    return end;
}



// Template + Iterator + Comparator
template<class ForwardIterator, class T, class Compare>
ForwardIterator search3(ForwardIterator start, ForwardIterator end, T key, Compare cmp)
{
    while(start!=end){
        if(cmp(*start, key)){
            return start;
        }
        start++;
    }
    return end;
}


int main(){
    
    // search()
    //--------------------------------------------------------------------------------------
    // int a[] = {1,2,3,4,10,12};
    // int key = 13;
    // int n = sizeof(a)/sizeof(int);
    // auto it = search(a, n, key);
    // if(it){
    //     cout << key << " is present!" << endl;
    // } else {
    //     cout << key << " is NOT present!";
    // }

    
    // search2()
    //--------------------------------------------------------------------------------------
    // list<int> l1;
    // l1.push_back(1);
    // l1.push_back(2);
    // l1.push_back(5);
    // l1.push_back(3);

    // auto itr = search2(l1.begin(), l1.end(), 2);
    
    // if(itr == l1.end()){
    //     cout << "Element not present" << endl;
    // } else {
    //     cout << *itr << " found!"<< endl;
    // }
    
    
    // search3()
    //--------------------------------------------------------------------------------------
    Book b1("C++", 100);            // old edition book
    Book b2("python", 120);
    Book b3("java", 130);

    list<Book> l;

    l.push_back(b1);
    l.push_back(b2);
    l.push_back(b3);

    // Book booktofind("C++", 110);      // new edition book
    Book booktofind("Cython", 190);

    BookCompare cmp;
    auto it = search3(l.begin(), l.end(), booktofind,  cmp);         // in place of auto we can have list<Book>::iterator
    if(it != l.end()){
        cout << "Book found in the library" << endl;
    } else {
        cout << "Not found"<< endl;
    }

    return 0;
}