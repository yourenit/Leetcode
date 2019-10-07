/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */
//����ѵ����ڶ��ǺŵĴ���
//��jstart����ʾ�Ǻ���p����λ�ã�istart��ʾ�Ǻ�ƥ�䵽s����λ��
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

