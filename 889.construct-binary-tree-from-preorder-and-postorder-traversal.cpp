/*
 * @lc app=leetcode id=889 lang=cpp
 *
 * [889] Construct Binary Tree from Preorder and Postorder Traversal
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution1 {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return helper(pre, 0, pre.size()-1,post,0,post.size()-1);
    }
    TreeNode* helper(vector<int>& pre, int preLeft,int preRight, vector<int>& post,int postLeft, int postRight)
    {
        if(preLeft > preRight || postLeft > postRight)return NULL;
        TreeNode* cur = new TreeNode(pre[preLeft]);
        if(preLeft == preRight)return cur;
        int i =-1;
        for(i=postLeft; i<=postRight;i++)
        {
            if(post[i] == pre[preLeft +1])break;    
        }
        cur->left = helper(pre, preLeft+1, preLeft+1+(i-postLeft), post, postLeft, i);
        cur->right = helper(pre, preLeft +1+(i-postLeft)+1,preRight, post, i+1,postRight-1);
        return cur;
    }
};

class Solution {
public:
    TreeNode*  constructFromPrePost(vector<int>& pre, vector<int>& post) 
    {
        vector<TreeNode*> st;
        st.push_back(new TreeNode(pre[0]));
        for(int i=1, j =0;i<pre.size();i++)
        {
            TreeNode* node = new TreeNode(pre[i]);
            while(st.back()->val == post[j])
            {
                st.pop_back();
                ++j;
            }
            if(!st.back()->left)st.back()->left = node;
            else st.back()->right = node;
            st.push_back(node);
        }
        return st[0];
    }
};
