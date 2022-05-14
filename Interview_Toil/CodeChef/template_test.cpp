/**/
#include <bits/stdc++.h>

using namespace std;


void isOdd(int n) {
    if(n & 1) {
        cout << "Odd" << endl;
    } else {
        cout << "Not odd" << endl;
    }
}




int32_t main()
{
    // int x = 9;
    // string str = "10101";
    // cout << utility_binary_to_decimal(str) << endl;
    // cout << utility_decimal_to_binary(x) << endl;
    // vector<int> vec = {2,4,1,2,9,10,8,7,2};
    // vector<pair<int,char>> vect1={{1,'a'},{2,'b'},{3,'c'},{0,'z'},{10,'j'}};
    // sort(vect1.begin(), vect1.end(), comp_pair_second);
    // cout << vect1 << endl;
    // cout << vec << endl;
    // cout << PrimeFactors(24) << endl;
    // Sieve(10);
    // for (int i = 0; i < 10; ++i)
    // {
    //     cout << prime[i] << " ";
    // }
    // cout << endl;
    // cout << utility_nCr(5,3) << endl;
    // cout << utility_isPowerTwo(15) << endl;
    // cout << utility_isSubstring("abcdefabc","efa") << endl;
    // cout << utility_LSB(9) << endl;

    // vector<int> vect = {2,7,1,3,4,10,20,0};
    // cout << vect << endl;

    // // cout <<  << endl;

    // if(utility_is_sorted(vect)) {
    //     cout << "Yes" << endl;
    // } else {
    //     cout << "No" << endl;
    // }

    // utility_sort(vect);

    // cout << vect << endl;
    
    // if(utility_is_sorted(vect)) {
    //     cout << "Yes" << endl;
    // } else {
    //     cout << "No" << endl;
    // }

    // isOdd(4);

    int i = 0x12345678;
    
    cout << "i: " << i << endl;
    cout << "&i: " << &i << endl;
    cout << "*&i: " << *&i << endl;
    cout << "(char*)&i: " << (char*)&i << endl;
    cout << "*((char*)&i): " << *((char*)&i) << endl;

    if (*((char*)&i) == 0x12)
        cout << "Big endian" << endl;
    else    
        cout << "Little endian" << endl;


    return 0;
}