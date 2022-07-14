// https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/

class Solution
{
public:
    int countOdds(int low, int high)
    {
        // int count = 0;
        // for(int i = low; i <= high; i++) {
        //     if(i&1) count++;
        // }
        // return count;
        // xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
        // return ( !(low&1) && !(high&1) ) ? (high-low)/2 : ((high-low)/2 + 1);
        // if low and high both are even number then there is only (high-low)/2 odd numbers between them.
        // if one of the number of high and low is odd then there is only (high-low)/2 + 1 odd numbers between them.
        // xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

        int count = 0;
        if (low % 2 == 0 && high % 2 == 0)
        {
            count = (high - low) / 2;
        }
        else if (low % 2 != 0 && high % 2 != 0)
            count = (high - low) / 2 + 1;
        else
        {
            count = ((high - low) + 1) / 2;
        }
        return count;
    }
};