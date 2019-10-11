/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
#include <string>
using namespace std;
//未考虑字符串多个字符相同的情况
class Solution1
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int i = 1, pre = 0;
        string str;
        while (i <= s.size())
        {
            str = s.substr(pre, i - pre);
            for (int j = 0; j < wordDict.size(); j++)
            {
                //如果匹配，则更新两个指针的位置
                if (str.compare(wordDict[j]) == 0)
                {
                    pre = i;
                    break;
                }
            }
            //如果不匹配，则指向下一个位置
            i++;
        }
        return pre == i - 1;
    }
};

//递归:将原字符串分为两部分进行判断
class Solution2
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<int> m(s.size(), -1);
        return check(s, wordSet, 0, m);
    }
    bool check(string s, unordered_set<string> &wordSet, int start, vector<int> &m)
    {
        //start表示分段的下标
        if (start >= s.size())
            return true;
        if (m[start] != -1)
            return m[start];
        for (int i = start + 1; i <= s.size(); i++)
        {
            //直到成功匹配
            if (wordSet.count(s.substr(start, i - start)) && check(s, wordSet, i, m))
            {
                return m[start] = 1;
            }
        }
        return m[start] = 0;
    }
};
//动态规划：与递归一样也是将字符串分为两部分判断，只不过动态规划对子字符串同样分为两部分
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        //dp[i]表示(0,i)是否能成功匹配wordDict中的字符串
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        //i与递归中的start作用相同
        for (int i = 0; i <= s.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (dp[j] && wordSet.count(s.substr(j, i - j)))
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp.back();
    }
};
// @lc code=end
