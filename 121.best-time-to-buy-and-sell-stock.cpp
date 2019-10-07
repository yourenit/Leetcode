/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 1)return 0;
       int res = 0;
       int minPrice = INT_MAX;
       for(int i=0;i<prices.size();i++)
       {
           minPrice = min(minPrice, prices[i]);
           res= max(res, prices[i] - minPrice);
       } 
       return res;
    }
};
// @lc code=end

