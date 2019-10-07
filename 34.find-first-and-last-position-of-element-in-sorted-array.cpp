/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       int left = 0,right = nums.size()-1;
       vector<int> res(2,-1);
       if(nums.size() == 0)return res;
       while(left < right){
           int mid = left + (right - left)/2;
           if(nums[mid] < target)left=mid+1;
           else right = mid;
       } 
       if(nums[right] != target)return res;
       res[0]=right;
       right = nums.size();
       while(left < right){
           int mid = left + (right - left)/2;
           if(nums[mid] <= target) left = mid +1;
           else right = mid;
       }
       res[1] = left - 1;
       return res;
    }
};

