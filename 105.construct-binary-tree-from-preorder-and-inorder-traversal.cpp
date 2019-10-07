/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
	{
		return buildTree(preorder, 0 ,preorder.size()-1, inorder, 0, inorder.size()-1);
	}
	TreeNode* buildTree(vector<int>& preorder,int pLeft, int pRight, vector<int>& inorder, int iLeft,int iRight)
	{
		if(iLeft > iRight || pLeft > pRight)return NULL;
		TreeNode* cur = new TreeNode(preorder[pLeft]);
		//寻找根节点在中序遍历中
		int i = 0;
		for(i = iLeft;i<inorder.size();i++)
		{
			if(inorder[i] == cur->val)break;
		}
		cur->left = buildTree(preorder,pLeft+1, pLeft + i-iLeft, inorder,iLeft, i -1);
		cur->right = buildTree(preorder, pLeft+i-iLeft+1, pRight, inorder, i+1,iRight);
		return cur;
	}
};

