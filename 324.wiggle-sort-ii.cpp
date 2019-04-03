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
˼·���������Ƚ�������Ȼ�������Ϊ�����֣�Ȼ�����δ�ǰ����벿�ֵ����һλ��ǰȡֵ���д�š�
�ͻ�ʵ��num[i]<num[i+1]>num[i+3]<num[i+4]��
*/
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> tmp=nums;
        sort(tmp.begin(),tmp.end());
        int n=nums.size(),k=(n+1)/2,j=n;
        for(int i=0;i<n;i++){
            nums[i] = i & 1 ? tmp[--j] : tmp[--k];       //����������Ӻ�벿��ȡֵ�������ż����ǰ�벿��ȡֵ���д��
        }
    }
};

