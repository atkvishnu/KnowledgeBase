// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

/*
// xxxxxxxxxxxxxxxxxxxxxxxxxx TLE xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int sz = prices.size();
        vector<int> prof;
        // for(i,k; i < sz, k < sz-1; i++, k++) {
        //     int diff = prices[i]-prices[k];
        //     if(diff>=0) prof.push_back(diff);
        // }
        for(int i = 0; i < sz; i++) {
            for(int j = i+1; j < sz; j++) {
                int diff = prices[j] - prices[i];
                if(diff>=0) prof.push_back(diff);
            }
        }
        sort(prof.begin(),prof.end());
        if(prof.empty()) {
            return 0;
        }
        return prof.back();
    }
};
// xxxxxxxxxxxxxxxxxxxxxxxxxxx TLE xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
*/
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int buy = 1e4;
        int res = 0;
        for (int price : prices)
        {
            buy = min(buy, price);
            res = max(res, price - buy);
        }
        return res;
    }
};
