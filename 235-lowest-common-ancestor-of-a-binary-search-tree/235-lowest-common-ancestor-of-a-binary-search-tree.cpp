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
    TreeNode* ans;
    
    bool solve(TreeNode* root,TreeNode* p,TreeNode* q){
        if(!root)return false;
        bool left=solve(root->left,p,q),right=solve(root->right,p,q);
        if(left && right)ans=root;
        if((left || right) && (root->val==p->val || root->val==q->val)){
            ans=root;
        }
        return (left||right||root->val==p->val||root->val==q->val);
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        solve(root,p,q);
        return ans;
    }
};