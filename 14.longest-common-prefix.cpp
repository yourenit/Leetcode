/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (33.19%)
 * Total Accepted:    433.8K
 * Total Submissions: 1.3M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * 
 * 
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * Note:
 * 
 * All given inputs are in lowercase letters a-z.
 * 
 */
//解法一：按列搜索，对比每行对应列的字符是否相等
// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs) {
//        if( strs.size() <= 0) return "";
//        string res;
//        for(int j=0;j<strs[0].size();j++){
//            char c=strs[0][j];
//            for(int i=1;i<strs.size();i++){
//                if( j >= strs[i].size() || strs[i][j] !=c)return res;
//            }
//            res.push_back(c);
//        } 
//        return res;
//     }
// };

//解法二：只需找到以第一个字符串不相等的地方，前面即为前缀
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       if( strs.size() <= 0) return "";
       for(int j=0;j<strs[0].size();j++){
           for(int i=0;i<strs.size();i++){
               if( j >= strs[i].size() || strs[i][j] !=strs[0][j]) return strs[i].substr(0,j);
           }
       } 
       return strs[0];
    }
};


