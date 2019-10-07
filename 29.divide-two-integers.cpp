/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */
class Solution {
public:
    int divide(int dividend, int divisor) {
        long long res=(long)dividend/divisor;
        return res>INT_MAX?INT_MAX:(int)res;
    }
};

