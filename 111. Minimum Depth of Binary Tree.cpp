/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root)return 0;
        
        int minleft=minDepth(root->left);
        int minright=minDepth(root->right);
        return (minleft&&minright)?1+min(minleft,minright):minright+1+minleft;
    }
};

//����ֵ��max��ͬ���ķ���ֵ������������������������Ϊ0�����