// pair container helps us bind two values together as a single object

#include <iostream>
using namespace std;

int main(){

    // 1. pair container
    // pair<int, int> p(10, 20);

    // 2. pair container with custom type
    pair<int, char> p;
    p.first = 10;
    p.second = 'B';
    cout << p.first << ", " << p.second << endl;


    // 3. another way to create pair container
    pair<int, char> p2(p);
    cout << p2.first << ", " << p2.second << endl;


    // 4. we can also use a make_pair function to create pair container
    pair<int, string> p3 = make_pair(100, "Audi");
    cout << p3.first << ", " << p3.second << endl;

    // 5. Take input from user
    int a,b;
    cin >> a >> b;
    pair <int, int> p4 = make_pair(a,b);


    // Array of Pairs



    // Vector of Pairs

    pair<pair<int,int>, string> car;
    car.first.first = 10;
    car.first.second = 20;
    car.second = "Audi";
    cout << car.first.first << ", " << car.first.second << ", " << car.second << endl; 
}