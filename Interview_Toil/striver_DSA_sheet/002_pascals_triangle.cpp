/**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
/*======================================================================*/
#define FAST() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin.exceptions(cin.failbit);
#define testcases int t; cin >> t; while (t--)
#define sz(x) (int)(x).size()
#define endl "\n"
#define SS stringstream
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(a) a.begin(), a.end()
#define precision(n) fixed << setprecision(n)

#define hashmap unordered_map
#define hashset unordered_set

using ll = long long;
using ull = unsigned long long;
using li = __int128;
using uli = unsigned __int128;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

const ll LL_INF = (1LL << 60); // 1e18
const ll INF = (1 << 30); // 1e9
const ll MOD2 = 998244353; // FFT
const ll MOD = 1e9 + 7;
const int MAX_N = 1e5 + 5;
const ld EPS = 1e-8;
ld PI = acos(-1.0);

template <typename A, typename B> ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>ostream &operator<<(ostream &os, const T_container &v){os << "$ "; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << ' ';}
/*==========================================================================================*/
/*======================================ordered_set=========================================*/
/* ordered_set (ascending) - SET */
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

/* use less_equal for MULTISET : ordered_multiset (ascending) */
template <typename T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <class key, class value, class cmp = less<key>> using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
/* ordered_map<int,int> my_map;*/

/* DECLARATION: ordered_set A; FNS: *A.lower_bound(<>), *A.upper_bound(<>), A.erase(<>)
   A.order_of_key(val): returns the no. of values less than val
   *A.find_by_order(k): returns the iterator to kth largest element.(0-based) */
/*========================================================================================*/
/*================================Utility Functions=======================================*/
#define utility_MAX(x, y) (x > y) ? x : y
#define utility_MIN(x, y) (x < y) ? x : y
#define utility_MID(h, l) (h + (l - h) / 2)

#define utility_UNIQUE(store) store.resize(unique(store.begin(), store.end()) - store.begin())

#define utility_toUpper(x) transform(x.begin(), x.end(), x.begin(), ::toupper);
#define utility_toLower(x) transform(x.begin(), x.end(), x.begin(), ::tolower);

#define utility_sort(a) sort(a.begin(), a.end())
#define utility_is_sorted(a) is_sorted(a.begin(), a.end())
#define utility_fill_elements(a, n) fill(a.begin(), a.end(), n)
#define utility_find_elements(a, n) find(a.begin(), a.end(), n)
#define utility_reverse_elements(a) reverse(a.begin(), a.end())
#define utility_replace_elements(a, n) replace(a.begin(), a.end(), n)
#define utility_max_element(a) max_element(a.begin(), a.end())
#define utility_min_element(a) min_element(a.begin(), a.end())

#define utility_next_permutation(a) next_permutation(a.begin(), a.end())

template <class T> T utility_Floor(T x){ return floor(x); }
template <class T> T utility_Ceil(T x){ return ceil(x); }
template <class T> T utility_gcd(T a, T b) { return (b ? __gcd(a, b) : a); }
template <class T> T utility_lcm(T a, T b) { return (a / gcd(a, b)) * b; }
template <class T> string converter(T n){ SS x; x << n; return x.str(); }
template <typename T> T utility_nCr(T n, T r){ if (r > n - r)r = n - r;int ans = 1, i;for (i = 1; i <= r; i++){ans *= n - r + i;ans /= i;}return ans;}
template <typename T> inline T utility_mod_this_number(const T& x) { return x % MOD; }
template <class T, class K> pair<T,K> mp(T a, K b) { return make_pair(a,b); }

/* 2 - binary, 8 - octal, 10 - decimal and 16 - hexadecimal */
// long long utility_binary_to_decimal(string s) { long long res = stoi(s, 0, 2); return res; }
// string utility_decimal_to_binary(int n) { char res[100]; itoa(n, res, 2); string s = res; return s; }

inline bool utility_isPrime(int n){if (n < 2)return false;for (int i = 2; i * i <= n; i++)if (n % i == 0)return false;return true;}
inline bool utility_isPowerTwo(int x) { return (x && !(x & (x - 1))); };
inline bool utility_isSubstring(string s1, string s2){ if (s1.find(s2) != string::npos) return true; return false; }
inline long long utility_getFactorial(int n){ const unsigned int M = 1000000007; unsigned long long f = 1; for(int i = 1; i <= n; i++) { f = (f*i) % M; } return f; }

/* Comparator functions*/
bool comp_pair_first(const pair<int, int> &a, const pair<int, int> &b) { return (a.first < b.first); }
bool comp_pair_second(const pair<int, int> &a, const pair<int, int> &b) { return (a.second < b.second); }
bool comp_even_in_front_odds_in_back(int num1, int num2) { return (num1 % 2 == 0) and (num2 % 2 == 1); }
bool comp_asc(int num1, int num2) { return num1 < num2; }
bool comp_desc(int num1, int num2) { return num1 > num2; }

/*========================================================================================*/
/*=====================================Bitwise============================================*/
/* a=target variable, b=bit number to act upon 0-n */
#define BIT_SET(a, b) ((a) |= (1ULL << (b)))
#define BIT_CLEAR(a, b) ((a) &= ~(1ULL << (b)))
#define BIT_FLIP(a, b) ((a) ^= (1ULL << (b)))

/* '!!' to make sure this returns 0 or 1 */
#define BIT_CHECK(a, b) (!!((a) & (1ULL << (b))))

#define BITMASK_SET(x, mask) ((x) |= (mask))
#define BITMASK_CLEAR(x, mask) ((x) &= (~(mask)))
#define BITMASK_FLIP(x, mask) ((x) ^= (mask))
#define BITMASK_CHECK_ALL(x, mask) (!(~(x) & (mask)))
#define BITMASK_CHECK_ANY(x, mask) ((x) & (mask))

#define utility_count_ones(n) __builtin_popcountll(n)
#define utility_count_leading_zeroes(n) __builtin_clzll(n)
#define utility_count_trailing_zeroes(n) __builtin_ctzll(n)
#define utility_parity(n) __builtin_parityll(x)
inline int utility_LSB(int n){return n & 1;}
/*========================================================================================*/
/*===================================Prime Generator======================================*/
/* Sieve */
const int N = 1e7 + 10; int prime[20000010]; bool isprime[N]; int nprime;
template <typename T> void Sieve(T a){ nprime = 0; memset(isprime, true, sizeof(isprime)); isprime[1] = false; for (int i = 2; i < N; i++){ if (isprime[i]){ prime[nprime++] = i;for (int j = 2; i * j < N; j++)isprime[i * j] = false;}}}

/* Prime Factors */
template <typename T> inline vector<int> PrimeFactors(T n){ vi res; int c = 2; while(n>1){ if(n%c==0) { res.push_back(c); n/=c; } else {c++; } } return res; }
/*========================================================================================*/
/* 
 * atof, atoi, atol, atoll
 * strtod, strtof, strtol*(base), strtoll*(base), strtold, strtoul*(base), strtoull*(base)
 * stoi*(0), stod*(0), stol*(10), stold*(0), stoll, stoul*(10), stoull*(10)
 * itoa*(base), to_string(<int>)
 */
/*========================================================================================*/

// Method 1 [O(n^2)]
void f1(long n) {
   vector<vector<int>> vect(n);
   // cout << vect << endl;
   for (int i = 0; i < n; ++i) {    // n
      vect[i].resize(i+1);          // n
      vect[i][0] = vect[i][i] = 1;  // n
      for (int j = 1; j < i; ++j) { // n*(i-1) ~= n^2
         vect[i][j] = vect[i-1][j-1] + vect[i-1][j];
      }
   }  // f(n) = 2n^2 + 3n

   // cout << vect << endl;
   for (int i = 0; i < n; ++i) {   // n
       cout << vect[i] << endl;
   }

   cout << endl;
}


// Method 2 [O(n^2)]
void f2(long n) {   
    // for i := 0 to n
    //   for j = 0 to n – i – 2, print black space
    //   for j := 0 to i, perform nCr(i, j)
   for(int i = 0; i < n; i++) {              // n
      for(int j = 0; j < (n-i-1); j++) {     // n*(n-1) ~= n^2 - n
         cout << setw(3) << " "; //printing space to show triangular form
      }
      for(int j = 0; j < (i+1); j++) {       // n*(n+1) = n^2 + n
         cout << setw(3) << utility_nCr(i, j) << setw(3) << " ";
      }
      cout << endl;
   }  // f(n) = 2n^2 + n
}

// Method 3 (O(n^2))
void f3(long n) {
   for(int i = 0; i < n; i++) {              // n
      for(int j = 0; j < (i+1); j++) {       // n*(i+1) ~= n^2 + n
         cout << utility_nCr(i, j) << " ";
      }
      cout << endl;
   }
}

// Method 4 (O(n^2))
void f4(long n) {
   const int maxn = 100;
   int pascals[maxn+1][maxn+1];
   pascals[0][0] = 1;
   for (int n = 1; n <= maxn; ++n) {
      pascals[n][0] = pascals[n][n] = 1;
      for (int k = 1; k < n; ++k) {
         pascals[n][k] = pascals[n-1][k-1] + pascals[n-1][k];
      }
   }
   
   for (int i = 0; i < n; ++i) {
      // for (int j = 0; j < (n-i); ++j) {
      //    cout << setw(3) << " ";
      // }

      for (int j = 0; j < n; ++j) {
         cout << pascals[i][j] << setw(5);
      }
      cout << endl;
   }
}

int32_t main()
{
    FAST();
    // Pascal triangle is an array of binomial coefficients.
    int n;
    cin >> n;
    
    cout << "Method 1: " << endl << endl;
    f1(n);

    //----------------------------------------
    cout << "Method 2: " << endl << endl;
    f2(n);

    //----------------------------------------
    cout << endl << "Method 3: " << endl << endl;
    f3(n);

    //----------------------------------------
    cout << endl << "Method 4: " << endl << endl;
    f4(n);

    return 0;
}
