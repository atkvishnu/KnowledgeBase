// https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/

class Solution
{
public:
    int subtractProductAndSum(int n)
    {
        int prod = 1;
        int sum = 0;
        for (int t = n; t; t /= 10)
        {
            prod *= t % 10;
            sum += t % 10;
        }
        return prod - sum;
    }
};