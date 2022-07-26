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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)return root;
        auto left=lowestCommonAncestor(root->left,p,q),right=lowestCommonAncestor(root->right,p,q);
        if((left && right) || (root->val==p->val || root->val==q->val))return root;
        return left?left:right;
    }
};