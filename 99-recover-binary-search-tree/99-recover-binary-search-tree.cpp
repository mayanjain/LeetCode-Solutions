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
    vector<int> nodes;
    bool all=0;
    int cur=0;
    
    void dfs(TreeNode* root){
        if(!root)return ;
        dfs(root->left);
        if(!all)nodes.push_back(root->val);
        else root->val=nodes[cur++];
        dfs(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        dfs(root);
        all = 1;
        sort(nodes.begin(),nodes.end());
        dfs(root);
    }
};