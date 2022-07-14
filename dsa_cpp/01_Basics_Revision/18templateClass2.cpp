///THIS IS SAME AS 18templateClass.cpp, only difference is that we are implementing the functions outside the class

#include <iostream>
#include <stdlib.h>
#include <stdio.h> 

using namespace std; 

template <class T>
class Arithmetic 
{
private:
    T a;
    T b;
public:
    Arithmetic(T a, T b);       // If we are implementing the function outside the class, then we should have the declaration of those fns. inside the class 
    //These are Declaration only, initialization is done later after the class is over
    T add();
    T sub();
};

template <class T>
Arithmetic<T>::Arithmetic(T a, T b)        //This is the constructor which is used to initialize the above a and b in private!
{   // The parameters(T a, T b) in the above constructor are different from the T a, T b that are mentioned in private, that's why we need a "this" operator and a arrow operator to access the a, b in the private class. If we write a = a, in place of: this-> a = a; then that private class won't be accessed. 
    this -> a = a;          // this -> a : means it's accessing the a from the private class (this->: is a pointer to the "current object" in C++)  
    this -> b = b;
}

template <class T>
T Arithmetic<T>::add() {
    T c;
    c = a+b;
    return c;
}

template <class T>
T Arithmetic<T>::sub(){
    T c;
    c = a-b;
    return c;
}


int main()
{
    Arithmetic <int> ar (10,5);             //here "current object" is ar;  and 10 refers to "a" and 5 refers to "b"
    cout << ar.add() << endl;

    Arithmetic <float> ar1 (1.5,1.2);           //here "current object" is ar1; and 1.5 refers to "a" and 1.2 refers to "b"
    cout << ar1.add() << endl;

    Arithmetic <double> ar2 (1.5233324234,1.2123124235);           //here "current object" is ar1; and 1.5 refers to "a" and 1.2 refers to "b"
    cout << ar2.add()<<endl;

    Arithmetic <char> ar3 ('A','B');         
    cout << (int)ar3.sub()<<endl;           //int('A') - int('B') = -1

    Arithmetic <char> ar4 ('B','A');           
    cout << (int)ar4.sub();


    return 0;
}