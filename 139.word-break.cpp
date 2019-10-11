/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
#include <string>
using namespace std;
//δ�����ַ�������ַ���ͬ�����
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
                //���ƥ�䣬���������ָ���λ��
                if (str.compare(wordDict[j]) == 0)
                {
                    pre = i;
                    break;
                }
            }
            //�����ƥ�䣬��ָ����һ��λ��
            i++;
        }
        return pre == i - 1;
    }
};

//�ݹ�:��ԭ�ַ�����Ϊ�����ֽ����ж�
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
        //start��ʾ�ֶε��±�
        if (start >= s.size())
            return true;
        if (m[start] != -1)
            return m[start];
        for (int i = start + 1; i <= s.size(); i++)
        {
            //ֱ���ɹ�ƥ��
            if (wordSet.count(s.substr(start, i - start)) && check(s, wordSet, i, m))
            {
                return m[start] = 1;
            }
        }
        return m[start] = 0;
    }
};
//��̬�滮����ݹ�һ��Ҳ�ǽ��ַ�����Ϊ�������жϣ�ֻ������̬�滮�����ַ���ͬ����Ϊ������
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        //dp[i]��ʾ(0,i)�Ƿ��ܳɹ�ƥ��wordDict�е��ַ���
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        //i��ݹ��е�start������ͬ
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
