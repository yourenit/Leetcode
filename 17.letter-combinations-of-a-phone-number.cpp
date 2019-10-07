/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */
class Solution {
public:
    vector<string> letterCombinations(string digits) {
       if(digits.length() == 0)return vector<string>();
       vector<string> res;
       string str="";
       res.push_back(str);
       print(digits,0,res);
       sort(res.begin(),res.end());
       return res; 
    }
    void print(string digist,int i,vector<string> &res){
        if(i == digist.length())return;
        char c=digist[i];
        vector<string> t(res.begin(),res.end());
        res.clear();
        int m=((c-'0')-2)*3;
        if(c>='8')m+=1;
        for_each(t.begin(),t.end(),[&](string a){res.push_back(a+=('a'+m));});
        for_each(t.begin(),t.end(),[&](string a){res.push_back(a+=('a'+m+1));});
        for_each(t.begin(),t.end(),[&](string a){res.push_back(a+=('a'+m+2));});
        if(c=='7' || c=='9')for_each(t.begin(),t.end(),[&](string a){res.push_back(a+=('a'+m+3));});
        print(digist,i+1,res);
    }
};

