//递归版
vector<int> inorderTraversal(TreeNode* root){
    vector<int> res;
    inorder(root,res);
    return res;
}

void inorder(TreeNode * root,vector<int>& res)
{
    if(!root)return;
    inorder(root->left,res);
    res.push_back(root->val);
    inorder(root->right,res);
}


//非递归版
vector<int> inorderTraversal(TreeNode* root)
{
    stack<TreeNode*> stack;
    vector<int> res;
    while(root != NULL || !stack.empty())
    {
        if(root != NULL){
            stack.push(root);
            root=root->left;
        }else{
            TreeNode * node = stack.top();
            stack.pop();
            res.push_back(node->val);
            root = node->right;
        }
    }
}
