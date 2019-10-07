/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
      for (int j = 0; j < coins.size(); j++) {
        if (coins[j] <= i) {
          dp[i] = min(dp[i], dp[i - coins[j]] + 1);
        }
      }
    }
    return (dp.back() > amount) ? -1 : dp.back();
  }
};

class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    return dfs(coins, amount, dp);
  }
  int dfs(vector<int> &coins, int amount, vector<int> &dp) {
    if (amount < 0)
      return -1;
    if (dp[amount] != INT_MAX)
      return dp[amount];
    for (int i = 0; i < coins.size(); i++) {
      int tmp = dfs(coins, amount - coins[i], dp);
      if (tmp >= 0) {
        dp[amount] = min(dp[amount], tmp + 1);
      }
    }
    return dp[amount] = (dp[amount] == INT_MAX) ? -1 : dp[amount];
  }
};
// @lc code=end
