/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */
//���취
class Solution1 {
public:
    int maxArea(vector<int>& height) {
       int water=0;
       int maxi=0;
       for(int i =0;i < height.size();i++){
           int tmp=0;
           for(int j=0;j< i ;j++){
               tmp = max(tmp,min(height[j],height[i])*(i-j));
           }
           water=max(tmp,water);
       } 
       return water;
    }
};

//���㷨ֻ��Ƚ�һ�μ��ɣ�����ָ���ƶ�ʹ���������
class Solution{
public:
    int maxArea(vector<int>& height){
        int water=0,i=0,j=height.size()-1;
        while(i < j){
            water = max(water,min(height[j],height[i])*(j-i));
            height[i] > height[j]?j--:i++;
        }
        return water;
    }
};
