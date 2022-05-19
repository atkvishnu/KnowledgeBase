#include <iostream>
#include <stdlib.h>
#include <stdio.h> 

using namespace std; 

template <class T>
class Arithmetic {
private:
    T a;
    T b;
public:
    Arithmetic(T a, T b)        //This is the constructor which is used to initialize the above a and b in private!
    {   // The parameters(T a, T b) in the above constructor are different from the T a, T b that are mentioned in private, that's why we need a "this" operator and a arrow operator to access the a, b in the private class. If we write a = a, in place of: this-> a = a; then that private class won't be accessed. 
        this -> a = a;          // this -> a : means it's accessing the a from the private class (this->: is a pointer to the "current object" in C++)  
        this -> b = b;
    }
    T add() {
        T c;
        c = a+b;
        return c;
    }
    T sub(){
        T c;
        c = a-b;
        return c;
    }
};

int main()
{
    Arithmetic <int> ar (10,5);             //here "current object" is ar;  and 10 refers to "a" and 5 refers to "b"
    cout << ar.add() << endl;

    Arithmetic <float> ar1 (1.5,1.2);           //here "current object" is ar1; and 1.5 refers to "a" and 1.2 refers to "b"
    cout << ar1.add();
    return 0;
}