/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */
// #include <vector>
// using namespace std;
class Solution
{
public:
    void dfs(vector<int> &candidates, int index, int target, vector<int> tmp, vector<vector<int>> &res)
    {
        //cout<<candidates[index]<<" "<<sum<<endl;
        tmp.push_back(candidates[index]);
        int sum = 0;
        for_each(tmp.begin(), tmp.end(), [&](int t) { sum += t; });
        if (sum > target)
        { /*tmp.pop_back();*/
            return;
        }
        if (sum == target)
        {
            res.push_back(tmp);
            return;
        }

        for (int i = index; i < candidates.size(); i++)
        {
            dfs(candidates, i, target, tmp, res);
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> res;
        int sum = 0;
        vector<int> tmp;
        for (int i = 0; i < candidates.size(); i++)
        {
            dfs(candidates, i, target, tmp, res);
        }
        return res;
    }
};
