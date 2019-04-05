/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (36.15%)
 * Total Accepted:    549.9K
 * Total Submissions: 1.5M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * 
 * 
 * Note that an empty string is also considered valid.
 * 
 * Example 1:
 * 
 * 
 * Input: "()"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "()[]{}"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "(]"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "([)]"
 * Output: false
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "{[]}"
 * Output: true
 * 
 * 
 */
class Solution {
public:
    bool isValid(string s) {
        if(s.empty()) return true;
       stack<char> stack;
       for(int i=0;i<s.length();i++){
           if(s[i] == '(' || s[i] == '{' || s[i] == '[')stack.push(s[i]);
           else{
               if(stack.empty())return false;
               if(s[i] == ')' && stack.top() == '(')stack.pop();
               else if(s[i] == '}' && stack.top() == '{')stack.pop();
               else if(s[i] == ']' && stack.top() == '[')stack.pop();
               else return false;
           }
       } 
       return stack.empty();
    }
};

