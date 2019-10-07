/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() < 3)return res;
        sort(nums.begin(),nums.end());
        if(nums.back() < 0 || nums.front() > 0)return res;
        for(int i=0;i<nums.size()-2;i++)
        {
            if(nums[i] > 0)break;           //三个数必有一个为负，排序之后第一个必定为负数
            if(i > 0 && nums[i] == nums[i-1])continue;
            int left = i+1,right = nums.size()-1;
            while(left < right)
            {
                if(nums[left] + nums[right] + nums[i] == 0)
                {
                    res.push_back({nums[i],nums[left],nums[right]});
                    while(left < right && nums[left] == nums[left+1])left++;
                    while(left < right && nums[right] == nums[right-1])right--;
                }
                else if(nums[left] + nums[right] + nums[i] > 0)right--;
                else left++;
            }
        }
        return res;
    }
};

