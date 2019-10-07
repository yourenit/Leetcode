/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */
class Solution1
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        if (nums.size() < 4)
            return vector<vector<int>>();
        set<vector<int>> res;
        sort(nums.begin(), nums.end());
        vector<int> t(4, 0);
        int sum = 0;
        for (int i = 0; i < nums.size() - 3; i++)
        {
            for (int j = i + 1; j < nums.size() - 2; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                int left = j + 1, right = nums.size() - 1;
                while (left < right)
                {
                    sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum < target)
                        left++;
                    else if (sum > target)
                        right--;
                    else
                    {
                        t[0] = nums[i];
                        t[1] = nums[j];
                        t[2] = nums[left];
                        t[3] = nums[right];
                        res.insert(t);
                        left++;
                        right--;
                    }
                }
            }
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};

//手动去掉重复项
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        if (nums.size() < 4)
            return vector<vector<int>>();
        vector<vector<int>> res;
        vector<int> t(4, 0);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < nums.size() - 2; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                int left = j + 1, right = nums.size() - 1;

                while (left < right)
                {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum > target)
                        right--;
                    else if (sum < target)
                        left++;
                    else
                    {
                        t[0] = nums[i];
                        t[1] = nums[j];
                        t[2] = nums[left];
                        t[3] = nums[right];
                        res.push_back(t);
                        while (left < right && nums[left] == nums[left + 1])
                            left++;
                        while (left < right && nums[right] == nums[right - 1])
                            right--;
                        left++;
                        right--;
                    }
                }
            }
        }
        return res;
    }
};
