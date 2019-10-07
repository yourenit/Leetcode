/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
       vector<int> res;
       sort(nums.begin(),nums.end());
       int sum=0,min=INT_MAX;
       for(int i=1;i<nums.size()-1;i++){
           int left = i-1,right=i+1;
           while(left > -1 && right < nums.size()){
               sum=nums[left]+nums[i]+nums[right];
               if(sum < target){
                   right++;
               }else if(sum > target)left--; 
               else{
                   return target;
               }
               if(abs(sum -target) < min){
                   min=abs(sum-target);
                   res.push_back(sum);
               }
           }
       }
       return res.back();
       //return *min_element(res.begin(),res.end(),[&](int &a,int &b){ abs(a-target)<abs(b-target);});
    }
};

