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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)return {};
        vector<TreeNode*> nLevel={ root};
        vector<vector<int>> res;
        vector<int> vals;
        
        while(!nLevel.empty()){
            vals.clear();
            for_each(nLevel.begin(),nLevel.end(),[&](TreeNode* node){
                vals.push_back(node->val);
            });
            res.push_back(vals);
            nLevel=nextLevel(nLevel);
        }
        return res;
    }
    
    vector<TreeNode*> nextLevel(vector<TreeNode*> preLevel){
        vector<TreeNode*> res; 
        for(int i=0;i<preLevel.size();i++){
            if(preLevel[i]->left)
                res.push_back(preLevel[i]->left);
            if(preLevel[i]->right)
                res.push_back(preLevel[i]->right);
        }
        return res;
    }
};

