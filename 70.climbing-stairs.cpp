/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1)return 1;
        if(n == 2)return 2;
        int a=1,b=2,res = 0;
        for(int i=3;i<=n;i++)
        {
            res = a+b;
            a = b;
            b = res;
        }
        return res;
    }
};
// @lc code=end

