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
    vector<TreeNode*> ans;
    set<int> del;
    
    TreeNode* solvin(TreeNode* root){
        if(!root)return NULL;
        if(del.count(root->val)){
            delNode(root->left);
            delNode(root->right);
            return NULL;
        }
        root->left=solvin(root->left);
        root->right=solvin(root->right);
        return root;
    }
    
    void delNode(TreeNode* root){
        auto t=solvin(root);
        if(t)ans.push_back(t);
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(auto& i:to_delete)del.insert(i);
        delNode(root);
        return ans;
    }
};