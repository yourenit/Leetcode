/*
 * @lc app=leetcode id=44 lang=cpp
 *
 * [44] Wildcard Matching
 */
class Solution1 {
public:
    bool isMatch(string s, string p) {
       int i=0,j=0,iStart = -1,jStart = -1;
       while(i < s.length())
       {
           if(s[i] == p[j] || p[j] == '?')
           {
               i++;j++;
           }
           else if (p[j] == '*')
           {
               iStart = i;
               jStart = j++;
           }
           else if(iStart >= 0)
           {
               i = ++iStart;
               j = jStart+1;
           }else return false;
       } 
       while(j < p.size() && p[j] == '*')++j;
       return j==p.size();
    }
};
//动态规划做法
// class Solution{
// public:
//     bool isMatch(string s,string p)
//     {
//         int m = s.length(),n=p.length();
//         vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
//         dp[0][0] = true;        //字符串都为空的话，返回true
//         for(int i =0; i<=n;i++)
//         {
//             if(p[i-1] == '*') dp[0][i] = dp[0][i-1];
//         }
//         for(int i=1;i<=m;i++)
//         {
//             for(int j =1;j<=n;j++)
//             {
//                 if(p[j-1] == '*'){
//                     dp[i][j] = dp[i-1][j] || dp[i][j-1];
//                 }else
//                 {
//                     dp[i][j] = (s[i-1] == p[j-1] || p[j-1] == '?') && dp[i-1][j-1];
//                 }
//             }
//         }
//         return dp[m][n];
//     }
// };
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= n; ++i) {
            if (p[i - 1] == '*') dp[0][i] = dp[0][i - 1];
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                } else {
                    dp[i][j] = (s[i - 1] == p[j - 1] || p[j - 1] == '?') && dp[i - 1][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};
