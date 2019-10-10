/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */
//��һ�ֽⷨ���ݹ飬��*�Ĵ����õݹ鴦��
class Solution1
{
public:
    bool isMatch(string s, string p)
    {
        //���pΪ�մ����򷵻�true;
        if (p.empty())
            return s.empty();
        //���p��s�ĳ��ȶ�Ϊ1������Ȼ���p[0]Ϊ'.'���򷵻�true;
        if (p.size() == 1)
            return (s.size() == 1) && (p[0] == s[0] || p[0] == '.');
        //����ڶ����ַ���Ϊ'*'��
        if (p[1] != '*')
        {
            //��s��Ϊ�գ��򷵻�false;
            if (s.empty())
                return false;
            //����ƥ��ڶ����ַ�������ַ���
            return (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
        }
        //����ڶ����ַ�Ϊ'*'�����s����Ϊ�գ��ҵ�һ���ַ���ȷƥ��
        while (!s.empty() && (s[0] == p[0] || p[0] == '.'))
        {
            //���ȼ���*ǰ����ַ�����0�Σ��ж��Ƿ�ƥ�䣬���ƥ�䣬����true;
            if (isMatch(s, p.substr(2)))
                return true;
            //�����ƥ�䣬��˵��*ǰ����ַ���������1�Σ���ȥ���Ѿ��ɹ�ƥ����ַ���s�����ַ���
            s = s.substr(1);
        }
        //�����һ���ַ���ƥ�䣬��˵��*��ǰ����ַ�Ϊ0�Σ���ֻƥ��*������ַ�����s��
        return isMatch(s, p.substr(2));
    }
};
#include <vector>
using namespace std;
//�ڶ��ֽⷨ����̬�滮
//���� dp[i][j] ��ʾ s[0,i) �� p[0,j) �Ƿ� match
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
