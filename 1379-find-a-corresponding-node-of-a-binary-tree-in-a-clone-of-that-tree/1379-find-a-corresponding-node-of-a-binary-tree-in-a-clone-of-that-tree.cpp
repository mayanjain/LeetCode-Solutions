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
    TreeNode* dfs(TreeNode* root,int req){
        if(!root)return NULL;
        if(root->val==req)return root;
        auto z=dfs(root->left,req);
        if(z)return z;
        return dfs(root->right,req);
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        int req=target->val;
        return dfs(cloned,req);
    }
};