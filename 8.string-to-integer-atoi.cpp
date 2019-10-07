/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */
class Solution {
public:
    int myAtoi(string str) {
        int i=0,sum=0,flag=0;
        while(i<str.length() && str[i] == ' ')i++;
        if(i<str.length() && (str[i] == '-' || str[i] =='+')){
            flag = (str[i++] == '+')?0:1;
        }
        while((str[i] >= '0' &&str[i] <= '9') && i < str.length()){
                if(INT_MAX/10 <= sum){
                    if(sum == INT_MAX/10 && str[i] >'7')
                        return flag?INT_MIN:INT_MAX;
                    else if(sum > INT_MAX/10)return flag?INT_MIN:INT_MAX;
                }
                sum=sum*10 + (str[i]-'0');
            i++;
        }
        return flag?sum*(-1):sum;
    }
};

