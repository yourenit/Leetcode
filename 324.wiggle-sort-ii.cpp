/*
 * @lc app=leetcode id=324 lang=cpp
 *
 * [324] Wiggle Sort II
 *
 * https://leetcode.com/problems/wiggle-sort-ii/description/
 *
 * algorithms
 * Medium (27.64%)
 * Total Accepted:    56K
 * Total Submissions: 202.7K
 * Testcase Example:  '[1,5,1,1,6,4]'
 *
 * Given an unsorted array nums, reorder it such that nums[0] < nums[1] >
 * nums[2] < nums[3]....
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1, 5, 1, 1, 6, 4]
 * Output: One possible answer is [1, 4, 1, 5, 1, 6].
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1, 3, 2, 2, 3, 1]
 * Output: One possible answer is [2, 3, 1, 3, 1, 2].
 * 
 * Note:
 * You may assume all input has valid answer.
 * 
 * Follow Up:
 * Can you do it in O(n) time and/or in-place with O(1) extra space?
 */
/*
思路：将数组先进行排序，然后将数组分为两部分，然后依次从前、后半部分的最后一位向前取值进行存放。
就会实现num[i]<num[i+1]>num[i+3]<num[i+4]。
*/
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> tmp=nums;
        sort(tmp.begin(),tmp.end());
        int n=nums.size(),k=(n+1)/2,j=n;
        for(int i=0;i<n;i++){
            nums[i] = i & 1 ? tmp[--j] : tmp[--k];       //如果是奇数从后半部分取值，如果是偶数从前半部分取值进行存放
        }
    }
};

