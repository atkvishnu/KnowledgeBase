// https://www.codechef.com/LRNDSA01/problems/FLOW007


/*
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&&&&&@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@&&&@@@@@@&&&&&%&&&&&&&@@@@@@&&@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@&&&&&&@@&&&&&&&&&&&&&&&&&@@&&&&&@@@@@@@@@@@@@@
@@@@@@&&&&&&@@&&&&&&&&&@&&&%%%%%&&&&&&&&&&&&&&&@&&&&&&@@@@@@
@@@@@@&&&&&&&&%%%%%%%%%%%&% .*..,%@%%%%%&%%&&&&@&&&&&&@@@@@@
@@@@@@@&%%%%&&%%%%%%%%%% ....  . .%%%%%%%%%%%%%@&&&&&&@@@@@@
@@@@@@@&%%%%%&%%%%%%%%%. &&&&&&&&&/%%%%%%%%%%%%@%%%%&@@@@@@@
@&%%%%%%%%%%%%%##%&@&###.*,,,*,%&&./###%@@%%%%%%%%%%%&&&&&&@
@@%%%%%%%###########((#@#&,& &&%/&&,@&########%%%%%%%%%%%%@@
@@@%%%#########(((((((((((&&&&&#&& (((((((#######%%%%%%%%@@@
@@@@@######((((((((((((((((  &#% (((((((((((((######%%%@@@@@
@@@@@@#@#((((((((((((((..............,((((((((((####%&&@@@@@
@@%####(((%@&((((%@&%#... ............*%&@@#(((#@@######%%@@
@@@@@@%((((((&((//////%, /.........  %//((((((%((((###@@@@@@
@@@@@@@@@@@@(((//////&& // .......///&&///(((((((@@@@@@@@@@@
@@@@@@@@@@@(((////// &(### .......####&#///((((((&@@@@@@@@@@
@@@@@@@@@@@@@@@@@,,*&&*.**,...... ** **&& @@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@,//@ **** @(/% ,****@@/(,@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@,#@@ @@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
/*======================================================================*/
#define FAST() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define testcases int t; cin >> t; while (t--)
#define sz(x) (int)(x).size()
#define endl "\n"
#define SS stringstream
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define allelements(a) a.begin(), a.end()
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

const ll LINF = (1LL << 60); // 1e18
const ll INF = (1 << 30); // 1e9
const ll mod = (119 << 23) + 1; // 998244353->FFT
const ll MOD = 1e9 + 7;
const int MAX_N = 1e5 + 5;
const ld EPS = 1e-9;
ld PI = acos(-1.0);

template <typename A, typename B> ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>ostream &operator<<(ostream &os, const T_container &v){os << "$-> "; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << ' ';}
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
/*===========================================================================================*/
/*=========================================Functions=========================================*/
#define MAX(x, y) (x > y) ? x : y
#define MIN(x, y) (x < y) ? x : y
#define MID(h, l) (h + (l - h) / 2)

#define UNIQUE(store) store.resize(unique(store.begin(), store.end()) - store.begin())

#define toUpper(x) std::transform(x.begin(), x.end(), x.begin(), std::toupper);
#define toLower(x) std::transform(x.begin(), x.end(), x.begin(), std::tolower);

#define sort_elements(a) sort(a.begin(), a.end())
#define fill_elements(a, n) fill(a.begin(), a.end(), n)
#define find_elements(a, n) find(a.begin(), a.end(), n)
#define reverse_elements(a) reverse(a.begin(), a.end())
#define replace_elements(a, n) replace(a.begin(), a.end(), n)
#define maximum_element(a) max_element(a.begin(), a.end())
#define minimum_element(a) min_element(a.begin(), a.end())

#define next_permutation_elements(a) next_permutation(a.begin(), a.end())

template <class T> T Ceils(T x, T y){ return x / y + ((x % y) != 0); }
template <class T> T gcd(T a, T b) { return (b ? __gcd(a, b) : a); }
template <class T> T lcm(T a, T b) { return (a / gcd(a, b)) * b; }
template <class T> string converter(T n){ SS x; x << n; return x.str(); }
template <typename T> T nCr(T n, T r){ if (r > n - r)r = n - r;int ans = 1, i;for (i = 1; i <= r; i++){ans *= n - r + i;ans /= i;}return ans;}
template <typename T> inline T mod_this_number(const T& x) { return x % MOD; }

/* 2 - binary, 8 - octal, 10 - decimal and 16 - hexadecimal */
// inline ll binary_to_decimal_stoi(string s) { ll res = stoi(s, 0, 2); return res; }

/* decimal_to_binary, decimal_to_hexadecimal, decimal_to_octal */
// inline string decimal_to_binary_itoa(int n) { char res[100]; itoa(n, res, 2); string s = res; return s; }

inline bool isPrime(int n){if (n < 2)return false;for (int i = 2; i * i <= n; i++)if (n % i == 0)return false;return true;}
inline bool isPowerTwo(int x) { return (x && !(x & (x - 1))); };
inline bool isSubstring(string s1, string s2){ if (s1.find(s2) != string::npos) return true; return false; }
inline ll getFactorial(int num1){ int factorial = 1; for (int i = 2; i <= num1; i++){factorial = factorial * i;} return factorial; }

/* Comparator functions*/
bool comp_pair_first(const pair<int, int> &a, const pair<int, int> &b) { return (a.first < b.first); }
bool comp_pair_second(const pair<int, int> &a, const pair<int, int> &b) { return (a.second < b.second); }
bool comp_even_in_front_odds_in_back(int num1, int num2) { return (num1 % 2 == 0) and (num2 % 2 == 1); }
bool comp_asc(int num1, int num2) { return num1 < num2; }
bool comp_desc(int num1, int num2) { return num1 > num2; }
/*===========================================================================================*/
/*=================================Linked List===============================================*/
struct Node {
    int data; Node* next;
};
Node* newNode(int key){
    Node* temp = new Node;
    temp->data = key; temp->next = nullptr;
    return temp;
}
int linkedlistlen(Node * head){
    int res=0;
    while(head != nullptr){ res++;head=head->next; }
    return res;
}
/*=========================================================================================*/
/*=====================================Bitwise=============================================*/
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

#define COUNT_ONES(n) __builtin_popcountll(n)
#define COUNT_LEADING_ZEROES(n) __builtin_clzll(n)
#define COUNT_TRAILING_ZEROES(n) __builtin_ctzll(n)
#define PARITY(n) __builtin_parityll(x)
inline int last_bit(int n){return n & (-n);}
/*=========================================================================================*/
/*===================================Prime Generator=======================================*/
/* Sieve */
const int N = 1e7 + 10; int prime[20000010]; bool isprime[N]; int nprime;
template <typename T> void Sieve(T a){ nprime = 0; memset(isprime, true, sizeof(isprime)); isprime[1] = false; for (int i = 2; i < N; i++){ if (isprime[i]){ prime[nprime++] = i;for (int j = 2; i * j < N; j++)isprime[i * j] = false;}}}

/* Prime Factors */
template <typename T> inline vector<int> PrimeFactors(T n){ vi res; int c = 2; while(n>1){ if(n%c==0) { res.push_back(c); n/=c; } else {c++; } } return res; }

/* 
 * atof, atoi, atol, atoll
 * strtod, strtof, strtol*(base), strtoll*(base), strtold, strtoul*(base), strtoull*(base)
 * itoa*(base)
 * stoi*(0), stod*(0), stol*(10), stold*(0), stoll, stoul*(10), stoull*(10)
 */


int32_t main()
{
    FAST();
    testcases {
    	int n;
    	cin >> n;
    	string str = to_string(n);
    	reverse(str.begin(), str.end());
    	cout << stoi(str) << endl;
    }
    return 0;
}
