// https://leetcode.com/problems/happy-number/

class Solution
{

public:
    bool isHappy(int n)
    { // type int involves 32 bits, we can limit the counts to 31
        int count = 0;
        while (n != 1)
        {
            int sum = 0;
            while (n != 0)
            {
                // int num = n%10;
                // sum += num*num;
                sum += (n % 10) * (n % 10);
                n /= 10;
                count++;
            }
            n = sum;
            if (count > 31)
                return false;
        }
        return true;
    }
};