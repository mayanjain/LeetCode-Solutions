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
    TreeNode* ans=NULL;
    
    bool lca(TreeNode* root,TreeNode* p,TreeNode* q){
        if(!root)return false;
        auto left=lca(root->left,p,q),right=lca(root->right,p,q);
        if(left && right && !ans)ans=root;
        else if((left || right) && (root==q || root==p))ans=root;
        return (left||right||root==p||root==q);
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        lca(root,p,q);
        return ans;
    }
};