/*
 * @lc app=leetcode id=227 lang=cpp
 *
 * [227] Basic Calculator II
 */

// @lc code=start
#include <string>
#include <stack>
#include <ctype.h>
using namespace std;
// class Solution {
// public:
//     int calculate(string s) {
//         long res =0,num = 0,n=s.size();
//         char op = '+';
//         stack<int> st;
//         for(int i=0;i<n;i++)
//         {
//             //解析数字-
//             if(s[i] >= '0' && s[i] <= '9')
//             {
//                 num = num*10 + s[i] -'0';
//             }
//             if((s[i] < '0' && s[i] != ' ') || i == n-1)
//             {
//                 if(op == '+')st.push(num);
//                 if(op == '-')st.push(-num);
//                 if(op == '*' || op == '/')
//                 {
//                     int tmp =(op == '*')?st.top()*num:st.top()/num;
//                     st.pop();
//                     st.push(tmp);
//                 } 
//                 op = s[i];
//                 num = 0;
//             }
//         }
//         while(!st.empty())
//         {
//             res+=st.top();
//             st.pop();
//         }
//         return res;
//     }
// };
class Solution {
public:
    int calculate(string s)
    {
        long res= 0,num = 0,n=s.size(),curRes = 0;
        char op = '+';
        for(int i=0;i<n;i++)
        {
            char c = s[i];
            //解析数字
            if(c >= '0' && c <= '9')
            {
                num = num*10 + s[i] - '0';
            }
            //如果遇到运算符号或者结尾
            if((c < '0' && c!= ' ') || i == n-1)
            {
                switch(op)
                {
                    case '+': curRes+=num;break;
                    case '-': curRes-=num;break;
                    case '*': curRes*=num;break;
                    case '/': curRes/=num;break;
                }
                //这里替代了栈
                if(c == '+' || c == '-' || i == n-1)
                {
                    res += curRes;
                    curRes = 0;
                }
                op = c;
                num = 0;
            }
        }
        return res;
    }
};
// @lc code=end

