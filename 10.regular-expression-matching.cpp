/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */
//最大难点在于对星号的处理
//用jstart来表示星号在p串的位置，istart表示星号匹配到s串的位置
//
class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0,j = 0,iStart = -1,jStart = -1;
        while(i < s.length())
        {
            if(s[i] == p[j] || p[j] == '?')
            {
                ++i;++j;
            }else if(p[j] == '*')
            {
                iStart = i;
                jStart = j++;
            }else if(iStart >= 0)
            {
                i =++iStart;
                j = jStart +1;
            }else return false;
        }
        while( j <p.size() && p[j] == '*')++j;
        return j==p.size();
    }
};

