//思想：利用中序遍历的升序特性，每次判断与上次的中序遍历值进行比较。
class Solution{
public:
    bool isValidBST(TreeNode* root){
        if(!root)return true;
        if(isValidBST(root->left)){
            if(last < root->val){
                last = root->val;
                return isValidBST(root->right);
            }
        }
        return false;
    }
private:
    long last = -LONG_MAX;
}
