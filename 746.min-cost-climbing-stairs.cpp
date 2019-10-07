/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n == 1)return 0;
        if(n == 2)return min(cost[0], cost[1]);
        int minA=0,minB=0,res=0;
        minA = 0;
        minB = min(cost[0], cost[1]);
        for(int i=3;i<=cost.size();i++)
        {
            res = min(minB+cost[i-1],minA + cost[i-2]);
            minA = minB;
            minB = res;
            //minCost[i] = min(minCost[i-1]+cost[i-1],minCost[i-2] + cost[i-2]);
        }
        return res;
    }
};
// @lc code=end

