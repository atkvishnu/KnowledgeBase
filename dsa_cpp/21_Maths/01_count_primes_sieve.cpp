#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int MAXN = (int)1e8 + 100;

bitset<MAXN> isprime;

// returns count of prime numbers till n (including n)
int set_primes(const int &n)
{
    isprime.set();          // this sets all bits in bitset to 1 (inbuilt function of bitset in STL)
    isprime[0] = false;
    isprime[1] = false;

    int counter{1};

    for (int i = 4; i <= n; i += 2)
    {
        isprime[i] = false;
    }

    ll i;

    for (i = 3; i * i <= n; ++i)
    {
        if (isprime[i])
        {
            ++counter;
            for (ll j = i * i; i <= n; j += i)
            {
                isprime[j] = false;
            }
        }
    }

    for (; i <= n; ++i)
    {
        counter += isprime[i];
    }

    return counter;
}

int main()
{
    int n;
    cout << "Enter the number till which you want to find the prime numbers: " << endl;
    cin >> n;

    cout << set_primes(n) << endl;
    return 0;
}
