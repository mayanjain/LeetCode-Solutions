/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool valid(TreeNode* root,long mn,long mx){
        if(!root)return true;
        if(root->val<mn || root->val>mx)return false;
        return valid(root->left,mn,long(root->val)-1)&&valid(root->right,long(root->val)+1,mx);
    }
    
    bool isValidBST(TreeNode* root) {
        return valid(root,INT_MIN,INT_MAX);
    }
};