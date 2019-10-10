/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */
//第一种解法：递归，对*的处理用递归处理
class Solution1
{
public:
    bool isMatch(string s, string p)
    {
        //如果p为空串，则返回true;
        if (p.empty())
            return s.empty();
        //如果p和s的长度都为1，且相等或者p[0]为'.'，则返回true;
        if (p.size() == 1)
            return (s.size() == 1) && (p[0] == s[0] || p[0] == '.');
        //如果第二个字符不为'*'，
        if (p[1] != '*')
        {
            //若s串为空，则返回false;
            if (s.empty())
                return false;
            //否则，匹配第二个字符后面的字符串
            return (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
        }
        //如果第二个字符为'*'，如果s串不为空，且第一个字符正确匹配
        while (!s.empty() && (s[0] == p[0] || p[0] == '.'))
        {
            //首先假设*前面的字符出现0次，判断是否匹配，如果匹配，返回true;
            if (isMatch(s, p.substr(2)))
                return true;
            //如果不匹配，则说明*前面的字符出现至少1次，则去掉已经成功匹配的字符（s的首字符）
            s = s.substr(1);
        }
        //如果第一个字符不匹配，则说明*及前面的字符为0次，则只匹配*后面的字符串与s串
        return isMatch(s, p.substr(2));
    }
};
#include <vector>
using namespace std;
//第二种解法：动态规划
//其中 dp[i][j] 表示 s[0,i) 和 p[0,j) 是否 match
//1.  P[i][j] = P[i - 1][j - 1], if p[j - 1] != '*' && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
//2.  P[i][j] = P[i][j - 2], if p[j - 1] == '*' and the pattern repeats for 0 times;
//3.  P[i][j] = P[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'), if p[j - 1] == '*' and the pattern repeats for at least 1 times.
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (j > 1 && p[j - 1] == '*')
                {
                    dp[i][j] = dp[i][j - 2] || (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
                }
                else
                {
                    dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
            }
        }
        return dp[m][n];
    }
};
