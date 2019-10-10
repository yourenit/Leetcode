/*
 * @lc app=leetcode id=552 lang=cpp
 *
 * [552] Student Attendance Record II
 */

// @lc code=start
const int MOD = 1e9 + 7;
class Solution
{
public:
    int checkRecord(int n)
    {
        vector<int> P(n + 1, 0), A(n + 1, 0), L(n + 1, 0);
        P[1] = 1;
        L[1] = 1;
        A[1] = 1;
        if (n > 1)
        {
            L[2] = 3;
            A[2] = 2;
        }
        if (n > 2)
        {
            A[3] = 4;
        }
        for (int i = 2; i <= n; i++)
        {
            P[i] = ((P[i - 1] + L[i - 1]) % MOD + A[i - 1]) % MOD;
            if (i > 2)
                L[i] = ((A[i - 1] + P[i - 1]) % MOD + (A[i - 2] + P[i - 2]) % MOD) % MOD;
            if (i > 3)
                A[i] = ((A[i - 1] + A[i - 2]) % MOD + A[i - 3]) % MOD;
        }
        return ((A[n] + P[n]) % MOD + L[n]) % MOD;
    }
};

// @lc code=end
