// Indian money change problem.
// You are given a array of types of Indian currency, you are also given a target amount of money, you have to find a way to achieve the target amount by minimum number of Indian currency

#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {        // compare function helps us pick the number which is just lower or equal to the target amount  
    return a<=b;
}

int main() {

    // Indian Money Change
    int coins[] = {1,2,5,10,20,50,100,200,500,2000};
    int n = sizeof(coins)/sizeof(int);
    int money = 168;

    // first we find the highest value i.e., less than the `money`
    // 168-100
    // 68-50
    // 18-10
    // .....

    // One way is we use linear search, OR, binary_search(we will use lower_bound with our own comparator if needed)
    
    while(money > 0){
        int lb = lower_bound(coins, coins+n, money, compare) - coins - 1;
        int m = coins[lb];
        cout << m << ", ";
        money = money - m;    
    }
    cout << endl;


}