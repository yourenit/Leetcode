/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */
//
// class Solution {
// public:
//   string longestPalindrome(string s) {
//     if (s.size() < 2)
//       return s;
//     int n = s.size(), maxLen = 0, start = 0;
//     for (int i = 0; i < n - 1; i++) {
//       search(s, i, i, start, maxLen);
//       search(s, i, i + 1, start, maxLen);
//     }
//     return s.substr(start, maxLen);
//   }
//   void search(string s, int left, int right, int &start, int &maxLen) {
//     while (left >= 0 && right < s.size() && s[left] == s[right]) {
//       left--;
//       right++;
//     }
//     if (maxLen < right - left - 1) {
//       maxLen = right - left - 1;
//       start = left + 1;
//     }
//   }
// };
class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.empty())
            return "";
        int n = s.size(), dp[n][n] = {0}, left = 0, len = 1;
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = 1;
            for (int j = 0; j < i; j++)
            {
                dp[j][i] = (s[j] == s[i] && (i - j < 2 || dp[j + 1][i - 1]));
                if (dp[j][i] && len < i - j + 1)
                {
                    len = i - j + 1;
                    left = j;
                }
            }
        }
        return s.substr(left, len);
    }
};
