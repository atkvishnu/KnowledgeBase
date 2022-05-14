// https://www.codechef.com/APRIL221D/problems/MINMAXEQ




#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// #include <ext/rope>
// typedef __gnu_cxx::rope<char> rope;
// #include <ext/pb_ds/tag_and_trait.hpp>

//-------------------------------------------------------------------------------------------
#define FAST() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define testcases int t; cin >> t; while (t--)
#define isize(x) (int((x).size()))
#define char unsigned char
#define endl "\n"
#define SS stringstream
#define FOR(k, a, b) for (auto k = (a); k < (b); ++k)

#define IMAX INT_MAX
#define IMIN INT_MIN
#define hashmap unordered_map
#define hashset unordered_set

using ll = long long;
using ld = long double;
#define precision(n) fixed << setprecision(n)

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll mod = (119 << 23) + 1; // 998244353 = 1+(7*17*2^23) -> FFT
const ld EPS = 1e-9;
#define INF 2147483647
#define inf (1 << 30)
// inf = 1073741824

ld PI = acos(-1.0);
ld Pi = 3.1415926535897932384626433832795;

//---------------------------Print's All DS(Operator Overloaded)-------------------------------
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v)
{
    os << '{';
    string sep;
    for (const T &x : v)
        os << sep << x, sep = ", ";
    return os << '}';
}
//------------------------------------------------------------------------------------------

//--------------------------------------ordered_set-----------------------------------------
// ordered_set (ascending) - SET
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
using ordered_set_descending = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;

// use less_equal for MULTISET : ordered_multiset (ascending)
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <class key, class value, class cmp = less<key>>
using ext_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

// DECLARATION: ordered_set A;
// INBUILT FNS: *A.find_by_order(<>), A.order_of_key(<>), *A.lower_bound(<>), *A.upper_bound(<>), A.erase(<>)
// order_of_key(val): returns the no. of values less than val
// find_by_order(k): returns the iterator to kth largest element.(0-based)
//----------------------------------------------------------------------------------------

//-----------------------------------Functions Start--------------------------------------
#define MAX(x, y) (x > y) ? x : y

#define MIN(x, y) (x < y) ? x : y

#define MID(h, l) (h + (l - h) / 2)

#define UNIQUE(store) store.resize(unique(store.begin(), store.end()) - store.begin())

#define toUpper(x) std::transform(x.begin(), x.end(), x.begin(), std::toupper);

#define toLower(x) std::transform(x.begin(), x.end(), x.begin(), std::tolower);

template <class T>
T Ceils(T x, T y){
    return x / y + ((x % y) != 0);
}

template <class T>
T Multiply(T a, T b) { return a * b; }

template <class T>
T Larger(T a, T b) { return (a > b ? a : b); }

template <class T>
T Smaller(T a, T b) { return (a < b ? a : b); }

template <class T>
T gcd(T a, T b) { return (b ? __gcd(a, b) : a); }

template <class T>
T lcm(T a, T b) { return (a / gcd(a, b)) * b; }

template <class T>
string converter(T n){
    SS x;
    x << n;
    return x.str();
}

template <typename T>
inline T binary_to_decimal(T n){
    ll decimal = 0, i = 0, rem;
    while (n != 0){
        rem = n % 10;
        n /= 10;
        decimal += rem * pow(2, i);
        ++i;
    }
    return decimal;
}

inline long FastMax(long x, long y) { return (((y - x) >> (32 - 1)) & (x ^ y)) ^ y; }

inline long FastMin(long x, long y) { return (((y - x) >> (32 - 1)) & (x ^ y)) ^ x; }

#define sort_elements(a) sort(a.begin(), a.end())
#define fill_elements(a, n) fill(a.begin(), a.end(), n)
#define find_elements(a, n) find(a.begin(), a.end(), n)
#define reverse_elements(a) reverse(a.begin(), a.end())
#define replace_elements(a, n) replace(a.begin(), a.end(), n)
#define maximum_element(a) max_element(a.begin(), a.end())
#define minimum_element(a) min_element(a.begin(), a.end())
#define next_permutation_elements(a) next_permutation(a.begin(), a.end())

inline bool isPrime(int n){
    if (n < 2)
        return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

inline bool isPowerTwo(int x) { return (x && !(x & (x - 1))); };

inline bool isSubstring(string s1, string s2){
    if (s1.find(s2) != string::npos)
        return true;
    return false;
}

template <typename T>
T nCr(T n, T r){
    if (r > n - r)
        r = n - r;
    int ans = 1, i;
    for (i = 1; i <= r; i++)
    {
        ans *= n - r + i;
        ans /= i;
    }
    return ans;
}

// char to string
string cts(char c){
    string s = "";
    s += c;
    return s;
}

template <typename T>
inline T mod_this_number(const T& x) { return x % MOD; }

/* COMPARATOR FUNCTION*/
/* COMPARATOR FUNCTION FOR SORTING PAIRS USING 2ND VALUE */
bool sortbySecond(const pair<int, int> &a, const pair<int, int> &b) { return (a.second < b.second); }
/* COMPARATOR FUNCTION FOR SORTING PAIRS USING 1ST VALUE */
bool sortbyFirst(const pair<int, int> &a, const pair<int, int> &b) { return (a.first < b.first); }
int sortbyEvenodd(int num1, int num2) { return (num1 % 2 == 0) and (num2 % 2 == 1); }
bool mySortFunc(int num1, int num2) { return num1 < num2; }

inline ll getFactorial(int num1){
    int factorial = 1;
    for (int i = 2; i <= num1; i++)
    {
        factorial = factorial * i;
    }
    return factorial;
}
//------------------------------------------------------------------------------------
//---------------------------------MATRIX---------------------------------------------
//@? matrix unitMatrix zeroMatrix

template <class T>
struct matrix{
    int rows, cols;
    vector<T> data;
    matrix(int _r, int _c) : rows(_r), cols(_c), data(_r * _c) {}
    T *operator[](int rowid) { return &data[cols * rowid]; }
    const T *operator[](int rowid) const { return &data[cols * rowid]; }
};

template <class T>
matrix<T> operator+=(matrix<T> &A, matrix<T> B){
    FOR(i, 0, isize(A.data))
    A.data[i] += B.data[i];
    return A;
}

template <class T>
matrix<T> operator-=(matrix<T> &A, matrix<T> B){
    FOR(i, 0, isize(A.data))
    A.data[i] -= B.data[i];
    return A;
}

template <class T>
matrix<T> operator+(matrix<T> A, matrix<T> B) { return A += B; }
template <class T>
matrix<T> operator-(matrix<T> A, matrix<T> B) { return A -= B; }

template <class T>
matrix<T> operator*(matrix<T> A, matrix<T> B){
    matrix<T> C(A.rows, B.cols);
    for (int i = 0; i < A.rows; i++)
        for (int k = 0; k < B.cols; k++){
            T Cval(0);
            for (int j = 0; j < A.cols; j++)
                Cval += A[i][j] * B[j][k];
            C[i][k] = Cval;
        }
    return C;
}

template <class T>
matrix<T> operator*(matrix<T> A, T x){
    matrix<T> C(A.rows, A.cols);
    for (int i = 0; i < A.rows; i++)
        for (int k = 0; k < A.cols; k++)
            C[i][k] = A[i][k] * x;
    return C;
}

//@? unitMatrix
template <class T>
matrix<T> unitMatrix(int size){
    matrix<T> result(size, size);
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            result[i][j] = (i == j) ? 1 : 0;
    return result;
}

//@? zeroMatrix
template <class T>
matrix<T> zeroMatrix(int size){
    matrix<T> result(size, size);
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            result[i][j] = 0;
    return result;
}

//@? powerMatrix
template <class T>
matrix<T> powerMatrix(matrix<T> x, int q){
    matrix<T> one = unitMatrix<T>(x.rows);
    while (true)
    {
        if (q & 1)
            one = one * x;
        q >>= 1;
        if (!q)
            return one;
        x = x * x;
    }
}

//------------------------------------------------------------- ------------------------------

// ---------------------------------BITWISE---------------------------------------------------
/* a=target variable, b=bit number to act upon 0-n */
#define BIT_SET(a, b) ((a) |= (1ULL << (b)))
#define BIT_CLEAR(a, b) ((a) &= ~(1ULL << (b)))
#define BIT_FLIP(a, b) ((a) ^= (1ULL << (b)))

// '!!' to make sure this returns 0 or 1
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
//-----------------------------------------------------------------------------------------

//--------------------------------Prime Generator------------------------------------------
// Sieve
const int N = 1e7 + 10;
int prime[20000010];
bool isprime[N];
int nprime;
template <typename T>
void Sieve(T a)
{
    nprime = 0;
    memset(isprime, true, sizeof(isprime));
    isprime[1] = false;
    for (int i = 2; i < N; i++)
    {
        if (isprime[i])
        {
            prime[nprime++] = i;
            for (int j = 2; i * j < N; j++)
                isprime[i * j] = false;
        }
    }
}

// Prime Factors
template <typename T>
inline T PrimeFactors(T n)
{
    ll cnt = 0, sum = 1;
    for (int i = 0; prime[i] * prime[i] <= n and i < nprime; i++)
    {
        cnt = 0;
        while (n % prime[i] == 0)
        {
            cnt++;
            n /= prime[i];
        }
        sum *= (cnt + 1);
    }
    if (n > 1)
        sum *= 2;
    return sum;
}
//-----------------------------------------------------------------------------------------

//-----------------------------------Geometry----------------------------------------------
template <typename T>
inline T PointDistanceHorVer(T x1, T y1, T x2, T y2){return abs(x1 - x2) + abs(y1 - y2);}
template <typename T>
inline T PointDistanceDiagonally(T x1, T y1, T x2, T y2){return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));}
template <typename T>
inline T PointDistanceMinimum(T x1, T y1, T x2, T y2){
    T tmp1 = abs(x1 - x2);
    T tmp2 = abs(y1 - y2);
    T tmp3 = abs(tmp1 - tmp2);
    T tmp4 = min(tmp1, tmp2);
    return tmp3 + tmp4;
}
template <typename T>
inline T PointDistance3D(T x1, T y1, T z1, T x2, T y2, T z2){return sqrt(square(x2 - x1) + square(y2 - y1) + square(z2 - z1));}
template <typename T>
inline T Cube(T a) { return a * a * a; }
template <typename T>
inline T RectengularPrism(T a, T b, T c){return a * b * c;}
template <typename T>
inline T Pyramid(T base, T height){return (1 / 3) * base * height;}
template <typename T>
inline T Ellipsoid(T r1, T r2, T r3){return (4 / 3) * PI * r1 * r2 * r3;}
template <typename T>
inline T IrregualarPrism(T base, T height){return base * height;}
template <typename T>
inline T Sphere(T radius){return (4 / 3) * PI * radius * radius * radius;}
template <typename T>
inline T CylinderB(T base, T height){return base * height;} // base and height
template <typename T>
inline T CylinderR(T radius, T height){return PI * radius * radius * height;} // radius and height
template <typename T>
inline T Cone(T radius, T base, T height){return (1 / 3) * PI * radius * radius * height;}
//---------------------------------------------------------------------

int32_t main()
{
    FAST();

    // testcases {
    //     ll n, k, j;
    //     cin >> n >> k;
    //     vector<ll> vect;
        
    //     for (ll i = 0; i < n; ++i)
    //     {
    //         cin >> j;
    //         vect.push_back(j);
    //     }
    //     if(k>=n) {
    //         cout << n << endl;
    //     } else {
    //         vector<pair<ll,ll>> m;
    //         ll max = 0;
    //         for(ll i  = 0; i < n-1; i++) {
    //             if(m[i]==m[i+1]) {
    //                 max++;
    //             } else {
    //                 m.push_back({max+1, 0});
    //                 max = 0;
    //             }
    //         }
    //         m.push_back({max+1,0});
    //         sort(m.begin(),m.end(),[&](pair<ll,ll>a,pair<ll,ll>b){return a.first>b.second;});
    //         ll sum = 0;
    //         for(ll i = 0; i < m.size(); i++) {
    //             m[i].first = ((m[i].first)*(m[i].first+1))/2;
    //         }
    //         // ll max = 0;
    //         while(k>0) {
    //             if(m[max].first!=1){
    //                 m[max].first=(m[max].first/2);
    //                 max++;
    //                 k--;
    //             }
    //             if(max==m.size()-1){
    //                 break;
    //             }
    //         }
    //         for(ll i = 0; i < m.size(); i++) {
    //             sum += m[i].first;
    //         }
    //         cout << sum << endl;
    //     }
        
    // }
    testcases {
        ll n, k;
        cin >> n >> k;
        vector<int> v(n);
        priority_queue<ll> q;
        for (int i = 0; i < n; ++i){
            cin >> v[i];
        } 
        ll count = 1;
        for(int i = 0; i < n-1; i++) {
            if(v[i] == v[i+1]) count++;
            else {
                if(count > 1) q.push(count);
                count = 1;
            }
        }
        if(count > 1) q.push(count);
        while(k-->0 && !q.empty() && q.top()>1) {
            ll a = q.top()/2, b = a;
            if(q.top()%2==0) b--;
            q.pop();
            if(a > 1) q.push(a);
            if(b > 1) q.push(b);
        }
        ll ans = n;
        while(!q.empty()) {
            ans += (q.top()*(q.top()-1))/2;
            q.pop();
        }
        cout << ans << endl;
    }

    return 0;
}
