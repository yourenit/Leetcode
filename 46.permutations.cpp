/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
// 交换两个数字
// class Solution
// {
// public:
//     vector<vector<int>> permute(vector<int> &nums)
//     {
//         vector<vector<int>> res;
//         dfs(nums, 0, res);
//         return res;
//     }
//     void dfs(vector<int> &nums, int start, vector<vector<int>> &res)
//     {
//         if (start >= nums.size())
//         {
//             res.push_back(nums);
//         }
//         //每次循环，将一个元素再全排列中的所有位置都遍历，
//         //也可以认为将数组中的每个元素作为头，然后将剩下
//         //的元素递归即可。每次只交换两个数字。
//         for (int i = start; i < nums.size(); i++)
//         {
//             swap(nums[start], nums[i]);
//             dfs(nums, start + 1, res);
//             swap(nums[start], nums[i]);
//         }
//     }
// };

// class Solution
// {
// public:
//     vector<vector<int>> permute(vector<int> &nums)
//     {
//         vector<vector<int>> res;
//         vector<int> visited(nums.size(), 0), out;
//         dfs(nums, 0, visited, out, res);
//         return res;
//     }
//     void dfs(vector<int> &nums, int level, vector<int> &visited, vector<int> &out, vector<vector<int>> &res)
//     {
//         if (level == nums.size())
//         {
//             res.push_back(out);
//             return;
//         }
//         for (int i = 0; i < nums.size(); i++)
//         {
//             if (visited[i] == 1)
//                 continue;
//             visited[i] = 1;
//             out.push_back(nums[i]);
//             dfs(nums, level + 1, visited, out, res);
//             out.pop_back();
//             visited[i] = 0;
//         }
//     }
// };
class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        res.push_back(nums);
        while (next_permutation(nums.begin(), nums.end()))
        {
            res.push_back(nums);
        }
        return res;
    }
};
// @lc code=end
