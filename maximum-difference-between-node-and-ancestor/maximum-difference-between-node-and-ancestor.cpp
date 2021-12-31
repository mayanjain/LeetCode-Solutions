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
    int ans=0;
    int maxAncestorDiff(TreeNode* root,int mx=-1,int mn=-1) {
        if(!root)return 0;
        if(mx==-1)mx=root->val;
        if(mn==-1)mn=root->val;
        ans=max(ans,max(abs(root->val-mx),abs(root->val-mn)));
        mx=max(mx,root->val);
        mn=min(mn,root->val);
        maxAncestorDiff(root->left,mx,mn);
        maxAncestorDiff(root->right,mx,mn);
        return ans;
    }
};