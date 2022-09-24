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
    vector<vector<int>> ans;
    
    void path(TreeNode* root,vector<int>& cur,int target){
        if(!root)return;
        target-=root->val;
        cur.push_back(root->val);
        if(!target && !root->left && !root->right)ans.push_back(cur);
        path(root->left,cur,target);
        path(root->right,cur,target);
        target+=root->val;
        cur.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> cur;
        path(root,cur,targetSum);
        return ans;
    }
};