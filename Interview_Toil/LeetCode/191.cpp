// https://leetcode.com/problems/number-of-1-bits/

// class Solution {
// public:
//     int hammingWeight(uint32_t n) {
//         int res = 0;
//         for(int i = 0; i < 32; i++) {
//             res += (n & 1);
//             n = n >> 1;
//         }
//         return res;
//     }
// };

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        return __builtin_popcount(n);
        // GNU classes
        // __builtin_popcount = int = count number of ones
        // __builtin_popcountl = long int
        // __builtin_popcountll = long long
        // __builtin_ctz() = count trailing zeroes  (l, ll)
        // __builtin_clz() = count leading zero
        // __builtin_parity() = returns 1 if number of ones is odd and 0 if no. of ones is even
    }
};