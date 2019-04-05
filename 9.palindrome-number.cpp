/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 *
 * https://leetcode.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (42.51%)
 * Total Accepted:    539.2K
 * Total Submissions: 1.3M
 * Testcase Example:  '121'
 *
 * Determine whether an integer is a palindrome. An integer聽is聽a聽palindrome
 * when it聽reads the same backward as forward.
 * 
 * Example 1:
 * 
 * 
 * Input: 121
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -121
 * Output: false
 * Explanation: From left to right, it reads -121. From right to left, it
 * becomes 121-. Therefore it is not a palindrome.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 10
 * Output: false
 * Explanation: Reads 01 from right to left. Therefore it is not a
 * palindrome.
 * 
 * 
 * Follow up:
 * 
 * Coud you solve聽it without converting the integer to a string?
 * 
 */
//思路：先将数字翻转，然后判断与原来数字是否相同即可。
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)return false;
        return reverse(x) == x;
    }
    int reverse(int x) {
        int res=0;
        while(x != 0){
            if(res > INT_MAX/10)return 0; //如果res溢出，则返回0；
            res = res*10 + x%10;                //从个位数开始
            x/=10;
        }
        return res;
    }
};

