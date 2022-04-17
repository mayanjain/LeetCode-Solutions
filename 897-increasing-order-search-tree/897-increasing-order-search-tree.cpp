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
    TreeNode* cur=new TreeNode(0);
    TreeNode* ptr=cur;
    
    void inorder(TreeNode* root){
        if(!root)return;
        inorder(root->left);
        root->left=NULL;
        cur->right=root;
        cur=cur->right;
        inorder(root->right);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);
        return ptr->right;
    }
};