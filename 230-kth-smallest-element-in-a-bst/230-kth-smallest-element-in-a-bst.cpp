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
    int ans=-1;
    
    int kthSmallest(TreeNode* root, int& k) {
        if(ans!=-1 || !root)return ans;
        kthSmallest(root->left,k);
        if(!--k)ans=root->val;
        kthSmallest(root->right,k);
        return ans;
    }
};